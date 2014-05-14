#ifndef CROCODILE_H
#define CROCODILE_H
#include  "Animals.h"
class Crocodile:public Animals
{
	float toothslength;
	float tailLength;
	float byteStengt;

public:
	Crocodile(asex sex,float weight,animal animalType,float toothslength,float tailLength,float byteStengt);
	Crocodile(const Crocodile&);
	Crocodile& operator=(const Crocodile&);
	~Crocodile(void);
	//getters
	float getTooth()const;
	float getTail()const;
	float getByteStengt()const;
	//setters
	void setTooth(float&);
	void setTail(float&);
	void setByteStengt(float&);
	void Infomation()const;
};
#endif CROCODILE_H