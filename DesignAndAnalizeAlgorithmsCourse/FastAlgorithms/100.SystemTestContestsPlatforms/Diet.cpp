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

int mainQWE()
{
	//freopen("diet.in", "r", stdin);
	//freopen("diet.out", "w", stdout);
	int n;
	cin >> n;
	ll ways = 1;
	vector<int> constr(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (size_t j = 0; j < k; j++)
		{
			int z;
			cin >> z;
			constr[z-1] ++;
		}
	}
	int w = n;
	for (size_t k = 0; k < n; k++)
	{
		ways *= w-constr[k];
		w--;
	}
	cout << ways << endl;
	system("pause");
	return 0;
}