#pragma once
#ifndef RADIO_H
#define RADIO_H 
#include "subject.h"
class Radio:public virtual subject
{
	bool hasBattery;
public:
	Radio(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpb);
	bool getHasBattery();
	void printSubject();
	~Radio(void);
};
#endif

