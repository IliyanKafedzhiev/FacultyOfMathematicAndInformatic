#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

void ReadInput(vector<int>& Array, vector<pair<int, int> >& Questions)
{
	int ArrayLenght;
	scanf("%d", &ArrayLenght);

	Array.resize(ArrayLenght);
	for (size_t i = 0; i < ArrayLenght; i++)
	{
		scanf("%d", &Array[i]);
	}

	int QuestionsLenght;
	scanf("%d", &QuestionsLenght);

	Questions.resize(QuestionsLenght);
	for (size_t i = 0; i < QuestionsLenght; i++)
	{
		scanf("%d", &Questions[i].first);
		scanf("%d", &Questions[i].second);
	}
}

int indexOfLowerBound(vector<int>& Array, int lowwerBoud)
{
	int l = 0;
	int r = Array.size() - 1;
	int mid;

	while (r > l)
	{
		mid = (r + l) / 2;
		if (lowwerBoud >= Array[mid])
		{
			if (lowwerBoud == Array[mid])
			{
				l = mid - 1;
				return l;
			}
			else if (lowwerBoud == Array[mid + 1])
			{
				return mid;
			}
			l = mid + 1;
			if (l == Array.size() - 1)
			{
				l = Array.size();
				return l;
			}
		}
		else
		{
			r = mid - 1;
			if (r == 0 || mid == 0)
			{
				return -1;
			}
		}
	}
	return l;
}

int indexOfUpperBound(vector<int>& Array, int upperBound)
{
	int l = 0;
	int r = Array.size() - 1;
	int mid;

	while (r >= l)
	{
		if (l == r)
		{
			if (Array[l] <= upperBound)
			{
				return l + 1;
			}
			else
			{
				return l;
			}
		}
		mid = (r + l) / 2;
		if (upperBound >= Array[mid])
		{
			if (upperBound == Array[mid])
			{
				return mid + 1;
			}
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}

	}
	return r;
}

void MaxSubRange(vector<int>& Array, vector<pair<int, int> >& Questions)
{
	for (size_t i = 0; i < Questions.size(); i++)
	{
		int down = indexOfLowerBound(Array, Questions[i].first)+1;
		int up = indexOfUpperBound(Array, Questions[i].second);
		/*int down = lower_bound(Array.begin(), Array.end(), Questions[i].first) - Array.begin();
		int up = upper_bound(Array.begin(), Array.end(), Questions[i].second) - Array.begin();*/
		int currentRange = up - down;
		if (currentRange < 0)
		{
			currentRange = 0;
		}
		printf("%d\n", currentRange);
	}
}

void SubRangeProblem()
{
	vector<int> Array;
	vector<pair<int, int> >Questions;
	ReadInput(Array, Questions);
	MaxSubRange(Array, Questions);
}


//5
//1 2 3 4 5
//5
//-5 0
//7 12
//1 5
//-2 2
//4 7