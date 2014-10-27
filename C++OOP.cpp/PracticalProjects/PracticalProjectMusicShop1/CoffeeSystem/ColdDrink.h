#ifndef ColdDrink_H
#define ColdDrink_H
#include "Ingredians.h"
#include "Drink.h"
class ColdDrink : public Drink
{
public:
	ColdDrink(void);
	ColdDrink(const char*,const Ingredients*,int);
	ColdDrink(const ColdDrink&);
	ColdDrink& operator=(const ColdDrink&);
	~ColdDrink(void);
	virtual double getPrice ()const ;
	virtual Drink* clone()const ;
};
#endif



