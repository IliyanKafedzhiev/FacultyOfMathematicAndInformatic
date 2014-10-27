#include "B.h"
#include <cstring>

B::B(void)
{
	name=NULL;
}
B::B(char*Name)
{
	delete []name;
	this->name= new char [strlen(Name)+1];
	strcpy(name,Name);
}
B::B(const B& object)
{
	delete [] name;
	this->name=new char [strlen(object.name)+1];
	strcpy(name,object.name);
}
const char * B::getName () const
{
	return name;
}
void B:: setName(char * Name)
{
	delete []name;
	this->name= new char [strlen(Name)+1];
	strcpy(name,Name);
}
B& B::operator=(const B& N)
{
	if (this == &N)
	{
	return *this;
	}
	this->name=new char[strlen(N.name)+1];
	strcpy(name,N.name);
	return *this;
}
B::~B(void)
{
	delete[] name;
}
