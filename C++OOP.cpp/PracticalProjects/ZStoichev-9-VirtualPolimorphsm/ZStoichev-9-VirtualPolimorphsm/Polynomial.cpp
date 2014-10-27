#include "Polynomial.h"
#include <iostream>
#include <cstring>
using namespace std;

Polynomial::Polynomial(char* coefficients,int power)
{
	setCoefficients(coefficients);
}


Polynomial::~Polynomial(void)
{
}

void Polynomial::setCoefficients(char*coefficient)
{
	this->coefficients=new char [strlen(coefficient)+1];
	for (int i = 0; i <= strlen(coefficient); i++)
	{
		this->coefficients[i]=coefficient[i];
	}
}
