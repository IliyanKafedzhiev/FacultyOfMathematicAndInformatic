#include <iostream>
#include<fstream>
#include <stdexcept>
#include "MusicShop.h"


using namespace std;

int main()
{
	try
	{
		Record* f=new Record[10];
		Record* q=new Record[10];
		Record d("Unforgiven","Metalica",2332,32,Metal,CD);
		Record h("rakiichica","radoshisharkata",111,88,Metal,CD);
		for (int i = 0; i < 10; i++)
		{
			f[i]=d;
		}
		for (int i = 0; i < 9; i++)
		{
			q[i]=d;
		}
		q[9]=h;
		MusicShop s("Payner","Adress",20);
		s.setRecords(f,10);
		MusicShop g("NewShop","Adress",5);
		g.setRecords(q,10);
		//(g*s)->recordInformation(); // bezumie da vrashta masiv na koito ne znaem daljinata
		cout<<"Is Equal:"<<(g==s)<<endl;
		//writeInFile(g,"MusicShop.txt");
		delete [] f;
		delete [] q;
	}
	catch(exception& x)
	{
		cout<<x.what()<<endl;
	}
	return 0;
}
