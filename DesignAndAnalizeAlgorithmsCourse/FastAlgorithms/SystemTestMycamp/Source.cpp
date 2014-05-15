#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

void read(double tmp)
{
	double xx;

	if (cin>>xx)
	{
		read(xx);
	}


	printf("%lf\n", sqrt(tmp));
}

int mainZZ()
{
	double xx;
	if (cin >> xx)
	{
		read(xx);
	}
	return 0;
}
