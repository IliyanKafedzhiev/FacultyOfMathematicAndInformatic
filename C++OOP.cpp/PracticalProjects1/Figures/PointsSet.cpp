#include "PointsSet.h"


#include <iostream>

using namespace std;

PointsSet::PointsSet(void):numberOfvectors(0),vectors(NULL),numberOfPoints(0),points(NULL)
{
	
}

PointsSet::PointsSet(Vector** pointers,int count):numberOfvectors((count > 0)?count:0)
{
	vectors = new Vector* [count];
	for (int i = 0; i < count; i++)
	{
		vectors [i] = pointers [i];
	}
}

PointsSet::PointsSet(Vector** pointers,int count,Points3D**ppointers,int pcount):numberOfvectors((count > 0)?count:0),numberOfPoints((pcount > 0)?pcount:0)
{
	vectors = new Vector* [count];
	for (int i = 0; i < count; i++)
	{
		vectors [i] = pointers [i];
	}
	points = new Points3D* [pcount];
	for (int i = 0; i < pcount; i++)
	{
		points [i] = ppointers [i];
	}
}

PointsSet::PointsSet(const PointsSet& right):numberOfvectors(right.numberOfvectors),
	numberOfPoints(right.numberOfPoints)
{
	vectors = new Vector* [right.numberOfvectors];
	for (int i = 0; i < right.numberOfvectors; i++)
	{
		vectors [i] = right.vectors [i];
	}
	points = new Points3D* [right.numberOfPoints];
	for (int i = 0; i < right.numberOfPoints; i++)
	{
		points [i] = right.points [i];
	}
}

PointsSet&  PointsSet::operator=(const PointsSet& right)
{
	if (this != &right)
	{
		numberOfvectors = right.numberOfvectors;
		delete [] vectors;
		vectors = new Vector* [right.numberOfvectors];
		for (int i = 0; i < right.numberOfvectors; i++)
		{
			vectors[i] = right.vectors[i];
		}
	}
	return *this;
}

PointsSet::~PointsSet(void)
{
	delete [] vectors;
	delete [] points;
	cout<<"PointSet"<<endl;
}
