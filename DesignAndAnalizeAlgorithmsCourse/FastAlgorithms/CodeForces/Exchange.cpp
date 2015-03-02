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
#include <stack>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;


int mainWQE()
{
	ll n;
	cin >> n;
	vector<int> digits;
	vector<pair<int, int > > evens;
	while (n > 0)
	{
		digits.push_back(n % 10);
		n /= 10;
	}

	for (int i = digits.size()-1; i > -1; i--)
	{
		if (digits[i] % 2 == 0)
		{
			evens.push_back(pair<int,int>(digits[i],i));
		}
	}
	if (!evens.size() || (evens.size() == digits.size()))
	{
		cout << "-1";
		//system("pause");
		return 0;
	}
	else
	{
		for (int i = 0; i < evens.size(); i++)
		{
			if (digits[0] > evens[i].first)
			{
				digits[evens[i].second] = digits[0];
				digits[0] = evens[i].first;
				break;
			}
			else if (i == evens.size() - 1)
			{
				digits[evens[i].second] = digits[0];
				digits[0] = evens[i].first;
				break;
			}
		}
	}
	for (int i = digits.size
		()-1; i > -1
		; i--)
	{
		printf("%d", digits[i]);
	}
	//printf("\n");

	//system("pause");
	return 0;
}