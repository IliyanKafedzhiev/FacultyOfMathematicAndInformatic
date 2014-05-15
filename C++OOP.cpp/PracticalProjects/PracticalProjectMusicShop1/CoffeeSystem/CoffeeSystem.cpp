#include "CoffeeSystem.h"


CoffeeSystem::CoffeeSystem(void):drinks(NULL),count(0),capasity(0)
{
}

CoffeeSystem::CoffeeSystem(const Drink*DR,int cnt,int cps):count(0),capasity(cps)
{
	drinks = new Drink* [capasity];
	for (int i = 0; i < cnt; i++)
	{
		addDrink(DR[i]);
	}
}

void CoffeeSystem::addDrink (const Drink& A)
{
	if (count >=capasity)
	{
		capasity *=2;
		Drink ** newPtr = new Drink* [capasity];
		for (int i = 0; i < count; i++)
		{
			newPtr[i] = drinks [i];
		}
		drinks = newPtr;

	}
	drinks[count] = A.clone();
	count++;
}

void CoffeeSystem::isAvaible(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(name,drinks[i]->getName()))
		{
			cout<<"We found Drink:"<<name<<"Congred"<<endl;
			cout<<"Price of Drink is:"<<drinks[i]->getPrice()<<"lv."<<endl;
			cout<<"Receip is:"<<endl;
			drinks[i]->printIngedients();
			return;
		}
	}
	cout<<"Not Found"<<endl;
}

CoffeeSystem::~CoffeeSystem(void)
{
	
		delete [] drinks;
}
