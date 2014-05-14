#include "Classes.h"
#include <iostream>
using namespace std;
#include <cstring>
/**************************************************************/
void Application::setName(const char* name)
{
    name=name?name:"";//proverka dali n==NULL
    strncpy(this->Name,name,sizeof(name));
}
Application::Application(const char* name,Category c,int s):cat(c)
{
    for(int i=0;i<1024;i++)
    {
        this->Name[i]=name[i];
    }
    Size=s;
}
void Application::print ()const
{
	cout<<Name<<"Size :"<<Size<<endl;
}
bool Application::operator==(const Application&tmp)
{
	for (int i = 0; i < 1024; i++)
	{
		if (this->Name[i]!=tmp.Name[i])
		{
			return false;
		}
	}
	if (this->Size!=tmp.Size)
	{
		return false;
	}
	return true;
}
/***************************************************************/
