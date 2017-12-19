/*
 * MeshObject.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: keega
 */

#include "MeshObject.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "math.h"



using namespace std;

/**
 * create a MeshObject and read in a .obj file.
 * loads points found in .obj file into three arrays.
 */
MeshObject::MeshObject(string fileName) {
	readFile(fileName);
}
/*
 * Private and only used to read in a mesh from .obj file.
 */
void MeshObject::readFile(string fileName) {
			string x;
		    ifstream inFile;
		    inFile.open(fileName);
		    if (!inFile) {
		        cout << "Unable to open file";
		        exit(1); // terminate with error
		    }
		    double v;
		    while (inFile >> x) {
		    	if (x == "v") {
		    	inFile >> v;
		    	xVertricies.push_back(v);
		    	inFile >> v;
		    	yVertricies.push_back(v);
		    	inFile >> v;
		    	zVertricies.push_back(v);
		    	}
		    }
		    inFile.close();
}
/*
 * Get a point that is a distance and angle from a point.
 * returns a array of points that are exactly X distance on a rotation from a point.
 * used: getPointsAtDistance(Point center, double angle, double distance);
 */
Point MeshObject::getPointAtDistance(Point p, double angle, double distance) {
	for (int i = 0; i < this->xVertricies.size(); i++) {
		double x = p.x + distance * cos(angle);
		double y = p.y + distance * sin(angle);
		if (xVertricies[i] == x && yVertricies[i] == y) {
			return Point(xVertricies[i], yVertricies[i], zVertricies[i]);
		}

	}
}

/**
 * returns all points that are outside that circle.
 *
 */
vector<Point> MeshObject::getPointsOutsideDistance(Point p, double distance) {
	vector<Point> temp;
	for (int i = 0; i < this->xVertricies.size(); i++) {
		double x1 = xVertricies[i] - p.x;
		double x = x1 * x1;
		double y1 = yVertricies[i] - p.y;
		double y = y1 * y1;
		double d = sqrt(x + y);
		if (d > distance) {
			temp.push_back(Point(xVertricies[i], yVertricies[i], zVertricies[i]));
		}

	}
	return temp;

}

MeshObject::~MeshObject() {
	// TODO Auto-generated destructor stub
}

