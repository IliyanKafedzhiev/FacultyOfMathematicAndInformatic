#pragma once
enum Position
	{
		IT,
		SALES,
	};
class Employee
{
public:
	virtual double getPayment()const=0;
	virtual void setPayment(double,double=0)=0;
	Employee(const char*tmp,const Position tmpPS);
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	virtual ~Employee(void);
private:
	char* name;
	Position PS;
	
};

