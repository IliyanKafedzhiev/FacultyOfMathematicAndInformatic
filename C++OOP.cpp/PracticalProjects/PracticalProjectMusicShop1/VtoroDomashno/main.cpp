#include <iostream>
#include <stdexcept>

#include "Tickets.h"
#include "StudentTicket.h"
#include "GroupTicket.h"
#include "NormalTicket.h"
#include "Train.h"

using namespace std;

int main ()
{
	try{
		cout<<"Sazndavane na vlak natisni molq popalnete dannite za vlaka:"<<endl;
		int capacity;
		cout<<"Vavedi kapaciteta na vlaka:"<<endl;
		cin>>capacity;
		int startPoint;
		cout<<"Vavedi nachalna gara nomer:"<<endl;
		cin>>startPoint;
		int endPoint;
		cout<<"Vavedi kraina gara nomer:"<<endl;
		cin>>endPoint;
		double tiketPrice;
		cout<<"Vavedi cena na bileta:"<<endl;
		cin>>tiketPrice;
		if (tiketPrice < 0 || endPoint < 0 || startPoint <0 || capacity < 1)
		{
			throw invalid_argument("Nevalidni Vhod Danni!");
		}
		Train A(startPoint,endPoint,capacity,tiketPrice);
		cout<<"Vavedi komanda:"<<endl;
		cout<<"Za Proverka na tekushtiq budjet sabran ot bileti natisni B:"<<endl;
		cout<<"Za Prodavane na bilet natisni S:"<<endl;
		cout<<"Za izhod natisni Q"<<endl;
		char c;
		while (cin>>c)
		{
			switch (c)
			{
			case 'B':
				cout<<"$:"<<A.getCurrentMoney()<<endl;
				break;
			case 'S':
				A.sellTicket();
				break;
			case 'Q':
				cout<<"Bye"<<endl;
				return 0;
				break;
			default:
				break;
			}
				cout<<"Vavedi komanda:"<<endl;
				cout<<"Za Prodavane na bilet natisni S:"<<endl;
				cout<<"Za Proverka na tekushtiq budjet sabran ot bileti natisni B:"<<endl;
				cout<<"Za izhod natisni Q"<<endl;

		}
	}
	catch(exception& x)
	{
		cout<<x.what()<<endl;
	}
	system("pause");
	return 0;
}