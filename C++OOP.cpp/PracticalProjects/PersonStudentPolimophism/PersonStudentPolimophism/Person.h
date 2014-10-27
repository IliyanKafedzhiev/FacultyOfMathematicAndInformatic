
#pragma once 
#ifndef PERSON_H
#define PERSON_H
#include "Date.h"
class Person
{
public:
	Person(void);
	Person(const Date,const char*);
	Person(const Person&);
	~Person(void);
	void printPerson();
	Person& operator=(const Person&);
	const char* getName()const;
	const Date getBDate()const;
	void setName(const char*);
	void setBDate (const Date);
	void setBDate (const unsigned,const short,const short);
private:
	Date dateOfBirth;
	char* Name;
};
#endif // PERSON_H
