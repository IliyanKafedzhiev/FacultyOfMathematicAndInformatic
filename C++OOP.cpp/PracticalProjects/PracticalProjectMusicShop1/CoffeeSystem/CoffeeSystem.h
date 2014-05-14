#ifndef COFFEESYSTEM_H
#define COFFEESYSTEM_H

#include "Drink.h"
#include <iostream>
#include <string>

using namespace std;

class CoffeeSystem
{
public:
	CoffeeSystem(void);
	CoffeeSystem(const Drink*,int,int);
	~CoffeeSystem(void);
	void isAvaible(const char*);
	void addDrink (const Drink&);
private:
	Drink** drinks;
	int count;
	int capasity;

};
#endif

