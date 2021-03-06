/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef ARROW_H
#define ARROW_H

#include <cg3/meshes/dcel/dcel_builder.h>

inline cg3::Dcel createArrow() {
	cg3::DcelBuilder b;
	b.addVertex(cg3::Point3d(-4.625000, 3.075000, 0.000000));
	b.addVertex(cg3::Point3d(-1.125000, 1.925933, -0.964181));
	b.addVertex(cg3::Point3d(-1.125000, 2.110819, -1.149067));
	b.addVertex(cg3::Point3d(-1.125000, 2.325000, -1.299038));
	b.addVertex(cg3::Point3d(-1.125000, 2.561970, -1.409539));
	b.addVertex(cg3::Point3d(-1.125000, 2.814528, -1.477212));
	b.addVertex(cg3::Point3d(-1.125000, 3.075000, -1.500000));
	b.addVertex(cg3::Point3d(-1.125000, 3.335472, -1.477212));
	b.addVertex(cg3::Point3d(-1.125000, 3.588030, -1.409539));
	b.addVertex(cg3::Point3d(-1.125000, 3.825000, -1.299038));
	b.addVertex(cg3::Point3d(-1.125000, 4.039181, -1.149067));
	b.addVertex(cg3::Point3d(-1.125000, 4.224067, -0.964181));
	b.addVertex(cg3::Point3d(-1.125000, 3.589426, -0.866025));
	b.addVertex(cg3::Point3d(-1.125000, 3.586256, -0.866875));
	b.addVertex(cg3::Point3d(-1.125000, 3.576933, -0.869373));
	b.addVertex(cg3::Point3d(-1.125000, 3.089426, -1.000000));
	b.addVertex(cg3::Point3d(-1.125000, 3.086197, -0.999135));
	b.addVertex(cg3::Point3d(-1.125000, 3.075000, -0.996135));
	b.addVertex(cg3::Point3d(-1.125000, 2.589426, -0.866025));
	b.addVertex(cg3::Point3d(-1.125000, 2.587138, -0.863737));
	b.addVertex(cg3::Point3d(-1.125000, 2.580280, -0.856880));
	b.addVertex(cg3::Point3d(-1.125000, 3.699173, -0.756278));
	b.addVertex(cg3::Point3d(-1.125000, 3.788317, -0.667134));
	b.addVertex(cg3::Point3d(-1.125000, 3.704838, -0.750613));
	b.addVertex(cg3::Point3d(-1.125000, 3.825613, -0.629838));
	b.addVertex(cg3::Point3d(-1.125000, 3.407910, -0.914662));
	b.addVertex(cg3::Point3d(-1.125000, 3.338285, -0.933318));
	b.addVertex(cg3::Point3d(-1.125000, 3.244023, -0.958576));
	b.addVertex(cg3::Point3d(-1.125000, 2.810381, -0.925230));
	b.addVertex(cg3::Point3d(-1.125000, 2.907279, -0.951194));
	b.addVertex(cg3::Point3d(-1.125000, 2.744654, -0.907619));
	b.addVertex(cg3::Point3d(-1.125000, 2.340075, -0.616675));
	b.addVertex(cg3::Point3d(-1.125000, 2.367064, -0.643663));
	b.addVertex(cg3::Point3d(-1.125000, 2.458325, -0.734925));
	b.addVertex(cg3::Point3d(-1.125000, 2.223401, -0.500000));
	b.addVertex(cg3::Point3d(-1.125000, 2.222631, -0.497128));
	b.addVertex(cg3::Point3d(-1.125000, 1.575000, 0.000000));
	b.addVertex(cg3::Point3d(-1.125000, 1.597788, -0.260472));
	b.addVertex(cg3::Point3d(-1.125000, 1.597788, 0.260472));
	b.addVertex(cg3::Point3d(-1.125000, 1.665461, -0.513030));
	b.addVertex(cg3::Point3d(-1.125000, 1.665461, 0.513030));
	b.addVertex(cg3::Point3d(-1.125000, 1.775962, -0.750000));
	b.addVertex(cg3::Point3d(-1.125000, 1.775962, 0.750000));
	b.addVertex(cg3::Point3d(-1.125000, 2.089426, 0.000000));
	b.addVertex(cg3::Point3d(-1.125000, 2.090132, 0.002636));
	b.addVertex(cg3::Point3d(-1.125000, 2.133890, -0.165943));
	b.addVertex(cg3::Point3d(-1.125000, 2.133890, 0.165943));
	b.addVertex(cg3::Point3d(-1.125000, 2.134246, -0.167272));
	b.addVertex(cg3::Point3d(-1.125000, 2.139284, -0.186074));
	b.addVertex(cg3::Point3d(-1.125000, 2.170816, 0.303752));
	b.addVertex(cg3::Point3d(-1.125000, 2.177004, -0.326844));
	b.addVertex(cg3::Point3d(-1.125000, 2.177004, 0.326844));
	b.addVertex(cg3::Point3d(-1.125000, 2.221468, 0.492787));
	b.addVertex(cg3::Point3d(-1.125000, 2.221468, -0.492787));
	b.addVertex(cg3::Point3d(-1.125000, 3.950171, 0.505280));
	b.addVertex(cg3::Point3d(-1.125000, 3.950171, -0.505280));
	b.addVertex(cg3::Point3d(-1.125000, 3.953232, -0.502218));
	b.addVertex(cg3::Point3d(-1.125000, 3.955451, -0.500000));
	b.addVertex(cg3::Point3d(-1.125000, 3.955451, 0.500000));
	b.addVertex(cg3::Point3d(-1.125000, 3.956195, 0.497222));
	b.addVertex(cg3::Point3d(-1.125000, 3.999284, -0.336412));
	b.addVertex(cg3::Point3d(-1.125000, 3.999284, 0.336412));
	b.addVertex(cg3::Point3d(-1.125000, 4.011528, 0.290716));
	b.addVertex(cg3::Point3d(-1.125000, 4.032067, -0.214064));
	b.addVertex(cg3::Point3d(-1.125000, 4.043660, 0.170801));
	b.addVertex(cg3::Point3d(-1.125000, 4.043660, -0.170801));
	b.addVertex(cg3::Point3d(-1.125000, 4.088652, -0.002888));
	b.addVertex(cg3::Point3d(-1.125000, 4.089426, 0.000000));
	b.addVertex(cg3::Point3d(-1.125000, 4.374038, -0.750000));
	b.addVertex(cg3::Point3d(-1.125000, 4.374038, 0.750000));
	b.addVertex(cg3::Point3d(-1.125000, 4.484539, -0.513030));
	b.addVertex(cg3::Point3d(-1.125000, 4.484539, 0.513030));
	b.addVertex(cg3::Point3d(-1.125000, 4.552212, -0.260472));
	b.addVertex(cg3::Point3d(-1.125000, 4.552212, 0.260472));
	b.addVertex(cg3::Point3d(-1.125000, 4.575000, 0.000000));
	b.addVertex(cg3::Point3d(-1.125000, 2.223401, 0.500000));
	b.addVertex(cg3::Point3d(-1.125000, 2.225269, 0.501869));
	b.addVertex(cg3::Point3d(-1.125000, 2.458325, 0.734925));
	b.addVertex(cg3::Point3d(-1.125000, 2.427676, 0.704275));
	b.addVertex(cg3::Point3d(-1.125000, 2.340075, 0.616675));
	b.addVertex(cg3::Point3d(-1.125000, 2.907279, 0.951194));
	b.addVertex(cg3::Point3d(-1.125000, 2.840566, 0.933318));
	b.addVertex(cg3::Point3d(-1.125000, 2.744654, 0.907619));
	b.addVertex(cg3::Point3d(-1.125000, 3.244023, 0.958576));
	b.addVertex(cg3::Point3d(-1.125000, 3.407910, 0.914662));
	b.addVertex(cg3::Point3d(-1.125000, 3.317736, 0.938824));
	b.addVertex(cg3::Point3d(-1.125000, 3.746131, 0.709319));
	b.addVertex(cg3::Point3d(-1.125000, 3.825613, 0.629838));
	b.addVertex(cg3::Point3d(-1.125000, 3.704838, 0.750613));
	b.addVertex(cg3::Point3d(-1.125000, 2.580280, 0.856880));
	b.addVertex(cg3::Point3d(-1.125000, 2.592010, 0.866718));
	b.addVertex(cg3::Point3d(-1.125000, 2.589426, 0.866025));
	b.addVertex(cg3::Point3d(-1.125000, 3.075000, 0.996135));
	b.addVertex(cg3::Point3d(-1.125000, 3.092068, 0.999292));
	b.addVertex(cg3::Point3d(-1.125000, 3.089426, 1.000000));
	b.addVertex(cg3::Point3d(-1.125000, 3.576933, 0.869373));
	b.addVertex(cg3::Point3d(-1.125000, 3.591404, 0.864047));
	b.addVertex(cg3::Point3d(-1.125000, 3.589426, 0.866025));
	b.addVertex(cg3::Point3d(-1.125000, 1.925933, 0.964181));
	b.addVertex(cg3::Point3d(-1.125000, 2.110819, 1.149067));
	b.addVertex(cg3::Point3d(-1.125000, 2.325000, 1.299038));
	b.addVertex(cg3::Point3d(-1.125000, 2.561970, 1.409539));
	b.addVertex(cg3::Point3d(-1.125000, 2.814528, 1.477212));
	b.addVertex(cg3::Point3d(-1.125000, 3.075000, 1.500000));
	b.addVertex(cg3::Point3d(-1.125000, 3.335472, 1.477212));
	b.addVertex(cg3::Point3d(-1.125000, 3.588030, 1.409539));
	b.addVertex(cg3::Point3d(-1.125000, 3.825000, 1.299038));
	b.addVertex(cg3::Point3d(-1.125000, 4.039181, 1.149067));
	b.addVertex(cg3::Point3d(-1.125000, 4.224067, 0.964181));
	b.addVertex(cg3::Point3d(-0.739724, 2.038703, 0.000000));
	b.addVertex(cg3::Point3d(-0.705049, 2.168113, -0.500000));
	b.addVertex(cg3::Point3d(-0.705049, 2.168113, 0.500000));
	b.addVertex(cg3::Point3d(-0.610314, 2.521666, -0.866025));
	b.addVertex(cg3::Point3d(-0.610314, 2.521666, 0.866025));
	b.addVertex(cg3::Point3d(-0.480905, 3.004629, -1.000000));
	b.addVertex(cg3::Point3d(-0.480905, 3.004629, 1.000000));
	b.addVertex(cg3::Point3d(-0.351495, 3.487592, -0.866025));
	b.addVertex(cg3::Point3d(-0.351495, 3.487592, 0.866025));
	b.addVertex(cg3::Point3d(-0.256761, 3.841145, -0.500000));
	b.addVertex(cg3::Point3d(-0.256761, 3.841145, 0.500000));
	b.addVertex(cg3::Point3d(-0.222086, 3.970555, 0.000000));
	b.addVertex(cg3::Point3d(0.225000, 1.639102, 0.000000));
	b.addVertex(cg3::Point3d(0.291987, 1.755127, -0.500000));
	b.addVertex(cg3::Point3d(0.291987, 1.755127, 0.500000));
	b.addVertex(cg3::Point3d(0.475000, 2.072115, -0.866025));
	b.addVertex(cg3::Point3d(0.475000, 2.072115, 0.866025));
	b.addVertex(cg3::Point3d(0.725000, 2.505127, -1.000000));
	b.addVertex(cg3::Point3d(0.725000, 2.505127, 1.000000));
	b.addVertex(cg3::Point3d(0.975000, 2.938140, -0.866025));
	b.addVertex(cg3::Point3d(0.975000, 2.938140, 0.866025));
	b.addVertex(cg3::Point3d(1.053427, 1.003427, 0.000000));
	b.addVertex(cg3::Point3d(1.148162, 1.098162, -0.500000));
	b.addVertex(cg3::Point3d(1.148162, 1.098162, 0.500000));
	b.addVertex(cg3::Point3d(1.158012, 3.255127, -0.500000));
	b.addVertex(cg3::Point3d(1.158012, 3.255127, 0.500000));
	b.addVertex(cg3::Point3d(1.225000, 3.371153, 0.000000));
	b.addVertex(cg3::Point3d(1.406980, 1.356980, -0.866025));
	b.addVertex(cg3::Point3d(1.406980, 1.356980, 0.866025));
	b.addVertex(cg3::Point3d(1.625000, -1.075000, 0.000000));
	b.addVertex(cg3::Point3d(1.647788, -1.075000, -0.260472));
	b.addVertex(cg3::Point3d(1.647788, -1.075000, 0.260472));
	b.addVertex(cg3::Point3d(1.689102, 0.175000, 0.000000));
	b.addVertex(cg3::Point3d(1.715461, -1.075000, -0.513030));
	b.addVertex(cg3::Point3d(1.715461, -1.075000, 0.513030));
	b.addVertex(cg3::Point3d(1.760534, 1.710534, -1.000000));
	b.addVertex(cg3::Point3d(1.760534, 1.710534, 1.000000));
	b.addVertex(cg3::Point3d(1.805127, 0.241987, -0.500000));
	b.addVertex(cg3::Point3d(1.805127, 0.241987, 0.500000));
	b.addVertex(cg3::Point3d(1.825962, -1.075000, -0.750000));
	b.addVertex(cg3::Point3d(1.825962, -1.075000, 0.750000));
	b.addVertex(cg3::Point3d(1.975933, -1.075000, -0.964181));
	b.addVertex(cg3::Point3d(1.975933, -1.075000, 0.964181));
	b.addVertex(cg3::Point3d(2.088703, -0.789724, 0.000000));
	b.addVertex(cg3::Point3d(2.114087, 2.064087, -0.866025));
	b.addVertex(cg3::Point3d(2.114087, 2.064087, 0.866025));
	b.addVertex(cg3::Point3d(2.122114, 0.425000, -0.866025));
	b.addVertex(cg3::Point3d(2.122114, 0.425000, 0.866025));
	b.addVertex(cg3::Point3d(2.126260, -1.075000, 0.000000));
	b.addVertex(cg3::Point3d(2.160819, -1.075000, -1.149067));
	b.addVertex(cg3::Point3d(2.160819, -1.075000, 1.149067));
	b.addVertex(cg3::Point3d(2.163178, -1.075000, 0.137778));
	b.addVertex(cg3::Point3d(2.171319, -1.075000, 0.168160));
	b.addVertex(cg3::Point3d(2.171319, -1.075000, -0.168160));
	b.addVertex(cg3::Point3d(2.215008, -1.075000, 0.331210));
	b.addVertex(cg3::Point3d(2.215008, -1.075000, -0.331210));
	b.addVertex(cg3::Point3d(2.218113, -0.755049, -0.500000));
	b.addVertex(cg3::Point3d(2.218113, -0.755049, 0.500000));
	b.addVertex(cg3::Point3d(2.220172, -1.075000, -0.350483));
	b.addVertex(cg3::Point3d(2.260067, -1.075000, 0.499370));
	b.addVertex(cg3::Point3d(2.260067, -1.075000, -0.499370));
	b.addVertex(cg3::Point3d(2.260235, -1.075000, -0.500000));
	b.addVertex(cg3::Point3d(2.260235, -1.075000, 0.500000));
	b.addVertex(cg3::Point3d(2.369689, -1.075000, 0.609454));
	b.addVertex(cg3::Point3d(2.372906, 2.322906, -0.500000));
	b.addVertex(cg3::Point3d(2.372906, 2.322906, 0.500000));
	b.addVertex(cg3::Point3d(2.375000, -1.075000, -1.299038));
	b.addVertex(cg3::Point3d(2.375000, -1.075000, 1.299038));
	b.addVertex(cg3::Point3d(2.382917, -1.075000, 0.622681));
	b.addVertex(cg3::Point3d(2.382917, -1.075000, -0.622681));
	b.addVertex(cg3::Point3d(2.467640, 2.417640, 0.000000));
	b.addVertex(cg3::Point3d(2.495937, -1.075000, -0.735702));
	b.addVertex(cg3::Point3d(2.502319, -1.075000, 0.742083));
	b.addVertex(cg3::Point3d(2.502319, -1.075000, -0.742083));
	b.addVertex(cg3::Point3d(2.555127, 0.675000, -1.000000));
	b.addVertex(cg3::Point3d(2.555127, 0.675000, 1.000000));
	b.addVertex(cg3::Point3d(2.571666, -0.660314, -0.866025));
	b.addVertex(cg3::Point3d(2.571666, -0.660314, 0.866025));
	b.addVertex(cg3::Point3d(2.611970, -1.075000, -1.409539));
	b.addVertex(cg3::Point3d(2.611970, -1.075000, 1.409539));
	b.addVertex(cg3::Point3d(2.625462, -1.075000, 0.865226));
	b.addVertex(cg3::Point3d(2.625462, -1.075000, -0.865226));
	b.addVertex(cg3::Point3d(2.626261, -1.075000, -0.866025));
	b.addVertex(cg3::Point3d(2.626261, -1.075000, 0.866025));
	b.addVertex(cg3::Point3d(2.793484, -1.075000, 0.910833));
	b.addVertex(cg3::Point3d(2.793484, -1.075000, -0.910833));
	b.addVertex(cg3::Point3d(2.804285, -1.075000, 0.913727));
	b.addVertex(cg3::Point3d(2.864528, -1.075000, -1.477212));
	b.addVertex(cg3::Point3d(2.864528, -1.075000, 1.477212));
	b.addVertex(cg3::Point3d(2.916038, -1.075000, -0.943671));
	b.addVertex(cg3::Point3d(2.956685, -1.075000, 0.954562));
	b.addVertex(cg3::Point3d(2.956685, -1.075000, -0.954562));
	b.addVertex(cg3::Point3d(2.988140, 0.925000, -0.866025));
	b.addVertex(cg3::Point3d(2.988140, 0.925000, 0.866025));
	b.addVertex(cg3::Point3d(3.054629, -0.530905, -1.000000));
	b.addVertex(cg3::Point3d(3.054629, -0.530905, 1.000000));
	b.addVertex(cg3::Point3d(3.125000, -4.575000, 0.000000));
	b.addVertex(cg3::Point3d(3.125000, -1.075000, -1.500000));
	b.addVertex(cg3::Point3d(3.125000, -1.075000, -0.999662));
	b.addVertex(cg3::Point3d(3.125000, -1.075000, 0.999662));
	b.addVertex(cg3::Point3d(3.125000, -1.075000, 1.500000));
	b.addVertex(cg3::Point3d(3.126261, -1.075000, -1.000000));
	b.addVertex(cg3::Point3d(3.126261, -1.075000, 1.000000));
	b.addVertex(cg3::Point3d(3.293429, -1.075000, 0.955207));
	b.addVertex(cg3::Point3d(3.293429, -1.075000, -0.955207));
	b.addVertex(cg3::Point3d(3.305127, 1.108013, -0.500000));
	b.addVertex(cg3::Point3d(3.305127, 1.108013, 0.500000));
	b.addVertex(cg3::Point3d(3.336483, -1.075000, 0.943671));
	b.addVertex(cg3::Point3d(3.385472, -1.075000, -1.477212));
	b.addVertex(cg3::Point3d(3.385472, -1.075000, 1.477212));
	b.addVertex(cg3::Point3d(3.389695, -1.075000, -0.929413));
	b.addVertex(cg3::Point3d(3.421152, 1.175000, 0.000000));
	b.addVertex(cg3::Point3d(3.456740, -1.075000, 0.911448));
	b.addVertex(cg3::Point3d(3.456740, -1.075000, -0.911448));
	b.addVertex(cg3::Point3d(3.537592, -0.401495, -0.866025));
	b.addVertex(cg3::Point3d(3.537592, -0.401495, 0.866025));
	b.addVertex(cg3::Point3d(3.625169, -1.075000, 0.866318));
	b.addVertex(cg3::Point3d(3.625169, -1.075000, -0.866318));
	b.addVertex(cg3::Point3d(3.626261, -1.075000, -0.866025));
	b.addVertex(cg3::Point3d(3.626261, -1.075000, 0.866025));
	b.addVertex(cg3::Point3d(3.638030, -1.075000, -1.409539));
	b.addVertex(cg3::Point3d(3.638030, -1.075000, 1.409539));
	b.addVertex(cg3::Point3d(3.748832, -1.075000, -0.743454));
	b.addVertex(cg3::Point3d(3.748832, -1.075000, 0.743454));
	b.addVertex(cg3::Point3d(3.799439, -1.075000, 0.692847));
	b.addVertex(cg3::Point3d(3.807075, -1.075000, -0.685211));
	b.addVertex(cg3::Point3d(3.868454, -1.075000, -0.623832));
	b.addVertex(cg3::Point3d(3.868454, -1.075000, 0.623832));
	b.addVertex(cg3::Point3d(3.875000, -1.075000, -1.299038));
	b.addVertex(cg3::Point3d(3.875000, -1.075000, 1.299038));
	b.addVertex(cg3::Point3d(3.891145, -0.306761, -0.500000));
	b.addVertex(cg3::Point3d(3.891145, -0.306761, 0.500000));
	b.addVertex(cg3::Point3d(3.991824, -1.075000, -0.500461));
	b.addVertex(cg3::Point3d(3.991824, -1.075000, 0.500461));
	b.addVertex(cg3::Point3d(3.992286, -1.075000, -0.500000));
	b.addVertex(cg3::Point3d(3.992286, -1.075000, 0.500000));
	b.addVertex(cg3::Point3d(4.020555, -0.272086, 0.000000));
	b.addVertex(cg3::Point3d(4.037289, -1.075000, 0.332046));
	b.addVertex(cg3::Point3d(4.037289, -1.075000, -0.332046));
	b.addVertex(cg3::Point3d(4.056991, -1.075000, -0.258519));
	b.addVertex(cg3::Point3d(4.060078, -1.075000, 0.246997));
	b.addVertex(cg3::Point3d(4.081089, -1.075000, 0.168584));
	b.addVertex(cg3::Point3d(4.081089, -1.075000, -0.168584));
	b.addVertex(cg3::Point3d(4.089181, -1.075000, -1.149067));
	b.addVertex(cg3::Point3d(4.089181, -1.075000, 1.149067));
	b.addVertex(cg3::Point3d(4.126261, -1.075000, 0.000000));
	b.addVertex(cg3::Point3d(4.274067, -1.075000, -0.964181));
	b.addVertex(cg3::Point3d(4.274067, -1.075000, 0.964181));
	b.addVertex(cg3::Point3d(4.424038, -1.075000, -0.750000));
	b.addVertex(cg3::Point3d(4.424038, -1.075000, 0.750000));
	b.addVertex(cg3::Point3d(4.534539, -1.075000, -0.513030));
	b.addVertex(cg3::Point3d(4.534539, -1.075000, 0.513030));
	b.addVertex(cg3::Point3d(4.602212, -1.075000, -0.260472));
	b.addVertex(cg3::Point3d(4.602212, -1.075000, 0.260472));
	b.addVertex(cg3::Point3d(4.625000, -1.075000, 0.000000));
	b.addFace(0, 2, 1);
	b.addFace(0, 1, 41);
	b.addFace(0, 3, 2);
	b.addFace(0, 4, 3);
	b.addFace(0, 5, 4);
	b.addFace(0, 6, 5);
	b.addFace(0, 7, 6);
	b.addFace(0, 8, 7);
	b.addFace(0, 9, 8);
	b.addFace(0, 10, 9);
	b.addFace(0, 11, 10);
	b.addFace(0, 68, 11);
	b.addFace(0, 37, 36);
	b.addFace(0, 36, 38);
	b.addFace(0, 39, 37);
	b.addFace(0, 38, 40);
	b.addFace(0, 41, 39);
	b.addFace(0, 40, 42);
	b.addFace(0, 42, 98);
	b.addFace(0, 70, 68);
	b.addFace(0, 69, 71);
	b.addFace(0, 108, 69);
	b.addFace(0, 72, 70);
	b.addFace(0, 71, 73);
	b.addFace(0, 74, 72);
	b.addFace(0, 73, 74);
	b.addFace(0, 98, 99);
	b.addFace(0, 99, 100);
	b.addFace(0, 100, 101);
	b.addFace(0, 101, 102);
	b.addFace(0, 102, 103);
	b.addFace(0, 103, 104);
	b.addFace(0, 104, 105);
	b.addFace(0, 105, 106);
	b.addFace(0, 106, 107);
	b.addFace(0, 107, 108);
	b.addFace(31, 1, 2);
	b.addFace(31, 34, 1);
	b.addFace(34, 35, 1);
	b.addFace(35, 53, 1);
	b.addFace(53, 41, 1);
	b.addFace(33, 2, 3);
	b.addFace(32, 31, 2);
	b.addFace(33, 32, 2);
	b.addFace(20, 3, 4);
	b.addFace(20, 33, 3);
	b.addFace(30, 4, 5);
	b.addFace(18, 19, 4);
	b.addFace(30, 18, 4);
	b.addFace(19, 20, 4);
	b.addFace(29, 5, 6);
	b.addFace(29, 28, 5);
	b.addFace(28, 30, 5);
	b.addFace(27, 6, 7);
	b.addFace(16, 6, 15);
	b.addFace(27, 15, 6);
	b.addFace(17, 6, 16);
	b.addFace(17, 29, 6);
	b.addFace(25, 7, 8);
	b.addFace(25, 26, 7);
	b.addFace(26, 27, 7);
	b.addFace(14, 8, 9);
	b.addFace(25, 8, 14);
	b.addFace(23, 9, 10);
	b.addFace(13, 9, 12);
	b.addFace(21, 12, 9);
	b.addFace(14, 9, 13);
	b.addFace(23, 21, 9);
	b.addFace(23, 10, 11);
	b.addFace(22, 23, 11);
	b.addFace(24, 22, 11);
	b.addFace(24, 11, 55);
	b.addFace(55, 11, 68);
	b.addFace(116, 13, 12);
	b.addFace(12, 21, 116);
	b.addFace(116, 14, 13);
	b.addFace(14, 116, 25);
	b.addFace(15, 114, 16);
	b.addFace(15, 27, 114);
	b.addFace(114, 17, 16);
	b.addFace(17, 114, 29);
	b.addFace(18, 112, 19);
	b.addFace(18, 30, 112);
	b.addFace(112, 20, 19);
	b.addFace(20, 112, 33);
	b.addFace(21, 23, 116);
	b.addFace(23, 22, 116);
	b.addFace(24, 118, 22);
	b.addFace(118, 116, 22);
	b.addFace(55, 118, 24);
	b.addFace(25, 114, 26);
	b.addFace(116, 114, 25);
	b.addFace(27, 26, 114);
	b.addFace(29, 112, 28);
	b.addFace(30, 28, 112);
	b.addFace(114, 112, 29);
	b.addFace(31, 32, 110);
	b.addFace(34, 31, 110);
	b.addFace(33, 110, 32);
	b.addFace(112, 110, 33);
	b.addFace(34, 110, 35);
	b.addFace(110, 53, 35);
	b.addFace(45, 36, 37);
	b.addFace(46, 38, 36);
	b.addFace(43, 44, 36);
	b.addFace(45, 43, 36);
	b.addFace(44, 46, 36);
	b.addFace(50, 37, 39);
	b.addFace(47, 45, 37);
	b.addFace(48, 47, 37);
	b.addFace(50, 48, 37);
	b.addFace(51, 40, 38);
	b.addFace(46, 49, 38);
	b.addFace(49, 51, 38);
	b.addFace(53, 39, 41);
	b.addFace(50, 39, 53);
	b.addFace(52, 42, 40);
	b.addFace(51, 52, 40);
	b.addFace(52, 98, 42);
	b.addFace(43, 109, 44);
	b.addFace(43, 45, 109);
	b.addFace(109, 46, 44);
	b.addFace(45, 47, 109);
	b.addFace(46, 109, 49);
	b.addFace(47, 48, 109);
	b.addFace(50, 109, 48);
	b.addFace(51, 49, 111);
	b.addFace(109, 111, 49);
	b.addFace(53, 110, 50);
	b.addFace(110, 109, 50);
	b.addFace(52, 51, 111);
	b.addFace(75, 98, 52);
	b.addFace(75, 52, 111);
	b.addFace(58, 71, 54);
	b.addFace(58, 54, 119);
	b.addFace(54, 71, 69);
	b.addFace(54, 69, 108);
	b.addFace(87, 54, 108);
	b.addFace(54, 87, 119);
	b.addFace(56, 55, 70);
	b.addFace(118, 55, 56);
	b.addFace(55, 68, 70);
	b.addFace(57, 56, 70);
	b.addFace(57, 118, 56);
	b.addFace(60, 57, 70);
	b.addFace(57, 60, 118);
	b.addFace(59, 71, 58);
	b.addFace(58, 119, 59);
	b.addFace(61, 71, 59);
	b.addFace(119, 61, 59);
	b.addFace(63, 60, 72);
	b.addFace(60, 63, 118);
	b.addFace(60, 70, 72);
	b.addFace(61, 62, 73);
	b.addFace(61, 119, 62);
	b.addFace(61, 73, 71);
	b.addFace(62, 64, 73);
	b.addFace(64, 62, 120);
	b.addFace(119, 120, 62);
	b.addFace(65, 63, 72);
	b.addFace(65, 120, 63);
	b.addFace(120, 118, 63);
	b.addFace(64, 67, 74);
	b.addFace(67, 64, 120);
	b.addFace(64, 74, 73);
	b.addFace(66, 65, 74);
	b.addFace(66, 120, 65);
	b.addFace(65, 72, 74);
	b.addFace(67, 66, 74);
	b.addFace(67, 120, 66);
	b.addFace(76, 98, 75);
	b.addFace(75, 111, 76);
	b.addFace(79, 98, 76);
	b.addFace(111, 79, 76);
	b.addFace(78, 77, 98);
	b.addFace(77, 78, 113);
	b.addFace(89, 100, 77);
	b.addFace(89, 77, 113);
	b.addFace(77, 99, 98);
	b.addFace(77, 100, 99);
	b.addFace(79, 78, 98);
	b.addFace(79, 111, 78);
	b.addFace(111, 113, 78);
	b.addFace(81, 80, 102);
	b.addFace(80, 81, 115);
	b.addFace(92, 103, 80);
	b.addFace(92, 80, 115);
	b.addFace(80, 103, 102);
	b.addFace(82, 81, 102);
	b.addFace(82, 113, 81);
	b.addFace(113, 115, 81);
	b.addFace(82, 101, 90);
	b.addFace(113, 82, 90);
	b.addFace(82, 102, 101);
	b.addFace(83, 85, 104);
	b.addFace(83, 115, 85);
	b.addFace(93, 83, 103);
	b.addFace(115, 83, 93);
	b.addFace(83, 104, 103);
	b.addFace(85, 84, 104);
	b.addFace(84, 85, 117);
	b.addFace(84, 95, 105);
	b.addFace(95, 84, 117);
	b.addFace(84, 105, 104);
	b.addFace(115, 117, 85);
	b.addFace(86, 87, 108);
	b.addFace(87, 86, 119);
	b.addFace(88, 86, 108);
	b.addFace(88, 117, 86);
	b.addFace(117, 119, 86);
	b.addFace(96, 88, 106);
	b.addFace(117, 88, 96);
	b.addFace(88, 107, 106);
	b.addFace(88, 108, 107);
	b.addFace(89, 91, 101);
	b.addFace(91, 89, 113);
	b.addFace(89, 101, 100);
	b.addFace(90, 101, 91);
	b.addFace(91, 113, 90);
	b.addFace(92, 94, 103);
	b.addFace(94, 92, 115);
	b.addFace(94, 93, 103);
	b.addFace(94, 115, 93);
	b.addFace(95, 97, 106);
	b.addFace(97, 95, 117);
	b.addFace(95, 106, 105);
	b.addFace(97, 96, 106);
	b.addFace(97, 117, 96);
	b.addFace(109, 110, 121);
	b.addFace(111, 109, 123);
	b.addFace(121, 123, 109);
	b.addFace(110, 112, 122);
	b.addFace(122, 121, 110);
	b.addFace(113, 111, 125);
	b.addFace(123, 125, 111);
	b.addFace(112, 114, 124);
	b.addFace(124, 122, 112);
	b.addFace(115, 113, 127);
	b.addFace(125, 127, 113);
	b.addFace(114, 116, 126);
	b.addFace(126, 124, 114);
	b.addFace(117, 115, 129);
	b.addFace(127, 129, 115);
	b.addFace(116, 118, 128);
	b.addFace(128, 126, 116);
	b.addFace(119, 117, 134);
	b.addFace(129, 134, 117);
	b.addFace(118, 120, 133);
	b.addFace(133, 128, 118);
	b.addFace(120, 119, 135);
	b.addFace(134, 135, 119);
	b.addFace(135, 133, 120);
	b.addFace(121, 122, 130);
	b.addFace(123, 121, 132);
	b.addFace(130, 132, 121);
	b.addFace(122, 124, 131);
	b.addFace(131, 130, 122);
	b.addFace(125, 123, 137);
	b.addFace(132, 137, 123);
	b.addFace(124, 126, 136);
	b.addFace(136, 131, 124);
	b.addFace(127, 125, 145);
	b.addFace(137, 145, 125);
	b.addFace(126, 128, 144);
	b.addFace(144, 136, 126);
	b.addFace(129, 127, 154);
	b.addFace(145, 154, 127);
	b.addFace(128, 133, 153);
	b.addFace(153, 144, 128);
	b.addFace(134, 129, 174);
	b.addFace(154, 174, 129);
	b.addFace(130, 131, 141);
	b.addFace(132, 130, 147);
	b.addFace(141, 147, 130);
	b.addFace(131, 136, 146);
	b.addFace(146, 141, 131);
	b.addFace(137, 132, 156);
	b.addFace(147, 156, 132);
	b.addFace(133, 135, 173);
	b.addFace(173, 153, 133);
	b.addFace(135, 134, 179);
	b.addFace(174, 179, 134);
	b.addFace(179, 173, 135);
	b.addFace(136, 144, 155);
	b.addFace(155, 146, 136);
	b.addFace(145, 137, 184);
	b.addFace(156, 184, 137);
	b.addFace(162, 139, 138);
	b.addFace(205, 138, 139);
	b.addFace(160, 138, 140);
	b.addFace(205, 140, 138);
	b.addFace(160, 157, 138);
	b.addFace(157, 162, 138);
	b.addFace(164, 142, 139);
	b.addFace(205, 139, 142);
	b.addFace(162, 164, 139);
	b.addFace(163, 140, 143);
	b.addFace(205, 143, 140);
	b.addFace(161, 160, 140);
	b.addFace(163, 161, 140);
	b.addFace(141, 146, 152);
	b.addFace(147, 141, 166);
	b.addFace(152, 166, 141);
	b.addFace(169, 148, 142);
	b.addFace(205, 142, 148);
	b.addFace(164, 167, 142);
	b.addFace(167, 169, 142);
	b.addFace(168, 143, 149);
	b.addFace(205, 149, 143);
	b.addFace(168, 163, 143);
	b.addFace(144, 153, 183);
	b.addFace(183, 155, 144);
	b.addFace(154, 145, 202);
	b.addFace(184, 202, 145);
	b.addFace(165, 152, 146);
	b.addFace(146, 155, 165);
	b.addFace(156, 147, 186);
	b.addFace(166, 186, 147);
	b.addFace(178, 150, 148);
	b.addFace(205, 148, 150);
	b.addFace(169, 170, 148);
	b.addFace(170, 178, 148);
	b.addFace(177, 149, 151);
	b.addFace(205, 151, 149);
	b.addFace(168, 149, 171);
	b.addFace(172, 171, 149);
	b.addFace(177, 172, 149);
	b.addFace(182, 158, 150);
	b.addFace(205, 150, 158);
	b.addFace(178, 180, 150);
	b.addFace(180, 182, 150);
	b.addFace(181, 151, 159);
	b.addFace(205, 159, 151);
	b.addFace(177, 151, 181);
	b.addFace(157, 160, 152);
	b.addFace(157, 152, 162);
	b.addFace(161, 152, 160);
	b.addFace(163, 152, 161);
	b.addFace(162, 152, 164);
	b.addFace(166, 152, 163);
	b.addFace(152, 165, 164);
	b.addFace(153, 173, 201);
	b.addFace(201, 183, 153);
	b.addFace(174, 154, 215);
	b.addFace(202, 215, 154);
	b.addFace(185, 165, 155);
	b.addFace(155, 183, 185);
	b.addFace(184, 156, 204);
	b.addFace(186, 204, 156);
	b.addFace(190, 175, 158);
	b.addFace(205, 158, 175);
	b.addFace(182, 190, 158);
	b.addFace(189, 159, 176);
	b.addFace(205, 176, 159);
	b.addFace(181, 159, 189);
	b.addFace(166, 163, 168);
	b.addFace(164, 165, 167);
	b.addFace(169, 167, 165);
	b.addFace(170, 169, 165);
	b.addFace(165, 178, 170);
	b.addFace(178, 165, 180);
	b.addFace(165, 185, 180);
	b.addFace(166, 168, 171);
	b.addFace(171, 172, 166);
	b.addFace(177, 166, 172);
	b.addFace(181, 166, 177);
	b.addFace(186, 166, 181);
	b.addFace(173, 179, 214);
	b.addFace(214, 201, 173);
	b.addFace(179, 174, 220);
	b.addFace(215, 220, 174);
	b.addFace(194, 187, 175);
	b.addFace(205, 175, 187);
	b.addFace(190, 191, 175);
	b.addFace(191, 194, 175);
	b.addFace(193, 176, 188);
	b.addFace(205, 188, 176);
	b.addFace(192, 189, 176);
	b.addFace(193, 192, 176);
	b.addFace(220, 214, 179);
	b.addFace(182, 180, 185);
	b.addFace(186, 181, 189);
	b.addFace(190, 182, 185);
	b.addFace(203, 185, 183);
	b.addFace(183, 201, 203);
	b.addFace(202, 184, 224);
	b.addFace(204, 224, 184);
	b.addFace(191, 190, 185);
	b.addFace(185, 194, 191);
	b.addFace(194, 185, 198);
	b.addFace(185, 203, 198);
	b.addFace(186, 189, 192);
	b.addFace(192, 193, 186);
	b.addFace(193, 195, 186);
	b.addFace(199, 186, 195);
	b.addFace(204, 186, 199);
	b.addFace(194, 198, 187);
	b.addFace(200, 196, 187);
	b.addFace(205, 187, 196);
	b.addFace(198, 200, 187);
	b.addFace(195, 193, 188);
	b.addFace(199, 195, 188);
	b.addFace(199, 188, 197);
	b.addFace(205, 197, 188);
	b.addFace(200, 207, 196);
	b.addFace(205, 196, 206);
	b.addFace(207, 206, 196);
	b.addFace(199, 197, 208);
	b.addFace(205, 209, 197);
	b.addFace(208, 197, 209);
	b.addFace(200, 198, 203);
	b.addFace(204, 199, 208);
	b.addFace(207, 200, 203);
	b.addFace(223, 203, 201);
	b.addFace(201, 214, 223);
	b.addFace(215, 202, 240);
	b.addFace(224, 240, 202);
	b.addFace(210, 207, 203);
	b.addFace(203, 213, 210);
	b.addFace(213, 203, 219);
	b.addFace(203, 223, 219);
	b.addFace(204, 208, 211);
	b.addFace(211, 212, 204);
	b.addFace(212, 216, 204);
	b.addFace(221, 204, 216);
	b.addFace(224, 204, 221);
	b.addFace(205, 206, 217);
	b.addFace(205, 218, 209);
	b.addFace(205, 217, 229);
	b.addFace(205, 230, 218);
	b.addFace(205, 229, 237);
	b.addFace(205, 238, 230);
	b.addFace(205, 237, 252);
	b.addFace(205, 253, 238);
	b.addFace(205, 252, 255);
	b.addFace(205, 256, 253);
	b.addFace(205, 255, 257);
	b.addFace(205, 258, 256);
	b.addFace(205, 257, 259);
	b.addFace(205, 260, 258);
	b.addFace(205, 259, 261);
	b.addFace(205, 262, 260);
	b.addFace(205, 261, 263);
	b.addFace(205, 263, 262);
	b.addFace(207, 210, 206);
	b.addFace(210, 217, 206);
	b.addFace(211, 208, 209);
	b.addFace(211, 209, 218);
	b.addFace(213, 217, 210);
	b.addFace(212, 211, 218);
	b.addFace(216, 212, 230);
	b.addFace(212, 218, 230);
	b.addFace(213, 229, 217);
	b.addFace(219, 229, 213);
	b.addFace(214, 220, 239);
	b.addFace(239, 223, 214);
	b.addFace(220, 215, 245);
	b.addFace(240, 245, 215);
	b.addFace(221, 216, 230);
	b.addFace(222, 219, 223);
	b.addFace(222, 229, 219);
	b.addFace(245, 239, 220);
	b.addFace(225, 224, 221);
	b.addFace(225, 221, 238);
	b.addFace(221, 230, 238);
	b.addFace(226, 222, 223);
	b.addFace(226, 237, 222);
	b.addFace(222, 237, 229);
	b.addFace(227, 226, 223);
	b.addFace(223, 231, 227);
	b.addFace(231, 223, 234);
	b.addFace(223, 239, 234);
	b.addFace(224, 225, 228);
	b.addFace(228, 232, 224);
	b.addFace(232, 233, 224);
	b.addFace(240, 224, 233);
	b.addFace(228, 225, 253);
	b.addFace(225, 238, 253);
	b.addFace(226, 227, 252);
	b.addFace(226, 252, 237);
	b.addFace(227, 231, 252);
	b.addFace(232, 228, 253);
	b.addFace(234, 255, 231);
	b.addFace(231, 255, 252);
	b.addFace(233, 232, 256);
	b.addFace(232, 253, 256);
	b.addFace(236, 240, 233);
	b.addFace(236, 233, 256);
	b.addFace(235, 234, 239);
	b.addFace(235, 255, 234);
	b.addFace(241, 235, 239);
	b.addFace(241, 257, 235);
	b.addFace(235, 257, 255);
	b.addFace(240, 236, 242);
	b.addFace(242, 236, 258);
	b.addFace(236, 256, 258);
	b.addFace(243, 241, 239);
	b.addFace(239, 247, 243);
	b.addFace(239, 245, 248);
	b.addFace(247, 239, 248);
	b.addFace(240, 242, 244);
	b.addFace(244, 246, 240);
	b.addFace(245, 240, 249);
	b.addFace(246, 249, 240);
	b.addFace(241, 243, 259);
	b.addFace(241, 259, 257);
	b.addFace(244, 242, 260);
	b.addFace(242, 258, 260);
	b.addFace(247, 259, 243);
	b.addFace(246, 244, 260);
	b.addFace(251, 248, 245);
	b.addFace(250, 245, 249);
	b.addFace(254, 245, 250);
	b.addFace(254, 251, 245);
	b.addFace(249, 246, 262);
	b.addFace(246, 260, 262);
	b.addFace(248, 261, 247);
	b.addFace(247, 261, 259);
	b.addFace(251, 261, 248);
	b.addFace(250, 249, 262);
	b.addFace(254, 250, 263);
	b.addFace(250, 262, 263);
	b.addFace(251, 254, 263);
	b.addFace(251, 263, 261);
	b.finalize();
	return b.dcel();
}

#endif // ARROW_H
