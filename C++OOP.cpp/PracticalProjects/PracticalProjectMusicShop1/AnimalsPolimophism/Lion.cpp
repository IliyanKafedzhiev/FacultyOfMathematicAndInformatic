#include "Lion.h"

#include <iostream>

using namespace std;

Lion::Lion(asex sex,float weight,animal animalType,float toothslength,float tailLength)
	:Animals(sex,weight,animalType),toothslength(toothslength),tailLength(tailLength)
{
}

Lion::Lion(const Lion&tmp):Animals(tmp),toothslength(tmp.toothslength),tailLength(tmp.tailLength)
{
}

Lion& Lion::operator=(const Lion& tmp)
{
	if (this!=&tmp)
	{
		Animals::operator=(tmp);
		toothslength=tmp.toothslength;
		tailLength=tmp.tailLength;
	}
	return *this;
}


Lion::~Lion(void)
{
}
//getters
float Lion::getTooth()const
{
	return toothslength;
}

float Lion::getTail()const
{
	return tailLength;
}
//setters
void Lion::setTooth(float&tmp)
{
	toothslength=tmp;
}

void Lion::setTail(float& tmp)
{
	tailLength=tmp;
}
//methods
void Lion::Infomation()const
{
	Animals::animalInformation();
	cout<<"toothslength"<<toothslength<<endl;
	cout<<"tailLength"<<tailLength<<endl;
}
