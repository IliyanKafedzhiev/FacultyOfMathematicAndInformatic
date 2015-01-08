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

int Junior()
{
	freopen("basek.in", "r", stdin);
	freopen("basek.out", "w", stdout);
	ll k,n,m;
	cin >> k;
	cin >> n;
	cin >> m;
	
	ll Nval = 0;
	ll Mval = 0;
	int step = 0,num;
	while (m >0)
	{
		num = m % 10;
		m /= 10;
		Mval += num * std::pow(k, step);
		step++;
	}
	step = 0;
	while (n >0)
	{
		num = n % 10;
		n /= 10;
		Nval += num * std::pow(k, step);
		step++;
	}
	if (Nval == Mval)
	{
		cout << 0 << endl;
	}
	else if (Nval > Mval)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;
	}
	//system("pause");
	return 0;
}