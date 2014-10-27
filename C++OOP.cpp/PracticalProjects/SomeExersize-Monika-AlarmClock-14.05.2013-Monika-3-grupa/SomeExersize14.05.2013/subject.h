#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
class subject
{
	char* Model;
	double price;
	char* Color;
public:
	subject(char* Model,double price, char* Color);
	~subject(void);
	char* GetModel();
	char* GetColor();
	void  printSubject();
};
#endif 

