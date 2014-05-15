// SomeExersize14.05.2013.cpp : Defines the entry point for the console application.
#include <iostream>
#include <cstring>

#include "subject.h"
#include "Watch.h"
#include  "alarmClock.h"
#include "Radio.h"
#include "RadioAlarmCLock.h"
using namespace std;

int main()
{
	RadioAlarmClock nokia("Nokia",100,"White",true,true,24,224);
	nokia.printSubject();
	return 0;
}

