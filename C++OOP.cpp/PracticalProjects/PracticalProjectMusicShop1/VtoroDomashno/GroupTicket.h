#ifndef GROUPTICKET_H
#define GROUPTICKET_H

#include "Tickets.h"

class GroupTicket : public Tickets
{
public:
	GroupTicket ();
	GroupTicket(double price,int=4);
	~GroupTicket(void);
	virtual double getPrice() ;
private:
	int people;
};
#endif 


