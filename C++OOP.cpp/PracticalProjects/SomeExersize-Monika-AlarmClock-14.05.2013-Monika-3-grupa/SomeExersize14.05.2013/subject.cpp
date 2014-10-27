#include "subject.h"
#include <iostream>
#include <cstring>
using namespace std;
char * SetStr(char*Model,char*tmpModel)
{
	Model = new char[strlen(tmpModel)+1];
	for (int i = 0; i <= strlen(tmpModel); i++)
	{
		Model[i]=tmpModel[i];
	}
	return Model;
}
subject::subject(char* tmpModel,double tmpPrice,char* tmpColor):price(tmpPrice)
{
	Model=SetStr(Model,tmpModel);
	Color=SetStr(Color,tmpColor);
}

char* subject::GetModel()
{
	return Model;
}

char* subject::GetColor()
{
	return Color;
}

void subject::printSubject()
{
	cout<<Model<<endl;
	cout<<price<<endl;
	cout<<Color<<endl;
}

subject::~subject(void)
{
	delete [] Model;
	delete [] Color;
}
