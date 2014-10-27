#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student: public Person
{
public:
	Student(void);
	Student(const char*,const Date,const char*,double);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student(void);
	const char * getFacultyNum()const;
	const double getAverageGrade()const;
	void setFacultyNum(const char*);
	void setAverageGrade(const double);
	void printStudent();

private:
	char*FacultyNumber;
	double AverageGrade;
};
#endif  // STUDENT_H
