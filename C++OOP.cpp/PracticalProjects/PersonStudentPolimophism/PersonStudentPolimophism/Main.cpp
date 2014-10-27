#include <iostream>
#include <cstring>
#include "Person.h"
#include "Student.h"
#include "Date.h"
using namespace std;
int main ()
{
	Date mishob(2012,2,3);
	Date a(1993,3,23);
	Person Misho(mishob,"Misho Krastev");
	Student pesho("petar",mishob,"778723",4.23);
	pesho.printStudent();
	return 0;
}