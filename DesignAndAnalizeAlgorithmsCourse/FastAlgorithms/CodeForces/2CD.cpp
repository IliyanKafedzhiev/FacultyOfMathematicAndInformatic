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


int mainWWQ()
{
	int r,x, y,tx,ty;
	cin >> r;
	cin >> x;
	cin >> y;
	cin >> tx;
	cin >> ty;
	Point c(x, y);
	Point t(tx, ty);
	ld dist = t.dist(c);
	if (dist == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int res = dist / r;
	int newRes = res / 2;
	if (dist > r*res)
	{
		newRes++;
	}
	cout << newRes << endl;
	//system("pause");
	return 0;
}