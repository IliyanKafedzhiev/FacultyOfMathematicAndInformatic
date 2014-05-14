#include "Animals.h"
#include "Parrot.h"
#include "Crocodile.h"
#include "Lion.h"
#include "Zoo.h"

#include <iostream>

using namespace std;

int main()
{
	Lion l(MALE,77,MAMMAL,5,45);
	Parrot p(FEMALE,1,BIRD,WHITE,1);
	Crocodile c(MALE,1111,RAPTILE,10,11,12);
	Lion l2(FEMALE,80,MAMMAL,5,40);
	//Animal* a[3] = {&l,&p,&c}; 
	Zoo newzoo("Sofia",10);
	newzoo.addZoo(&l);
	newzoo.addZoo(&p);
	newzoo.addZoo(&c);
	newzoo.addZoo(&l2);
	newzoo.information();
	newzoo.animalCounter();
	system ("pause"); 
	return 0;
}