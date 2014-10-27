#include <iostream>
#include "Points3D.h"

#ifndef VECTOR_H
#define VECTOR_H
class Vector
{
public:
	Vector(void);
	Vector(int,int,int);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	Vector& operator=(const Points3D&);

	~Vector(void);

	//Methods
	void print (std :: ostream&) const;

	friend class Line;
protected:
	int x;
	int y;
	int z;
};
#endif
