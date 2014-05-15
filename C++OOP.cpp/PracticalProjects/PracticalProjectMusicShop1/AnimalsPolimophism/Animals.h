#ifndef ANIMALS_H
#define ANIMALS_H
enum asex
{
	DEFALT,
	MALE,
	FEMALE
};

enum animal
{
	DEF,
	BIRD,
	FISH,
	RAPTILE,
	MAMMAL
};

class Animals
{
	asex sex;
	float weight;
	animal animalType;
public:
	Animals(asex sex,float weight,animal animalType);
	Animals(const Animals&);
	Animals& operator=(const Animals&);
	~Animals(void);
	//selectors
	asex getSex ()const;
	float getWeight ()const;
	animal getAnimalType ()const;
	//geters
	void setSex (asex&);
	void setWeight (float&);
	void setAnimalType (animal&);
	virtual void Infomation()const=0;
	virtual void animalInformation()const;
};
#endif 

