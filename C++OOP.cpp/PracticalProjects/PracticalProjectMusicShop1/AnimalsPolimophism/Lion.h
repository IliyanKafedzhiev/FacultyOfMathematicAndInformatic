#ifndef LION_H
#define LION_H
#include  "Animals.h"
class Lion:public Animals
{
	float toothslength;
	float tailLength;

public:
	Lion(asex sex,float weight,animal animalType,float toothslength,float tailLength);
	Lion(const Lion&);
	Lion& operator=(const Lion&);
	~Lion(void);
	//getters
	float getTooth()const;
	float getTail()const;
	//setters
	void setTooth(float&);
	void setTail(float&);
	void Infomation()const;
};
#endif LION_H

