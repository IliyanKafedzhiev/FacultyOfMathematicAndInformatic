#include "alarmClock.h"
#include <iostream>
using namespace std;

alarmClock::alarmClock(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpIsElectron,short tmpmelody)
	:Watch(tmpModel , tmpPrice, tmpColor,tmpIsElectron)
	,subject(tmpModel, tmpPrice,  tmpColor)
{
	melody=tmpmelody;
}

short alarmClock::GetMelody()
{
	return melody;
}
void alarmClock::printSubject()
{
	Watch::printSubject();
	cout<<melody<<endl;
}
alarmClock::~alarmClock(void)
{
}
