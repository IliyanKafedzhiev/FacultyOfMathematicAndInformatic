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

typedef long long ll;
typedef long double ld;
int DIGITS[1003];//, DIST[105];

int mainWE()
{
	int n;
	cin >> n;
	 
	char a;
	int mind=10;
	int position;
	int occurance = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		DIGITS[i] = a - '0';
		if (mind >= DIGITS[i])
		{
			if (mind==DIGITS[i])
			{
				if (position == i - 1)
				{
					occurance++;
				}
				else
				{
					occurance = 1;

				}
			}

			position = i;
		}
	}

	 
	system("pause");
	return 0;
}