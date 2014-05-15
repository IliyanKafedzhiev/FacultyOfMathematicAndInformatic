#include "Train.h"

#include <iostream>

using namespace std;

Train::Train(int startStation,int endStation,int capacity,double ticketPrice)
	:capacity((capacity>0)?capacity:1),startStation(startStation)
	,endStation(endStation),currentCountPasinger(0),ticketPrice((ticketPrice>0)?ticketPrice:0)
{
	tickets = new Tickets*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		tickets[i]=NULL;
	}
}


Train::~Train(void)
{
	delete [] tickets;
}

bool Train::sellTicket()
{
	if (isFull())
	{
		cout<<"Vlaka e palen!"<<endl;
		return false;
	}
	char c;
	cout<<"Vavedi kakav bilet iskate N-normal,S-studentski,G-grupov"<<endl;
	cin>>c;
	if (!(c == 'N' || c == 'S' || c == 'G'))
	{
		cout<<"Error"<<endl;
		return false;
	}
	cout<<endl;
	Tickets* crr;
	switch (c)
	{
	case 'N':
		crr = new NormalTicket(ticketPrice);
		tickets[currentCountPasinger]=crr;
		currentCountPasinger++;
		break;
	case 'S':
		crr = new StudentTicket(ticketPrice);
		tickets[currentCountPasinger]=crr;
		currentCountPasinger++;
		break;
	case 'G':
		cout<<"Kolko choveka //min 4 choveka"<<endl;
		int people;
		cin>>people;
		if (people < 4)
		{
			throw invalid_argument ("Mnogo malko hora si vavela");
		}
		crr = new GroupTicket(ticketPrice,people);
		tickets[currentCountPasinger]=crr;
		currentCountPasinger+= people;
		break;
	default:
		cout<<"Error"<<endl;
		return false;
		break;
	}
	cout<<"OK"<<endl;
	return true;
}

bool Train::isFull()const
{
	return currentCountPasinger>=capacity;
}

double Train::getCurrentMoney()const
{
	double sum = 0;
	for (int i = 0; i < currentCountPasinger; i++)
	{
		sum += tickets[i]->getPrice();
	}
	return sum;
}

int Train::getStartStation()const
{
	return startStation;
}

int Train::getEndStation()const
{
	return endStation;
}
