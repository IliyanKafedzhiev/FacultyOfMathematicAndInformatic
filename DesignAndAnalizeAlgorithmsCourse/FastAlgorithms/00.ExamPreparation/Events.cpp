#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Event{
	int hour, minute, second, day, year, month;
	int inputPosition;
	bool operator < (const Event& other) const
	{
		if (year != other.year)
		{
			return year < other.year;
		}
		if (month != other.month)
		{
			return month < other.month;
		}
		if (day != other.day)
		{
			return day < other.day;
		}
		if (hour != other.hour)
		{
			return hour < other.hour;
		}
		if (minute != other.minute)
		{
			return minute < other.minute;
		}
		if (second != other.second)
		{
			return second < other.second;
		}
		return false;
	}

};

void  Events()
{
	int num;
	scanf("%d", &num);
	vector<Event> Events(num);
	for (int i = 0; i<Events.size(); ++i)
	{
		Event ev;
		scanf("%d.%d.%d %d:%d:%d", &ev.day, &ev.month, &ev.year,&ev.hour, &ev.minute, &ev.second);
		ev.inputPosition = i + 1;
		Events[i] = ev;
	}

	stable_sort(Events.begin(), Events.end());

	for (int i = 0; i<Events.size(); ++i)
	{
		printf("%d\n", Events[i].inputPosition);
	}
}
