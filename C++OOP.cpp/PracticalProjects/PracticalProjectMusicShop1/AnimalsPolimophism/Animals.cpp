#include "Animals.h"
#include <iostream>

using namespace std;

Animals::Animals(asex sex,float weight,animal animalType):
	sex(sex),animalType(animalType),weight((weight > 0)?weight:0)
{	
}

Animals::Animals(const Animals&tmp):sex(tmp.sex),animalType(tmp.animalType),weight((tmp.weight > 0)?tmp.weight:0)
{
}

Animals& Animals::operator=(const Animals&tmp)
{
	if (this!=&tmp)
	{
		sex=tmp.sex;
		weight=tmp.weight;
		animalType=tmp.animalType;
	}
	return *this;
}

Animals::~Animals(void)
{
}
//selectors
asex Animals::getSex ()const
{
	return sex;
}

float Animals::getWeight ()const
{
	return weight;
}

animal Animals::getAnimalType ()const
{
	return animalType;
}
//getters
void Animals::setSex (asex& tmp)
{
	sex=tmp;
}

void Animals::setWeight (float & tmp)
{
	weight=(tmp > 0)?tmp:0;
}

void Animals::setAnimalType (animal& tmp)
{
	animalType=tmp;
}

void Animals::animalInformation()const
{
	cout<<"Weight:"<<weight<<endl;
}