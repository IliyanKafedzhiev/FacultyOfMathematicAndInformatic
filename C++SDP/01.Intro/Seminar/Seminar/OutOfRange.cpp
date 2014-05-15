#include <iostream>
#include <cstring>
#include "OutOfRange.h"
using namespace std;

OutOfRange::OutOfRange(const char* Range, int Index):Exeption(Range)
{
	this->index = Index;
}


OutOfRange::~OutOfRange(void)
{
	// izvikva avtomatichno destruktora na bazoviq klas
}

void OutOfRange::print()
{
	Exeption::print();
	cout<<"Index:"<<index<<endl;
}
int OutOfRange::getIndex() const
{
	return index;
}