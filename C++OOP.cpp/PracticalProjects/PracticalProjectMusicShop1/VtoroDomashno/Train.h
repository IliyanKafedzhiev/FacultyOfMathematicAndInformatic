#ifndef TRAIN_H
#define TRAIN_H

#include "Tickets.h"
#include "StudentTicket.h"
#include "GroupTicket.h"
#include "NormalTicket.h"

class Train
{
public:
	Train(int startStation,int endStation,const int capacity,double ticketPrice=30);
	~Train(void);
	double getCurrentMoney()const;
	bool sellTicket();
	bool isFull()const;
	//getters
	int getStartStation()const;
	int getEndStation()const;
private:
	double ticketPrice;
	Tickets** tickets;
	int startStation;
	int endStation;
	const int capacity;
	int currentCountPasinger;
};
#endif

