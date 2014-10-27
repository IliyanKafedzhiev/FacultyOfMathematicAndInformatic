#include "StudentTicket.h"


StudentTicket::StudentTicket(void):Tickets()
{

}

StudentTicket::StudentTicket(double p):Tickets(p)
{

}

double StudentTicket::getPrice()
{
	return price*0.5;
}

StudentTicket::~StudentTicket(void)
{
}
