#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
typedef long double ld;

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

ll power(ll a, ll n, ll p)
{
	if (a == 0)
	{
		return 0;
	}

	ll res = 1ll;

	while (n > 0)
	{
		if ((n % 2) == 1)
		{
			res = (a * res) % p;
			//n -= 1;
		}
		a = (a*a)%p;
		n /= 2;
	}
	return res;
}

//int main()
//{
//	ll n, m, y,tests;
//	cin >> tests;
//	vector <ll> res;
//
//	for (ll j = 0; j < tests; j++)
//	{
//		cin >> n;
//		cin >> m;
//		cin >> y;
//		bool exists = false;
//		for (ll i = 0; i < m; i++)
//		{
//			if (y == power(i, n, m))
//			{
//				res.push_back(i);
//			}
//		}
//		if (!res.size())
//		{
//			cout << -1 << endl;
//		}
//		else
//
//		{
//			for (size_t i = 0; i < res.size(); i++)
//			{
//				if (i != res.size() - 1)
//				{
//					cout << res[i] << " ";
//				}
//				else
//				{
//					cout << res[i] << endl;
//				}
//			}
//		}
//		res.clear();
//	}
//	system("pause");
//	return 0;
//}