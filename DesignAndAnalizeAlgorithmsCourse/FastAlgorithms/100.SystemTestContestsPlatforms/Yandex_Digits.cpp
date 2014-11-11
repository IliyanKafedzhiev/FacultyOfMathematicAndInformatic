#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

int CountDigits(int x)
{
	int res = 0,lasDig;
	while (x > 0)
	{
		lasDig = x % 10;
		x /= 10;
		res += lasDig;
	}
	return res;
}

int mainProblem()
{
	int n;
	cin >> n;

	vector<int> numbers;
	vector<int> sums;
	int i = 1;
	int minSum = 1;

	for (size_t j = 1; j < n; j++)
	{
		numbers.clear();
		for (size_t k = j; k < INT_MAX; k++)
		{
			if (numbers.size() == n)
			{
				int cSum = 0;
				for (size_t z = 0; z < n; z++)
				{
					cSum += numbers[z];
				}
				sums.push_back(cSum);
			}
		}
	}
	return 0;
}