#ifndef PLANE_H
#define PLANE_H

#include "PlanarShape.h"

class Plane : public PlanarShape
{
public:
	Plane(void);
	Plane(Points3D A,Points3D B,Points3D C );
	Plane(const Plane&);
	~Plane(void);
	double volume () const ;
	double area () const ;
	bool contains (const Points3D&)const;
	virtual PlanarShape* getPlane () const ;
private:
	double a;
	double b;
	double c;
	double d;
};
#endif
