#include <iostream>
#include <cstring>
#include "Part.h"
using namespace std;
Part::Part(void):serNum(0),price(0)
{
	namePart=new char[];
	strcpy(namePart,"");
}
Part::Part(int x,double y,char*tmp):serNum(x),price(y)
{
	namePart=new char[strlen(tmp)+1];
	strcpy(namePart,tmp);
}
Part::Part(const Part&tmp):serNum(tmp.serNum),price(tmp.price)
{
	namePart=new char [strlen(tmp.namePart)+1];
	strcpy(namePart,tmp.namePart);
}
int Part::getSerNum()const
{
	return serNum;
}
double Part::getPrice()const
{
	return price;
}
char* Part::getNamePart()const
{
	return namePart;
}
void Part::couta()
{
	cout<<serNum<<endl;
	cout<<price<<endl;
	cout<<namePart<<endl;
}
void Part::setSerNum(const int tmp)
{
	serNum=tmp;
}
void Part::setPrice(const double tmp)
{
	price=tmp;
}
void Part::setNamePart(const char* tmp)
{
	delete namePart;
	namePart=new char [strlen(tmp)+1];
	strcpy(namePart,tmp);
}
Part::~Part(void)
{
	delete []namePart;
}
