#include <iostream>

#include "PointsSet.h"
#include "Vector.h"
#include "Line.h"
#include "Triangle.h"
#include "Plane.h"

using namespace std;

int main ()
{
	PointsSet* s = new Plane();

	delete [] s;
	return 0;
}