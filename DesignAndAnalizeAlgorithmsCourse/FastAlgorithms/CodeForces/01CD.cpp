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


int maiWEn()
{
	int n , k;
	cin >> n;
	cin >> k;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	
	int m = 0;

	for (int i = 0; i < v.size() && k>0; i++)
	{
		if (k>=v[i].first)
		{
			k -= v[i].first;
			m++;
		}
	}
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		if (m - 1 == i)
		{
			cout << v[i].second << endl;
		}
		else
			cout << v[i].second << " ";
	}
	

	//system("pause");
	return 0;
}