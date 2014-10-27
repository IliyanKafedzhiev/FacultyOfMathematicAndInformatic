#include "Parrot.h"

#include <iostream>

using namespace std;

Parrot::Parrot(asex sex,float weight,animal animalType,Colors color,bool canSpeak)
	:Animals(sex,weight,animalType),color(color),canSpeak(canSpeak)
{
}

Parrot::Parrot(const Parrot&tmp):Animals(tmp),color(tmp.color),canSpeak(tmp.canSpeak)
{
}

Parrot& Parrot::operator=(const Parrot& tmp)
{
	if (this!=&tmp)
	{
		Animals::operator=(tmp);
		color=tmp.color;
		canSpeak=tmp.canSpeak;
	}
	return *this;
}


Parrot::~Parrot(void)
{
}
//getters
Colors Parrot::getColor()const
{
	return color;
}

bool Parrot::getIsSpeak()const
{
	return canSpeak;
}
//setters
void Parrot::setColor(Colors&tmp)
{
	color=tmp;
}

void Parrot::setCanSpeak(bool& tmp)
{
	canSpeak=tmp;
}
//methods
void Parrot::Infomation()const
{
	Animals::animalInformation();
	cout<<"Color"<<color<<endl;
	cout<<"canSpeak"<<canSpeak<<endl;
}
