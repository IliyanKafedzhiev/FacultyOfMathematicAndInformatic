#include  <iostream>

#include "Ingredient.h"
#include "Drink.h"
#include "CoffeeSystem.h"
#include "ColdDrink.h"
#include "HotDrinks.h"

using namespace std;


int main ()
{
	Ingredient sol("solche",1.32);
	Ingredients haivan;
	haivan.ingred=sol;
	haivan.quantity=4;
	Ingredient s("solche",1.32);
	Ingredients h;
	h.ingred=s;
	h.quantity=7;
	Drink* chai=new HotDrink("chai",&haivan,1);
	Drink* fresh= new ColdDrink("fresh",&h,1);
	CoffeeSystem sys(chai,1,2);
	sys.addDrink(*fresh);
	sys.isAvaible("fresh");
	
	return 1;
}
