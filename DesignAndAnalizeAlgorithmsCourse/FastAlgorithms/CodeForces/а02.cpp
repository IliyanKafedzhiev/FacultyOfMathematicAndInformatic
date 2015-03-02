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
	/*
	Ax + By + C - line
	(A,B) -perpendicular vector
	(-B,A) -paralel vector
	*/
	struct Point
	{
		ld x, y;
		bool real;
		Point(ld _x = 0, ld _y = 0) :x(_x), y(_y), real(true){}
		ld dist2(const Point& p){ return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y); }
		ld dist(const Point& p){ return sqrt(dist2(p)); }
	};
	static ld area(const Point& a, const Point& b, const Point& c)
	{
		return (a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x)*0.5;
	}

	static ld areaFull(std::vector<Point>& figure)
	{
		ld ar = 0;
		for (int i = 0; i < figure.size() - 2; i++)
		{
			ar += area(figure[i], figure[i + 1], figure[figure.size()]);
		}

		return ar;
	}

	struct Line{
		ld a, b, c;
		Line(ld _a = 0, ld _b = 0, ld _c = 0) :a(_a), b(_b), c(_c){}
		Line(const Point& A, const Point& B)
		{
			a = A.y - B.y;

			b = B.x - A.x;

			c = A.x*B.y - A.y*B.x;
		}
	};

	struct Vector
	{
		ld vx, vy;
		Vector(ld _vx = 0, ld _vy = 0) :vx(_vx), vy(_vy){}
		ld len(){ return sqrt(vx*vx + vy*vy); }
		Vector(const Point&A, const Point&B)
		{
			vx = B.x - A.x;
			vy = B.y - A.y;
		}
		static ld scalar(const Vector&v, const Vector&u) // v scalar u = 0 if vectors are perpendicularic
		{
			return v.vx*u.vx + v.vy*u.vy;
		}
		Vector operator *(ld k){ Vector res(vx*k, vy*k); return res; }
		static ld crossProduct(const Vector&a, const Vector&b) // a cross-product b = 0 if vectors are parrallel
		{
			return a.vx*b.vy - a.vy*b.vx;
		}
	};

	bool areParalelLines(const Line& l1, const Line& l2)
	{
		return nula(Vector::crossProduct(Vector(l1.a, l1.b), Vector(l2.a, l2.b)));
	}
}

using namespace Geometry;

int mainÂÅß()
{
	int n, x1 = 0, y1 = 1, shoots = 0;
	cin >> n;
	cin >> x1;
	cin >> y1;
	Point arm(x1, y1);
	vector<Point> distinctPoints;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	while (n>0)
	{
		cin >> x1;
		cin >> y1;
		Point animal(x1, y1);
		if (distinctPoints.size() > 0)
		{
			bool hasNula = false;
			for (size_t i = 0; i < distinctPoints.size(); i++)
			{
				if (nula(area(distinctPoints[i],animal,arm)))
				{
					hasNula = true;
				}
			}
			if (!hasNula)
			{
				shoots++;
				distinctPoints.push_back(animal);
			}
		}
		else
		{
			distinctPoints.push_back(Point(x1, y1));
			shoots++;
		}
		n--;
	}

	cout << shoots << endl;
	//system("pause");
	return 0;
}
