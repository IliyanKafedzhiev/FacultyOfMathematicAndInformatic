#include "Ingredient.h"

#include <iostream>
using namespace std;

Ingredient::Ingredient(void)
{
	name = NULL;
	price = 0;
}

Ingredient::Ingredient(const char* newName,double newPrice):name(NULL),price((newPrice > 0)?newPrice:0)
{
	if (newName == NULL)
	{
		cout<<"Nevalidno ime";
	}
	else
	{
		setName(newName);
	}

}

void Ingredient::setName(const char* newName)
{
	delete [] name;
	int len = strlen(newName)+1;
	name = new char [len];
	for (int i = 0; i < len; i++)
	{
		name [i] = newName [i];
	}
}

void Ingredient::setPrice(const double tmp)
{
	price = (tmp > 0)?tmp:0;
}

const char* Ingredient::getName()const
{
	return name;
}

double Ingredient::getPrice()const
{
	return price;
}

Ingredient::Ingredient(const Ingredient&right):price(right.price)
{
	setName(right.name);
}

Ingredient::~Ingredient(void)
{
	delete [] name;
}

Ingredient::Ingredient (Ingredient &&A)
{
	name = A.name;
	A.name = NULL;
	price = A.price;
	cout<<"constryctor &&"<<endl;
}

Ingredient& Ingredient::operator=(const Ingredient & A)
{
	if (this != &A)
	{
		price = A.price;
		setName(A.name);
	}
	return *this;
}
