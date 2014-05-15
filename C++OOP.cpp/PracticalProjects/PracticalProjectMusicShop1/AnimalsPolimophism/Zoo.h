#ifndef ZOO_H
#define ZOO_H

#include "Animals.h"

class Zoo
{
public:
	Zoo(const char*,int=2);
	Zoo(const Zoo&);
	Zoo& operator=(const Zoo&);
	~Zoo(void);
	Animals* operator[](int)const;
	void animalCounter()const;
	bool IsFull()const;
	void addZoo(Animals*);
	void removeZoo(Animals*);
	void information()const;
	void resize(int);
	//setters
	void setName(const char*);
private:
	char* zooName;
	int maxAnimalCount;
	int animalCount;
	Animals** animals;
};
#endif ZOO_H
