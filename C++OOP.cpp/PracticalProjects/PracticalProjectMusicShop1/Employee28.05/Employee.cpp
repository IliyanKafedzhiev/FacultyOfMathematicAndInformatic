#include "Employee.h"
#include <cstring>

Employee::Employee(const char*tmp,const Position tmpPS)
{
	name=new char [strlen(tmp)+1];
	for (int i = 0; i <= strlen(tmp); i++)
	{
		name[i]=tmp[i];
	}
}

Employee::Employee(const Employee&tmp):PS(tmp.PS)
{
	delete [] name;
	name=new char[strlen(tmp.name)+1];
	for (int i = 0; i <= strlen(tmp.name); i++)
	{
		name[i]=tmp.name[i];
	}
}

Employee& Employee::operator=(const Employee&tmp)
{
	if (this!=&tmp)
	{
		this->PS=tmp.PS;
		delete [] name;
		name=new char[strlen(tmp.name)+1];
		for (int i = 0; i <= strlen(tmp.name); i++)
		{
			name[i]=tmp.name[i];
		}
	}
	return *this;
}

Employee::~Employee(void)
{
	delete [] name;
}
