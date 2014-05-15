
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main ()
{
	char buffer[20];
	int min=0,max=0;
	fstream ifile ("Text1.txt" , fstream::in);
	if (!ifile)
	{
		cout<<"faila nese otvori"<<endl;
		return 1;
	}
	while (!ifile.eof())
	{

		ifile>>buffer;
		if (buffer[0] == '#')
		{
			cout<<min<<"e min, "<<max<<"e max"<<endl;
			min=max=0;
		}
		if ((atoi (buffer))>=max)
		{
			max=(atoi (buffer));
		}
		if ((atoi (buffer))<=min)
		{
			min=(atoi (buffer));
		}
		

		
	}

	ifile.close();
	return 0;
}



