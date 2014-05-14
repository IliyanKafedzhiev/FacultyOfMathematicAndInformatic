#ifndef TICKETS_H
#define TICKETS_H
class Tickets
{
public:
	Tickets ();
	Tickets(double price);
	~Tickets(void);
	virtual double getPrice() = 0;
protected:
	const double price;
};
#endif 

