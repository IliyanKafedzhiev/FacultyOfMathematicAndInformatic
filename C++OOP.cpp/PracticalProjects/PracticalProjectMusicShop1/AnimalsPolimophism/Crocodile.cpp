#include "Crocodile.h"

#include <iostream>

using namespace std;

Crocodile::Crocodile(asex sex,float weight,animal animalType,float toothslength,float tailLength,float byteStengt)
	:Animals(sex,weight,animalType),toothslength(toothslength),tailLength(tailLength),byteStengt(byteStengt)
{
}

Crocodile::Crocodile(const Crocodile&tmp):Animals(tmp),toothslength(tmp.toothslength),tailLength(tmp.tailLength),byteStengt(tmp.byteStengt)
{
}

Crocodile& Crocodile::operator=(const Crocodile& tmp)
{
	if (this!=&tmp)
	{
		Animals::operator=(tmp);
		toothslength=tmp.toothslength;
		tailLength=tmp.tailLength;
		byteStengt=tmp.byteStengt;
	}
	return *this;
}


Crocodile::~Crocodile(void)
{
}
//getters
float Crocodile::getTooth()const
{
	return toothslength;
}

float Crocodile::getTail()const
{
	return tailLength;
}

float Crocodile::getByteStengt()const
{
	return byteStengt;
}
//setters
void Crocodile::setTooth(float&tmp)
{
	toothslength=tmp;
}

void Crocodile::setTail(float& tmp)
{
	tailLength=tmp;
}

void Crocodile::setByteStengt(float&tmp)
{
	byteStengt=tmp;
}
//methods
void Crocodile::Infomation()const
{
	Animals::animalInformation();
	cout<<"toothslength"<<toothslength<<endl;
	cout<<"tailLength"<<tailLength<<endl;
	cout<<"byteStengt"<<byteStengt<<endl;
}
