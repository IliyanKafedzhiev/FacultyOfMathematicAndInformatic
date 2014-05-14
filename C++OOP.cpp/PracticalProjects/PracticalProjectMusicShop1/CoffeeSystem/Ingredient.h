#ifndef INGREDIENT_H
#define INGREDIENT_H
class Ingredient
{
public:
	Ingredient(void);
	Ingredient(const char* name,double price);
	Ingredient(const Ingredient&);
	Ingredient& operator=(const Ingredient&);
	Ingredient(Ingredient &&A);
	~Ingredient(void);
	void setName(const char*);
	void setPrice(double);
	const char* getName()const;
	double getPrice()const;
private:
	char* name;
	double price;
};
#endif

