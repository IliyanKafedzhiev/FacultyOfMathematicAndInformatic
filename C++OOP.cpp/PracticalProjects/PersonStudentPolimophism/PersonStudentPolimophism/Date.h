#pragma once
#ifndef DATE_H
#define DATE_H
class Date
{
public:
	Date(void);
	Date(const unsigned,const short, const short);
	Date(const Date&);
	~Date(void);
	void printDate();
	Date& operator=(const Date&);
	void setDate(const unsigned,const short,const short);

private:
	unsigned year;
	short month;
	short day;
};
#endif // DATE_H

