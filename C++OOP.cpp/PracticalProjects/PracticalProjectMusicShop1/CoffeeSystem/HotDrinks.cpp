#include "HotDrinks.h"

#include <iostream>
#include <cstring>

using namespace std;

HotDrink::HotDrink(void)
{
}

HotDrink::HotDrink(const char * name,const Ingredients* tmp,int howMany):Drink(name,tmp,howMany)
{

}

HotDrink::HotDrink(const HotDrink& right):Drink(right)
{
}

HotDrink& HotDrink::operator=(const HotDrink& right)
{
	if (this != &right)
	{
		Drink::operator=(right);
	}
	return *this;
}

Drink* HotDrink::clone()const
{
	return new HotDrink(*this);
}

double HotDrink::getPrice()const
{
	double price = 0;
	for (int i = 0; i < howManyIngredients; i++)
	{
		price = price + (Ingredentes[i].ingred.getPrice() * Ingredentes[i].quantity);
	}
	return price * 1.33;
}

