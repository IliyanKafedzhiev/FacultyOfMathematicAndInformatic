#include <iostream>

#include "Amphib.h"

using namespace std;

int main ()
{
	Amphib X("audi",2,1.5,50,220,115);
	Vehicle *Y=static_cast<Vehicle*>(&X);
	Y->printVehicle(*Y);
	return 0;
}