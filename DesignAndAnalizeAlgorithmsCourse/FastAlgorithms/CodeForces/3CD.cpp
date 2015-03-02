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

struct Point
{
	ld x, y;
	bool real;
	Point(ld _x = 0, ld _y = 0) :x(_x), y(_y), real(true){}
	ld dist2(const Point& p){ return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y); }
	ld dist(const Point& p){ return sqrt(dist2(p)); }
};

bool mx [1001][1001];
int mainWWE()
{
	int m , n,k;
	cin >> n;
	cin >> m;
	cin >> k;
	int x, y;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		cin >> y;
		mx[x][y] = true;
		bool end = false;
		if ((x-1 >= 1) && (y - 1) >= 1)
		{
			if (mx[x - 1][y - 1] && mx[x - 1][y] && mx[x][y - 1])
			{
				end = true;
			}
		}
		if (x + 1 <= n && y - 1 >= 1)
		{
			if (mx[x + 1][y - 1] && mx[x + 1][y] && mx[x][y - 1])
			{
				end = true;
			}
		}
		if (x+1 <= n && y+1 <= m)
		{
			if (mx[x + 1][y + 1] && mx[x + 1][y] && mx[x][y + 1])
			{
				end = true;
			}
		}
		if (x-1 >=1 && y+1 <=m)
		{
			if (mx[x - 1][y + 1] && mx[x - 1][y] && mx[x][y + 1])
			{
				end = true;
			}
		}

		if (end)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;

	return 0;
}