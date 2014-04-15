#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>


using namespace std;

void ReadInput(vector<pair<long long, long long> >& Data)
{
	int nums;
	scanf("%d", &nums);
	Data.resize(nums);
	for (size_t i = 0; i < nums; i++)
	{
		long long lenght;
		long long vodka;
		scanf("%lld ", &lenght);
		scanf("%lld", &vodka);
		Data[i].first = lenght;
		Data[i].second = vodka;
	}
	sort(Data.begin(), Data.end());
}

bool specialFunck(vector<pair<long long, long long> > Data, long long middle)
{
	for (size_t i = 0; i < Data.size() - 1; i++)
	{
		if (Data[i].second >= middle)
		{
			long long vodkaForNextParty = Data[i].second - middle - (Data[i + 1].first - Data[i].first);
			if (vodkaForNextParty > 0)
			{
				Data[i].second -= middle;
				Data[i + 1].second += vodkaForNextParty;
			}
		}
		else if (Data[i].second < middle)
		{
			long long NeededVodka = middle - Data[i].second;
			Data[i + 1].second = Data[i + 1].second - (Data[i + 1].first - Data[i].first) - NeededVodka;
		}
	}
	if (Data[Data.size() - 1].second >= middle)
	{
		return true;
	}
	return false;
}

int findOptimalPartyes(vector<pair<long long, long long> > Data)
{
	long long l, r, mid, vodkaSum = 1;
	l = 1;
	for (size_t i = 0; i < Data.size(); i++)
	{
		vodkaSum += Data[i].second;
	}

	r = vodkaSum / Data.size();

	int optimalVodka = r;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (specialFunck(Data, mid))
		{
			optimalVodka = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return optimalVodka;
}

int mainZZ()
{
	vector<pair<long long, long long> > Data;
	ReadInput(Data);
	printf("%d\n", findOptimalPartyes(Data));
	return 0;
}