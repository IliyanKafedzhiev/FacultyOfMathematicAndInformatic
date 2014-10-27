#include "Tickets.h"


Tickets::Tickets(void):price(30)
{
}

Tickets::Tickets(double p):price ((p>0)?p:0)
{

}

Tickets::~Tickets(void)
{
}
