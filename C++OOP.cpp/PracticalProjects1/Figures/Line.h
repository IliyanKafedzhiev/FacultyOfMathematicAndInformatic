#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
	Line(Points3D first,Points3D second);
	Line(Vector& dest,Points3D point);
	double volume () const ;
	double area () const ;
	virtual bool contains (const Points3D&)const;
	void printLine( std::ostream&)const;
};

#endif