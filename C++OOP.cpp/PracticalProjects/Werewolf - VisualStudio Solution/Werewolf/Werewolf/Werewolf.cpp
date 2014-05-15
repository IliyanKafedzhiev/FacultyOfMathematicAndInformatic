#include "Werewolf.h"
#include <cstring>

// Class Animal

Animal::Animal(const char* breed, bool fur, bool legs, bool tail,
		FurColors furColor, int legsCount, double tailLength)
{
	this->breed = new char[strlen(breed) + 1];
	strcpy(this->breed, breed);
	
	this->fur = fur;
	if (fur)
	{
		this->furColor = furColor;
	}
	else
	{
		this->furColor = HAIRLESS;
	}

	this->legs = legs;
	if (legs)
	{
		this->legsCount = legsCount;
	}
	else
	{
		this->legsCount = 0;
	}

	this->tail = tail;
	if (tail)
	{
		this->tailLength = tailLength;
	}
	else
	{
		this->tailLength = 0;
	}	
}

Animal::Animal(const Animal& animal)
{
	this->Copy(animal);
}

Animal& Animal::operator = (const Animal& animal)
{
	if (this != &animal)
	{
		this->Delete();
		this->Copy(animal);
	}

	return *this;
}

Animal::~Animal()
{
	this->Delete();
}

void Animal::Delete()
{
	delete[] this->breed;
}

void Animal::Copy(const Animal& animal)
{
	this->breed = new char[strlen(animal.breed) + 1];
	strcpy(this->breed, animal.breed);
	
	this->fur = animal.fur;
	this->furColor = animal.furColor;

	this->legs = animal.legs;
	this->legsCount = animal.legsCount;

	this->tail = animal.tail;
	this->tailLength = animal.tailLength;
}

// Class Person

Person::Person(const char* name, unsigned int age, Sex sex)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->sex = sex;
}

Person::Person(const Person& person)
{
	this->Copy(person);
}

Person& Person::operator = (const Person& person)
{
	if (this != &person)
	{
		this->Delete();
		this->Copy(person);
	}

	return *this;
}
	
Person::~Person()
{
	this->Delete();
}

void Person::Delete()
{
	delete[] this->name;
}

void Person::Copy(const Person& person)
{
	this->name = new char[strlen(person.name) + 1];
	strcpy(this->name, person.name);
	this->age = person.age;
	this->sex = person.sex;
}

Wolf::Wolf(const char* breed, bool fur, bool legs, bool tail,double toothsLenght,bool packMember,
		FurColors furColor , int legsCount , double tailLength ,unsigned int packSize
		):Animal(breed,fur,legs,tail,furColor,legsCount,tailLength)
{
	this->toothsLenght=toothsLenght;
	this->packMember=packMember;
	if(packMember)
	{
		this->packSize = packSize;
	}
	else
	{
		this->packSize = 0;
	}
}
void Wolf::Copy(const Wolf& wolf)
{
	this->toothsLenght=wolf.toothsLenght;
	this->packMember=wolf.packMember;
	this->packSize=wolf.packSize;
}
Wolf::Wolf(const Wolf& wolf)
	: Animal(wolf)
{
	this->Copy(wolf);
}

Wolf& Wolf::operator=(const Wolf& wolf)
{
	if (this != &wolf)
	{
		Animal::operator=(wolf);
		this->Copy(wolf);
	}
	return *this;
}

Werewolf::Werewolf(const char* breed, bool fur, bool legs, bool tail,double toothsLenght,bool packMember,
		const char* name, unsigned int age, Sex sex,char* firstChange,
		FurColors furColor  , int legsCount, double tailLength ,unsigned int packSize)
		:Person(name,age,sex),Wolf(breed,fur,  legs,  tail, toothsLenght, packMember,
		 furColor ,  legsCount ,  tailLength , packSize)
{
	strcpy(this->firstChange,firstChange);
}
void Werewolf::Copy(const Werewolf& werewolf)
{
	strcpy(this->firstChange,werewolf.firstChange);
}
Werewolf::Werewolf(const Werewolf& werewolf):Person(werewolf),Wolf(werewolf)
{
	this->Copy(werewolf);
}
Werewolf& Werewolf::operator=(const Werewolf& werewolf)
{
	if (this!=&werewolf)
	{
		Wolf::operator=(werewolf);
		Person::operator=(werewolf);
		this->Copy(werewolf);
	}
	return *this;
}