#ifndef NORMALTICKET_H
#define NORMALTICKET_H

#include "Tickets.h"

class NormalTicket : public Tickets
{
public:
	NormalTicket ();
	NormalTicket(double price);
	~NormalTicket(void);
	virtual double getPrice() ;
private:
};
#endif 
