#include "GroupTicket.h"


GroupTicket::GroupTicket(void):Tickets()
{
	people=4;
}

GroupTicket::GroupTicket(double p,int c):Tickets(p),people(c)
{

}

double GroupTicket::getPrice()
{
	return price*0.3*people;
}

GroupTicket::~GroupTicket(void)
{
}
