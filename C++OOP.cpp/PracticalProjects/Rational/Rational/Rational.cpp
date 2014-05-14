#include "Rational.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

Rational::Rational()
{
	Numenator=0;
	Denominator=1;
	Name=new char[1];
	assert(Name!=NULL);
	strcpy(Name,"");

}
Rational::Rational(int num,int denum,char * name)
{
	Name=new char [strlen(name)+1];
	strcpy(Name,name);
	Numenator=num;
	Denominator=(denum==0)?1:denum;
}
Rational::Rational(const Rational&A)
{
	Numenator=A.Numenator;
	Denominator=A.Denominator;
	Name=new char [strlen(A.Name)+1];
	strcpy(Name,A.Name);
}
Rational::~Rational(void)
{
	delete [] Name;
}
int Rational::getNumerator()const
{
	return Numenator;
}
int Rational::getDeNum()const
{
	return Denominator;
}
char* Rational::getNAme()const
{
	return Name;
}
void Rational::setDeNomirator(int x)
{
	Denominator=x;
}
void Rational::setNumerator(int x)
{
	Numenator=x;
}
void Rational::setName(const char* x)
{
	Name=new char [strlen(x)+1];
	strcpy(Name,x);
}
Rational& Rational::operator=(const Rational&A) 
{
	if (this!=&A)
	{
		delete [] Name;
		Name=new char [strlen(A.Name)+1];
		strcpy(Name,A.Name);
		Numenator=A.Numenator;
		Denominator=A.Denominator;
		return *this;
	}

}
Rational Rational::operator+(const Rational&A)
{
	if(Denominator==A.Denominator)
	{
		Numenator=Numenator+A.Numenator;
		return Rational(Numenator,Denominator,"new");
	}
	else
	{
		Numenator=Numenator*A.Denominator+A.Numenator*Denominator;
		return Rational(Numenator,Denominator*Denominator,"new");
	}
}
Rational Rational::operator++(int x)
{
	Rational tmp = *this;
	*this=*this+1;
	return tmp;
}
Rational& Rational::operator++()
{
	return 1+*this;
}
Rational& Rational::operator--()
{
	return *this-1;
}
Rational Rational::operator--(int c)
{
	Rational tmp=*this;
	*this=*this-1;
	return tmp;
}
void Rational::operator+=(const Rational&A)
{
	*this=(*this)+A;
}
Rational Rational::operator-(const Rational&A)
{
	if(Denominator==A.Denominator)
	{
		Numenator=Numenator-A.Numenator;
		return Rational(Numenator,Denominator,"new");
	}
	else
	{
		Numenator=Numenator*A.Denominator-A.Numenator*Denominator;
		return Rational(Numenator,Denominator*Denominator,"new");
	}
}
void Rational::operator-=(const Rational&A)
{
	*this=(*this)-A;
}
bool Rational::operator==(const Rational&A)
{
	double x,y;
	x=Numenator/Denominator;
	y=A.Numenator/A.Denominator;
	if (abs(x-y)<0.00000000001 )
	{
		return 1;
	}
	else
		return 0;
}
bool Rational::operator!=(const Rational&A)
{
	return !(*this==A);
}
istream& operator>>(istream& A,Rational&B)
{
	A>>B.Numenator;
	A>>B.Denominator;

	return A;

}
ostream& operator<<(ostream& A,const Rational& B)
{
	A<<B.Numenator<<"/"<<B.Denominator<<B.Name;
	return A;

}
bool Rational::operator>=(const Rational&A)
{
	double x,y;
	x=Numenator/Denominator;
	y=A.Numenator/A.Denominator;
	if ((x-y)>=0.00000000001 || *this==A)
	{
		return 1;
	}
	else
		return 0;
}
bool Rational::operator<(const Rational&A)
{
	if(!(*this>=A))
		return 1;
	else
		return 0;

}
bool Rational:: operator>(const Rational&A)
{
	if(!(*this<A))
		return 1;
	else 
		return 0;
}
bool Rational::operator<= (const Rational&A)
{
	if (!(*this>A))
		return 1;
	else 
		return 0;
}
Rational operator+(const Rational&A,const int x)
{
	
	return Rational(A.Numenator+x*A.Denominator,A.Denominator,"new");
}
Rational operator+(const int x,const Rational&A)
{
	return Rational(A.Numenator+x*A.Denominator,A.Denominator,"new");
}
Rational& operator-(const int x,Rational&A)
{
	A.Numenator=x*A.Denominator-A.Numenator;
	return A;
}
Rational& operator-(Rational&A,const int x)
{
	A.Numenator=A.Numenator-x*A.Denominator;
	return A;
}
Rational Rational::operator*(const Rational&A)const 
{
	return Rational(Numenator*A.Numenator,Denominator*A.Denominator,"name");
}
Rational& Rational::operator*=(const Rational&A)
{
	return *this*A;
}




