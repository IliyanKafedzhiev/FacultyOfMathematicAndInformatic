#include "UnaryFuncktion.h"
class Polynomial:public UnaryFunction
{
	char*coefficients;
	int power;
	int*getCoefficients;
	void setCoefficients(char*);
public:
	virtual double value(double x) const=0;
	virtual UnaryFunction* derivative() const=0;
	virtual UnaryFunction* clone() const=0;

	Polynomial(char* coefficients,int power);
	~Polynomial(void);
};

