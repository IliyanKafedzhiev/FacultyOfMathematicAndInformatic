#include "Exeption.h"
#include <iostream>
#include <cstring>

using namespace std;

void Exeption::setReason(const char* Reason)
{
	delete [] reason;
	this->reason = new char [strlen(Reason) + 1];
	strcpy_s(reason,strlen(Reason) + 1,Reason);
}

Exeption::Exeption(const char* theReason):reason(NULL)
{
	setReason(theReason);
}


Exeption::~Exeption(void)
{
	delete [] reason;
}

Exeption::Exeption(const Exeption& other):reason(NULL)
{
	setReason(other.reason);
}

Exeption& Exeption::operator=(const Exeption& right)
{
	if (this == &right)
	{
		return*this;
	}
	setReason(right.reason);
	return*this;
}

void Exeption::print()const
{
	std::cout<<reason<<std::endl;
}