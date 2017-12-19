// Example program

#include <iostream>

#include "MeshObject.h"


using namespace std;
int main()
{
    MeshObject * obj = new MeshObject("model.obj");
    vector<Point> temp = obj->getPointsInDistance(Point(0, 0, 10), 10, 20);
    for (int i = 0; i < temp.size(); i++) {
    	cout << "X " << temp[i].x << ", Y " << temp[i].y << ", Z " << temp[i].z << "\n";
    }
    delete obj;
}
