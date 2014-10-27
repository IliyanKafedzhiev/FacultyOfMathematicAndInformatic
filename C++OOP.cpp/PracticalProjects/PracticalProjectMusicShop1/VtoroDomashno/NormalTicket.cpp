#include "NormalTicket.h"



NormalTicket::NormalTicket(void):Tickets()
{

}

NormalTicket::NormalTicket(double p):Tickets(p)
{

}

double NormalTicket::getPrice()
{
	return price;
}

NormalTicket::~NormalTicket(void)
{
}

