#include "Vector.h"


Vector::Vector(void):x(0),y(0),z(0)
{
}

Vector::Vector(int x,int y ,int z):x(x),y(y),z(z)
{

}

Vector::Vector(const Vector& right):x(right.x),y(right.y),z(right.z)
{

}

Vector& Vector::operator=(const Vector& right)
{
	if (this != &right)
	{
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
	}
	return *this;
}

Vector& Vector::operator=(const Points3D& pointVector)
{
	x = pointVector.x;
	y = pointVector.y;
	z = pointVector.z;
	return *this;

}

void Vector::print(std::ostream& stream)const
{
	stream<<"X:"<<x<<std::endl;
	stream<<"Y:"<<y<<std::endl;
	stream<<"Z:"<<z<<std::endl;
}

Vector::~Vector(void)
{
}
