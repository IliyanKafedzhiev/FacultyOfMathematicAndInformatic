#pragma once
#ifndef ALARMCLOCK_H
#include "Watch.h"
class alarmClock: public Watch
{
	short melody;
public:
	alarmClock(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpIsElectron,short tmpmelody);
	short GetMelody();
	void printSubject();
	~alarmClock(void);
};
#endif

