#include "Plane.h"
#include <cmath>

#include <iostream>

using namespace std;

Plane::Plane(void)
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

Plane::Plane(Points3D A,Points3D B,Points3D C )
{
	points = new Points3D* [3];
	points[0] = &A;
	points[1] = &B;
	points[2] = &C;
	numberOfPoints = 3;
	int p1 = points[1]->x - points[0]->x;
	int p2 = points[1]->y - points[0]->y;
	int p3 = points[1]->z - points[0]->z;
	int q1 = points[2]->x - points[0]->x;
	int q2 = points[2]->y - points[0]->y;
	int q3 = points[2]->z - points[0]->z;
	a = p2*q3 - p3*q2;
	b = p3*q1 - p1*q3;
	c = p1*q2 - p2*q1;
	d = -points[0]->x*(p2*q3 - p3*q2)
		-points[0]->y*(p3*q1 - p1*q3)
		-points[0]->z*(p1*q2 - p2*q1);
}

Plane::Plane(const Plane& right):a(right.a),b(right.b),c(right.c),d(right.d)
{
	numberOfPoints = right.numberOfPoints;
	points = new Points3D* [right.numberOfPoints];
	for (int i = 0; i < right.numberOfPoints; i++)
	{
		points [i] = right.points [i];
	}
}

double Plane::volume () const
{
	return 0;
}
double Plane::area () const 
{
	return _CMATH_::HUGE_VAL;
}
bool Plane::contains (const Points3D& Point)const
{
	if (a * Point.x  + b * Point.y + c * Point.z + d == 0)
	{
		return true;
	}

	return false;
}
PlanarShape* Plane::getPlane()const
{
	return new Plane(*this);
}

Plane::~Plane(void)
{
	cout<<"Plane"<<endl;
}
