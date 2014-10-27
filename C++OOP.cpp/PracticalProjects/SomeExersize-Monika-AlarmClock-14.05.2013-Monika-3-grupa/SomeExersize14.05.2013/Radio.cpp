#include "Radio.h"
#include <iostream>
using namespace std;

Radio::Radio(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpBattery)
	:subject (tmpModel,tmpPrice,tmpColor)
{
	hasBattery=tmpBattery;
}

bool Radio::getHasBattery()
{
	return hasBattery;
}

void Radio::printSubject()
{
	subject::printSubject();
	cout<<hasBattery<<endl;
}

Radio::~Radio(void)
{
}
