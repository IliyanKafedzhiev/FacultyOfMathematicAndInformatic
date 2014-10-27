#ifndef PARROT_H
#define PARROT_H
#include  "Animals.h"
enum Colors
{
	BLUE,
	WHITE,
};
class Parrot:public Animals
{
	Colors color;
	bool canSpeak;

public:
	Parrot(asex sex,float weight,animal animalType,Colors color,bool canSpeak);
	Parrot(const Parrot&);
	Parrot& operator=(const Parrot&);
	~Parrot(void);
	//getters
	Colors getColor()const;
	bool getIsSpeak()const;
	//setters
	void setColor(Colors&);
	void setCanSpeak(bool&);
	//methods
	void Infomation()const;
};
#endif PARROT_H
