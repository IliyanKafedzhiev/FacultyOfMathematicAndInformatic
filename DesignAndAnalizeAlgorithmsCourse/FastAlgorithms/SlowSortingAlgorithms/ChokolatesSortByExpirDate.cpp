#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

struct DateT
{
	int day;
	int mouth;
	int year;
	int order;
	bool operator < (const DateT& right) const
	{
		if (year != right.year)
		{
			return year < right.year;
		}
		else if (mouth != right.mouth)
		{
			return mouth < right.mouth;
		}
		else if (day != right.day)
		{
			return day < right.day;
		}
		return false;
	}
};


int mainXX()
{
	int Gen;
	scanf("%d", &Gen);
	vector<DateT> Dates;

	for (size_t i = 0; i < Gen; i++)
	{
		int day, year, mouth;
		scanf("%d.%d.%d",&day,&mouth,&year);
		DateT current = { day, mouth, year, i+1 };
		Dates.push_back(current);
	}
	
	sort(Dates.begin(), Dates.end());
	for (size_t i = 0; i < Dates.size(); i++)
	{
		printf("%d", Dates[i].order);
		if (i != Dates.size() - 1)
		{
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

