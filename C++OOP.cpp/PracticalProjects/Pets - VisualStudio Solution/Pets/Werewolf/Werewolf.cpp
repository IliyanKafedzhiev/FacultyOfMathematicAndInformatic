#include "Werewolf.h"
#include <cstring>
#include <iostream>
#include <assert.h>

using namespace std;

/***************************************************/
//PETS
/***************************************************/

Pets::Pets(const char* name,bool male):gender(male?'m':'f')
{
	setName(name);
}

Pets::Pets(const Pets&p):gender(p.gender),Name(NULL)
{
	setName(p.Name);
}

Pets:: ~Pets(void)
{
	delete[] Name;
}

Pets& Pets::operator=(const Pets&p)
{
	if(this==&p)
	{
		return *this;
	}
	else
	{
		if (gender!=p.gender)
		{
			throw "invalid assigment";
		}
		setName(p.Name);
		return *this;
	}
}

void Pets::setName(const char* newName)
{
	Name=new char[strlen(newName)+1];
	strcpy(Name,newName);
}

char* Pets::getName()const
{
	return Name;
}

void  Pets::printPet(const Pets& p)
{
	cout<<p.getName()<<endl;
	p.speak();
}

Pets* Pets::createPets()
{
	char c;
	cin>>c;
	switch (c)
	{
	case 'c':return new Cat("maca",false);
	case 'd':return new Dog("lucky",true,"haski");
	default:
		break;
	}
	return NULL;
}

char Pets::getGender()
{
	return gender;
}

/***************************************************/
//CAT
/***************************************************/

Cat::Cat(const char* name,bool male):Pets(name,male)
{
}

void Cat::speak()const
{
	cout<<"Mqyyyyy"<<endl;
}

Cat::~Cat(void)
{
}

void Cat::climb()const
{
	cout<<"Gore na chereshata"<<endl;
}

/***************************************************/
//DOG
/***************************************************/

Dog::Dog(const char* name,bool male,const char* breed):Pets(name,male)
{
	setBreed(breed);
}

Dog::Dog(const Dog&d):Pets(d)
{

	setBreed(d.breed);
}

void Dog::speak()const
{
	cout<<"Djafff Djafff"<<endl;
}

Dog::~Dog(void)
{
	delete [] this->breed;
}

void Dog::setBreed(const char*b)
{
	breed=new char[strlen(b)+1];
	strcpy(breed,b);
}

Dog& Dog::operator=(const Dog&d)
{
	assert(d.gender==gender);
	if (this!=&d)
	{
		Pets::operator=(d);
		setBreed(d.breed);
	}
	return *this;
}

char* Dog::getBreed()
{
	return breed;
}
