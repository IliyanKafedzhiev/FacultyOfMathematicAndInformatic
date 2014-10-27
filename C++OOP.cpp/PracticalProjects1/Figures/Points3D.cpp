#include "Points3D.h"

Points3D& Points3D::operator-(const Points3D& right)const
{
	Points3D* newPoint = new Points3D;
	newPoint->x = right.x - x;
	newPoint->y = right.y - y;
	newPoint->z = right.z - z;
	return *newPoint;
}
Points3D::Points3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Points3D::Points3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}