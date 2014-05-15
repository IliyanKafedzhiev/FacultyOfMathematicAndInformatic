#ifndef DRINK_H
#define DRINK_H
#include "Ingredians.h"
class Drink
{
public:
	Drink(void);
	Drink(const char*,const Ingredients*,int);
	Drink(const Drink&);
	virtual Drink& operator=(const Drink&);
	~Drink(void);
	virtual double getPrice ()const = 0;
	virtual Drink* clone()const = 0;
	void setName(const char*);
	void setIngredients(const Ingredients* tmp,int howMany);
	const char* getName()const;
	const Ingredients* getIngredients()const;
	void printIngedients()const;
protected:
	char* name;
	Ingredients * Ingredentes;
	int howManyIngredients;
};
#endif

