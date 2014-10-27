#ifndef SHAPE_H
#define SHAPE_H

#include "PointsSet.h"

class Shape : public PointsSet
{
public:
	Shape(void);
	
	virtual double volume () const = 0;
	virtual double area () const = 0;
	virtual bool contains (const Points3D&) const = 0;
	 ~Shape(void);
};

#endif

