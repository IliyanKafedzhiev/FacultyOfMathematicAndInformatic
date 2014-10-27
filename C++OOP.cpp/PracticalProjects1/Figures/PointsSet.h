#ifndef POINTSSET_H
#define POINTSSET_H

#include "Points3D.h"
#include "Vector.h"

class PointsSet
{
public:
	PointsSet(void);
	PointsSet(Vector**,int);
	PointsSet(Vector**,int,Points3D**,int);
	PointsSet(const PointsSet&);
	PointsSet& operator=(const PointsSet&);
	virtual bool contains(const Points3D&)const = 0;
	virtual ~PointsSet(void);
protected:
	Vector ** vectors;
	Points3D ** points;
	int numberOfvectors;
	int numberOfPoints;
};
#endif