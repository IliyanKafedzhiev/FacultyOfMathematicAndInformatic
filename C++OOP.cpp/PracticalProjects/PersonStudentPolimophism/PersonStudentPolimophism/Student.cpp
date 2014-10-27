#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(void):AverageGrade(0)
{
	FacultyNumber=new char [2];
	FacultyNumber[0]='\0';
	
}
Student::Student(const char*tmpName,const Date tmpDate,const char* tmpFacultyNumber,const double tmpAverageGrade )
				 :Person(tmpDate,tmpName)
{
	FacultyNumber=new char[strlen(tmpFacultyNumber)+1];
	for(int i=0;i<=strlen(tmpFacultyNumber);i++)
	{
		FacultyNumber[i]=tmpFacultyNumber[i];
	}
	AverageGrade=tmpAverageGrade;
}

Student::Student(const Student& tmp)
	:Person(tmp.getBDate(),tmp.getName())
{
	delete [] FacultyNumber;
	FacultyNumber=new char[strlen(tmp.FacultyNumber)+1];
	for(int i=0;i<=strlen(tmp.FacultyNumber);i++)
	{
		FacultyNumber[i]=tmp.FacultyNumber[i];
	}
	AverageGrade=tmp.AverageGrade;
}
Student& Student::operator=(const Student&tmp)
{
	if(this!=&tmp)
	{
		delete [] FacultyNumber;
		FacultyNumber=new char[strlen(tmp.FacultyNumber)+1];
		for(int i=0;i<=strlen(tmp.FacultyNumber);i++)
		{
			FacultyNumber[i]=tmp.FacultyNumber[i];
		}
		AverageGrade=tmp.AverageGrade;
	}
	return *this;
}
const char* Student::getFacultyNum()const
{
	return FacultyNumber;
}
const double Student::getAverageGrade() const
{
	return AverageGrade;
}
void Student::setFacultyNum(const char*tmp)
{
	delete [] FacultyNumber;
	FacultyNumber=new char[strlen(tmp)+1];
	for(int i=0;i<=strlen(tmp);i++)
	{
		FacultyNumber[i]=tmp[i];
	}
}
void Student::setAverageGrade(const double tmp)
{
	AverageGrade=tmp;
}
void Student::printStudent()
{
	this->printPerson();
	cout<<endl<<"FacultyNumber"<<FacultyNumber<<endl<<"AverageGrade:"<<AverageGrade<<endl;
}
Student::~Student(void)
{
	delete [] FacultyNumber;
}
