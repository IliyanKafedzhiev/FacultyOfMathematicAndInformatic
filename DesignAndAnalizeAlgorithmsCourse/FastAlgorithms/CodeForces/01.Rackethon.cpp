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

int n, m, c, d;
int arr[51];
int res[51];

ll f(ll p)
{
	ll s = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			int mini = n;
			for (size_t k = i; k <= j; k++)
			{
				mini = std::min(mini, arr[k]);
			}
			if (i != j)
			{
				s += mini;
			}
		}
	}
	return s;
}


int mainWWQE()
{
	cin >> n;
	cin >> m;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	ll m1 = 1;

	ll max = 0,s;
	do
	{
		s = f(1);
		if (max < s){
			max = s;
			m1 = 1;
		}
		else if (s == max)
		{
			m1++;
			if (m1 == m)
			{
				memcpy(res, arr, n*sizeof(int));
			}
		}
	} while (std::next_permutation(arr, arr + n));

	for (size_t i = 0; i < n; i++)
	{
		printf("%d", res[i]);
		if (i != n-1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	system("pause");
	return 0;
}