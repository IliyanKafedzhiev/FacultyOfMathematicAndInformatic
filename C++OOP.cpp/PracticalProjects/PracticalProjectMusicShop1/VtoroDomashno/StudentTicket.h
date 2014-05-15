#ifndef STUDENTTICKET_H
#define STUDENTTICKET_H

#include "Tickets.h"

class StudentTicket : public Tickets
{
public:
	StudentTicket ();
	StudentTicket(double price);
	~StudentTicket(void);
	virtual double getPrice() ;
private:
};
#endif 
