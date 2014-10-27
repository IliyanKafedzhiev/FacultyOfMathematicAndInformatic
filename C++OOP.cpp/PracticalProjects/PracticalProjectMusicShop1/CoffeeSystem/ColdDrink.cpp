#include "ColdDrink.h"

#include <iostream>
#include <cstring>

using namespace std;

ColdDrink::ColdDrink(void)
{
}

ColdDrink::ColdDrink(const char * name,const Ingredients* tmp,int howMany):Drink(name,tmp,howMany)
{

}

ColdDrink::ColdDrink(const ColdDrink& right):Drink(right)
{
}

ColdDrink& ColdDrink::operator=(const ColdDrink& right)
{
	if (this != &right)
	{
		Drink::operator=(right);
	}
	return *this;
}

Drink* ColdDrink::clone()const
{
	return new ColdDrink(*this);
}

double ColdDrink::getPrice()const
{
	double price = 0;
	for (int i = 0; i < howManyIngredients; i++)
	{
		price = price + (Ingredentes[i].ingred.getPrice() * Ingredentes[i].quantity);
	}
	return price * 1.15;
}


