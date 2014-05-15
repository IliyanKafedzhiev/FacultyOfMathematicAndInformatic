#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(void):year(0),month(0),day(0)
{
}
Date::Date(const unsigned tmpYear,const short tmpMonth,const short tmpDay)
{
	year=tmpYear;
	month=(tmpMonth<=12 && tmpMonth>=0)?tmpMonth:0;
	day=(tmpDay<=31 && tmpDay>=0)?tmpDay:0;
}
Date::Date(const Date& tmp)
{
	year=tmp.year;
	month=tmp.month;
	day=tmp.day;
}
void Date::setDate(const unsigned tmpYear,const short tmpMonth,const short tmpDay)
{
	year=tmpYear;
	month=(tmpMonth<=12 && tmpMonth>=0)?tmpMonth:0;
	day=(tmpDay<=31 && tmpDay>=0)?tmpDay:0;
}
Date& Date::operator=(const Date&tmp)
{
	year=tmp.year;
	month=tmp.month;
	day=tmp.day;
	return *this;
}
void Date::printDate()
{
	cout<<"Year: "<<year<<endl;
	cout<<"Month:"<<month<<endl;
	cout<<"Day:  "<<day<<endl;
}
Date::~Date(void)
{
}
