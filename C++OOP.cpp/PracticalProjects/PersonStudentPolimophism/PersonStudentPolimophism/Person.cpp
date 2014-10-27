#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;
Person::Person(void)
{
	Name=new char [1];
	Name[0]='\0';
}

Person::Person(const Date tmpD,const char*tmpN)
{
	Name=new char [strlen(tmpN)+1];
	for(int i=0;i<=strlen(tmpN);i++)
	{
		Name[i]=tmpN[i];
	}
	dateOfBirth=tmpD;
}

Person::Person(const Person& tmp)
{
	Name=new char [strlen(tmp.Name)+1];
	for(int i=0;i<=strlen(tmp.Name);i++)
	{
		Name[i]=tmp.Name[i];
	}
	dateOfBirth=tmp.dateOfBirth;
}
void Person::printPerson()
{
	cout<<Name<<endl;
	dateOfBirth.printDate();
}
Person& Person::operator=(const Person& tmp)
{
	if(this!=&tmp)
	{
		delete [] Name;
		Name=new char [strlen(tmp.Name)+1];
		for(int i=0;i<=strlen(tmp.Name);i++)
		{
			Name[i]=tmp.Name[i];
		}
		dateOfBirth=tmp.dateOfBirth;
	}
	return *this;
}
const char* Person::getName() const 
{
	return Name;
}
const Date Person::getBDate() const
{
	return dateOfBirth;
}	
void Person::setName(const char* tmp)
{
	delete [] Name;
	Name=new char [strlen(tmp)+1];
	for(int i=0;i<=strlen(tmp);i++)
	{
		Name[i]=tmp[i];
	}
}

void Person::setBDate(const Date tmp)
{
	dateOfBirth=tmp;
}
void Person::setBDate(const unsigned tmpYear,const short tmpMonth,const short tmpDay)
{
	dateOfBirth.setDate(tmpYear,tmpMonth,tmpDay);
}
Person::~Person(void)
{
	delete [] Name;
}
