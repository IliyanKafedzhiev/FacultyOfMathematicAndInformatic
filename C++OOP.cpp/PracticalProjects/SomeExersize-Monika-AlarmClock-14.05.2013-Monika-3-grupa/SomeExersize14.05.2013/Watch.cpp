#include "Watch.h"
#include "subject.h"
#include <iostream>
using namespace std;

Watch::Watch(char* tmpModel,double tmpPrice,char* tmpColor,bool tmpIsElectron):subject(tmpModel , tmpPrice,tmpColor)
{
	isElectron=tmpIsElectron;
}
bool Watch::GetIsElectron()
{
	return isElectron;
}
void Watch::printSubject()
{
	subject::printSubject();
	cout<<isElectron<<endl;
}
Watch::~Watch(void)
{
}
