/*
 * Point.h
 *
 *  Created on: Dec 18, 2017
 *      Author: keega
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	int x;
	int y;
	int z;
	Point(int x, int y, int z);
	virtual ~Point();
};

#endif /* POINT_H_ */
