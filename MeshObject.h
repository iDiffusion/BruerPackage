/*
 * MeshObject.h
 *
 *  Created on: Dec 18, 2017
 *      Author: keega
 */

#ifndef MESHOBJECT_H_
#define MESHOBJECT_H_

#include <string>
#include <vector>

#include "Point.h"

using namespace std;

class MeshObject {
public:
	vector<double> xVertricies;
	vector<double> yVertricies;
	vector<double> zVertricies;

	MeshObject(string file);
	vector<Point> getPointsInDistance(Point p, double angle, double distance);
	virtual ~MeshObject();
private:
	void readFile(string fileName);
	double abs(double x);
};


#endif /* MESHOBJECT_H_ */
