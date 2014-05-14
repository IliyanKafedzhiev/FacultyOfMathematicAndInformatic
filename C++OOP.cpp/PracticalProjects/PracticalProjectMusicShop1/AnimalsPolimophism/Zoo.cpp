#include "Zoo.h"
#include "Lion.h"
#include "Parrot.h"
#include "Crocodile.h"

#include <iostream>
#include <cstring>

using namespace std;

Zoo::Zoo(const char*name,int max):zooName(NULL),maxAnimalCount(max),animalCount(0)
{
	setName(name);
	animals = new Animals* [max];
	for (int i = 0; i < max; i++)
	{
		animals[i]=NULL;
	}
}

Zoo::Zoo(const Zoo& tmp):maxAnimalCount(tmp.maxAnimalCount),animalCount(tmp.animalCount)
{
	setName(tmp.zooName);
	delete [] animals;
	animals = new Animals*[tmp.maxAnimalCount];
	for (int i = 0; i < tmp.maxAnimalCount; i++)
	{
		animals[i] = tmp.animals[i];
	}
}

Zoo& Zoo::operator=(const Zoo&tmp)
{
	if (this!=&tmp)
	{
		maxAnimalCount=tmp.maxAnimalCount;
		animalCount=tmp.animalCount;
		setName(tmp.zooName);
		delete [] animals;
		animals = new Animals*[tmp.maxAnimalCount];
		for (int i = 0; i < tmp.maxAnimalCount; i++)
		{
			animals[i] = tmp.animals[i];
		}
	}
	return *this;
}

void Zoo::setName(const char* name)
{
	delete [] zooName;
	int len = strlen(name)+1;
	zooName = new char [len];
	for (int i = 0; i < len; i++)
	{
		zooName[i]=name[i];
	}
}

void Zoo::animalCounter()const
{
	int crc = 0;
	int par = 0;
	int lion = 0;
	for (int i = 0; i < animalCount; i++)
	{
		if (dynamic_cast <Lion*> (animals[i]))
		{
			lion++;
		}if (dynamic_cast <Crocodile*>(animals[i]))
		{
			crc++;
			}if (dynamic_cast <Parrot*>(animals[i]))
		{
			par++;
		}
	}
	cout<<crc<<"Crocodiles"<<endl;
	cout<<par<<"Parrots"<<endl;
	cout<<lion<<"Lions"<<endl;

}

Animals* Zoo::operator[](int index)const
{
	if (index <=animalCount && index > -1)
	{
		return animals[index];
	}
	else
	{
		return NULL;
	}
}

bool Zoo::IsFull()const
{
	return animalCount>=maxAnimalCount;
}

void Zoo::addZoo(Animals* tmp)
{
	if (!IsFull())
	{
		animals[animalCount]=tmp;
		animalCount++;
	}

}

void Zoo::removeZoo(Animals*tmp)
{
	for (int i = 0; i < animalCount; i++)
	{
		if (animals[i] == tmp)
		{
			animals[i] = animals[animalCount];
			animalCount--;
		}
	}
}

void Zoo::resize(int size)
{
	if (size<=animalCount)
	{
		return;
	}
	Animals** Ptr = new Animals*[size];
	for (int i = 0; i < animalCount; i++)
	{
		Ptr[i]=animals[i];
	}
	delete [] animals;
	animals = Ptr ;
}

void Zoo::information()const
{
	cout<<"ZooName"<<zooName<<endl;
	cout<<"maxAnimals:"<<maxAnimalCount<<endl;
	cout<<"animalCount:"<<animalCount<<endl;
	for (int i = 0; i < animalCount; i++)
	{
		animals[i]->Infomation();
	}
}

Zoo::~Zoo(void)
{
	delete [] zooName;
	delete [] animals;
}
