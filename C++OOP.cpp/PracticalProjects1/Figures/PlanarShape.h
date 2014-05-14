#ifndef PLANARSHAPE_H
#define PLANARSHAPE_H

#include "Shape.h"
class PlanarShape : public Shape
{
public:
	PlanarShape(void);
	virtual PlanarShape* getPlane () const = 0;
	 ~PlanarShape(void);
};

#endif PLANARSHAPE_H