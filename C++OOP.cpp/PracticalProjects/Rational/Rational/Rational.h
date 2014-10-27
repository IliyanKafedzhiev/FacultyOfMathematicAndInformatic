#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;
class Rational
{
public:
	//kontryktori -destryktori
	Rational();
	Rational (int num,int denum,char* name );
	Rational (const Rational&A);
	~Rational(void);
	//selektori 
	int getNumerator()const; 
	int getDeNum()const;
	char *getNAme()const;
	// mutatori
	void setDeNomirator(int);
	void setNumerator(int);
	void setName(const char*);
	//operatori
	Rational& operator=(const Rational&A); 
	Rational operator+(const Rational&A);
	Rational operator++(int);
	Rational& operator++();
	Rational operator--(int);
	Rational& operator--();
	Rational operator *(const Rational&)const;
	Rational& operator *=(const Rational&);
	void operator+=(const Rational&A);
	Rational operator-(const Rational&A);
	void operator-=(const Rational&A);
	bool operator==(const Rational&A);
	bool operator!=(const Rational&A);
	bool operator>=(const Rational&A);
	bool operator<(const Rational&A);
	bool operator>(const Rational&A);
	bool operator<=(const Rational&A);

	friend istream& operator>>(istream& ,Rational&);
	friend ostream& operator<<(ostream&,const Rational&);
	friend Rational  operator+(const Rational&,const int A);
	friend Rational  operator+(const int A,const Rational &);
	friend Rational&  operator-(const int A, Rational &);
	friend Rational&  operator-(Rational&,const int A);
private:
	char *Name;
	int Numenator;
	int Denominator;
};
#endif  RATIONAL_H

