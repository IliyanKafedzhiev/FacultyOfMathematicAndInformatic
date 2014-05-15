#include "Line.h"
#include <cmath>
#include <iostream>

using namespace std;

Line::Line(Points3D first,Points3D second)
{
	Vector* dir = new Vector;
	*dir = second - first;
	Points3D* point = new Points3D();
	*point = first; 
	vectors= new Vector* [1];
	vectors[0] = dir;
	points = new Points3D* [1];
	points[0] = point;
	numberOfvectors = 1;
	numberOfPoints = 1;
}

Line::Line(Vector& dest,Points3D pnt)
{
	Vector* dir = new Vector;
	*dir = dest;
	Points3D* point = new Points3D();
	*point = pnt; 
	vectors= new Vector* [1];
	vectors[0] = dir;
	points = new Points3D* [1];
	points[0] = point;
	numberOfvectors = 1;
	numberOfPoints = 1;

}

void Line::printLine(std::ostream& str)const
{
	str<<"Vector :"<<std::endl;
	vectors[0]->print(str);
	str<<"Point :"<<std::endl;
	str<<points[0]->x<<std::endl;
	str<<points[0]->y<<std::endl;
	str<<points[0]->z<<std::endl;
}

double  Line::volume () const
{
	return 0;
}

double  Line::area () const
{
	return 0;
}

bool Line::contains(const Points3D& p)const
{
	cout<<(((vectors[0]->x!=0)?((p.x-points[0]->x)/vectors[0]->x):0))<<std::endl;
	cout<<((vectors[0]->y!=0)?((p.y-points[0]->y)/vectors[0]->y):0)<<std::endl;
	if ((((vectors[0]->x!=0)?((p.x-points[0]->x)/vectors[0]->x):0 == (vectors[0]->y!=0)?((p.y-points[0]->y)/vectors[0]->y):0 ) )&&
		(((vectors[0]->x!=0)?((p.x-points[0]->x)/vectors[0]->x):0 == (vectors[0]->y!=0)?((p.y-points[0]->y)/vectors[0]->y):0 ) ))
	{
		if((((vectors[0]->x!=0)?((p.x-points[0]->x)/vectors[0]->x):0 == (vectors[0]->z!=0)?((p.z-points[0]->z)/vectors[0]->z):0 ) )&&
		(((vectors[0]->x!=0)?((p.x-points[0]->x)/vectors[0]->x):0 == (vectors[0]->z!=0)?((p.z-points[0]->z)/vectors[0]->z):0 ) ))
		{
			return true;
		}
	}
	return false;
}
