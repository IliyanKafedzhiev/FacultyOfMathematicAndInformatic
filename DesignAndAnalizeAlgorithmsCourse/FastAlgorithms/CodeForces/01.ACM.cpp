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

ld mx[11][11];

int mainWRT()
{
	int n;
	
	scanf("%d", &n);
	for (short i = 1; i <= n; i++)
	{
		mx[1][i] = 1;
		mx[i][1] = 1;
	}
	for (short i = 2; i <= n; i++)
	{
		for (short j = 2; j <= n; j++)
		{
			mx[i][j] = mx[i - 1][j] + mx[i][j - 1];
		}
	}
	cout << mx[n][n] << endl;
	//system("pause");
	return 0;
}