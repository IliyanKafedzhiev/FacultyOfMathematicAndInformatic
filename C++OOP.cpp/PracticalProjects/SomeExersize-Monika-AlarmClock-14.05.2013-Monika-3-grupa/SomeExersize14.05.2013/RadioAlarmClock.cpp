#include "RadioAlarmClock.h"
#include <iostream>
using namespace std;

RadioAlarmClock::RadioAlarmClock(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpb,bool tmpIsElectron,short tmpmelody,int tmpAlarmCounter)
	:subject(tmpModel, tmpPrice,  tmpColor)
	,Radio( tmpModel,tmpPrice,tmpColor,tmpb)
	,alarmClock(tmpModel,tmpPrice,tmpColor, tmpIsElectron, tmpmelody)
{
	this->alarmCounter=tmpAlarmCounter;
}


RadioAlarmClock::~RadioAlarmClock(void)
{
}

void RadioAlarmClock::printSubject()
{
	alarmClock::printSubject();
	cout<<"HasBattery:"<<Radio::getHasBattery()<<endl;
	cout<<"alarmCounter :"<<alarmCounter<<endl;
}