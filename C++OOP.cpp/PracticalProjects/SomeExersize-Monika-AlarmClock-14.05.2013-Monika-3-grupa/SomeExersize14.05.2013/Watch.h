#pragma once
#ifndef WATCH_H
#define WATCH_H
#include "subject.h"
class Watch:public virtual subject
{
	bool isElectron;
public:
	Watch(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpIsElectron);
	bool GetIsElectron();
	void printSubject();
	~Watch(void);
};
#endif

