#include <iostream>
#include "Rational.h"
using namespace std;
int main ()
{
	Rational s(9,6,"pesho");
	Rational k(23,3,"kurds");
	Rational z;
	z=s+43;
	cout<<z;
	return 0;
}