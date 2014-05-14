#ifndef HotDrink_H
#define HotDrink_H
#include "Ingredians.h"
#include "Drink.h"
class HotDrink : public Drink
{
public:
	HotDrink(void);
	HotDrink(const char*,const Ingredients*,int);
	HotDrink(const HotDrink&);
	HotDrink& operator=(const HotDrink&);
	~HotDrink(void);
	virtual double getPrice ()const ;
	virtual Drink* clone()const ;
};
#endif



