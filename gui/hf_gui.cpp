/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#include "hf_gui.h"
#include "ui_hf_gui.h"

#include <QMessageBox>
#include <QMovie>
#include <QPixmap>

#include <cg3/algorithms/global_optimal_rotation_matrix.h>
#include <cg3/algorithms/sphere_coverage.h>
#include <cg3/libigl/booleans.h>
#include <cg3/meshes/eigenmesh/algorithms/eigenmesh_algorithms.h>
#include <cg3/vcglib/smoothing.h>

#include "thread_worker.h"

HFGui::HFGui(QWidget *parent) :
    QFrame(parent),
	ui(new Ui::HFGui),
	mw((HFMainWindow&)*parent),
	actualRotationMatrix(Eigen::Matrix3d::Identity()),
	actualTab(0),
	rotatableMesh(mw.canvas),
	box(mw.canvas),
	actualAction(0)
{
    ui->setupUi(this);

	QPixmap pixmap(":/green.ico");
	ui->circLabel->setPixmap(pixmap);

	lsmesh.addSupportedExtension("obj");
	lsmesh.addSupportedExtension("ply");
	lsmesh.addSupportedExtension("dcel");
	lshfd.addSupportedExtension("hfd");
	mw.canvas.toggleCameraType();
	mw.canvas.pushDrawableObject(&guides);

	connect(&mw, SIGNAL(undoEvent()),
			this, SLOT(undo()));

	connect(&mw, SIGNAL(redoEvent()),
			this, SLOT(redo()));

	ThreadWorker* tw = new ThreadWorker;
	tw->moveToThread(&workerThread);
	connect(&workerThread, SIGNAL(finished()), tw, SLOT(deleteLater()));

	qRegisterMetaType<cg3::Dcel>("cg3::Dcel");
	qRegisterMetaType<Eigen::Matrix3d>("Eigen::Matrix3d");
	qRegisterMetaType<HFBox>("HFBox");
	qRegisterMetaType<HFEngine*>("HFEngine*");
	qRegisterMetaType<std::vector<cg3::Dcel>>("std::vector<cg3::Dcel>");
	qRegisterMetaType<cg3::BoundingBox3>("cg3::BoundingBox3");
	qRegisterMetaType<std::vector<std::pair<int, cg3::Point3d>>>("std::vector<std::pair<int, cg3::Point3d>>");

	connect(tw, SIGNAL(setProgressBarValue(uint)),
			this, SLOT(setProgressBarValue(uint)));

	connect(this, SIGNAL(taubinSmoothing(cg3::Dcel, uint, double, double)),
	        tw, SLOT(taubinSmoothing(cg3::Dcel, uint, double, double)));

	connect(tw, SIGNAL(taubinSmoothingCompleted(cg3::Dcel)),
	        this, SLOT(taubinSmoothingCompleted(cg3::Dcel)));

	connect(this, SIGNAL(optimalOrientation(cg3::Dcel, uint)),
			tw, SLOT(optimalOrientation(cg3::Dcel, uint)));

	connect(tw, SIGNAL(optimalOrientationCompleted(Eigen::Matrix3d)),
			this, SLOT(optimalOrientationCompleted(Eigen::Matrix3d)));

	connect(this, SIGNAL(cut(cg3::Dcel, HFBox)),
			tw, SLOT(cut(cg3::Dcel, HFBox)));

	connect(tw, SIGNAL(cutCompleted(cg3::Dcel)),
			this, SLOT(cutCompleted(cg3::Dcel)));

	connect(this, SIGNAL(restoreHighFrequencies(HFEngine*, uint, double)),
			tw, SLOT(restoreHighFrequencies(HFEngine*, uint, double)));

	connect(tw, SIGNAL(restoreHighFrequenciesCompleted()),
			this, SLOT(restoreHighFrequenciesCompleted()));

	connect(this, SIGNAL(computeDecomposition(HFEngine*)),
			tw, SLOT(computeDecomposition(HFEngine*)));

	connect(this, SIGNAL(computeDecompositionExact(HFEngine*)),
			tw, SLOT(computeDecompositionExact(HFEngine*)));

	connect(tw, SIGNAL(computeDecompositionCompleted(std::vector<cg3::Dcel>)),
			this, SLOT(computeDecompositionCompleted(std::vector<cg3::Dcel>)));

	connect(this, SIGNAL(packInOneStock(std::vector<cg3::Dcel>, cg3::BoundingBox3, double)),
			tw, SLOT(packInOneStock(std::vector<cg3::Dcel>, cg3::BoundingBox3, double)));

	connect(tw, SIGNAL(packInOneStockCompleted(bool, double, std::vector<std::pair<int, cg3::Point3d>>)),
			this, SLOT(packInOneStockCompleted(bool, double, std::vector<std::pair<int, cg3::Point3d>>)));

	workerThread.start();
}

HFGui::~HFGui()
{
	workerThread.quit();
	workerThread.wait();
	delete ui;
}

bool HFGui::loadMesh()
{
	std::string filename = lsmesh.loadDialog("Load Mesh");
	if (filename != ""){
		cg3::Dcel tmp;
		if(tmp.loadFromFile(filename)){
			clear();
			mesh = tmp;
			mesh.translate(-mesh.boundingBox().center());
			mesh.setFaceColors(cg3::GREY);
			mesh.update();

			mesh.setFaceFlags(0);

			mw.pushDrawableObject(&mesh, "Loaded Mesh");
			treeMesh = cg3::cgal::AABBTree3(mesh);
			hfEngine.setMesh(mesh);

			mw.canvas.fitScene();
			mw.canvas.update();

			ui->tabWidget->setEnabled(true);
			ui->tabWidget->setTabEnabled(0, true);
			ui->tabWidget->setTabEnabled(1, false);
			ui->tabWidget->setTabEnabled(2, false);
			ui->tabWidget->setTabEnabled(3, false);
			ui->tabWidget->setTabEnabled(4, false);
			ui->testFrame->setEnabled(true);
			actualTab = 0;
			guides.setBoundingBox(mesh.boundingBox());
			return true;
		}
	}
	return false;
}

bool HFGui::loadHFD()
{
	std::string filename = lshfd.loadDialog("Load HFD");
	if (filename != "") {
		std::ifstream myfile;
		myfile.open (filename, std::ios::in | std::ios::binary);
		if (myfile.is_open()){
			startWork();
			clear();
			uint v;
			cg3::deserialize(v, myfile);
			cg3::deserializeObjectAttributes("HFD", myfile, hfEngine, actualTab, mesh, actualRotationMatrix,
										   totalSurface, totalVolume, remainingSurface, remainingVolume, stock);
			myfile.close();
			afterLoadHFD();
			return true;
		}
	}
	return false;
}

void HFGui::afterLoadHFD()
{
	for (auto& d : hfDecomposition){
		d.update();
	}
	for (auto& v : packing){
		for (auto& d : v){
			d.update();
		}
	}
	ui->tabWidget->setEnabled(true);
	ui->tabWidget->setTabEnabled(0, false);
	ui->tabWidget->setTabEnabled(1, false);
	ui->tabWidget->setTabEnabled(2, false);
	ui->tabWidget->setTabEnabled(3, false);
	ui->tabWidget->setTabEnabled(4, false);
	ui->nBoxesLabel->setText(QString::number(hfEngine.boxes().size()));
	colorTestMesh();
	changeTab(actualTab);
	mw.pushDrawableObject(&mesh, "Loaded Mesh");
	treeMesh = cg3::cgal::AABBTree3(mesh);
	mesh.update();
	if (hfEngine.usesSmoothedMesh()){
		originalMesh = hfEngine.originalMesh();
		originalMesh.update();
		mw.pushDrawableObject(&originalMesh, "Non-Smoothed Mesh", false);
		mw.setDrawableObjectName(&mesh, "Smoothed Mesh");
	}
	updateSurfaceAndvolume();
	if (actualTab == 1 || actualTab == 2){
		box.set(mesh.boundingBox().min(), mesh.boundingBox().max());
		mw.pushDrawableObject(&box, "box");
		if (actualTab == 2){
			box.setDrawArrow(true);
		}
	}
	if (actualTab == 3){
		if (hfEngine.decomposition().size() > 0){
			mw.setDrawableObjectVisibility(&mesh, false);
			mw.setDrawableObjectVisibility(&originalMesh, false);
			hfDecomposition.clear();
			uint i = 0;
			for (const cg3::Dcel& d : hfEngine.decomposition())
				hfDecomposition.pushBack(d, "Block " + std::to_string(i++));
			mw.pushDrawableObject(&hfDecomposition, "Decomposition");
			ui->exportDecompositionPushButton->setEnabled(true);
			ui->nextPostProcessingPushButton->setEnabled(true);
		}
		if (hfEngine.usesSmoothedMesh()) {
			ui->restoreHighFrequenciesPushButton->setEnabled(true);
			ui->nRestoreIterationsSpinBox->setEnabled(true);
			ui->nRestoreIterationsLabel->setEnabled(true);
			ui->hausDescrLabel->setEnabled(true);
			ui->hausdorffDistanceLabel->setEnabled(true);
		}
	}
	if (actualTab == 4){
		mw.pushDrawableObject(&hfDecomposition, "Decomposition", false);
		mw.setDrawableObjectVisibility(&mesh, false);
		ui->xStockSpinBox->setValue(stock.maxX());
		ui->yStockSpinBox->setValue(stock.maxY());
		ui->zStockSpinBox->setValue(stock.maxZ());
		mw.pushDrawableObject(&stock, "Stock");
		if (hfEngine.packing().size() > 0){
			packing.clear();
			uint i = 0;
			for (const std::vector<cg3::Dcel>& stock : hfEngine.packing()){
				bool vis = i == 0;
				packing.pushBack(cg3::DrawableObjectsContainer<cg3::DrawableDcel>(), "Stock " + std::to_string(i), vis);
				uint j = 0;
				for (const cg3::Dcel& d : stock)
					packing.at(i).pushBack(d, "Block " + std::to_string(j++));
				i++;
			}

			mw.pushDrawableObject(&packing, "Packing");
			ui->clearPackingPushButton->setEnabled(true);
			ui->savePackingPushButton->setEnabled(true);
		}
		else {
			ui->clearPackingPushButton->setEnabled(false);
			ui->savePackingPushButton->setEnabled(false);
			mw.setDrawableObjectVisibility(&hfDecomposition, true);
		}
	}

	for (const HFBox& b: hfEngine.boxes()){
		guides.pushGuide(b.min());
		guides.pushGuide(b.max());
	}
	mw.canvas.fitScene();
	mw.canvas.update();
	guides.setBoundingBox(mesh.boundingBox());
	endWork();
}

bool HFGui::saveHFD()
{
	std::string filename = lshfd.saveDialog("Save HFD");
	if (filename != "") {
		std::ofstream myfile;
		myfile.open (filename, std::ios::out | std::ios::binary);
		if (myfile.is_open()){
			cg3::serialize(version, myfile);
			cg3::serializeObjectAttributes("HFD", myfile, hfEngine, actualTab, mesh, actualRotationMatrix,
										   totalSurface, totalVolume, remainingSurface, remainingVolume, stock);
			myfile.close();
			return true;
		}
	}
	return false;
}

void HFGui::clear()
{
	mw.deleteDrawableObject(&mesh);
	mw.deleteDrawableObject(&originalMesh);
	mw.deleteDrawableObject(&box);
	mw.deleteDrawableObject(&hfDecomposition);
	mw.deleteDrawableObject(&rotatableMesh);
	mw.deleteDrawableObject(&stock);
	mw.deleteDrawableObject(&packing);
	hfDecomposition.clear();
	hfEngine.clear();
	actions.clear();
	actualAction = 0;
	mw.canvas.update();
	guides.clear();
	packing.clear();

	ui->tabWidget->setCurrentIndex(0);
	ui->tabWidget->setEnabled(false);
	ui->testFrame->setEnabled(false);
}

void HFGui::addAction(const UserAction &action)
{
	if(actualAction != actions.size()){
		actions.erase(actions.begin() + actualAction, actions.end());
	}
	actions.push_back(action);
	actualAction++;
}

void HFGui::updateSurfaceAndvolume()
{
	remainingSurface = 0;
	for (cg3::Dcel::Face* f : mesh.faceIterator()){
		if (f->flag() != 1) {
			remainingSurface+=f->area();
		}
	}

	remainingVolume = mesh.volume();
	double percV = remainingVolume / totalVolume * 100;
	double percS = remainingSurface / totalSurface * 100;

	ui->remainingVolumeLabel->setText(QString::fromStdString(std::to_string(percV)) + " %");
	ui->remainingSurfaceLabel->setText(QString::fromStdString(std::to_string(percS)) + " %");
}

void HFGui::changeTab(uint tab)
{
	ui->tabWidget->setTabEnabled(actualTab, false);
	ui->tabWidget->setTabEnabled(tab, true);
	ui->tabWidget->setCurrentIndex(tab);
	actualTab = tab;
	if (tab >= 2){
		ui->testOrTrianglesCheckBox->setChecked(false);
		ui->testFrame->setEnabled(false);
	}
	else {
		ui->testFrame->setEnabled(true);
	}
}

void HFGui::startWork()
{
	ui->mainFrame->setEnabled(false);
	ui->tabWidget->setEnabled(false);
	ui->testFrame->setEnabled(false);
	ui->progressBar->setValue(0);
	QMovie *movie = new QMovie(":/wait.gif");
	ui->circLabel->setMovie(movie);
	movie->start();
}

void HFGui::endWork()
{
	ui->mainFrame->setEnabled(true);
	ui->tabWidget->setEnabled(true);
	if (actualTab < 2)
		ui->testFrame->setEnabled(true);
	ui->progressBar->setValue(100);
	ui->circLabel->setMovie(nullptr);
	QPixmap pixmap(":/green.ico");
	ui->circLabel->setPixmap(pixmap);
}

int HFGui::selectedTestdirection() const
{
	if (ui->testOrTrianglesCheckBox->isChecked()){
		if (ui->pxTestRadioButton->isChecked())
			return 0;
		if (ui->pyTestRadioButton->isChecked())
			return 1;
		if (ui->pzTestRadioButton->isChecked())
			return 2;
		if (ui->mxTestRadioButton->isChecked())
			return 3;
		if (ui->myTestRadioButton->isChecked())
			return 4;
		if (ui->mzTestRadioButton->isChecked())
			return 5;
	}
	else {
		return -1;
	}
	return -1;
}

void HFGui::colorTestMesh()
{
	int d = selectedTestdirection();
	if (d < 0){
		mesh.setFaceColors(cg3::GREY);

	}
	else {
		cg3::Vec3d dir = cg3::AXIS [d];
		for (cg3::Dcel::Face* f : mesh.faceIterator()) {
			if (f->normal().dot(dir) >= std::cos(ui->flipAngleSpinBox->value() * (M_PI / 180))){
				if (f->normal().dot(dir) >= std::cos(ui->lightToleranceSpinBox->value() * (M_PI / 180)))
					f->setColor(cg3::GREEN);
				else
					f->setColor(cg3::YELLOW);
			}
			else
				f->setColor(cg3::RED);
		}
	}
	mesh.update();
	mw.canvas.update();
}

void HFGui::undo()
{
	if (actualAction != 0 && actualTab <= 2){
		actualAction--;
		switch(actions[actualAction].type()){
		case UserAction::SMOOTHING :
			mesh = actions[actualAction].mesh();
			hfEngine.setMesh(mesh);
			if (actions[actualAction].firstSmoothing()){
				hfEngine.setUseSmoothedMesh(false);
				mw.deleteDrawableObject(&originalMesh);
				mw.setDrawableObjectName(&mesh, "Loaded Mesh");
			}
			totalVolume = mesh.volume();
			totalSurface = mesh.surfaceArea();
			remainingVolume = totalVolume;
			remainingSurface = totalSurface;
			changeTab(actions[actualAction].tab());
			break;
		case UserAction::ROTATE :
			mesh = actions[actualAction].mesh();
			actualRotationMatrix = actions[actualAction].actualRotationMatrix(); //avoid numerical errors
			changeTab(actions[actualAction].tab());
			break;
		case UserAction::CUT :
			bool b = mesh.isVisible();
			mesh = actions[actualAction].mesh();
			box.set(actions[actualAction].box().min(), actions[actualAction].box().max());
			box.setMillingDirection(actions[actualAction].box().millingDirection());
			hfEngine.popBox();
			mw.setDrawableObjectVisibility(&mesh, b);
			mw.pushDrawableObject(&box, "Box");
			mw.deleteDrawableObject(&hfDecomposition);
			updateSurfaceAndvolume();
			changeTab(actions[actualAction].tab());
			guides.popGuide();
			guides.popGuide();
			if (remainingVolume == totalVolume){
				ui->flipAngleSpinBox->setEnabled(true);
				ui->lightToleranceSpinBox->setEnabled(true);
			}
			ui->nBoxesLabel->setText(QString::number(hfEngine.boxes().size()));
			break;
		}
		mesh.update();
		treeMesh = cg3::cgal::AABBTree3(mesh);
		mw.canvas.update();
	}
}

void HFGui::redo()
{
	if (actualAction < actions.size() && actualTab <= 2){
		Eigen::Matrix3d rot;
		switch(actions[actualAction].type()){
		case UserAction::SMOOTHING :
			if (actions[actualAction].firstSmoothing()){
				originalMesh = actions[actualAction].mesh();
				hfEngine.setOriginalMesh(originalMesh);
				originalMesh.update();
				mw.pushDrawableObject(&originalMesh, "Non-Smoothed Mesh", false);
				mw.setDrawableObjectName(&mesh, "Smoothed Mesh");
			}
			//mesh = (cg3::Dcel)cg3::vcglib::taubinSmoothing(mesh, actions[actualAction].nIterations(), actions[actualAction].lambda(), actions[actualAction].mu());
			hfEngine.setMesh(mesh);
			totalVolume = mesh.volume();
			totalSurface = mesh.surfaceArea();
			remainingVolume = totalVolume;
			remainingSurface = totalSurface;
			changeTab(0);
			colorTestMesh();
			emit taubinSmoothing(mesh, actions[actualAction].nIterations(), actions[actualAction].lambda(), actions[actualAction].mu());
			break;
		case UserAction::ROTATE :
			rot = actions[actualAction].rotationMatrix();
			actualRotationMatrix *= rot;
			mesh.rotate(rot);
			changeTab(1);
			colorTestMesh();
			break;
		case UserAction::CUT :
			bool v = mesh.isVisible();
			box.set(actions[actualAction].box().min(), actions[actualAction].box().max());
			cg3::SimpleEigenMesh b = cg3::EigenMeshAlgorithms::makeBox(box.min(), box.max());
			mesh = cg3::DrawableDcel(cg3::libigl::difference(mesh, b));
			box.setMillingDirection(actions[actualAction].box().millingDirection());
			hfEngine.pushBox(actions[actualAction].box());
			mw.setDrawableObjectVisibility(&mesh, v);
			updateSurfaceAndvolume();
			changeTab(2);
			guides.pushGuide(box.min());
			guides.pushGuide(box.max());
			ui->flipAngleSpinBox->setEnabled(false);
			ui->lightToleranceSpinBox->setEnabled(false);
			ui->nBoxesLabel->setText(QString::number(hfEngine.boxes().size()));
			break;
		}
		mesh.update();
		treeMesh = cg3::cgal::AABBTree3(mesh);
		mw.canvas.update();
		actualAction++;
	}
}

void HFGui::setProgressBarValue(uint value)
{
	ui->progressBar->setValue(value);
}

void HFGui::on_clearPushButton_clicked()
{
	clear();
}

void HFGui::on_taubinSmoothingPushButton_clicked()
{
	startWork();

	bool firstSmooth = false;
	mesh.setFaceColors(cg3::GREY);
	if (!mw.containsDrawableObject(&originalMesh)){
		originalMesh = mesh;
		originalMesh.update();
		hfEngine.setOriginalMesh(originalMesh);
		mw.pushDrawableObject(&originalMesh, "Non-Smoothed Mesh", false);
		mw.setDrawableObjectName(&mesh, "Smoothed Mesh");
		firstSmooth = true;
	}
	addAction(UserAction(mesh, ui->nIterationsSpinBox->value(), ui->lambdaSpinBox->value(), ui->muSpinBox->value(), firstSmooth, actualTab));

	emit taubinSmoothing(mesh, ui->nIterationsSpinBox->value(), ui->lambdaSpinBox->value(), ui->muSpinBox->value());
}

void HFGui::taubinSmoothingCompleted(cg3::Dcel m)
{
	mesh = m;
	mesh.setFaceFlags(0);
	mesh.setFaceColors(cg3::GREY);
	mesh.update();
	hfEngine.setMesh(mesh);
	colorTestMesh();
	treeMesh = cg3::cgal::AABBTree3(mesh);

	mw.canvas.update();


	endWork();
}

void HFGui::on_smoothingNextPushButton_clicked()
{
	box.set(mesh.boundingBox().min(), mesh.boundingBox().max());
	mw.pushDrawableObject(&box, "box");
	changeTab(1);
	totalVolume = mesh.volume();
	totalSurface = mesh.surfaceArea();
	remainingVolume = totalVolume;
	remainingSurface = totalSurface;
	mw.canvas.update();
}

void HFGui::on_automaticOrientationRadioButton_toggled(bool checked)
{
	if (checked){
		ui->optimalOrientationPushButton->setEnabled(true);
		ui->nDirsSpinBox->setEnabled(true);
		ui->resetRotationPushButton->setEnabled(false);
		ui->manualOrientationDonePushButton->setEnabled(false);

		mw.setDrawableObjectVisibility(&mesh, true);
		mw.deleteDrawableObject(&rotatableMesh);
		mw.canvas.update();
	}
}

void HFGui::on_manualOrientationRadioButton_toggled(bool checked)
{
	if (checked){
		ui->optimalOrientationPushButton->setEnabled(false);
		ui->nDirsSpinBox->setEnabled(false);
		ui->resetRotationPushButton->setEnabled(true);
		ui->manualOrientationDonePushButton->setEnabled(true);

		mw.setDrawableObjectVisibility(&mesh, false);
		rotatableMesh.setMesh(mesh);
		mw.pushDrawableObject(&rotatableMesh, "Rot");
		mw.canvas.update();
	}
}

void HFGui::on_optimalOrientationPushButton_clicked()
{
	startWork();
	emit optimalOrientation(mesh, ui->nDirsSpinBox->value());
}

void HFGui::optimalOrientationCompleted(Eigen::Matrix3d rot)
{
	addAction(UserAction(mesh, rot, actualRotationMatrix, actualTab));
	actualRotationMatrix *= rot;
	mesh.rotate(rot);
	colorTestMesh();
	treeMesh = cg3::cgal::AABBTree3(mesh);
	mw.canvas.update();
	guides.setBoundingBox(mesh.boundingBox());
	endWork();
}

void HFGui::on_resetRotationPushButton_clicked()
{
	rotatableMesh.resetRotation();
	mw.canvas.update();
}

void HFGui::on_manualOrientationDonePushButton_clicked()
{
	Eigen::Matrix3d rot = rotatableMesh.rotationMatrix();
	addAction(UserAction(mesh, rot, actualRotationMatrix, actualTab));
	actualRotationMatrix *= rot;
	mesh.rotate(rot);
	colorTestMesh();
	treeMesh = cg3::cgal::AABBTree3(mesh);
	mw.canvas.update();
	ui->automaticOrientationRadioButton->toggle();
}

void HFGui::on_orientationNextPushButton_clicked()
{
	if (ui->manualOrientationRadioButton->isChecked()){
		QMessageBox* box = new QMessageBox(&mw);
		box->setWindowTitle("Rotation Mode");
		box->setText("You are in manual rotation mode.\n"
					 "Do you want to keep the actual rotation?");
		box->addButton(QMessageBox::Ok);
		box->button(QMessageBox::Ok)->setText("Keep Rotation");
		box->addButton(QMessageBox::Cancel);
		box->button(QMessageBox::Cancel)->setText("Discard Rotation");
		box->setEscapeButton(QMessageBox::Cancel);
		box->setDefaultButton(QMessageBox::Ok);
		int ret = box->exec();
		if (ret == QMessageBox::Ok){
			Eigen::Matrix3d rot = rotatableMesh.rotationMatrix();
			addAction(UserAction(mesh, rot, actualRotationMatrix, actualTab));
			actualRotationMatrix *= rot;
			mesh.rotate(rot);
			treeMesh = cg3::cgal::AABBTree3(mesh);
			ui->automaticOrientationRadioButton->toggle();
		}
	}
	finishRotation();
}

void HFGui::finishRotation()
{
	mw.setDrawableObjectVisibility(&mesh, true);
	mw.deleteDrawableObject(&rotatableMesh);
	changeTab(2);
	colorTestMesh();
	guides.setBoundingBox(mesh.boundingBox());
	box.setDrawArrow(true);
	mw.canvas.update();
}

void HFGui::on_pxRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::PLUS_X);
		mw.canvas.update();
	}
}

void HFGui::on_pyRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::PLUS_Y);
		mw.canvas.update();
	}
}

void HFGui::on_pzRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::PLUS_Z);
		mw.canvas.update();
	}
}

void HFGui::on_mxRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::MINUS_X);
		mw.canvas.update();
	}
}

void HFGui::on_myRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::MINUS_Y);
		mw.canvas.update();
	}
}

void HFGui::on_mzRadioButton_toggled(bool checked)
{
	if (checked){
		box.setMillingDirection(HFBox::MINUS_Z);
		mw.canvas.update();
	}
}

void HFGui::on_colorAllTrisPushButton_clicked()
{
	cg3::Vec3d dir = cg3::AXIS[box.millingDirection()];
	for (cg3::Dcel::Face* f : mesh.faceIterator()) {
		if (f->normal().dot(dir) >= std::cos(ui->flipAngleSpinBox->value() * (M_PI / 180))){
			if (f->normal().dot(dir) >= std::cos(ui->lightToleranceSpinBox->value() * (M_PI / 180)))
				f->setColor(cg3::GREEN);
			else
				f->setColor(cg3::YELLOW);
		}
		else
			f->setColor(cg3::RED);
	}
	mesh.update();
	mw.canvas.update();
}

void HFGui::on_containedTrisPushButton_clicked()
{
	mesh.setFaceColors(cg3::GREY);
	cg3::Vec3d dir = cg3::AXIS[box.millingDirection()];
	std::list<const cg3::Dcel::Face*> lf = treeMesh.containedDcelFaces(cg3::BoundingBox3(box.min(), box.max()));
	for(const cg3::Dcel::Face* f : lf){
		if (f->normal().dot(dir) >= std::cos(ui->flipAngleSpinBox->value() * (M_PI / 180))){
			if (f->normal().dot(dir) >= std::cos(ui->lightToleranceSpinBox->value() * (M_PI / 180)))
				mesh.face(f->id())->setColor(cg3::GREEN);
			else
				mesh.face(f->id())->setColor(cg3::YELLOW);
		}
		else
			mesh.face(f->id())->setColor(cg3::RED);
	}
	mesh.update();
	mw.canvas.update();
}

void HFGui::on_cutPushButton_clicked()
{
	bool isHF = true;
	double nonhfSurf = 0;
	cg3::Vec3d dir = cg3::AXIS[box.millingDirection()];
	std::list<const cg3::Dcel::Face*> lf = treeMesh.containedDcelFaces(cg3::BoundingBox3(box.min(), box.max()));
	for(const cg3::Dcel::Face* f : lf){
		if (f->normal().dot(dir) < std::cos(ui->flipAngleSpinBox->value() * (M_PI / 180))){
			isHF = false;
			nonhfSurf += f->area();
		}
	}
	bool continueCut = true;
	if (!isHF){
		nonhfSurf = (nonhfSurf / totalSurface) * 200;
		QMessageBox* box = new QMessageBox(&mw);
		box->setWindowTitle("Non HF Block");
		box->setText("You are trying to cut a block that is not an height-field w.r.t. the selected "
					 "milling direction.\n"
					 "There amount of losed surface is the " + QString::number(nonhfSurf) + "% of the total.\n"
					 "Are you sure to cut this block?");
		box->addButton(QMessageBox::Ok);
		box->button(QMessageBox::Ok)->setText("Cut");
		box->addButton(QMessageBox::Cancel);
		box->button(QMessageBox::Cancel)->setText("Cancel");
		box->setEscapeButton(QMessageBox::Cancel);
		box->setDefaultButton(QMessageBox::Cancel);
		int ret = box->exec();
		continueCut = ret == QMessageBox::Ok;
	}
	if (continueCut)
		startCut();
}

void HFGui::startCut()
{
	startWork();

	ui->flipAngleSpinBox->setEnabled(false);
	ui->lightToleranceSpinBox->setEnabled(false);
	guides.pushGuide(box.min());
	guides.pushGuide(box.max());

	HFBox hfbox(box.min(), box.max(), box.millingDirection(), actualRotationMatrix);
	hfEngine.pushBox(hfbox);
	addAction(UserAction(mesh, hfbox, actualTab));

	ui->nBoxesLabel->setText(QString::number(hfEngine.boxes().size()));

	emit cut(mesh, hfbox);
}

void HFGui::cutCompleted(cg3::Dcel res)
{
	mesh = res;
	mesh.update();
	treeMesh = cg3::cgal::AABBTree3(mesh);

	updateSurfaceAndvolume();

	mw.canvas.update();
	endWork();
}

void HFGui::on_xGuideCheckBox_stateChanged(int arg1)
{
	guides.setDrawX(arg1 == Qt::Checked);
	mw.canvas.update();
}

void HFGui::on_yGuidesCheckBox_stateChanged(int arg1)
{
	guides.setDrawY(arg1 == Qt::Checked);
	mw.canvas.update();
}

void HFGui::on_zGiudesCheckBox_stateChanged(int arg1)
{
	guides.setDrawZ(arg1 == Qt::Checked);
	mw.canvas.update();
}

void HFGui::on_snapMinXPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.min(), 0);
	box.setMin(cg3::Point3d(p.x(), box.min().y(), box.min().z()));
	mw.canvas.update();
}

void HFGui::on_snapMaxXPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.max(), 0);
	box.setMax(cg3::Point3d(p.x(), box.max().y(), box.max().z()));
	mw.canvas.update();
}

void HFGui::on_snapMinYPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.min(), 1);
	box.setMin(cg3::Point3d(box.min().x(), p.y(), box.min().z()));
	mw.canvas.update();
}

void HFGui::on_snapMaxYPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.max(), 1);
	box.setMax(cg3::Point3d(box.max().x(), p.y(), box.max().z()));
	mw.canvas.update();
}

void HFGui::on_snapMinZPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.min(), 2);
	box.setMin(cg3::Point3d(box.min().x(), box.min().y(), p.z()));
	mw.canvas.update();
}

void HFGui::on_snapMaxZPushButton_clicked()
{
	cg3::Point3d p = guides.nearest(box.max(), 2);
	box.setMax(cg3::Point3d(box.max().x(), box.max().y(), p.z()));
	mw.canvas.update();
}

void HFGui::on_decompositionNextPushButton_clicked()
{
	if (remainingSurface > 0){
		QMessageBox* box = new QMessageBox(&mw);
		box->setWindowTitle("Remaining Surface");
		box->setText("There is some remaining surface of the input model in the mesh.\n"
					 "What do you want to do with that?");
		box->addButton(QMessageBox::Ok);
		box->button(QMessageBox::Ok)->setText("Ignore Remaining Surface");
		box->addButton(QMessageBox::Cancel);
		box->button(QMessageBox::Cancel)->setText("Continue Decomposition");
		box->setEscapeButton(QMessageBox::Cancel);
		int ret = box->exec();
		if (ret == QMessageBox::Ok)
			finishDecomposition();
	}
	else
		finishDecomposition();
}

void HFGui::finishDecomposition()
{
	changeTab(3);

	if (mw.containsDrawableObject(&originalMesh)){
		ui->restoreHighFrequenciesPushButton->setEnabled(true);
		ui->nRestoreIterationsSpinBox->setEnabled(true);
		ui->nRestoreIterationsLabel->setEnabled(true);
		ui->hausDescrLabel->setEnabled(true);
		ui->hausdorffDistanceLabel->setEnabled(true);
		originalMesh = hfEngine.originalMesh();
		mw.refreshDrawableObject(&originalMesh);
	}

	mw.deleteDrawableObject(&box);
	mesh = hfEngine.mesh();
	mw.refreshDrawableObject(&mesh);
	guides.setDrawX(false);
	guides.setDrawY(false);
	guides.setDrawZ(false);

	mw.canvas.update();
}

void HFGui::on_restoreHighFrequenciesPushButton_clicked()
{
	startWork();

	emit restoreHighFrequencies(&hfEngine, ui->nIterationsSpinBox->value(), std::cos(ui->flipAngleSpinBox->value() * (M_PI / 180)));
}

void HFGui::restoreHighFrequenciesCompleted()
{
	mesh = hfEngine.mesh();
	mw.refreshDrawableObject(&mesh);
	ui->hausdorffDistanceLabel->setText(QString::fromStdString(std::to_string(hfEngine.hausdorffDistance())));
	mw.canvas.update();

	endWork();
}

void HFGui::on_computeDecompositionPushButton_clicked()
{
	startWork();
	mw.deleteDrawableObject(&hfDecomposition);
	if (ui->exactPredicatesCheckBox->isChecked())
		emit computeDecompositionExact(&hfEngine);
	else
		emit computeDecomposition(&hfEngine);
}

void HFGui::computeDecompositionCompleted(std::vector<cg3::Dcel> dec)
{
	uint i = 0;
	hfDecomposition.clear();
	hfEngine.decomposition() = dec;
	hfEngine.colorDecomposition();
	for (const cg3::Dcel& d : hfEngine.decomposition())
		hfDecomposition.pushBack(d, "Block " + std::to_string(i++));

	mw.setDrawableObjectVisibility(&mesh, false);
	mw.setDrawableObjectVisibility(&originalMesh, false);
	mw.pushDrawableObject(&hfDecomposition, "Decomposition");
	mw.canvas.update();
	ui->exportDecompositionPushButton->setEnabled(true);
	ui->nextPostProcessingPushButton->setEnabled(true);
	endWork();
}

void HFGui::on_exportDecompositionPushButton_clicked()
{
	std::string dir = lsmesh.directoryDialog();
	if (dir != "") {
		uint i = 0;
		for (const cg3::DrawableDcel& b : hfDecomposition){
			b.saveOnObj(dir + "/b" + std::to_string(i++) + ".obj", false);
		}
	}
}

void HFGui::on_nextPostProcessingPushButton_clicked()
{
	changeTab(4);
	ui->clearPackingPushButton->setEnabled(false);
	ui->savePackingPushButton->setEnabled(false);
	mw.setDrawableObjectVisibility(&hfDecomposition, false);
	stock.setMin(cg3::Point3d(0, 0, 0));
	stock.setMax(cg3::Point3d(ui->xStockSpinBox->value(), ui->yStockSpinBox->value(), ui->zStockSpinBox->value()));
	mw.pushDrawableObject(&stock, "Stock");
	mw.canvas.fitScene();
	mw.canvas.update();
}

void HFGui::on_xStockSpinBox_valueChanged(int arg1)
{
	stock.setMaxX(arg1);
	mw.canvas.update();
}

void HFGui::on_yStockSpinBox_valueChanged(int arg1)
{
	stock.setMaxY(arg1);
	mw.canvas.update();
}

void HFGui::on_zStockSpinBox_valueChanged(int arg1)
{
	stock.setMaxZ(arg1);
	mw.canvas.update();
}

void HFGui::on_clearPackingPushButton_clicked()
{
	packing.clear();
	mw.deleteDrawableObject(&packing);
	ui->clearPackingPushButton->setEnabled(false);
	ui->savePackingPushButton->setEnabled(false);
	mw.canvas.update();
}

void HFGui::on_packPushButton_clicked()
{
	hfEngine.comutePackingFromDecomposition(stock, ui->toolLengthSpinBox->value(), ui->distBetweenBlocksSpinBox->value(),
											cg3::Point2d(5, 2), 1, ui->sizesFactorSpinBox->value());
	packing.clear();

	uint i = 0;
	for (const std::vector<cg3::Dcel>& stock : hfEngine.packing()){
		bool vis = i == 0;
		packing.pushBack(cg3::DrawableObjectsContainer<cg3::DrawableDcel>(), "Stock " + std::to_string(i), vis);
		uint j = 0;
		for (const cg3::Dcel& d : stock)
			packing.at(i).pushBack(d, "Block " + std::to_string(j++));
		i++;
	}

	mw.pushDrawableObject(&packing, "Packing");
	ui->clearPackingPushButton->setEnabled(true);
	ui->savePackingPushButton->setEnabled(true);
	mw.canvas.update();
}

void HFGui::on_packOneStockButton_clicked()
{
	startWork();
	packing.clear();

	tmpPacking = hfEngine.packingPreProcessing(stock, ui->toolLengthSpinBox->value(), cg3::Point2d(5, 2), 1);
	emit packInOneStock(tmpPacking, stock, ui->distBetweenBlocksSpinBox->value());
}

void HFGui::packInOneStockCompleted(bool success, double factor, std::vector<std::pair<int, cg3::Point3d> > pack)
{
	if (success) {
		hfEngine.setOneStockPacking(tmpPacking, factor, stock, pack);

		uint i = 0;
		for (const std::vector<cg3::Dcel>& stock : hfEngine.packing()){
			bool vis = i == 0;
			packing.pushBack(cg3::DrawableObjectsContainer<cg3::DrawableDcel>(), "Stock " + std::to_string(i), vis);
			uint j = 0;
			for (const cg3::Dcel& d : stock)
				packing.at(i).pushBack(d, "Block " + std::to_string(j++));
			i++;
		}

		mw.pushDrawableObject(&packing, "Packing");
		ui->clearPackingPushButton->setEnabled(true);
		ui->savePackingPushButton->setEnabled(true);
		mw.canvas.update();
	}
	else {
		QMessageBox* box = new QMessageBox(&mw);
		box->setWindowTitle("Failed to Pack in One Stock");
		box->setText("It was not possible to pack the decomposition in a single "
					 "stock of the given sizes.");
		box->exec();
	}
	endWork();
}

void HFGui::on_savePackingPushButton_clicked()
{
	std::string folder = lsmesh.directoryDialog();
	if (folder != ""){
		stock.saveOnObj(folder + "/stock.obj");
		uint i = 0;
		for (const auto& p : packing){
			uint j = 0;
			for (const cg3::DrawableDcel& d : p){
				d.saveOnObj(folder + "/stock_" + std::to_string(i) + "_block_" + std::to_string(j++) + ".obj");
			}
			i++;
		}
	}
}

void HFGui::on_testOrTrianglesCheckBox_stateChanged(int arg1)
{
	bool b = arg1 == Qt::Checked;
	ui->pxTestRadioButton->setEnabled(b);
	ui->pyTestRadioButton->setEnabled(b);
	ui->pzTestRadioButton->setEnabled(b);
	ui->mxTestRadioButton->setEnabled(b);
	ui->myTestRadioButton->setEnabled(b);
	ui->mzTestRadioButton->setEnabled(b);
	colorTestMesh();
}

void HFGui::on_pxTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}

void HFGui::on_pyTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}

void HFGui::on_pzTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}

void HFGui::on_mxTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}

void HFGui::on_myTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}

void HFGui::on_mzTestRadioButton_toggled(bool checked)
{
	if (checked)
		colorTestMesh();
}
