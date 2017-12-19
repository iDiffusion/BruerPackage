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

MeshObject::MeshObject(string fileName) {
	readFile(fileName);
}

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

vector<Point> MeshObject::getPointsInDistance(Point p, double angle, double distance) {
	vector<Point> temp;
	for (int i = 0; i < this->xVertricies.size(); i++) {
		double x = p.x + distance * cos(angle);
		double y = p.y + distance * sin(angle);
		if (xVertricies[i] == x && yVertricies[i] == y) {
			temp.push_back(Point(xVertricies[i], yVertricies[i], zVertricies[i]));
		}

	}
	return temp;

}

double MeshObject::abs(double x) {
	if (x < 0) {
		return x * -1;
	} else {
		return x;
	}
}

MeshObject::~MeshObject() {
	// TODO Auto-generated destructor stub
}

