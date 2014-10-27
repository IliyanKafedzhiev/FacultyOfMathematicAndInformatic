#include "A.h"
#include <cstring>

A::A(void)
{
	name=NULL;
}
A::A(char*Name)
{
	delete []name;
	this->name= new char [strlen(Name)+1];
	strcpy(name,Name);
}
A::A(const A& object)
{
	delete [] name;
	this->name=new char [strlen(object.name)+1];
	strcpy(name,object.name);
}
const char * A::getName () const
{
	return name;
}
void A:: setName(char * Name)
{
	delete []name;
	this->name= new char [strlen(Name)+1];
	strcpy(name,Name);
}
A& A::operator=(const A& N)
{
	if (this == &N)
	{
	return *this;
	}
	this->name=new char[strlen(N.name)+1];
	strcpy(name,N.name);
	return *this;
}
A::~A(void)
{
	delete[] name;
}
