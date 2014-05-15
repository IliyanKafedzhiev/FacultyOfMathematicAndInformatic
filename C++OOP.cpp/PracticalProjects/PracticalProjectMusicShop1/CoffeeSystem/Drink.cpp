#include "Drink.h"

#include <iostream>
#include <cstring>

using namespace std;

Drink::Drink(void):Ingredentes(NULL),name(NULL),howManyIngredients(0)
{
}

Drink::Drink(const char * name,const Ingredients* tmp,int howMany):name(NULL)
	,Ingredentes(NULL)
{
	if (howMany  > 0 && name != NULL && tmp != NULL)
	{
		setIngredients(tmp,howMany);
		setName(name);
	}
	else 
	{
		cout<<"nevaledni vhod danni";
	}
}

Drink::Drink(const Drink& right):
	name(NULL),Ingredentes(NULL)
{
	setName(right.name);
	setIngredients(right.Ingredentes,right.howManyIngredients);
}

Drink& Drink::operator=(const Drink& right)
{
	if (this != &right)
	{
		setName(right.name);
		setIngredients(right.Ingredentes,right.howManyIngredients);
	}
	return *this;
}

void Drink::setName(const char* n)
{
	delete [] name;
	int len = strlen(n)+1;
	name = new char [len];
	for (int i = 0; i < len; i++)
	{
		name[i] = n[i];
	}
}

void Drink::setIngredients(const Ingredients* tmp,int howMany)
{
	delete []Ingredentes;
	Ingredentes = new Ingredients [howMany];
	for (int i = 0; i < howMany; i++)
	{
		Ingredentes[i] = tmp[i];
	}
	howManyIngredients = howMany;
}

const char* Drink::getName()const
{
	return name;
}

const Ingredients* Drink::getIngredients()const
{
	return Ingredentes;
}

Drink::~Drink(void)
{
	delete [] Ingredentes;
	delete [] name;
}

void Drink::printIngedients()const
{
	for (int i = 0; i < howManyIngredients; i++)
	{
		cout<<"Sastawka:"<<Ingredentes[i].ingred.getName()<<endl;
		cout<<"Kolichestvo:"<<Ingredentes[i].quantity<<endl;
		cout<<endl;
	}
}
