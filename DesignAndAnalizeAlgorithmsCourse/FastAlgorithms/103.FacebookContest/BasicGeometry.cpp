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
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-12;
bool nula(ld x){ return x < eps && x > -eps; }
int sign(ld x){ if (x < -eps)return-1; else if (x > eps)return 1; else return 0; }
namespace Geometry
{
struct Point{
	ld x, y;
	bool real;
	Point(ld _x = 0, ld _y = 0) :x(_x), y(_y), real(true){}
	ld dist2(const Point& p){ return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y); }
	ld dist(const Point& p){ return sqrt(dist2(p)); }
	static ld area(const Point& a, const Point& b, const Point& c)
	{
		return (a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x)*0.5;
	}
};
}
using namespace Geometry;
int main()
{
	Point a(0, 0), b(5, 0), c(0, 5);
	ld area = Point::area(a, b, c);
	assert(area == 12.5);

	return 0;
}
