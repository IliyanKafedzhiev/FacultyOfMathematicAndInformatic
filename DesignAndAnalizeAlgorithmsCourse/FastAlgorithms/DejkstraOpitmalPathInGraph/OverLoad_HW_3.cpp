#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Edge
{
	long long to;
	long long weight;
	Edge(long long a, long long b) :to(a), weight(b)
	{

	}
};

struct House
{
	long long x;
	long long y;
};

struct EdgeTo
{
	long long from;
	long long weight;
	EdgeTo(long long from, long long weight) :from(from), weight(weight)
	{
	}

	bool operator < (const EdgeTo& right)const
	{
		return this->weight < right.weight;
	}
};

class GraphS
{
public:
	long long Houses, Cables, Degree, maxY;
	vector<long long> PolynomCoef;
	vector<House> Houseses;
	bool* used;
	vector<vector<Edge> > AdjList;
	vector<long long> Distances;
	vector<long long> Previous;
	//DFS usefull data

	long long find_remainder( long long x)
	{
		int degree = Degree;
		long long remainder = 0;
		long long rem_x = llabs(x) % maxY;
		for (int i = 0; i < PolynomCoef.size(); ++i) {
			long long tmp = 1, co = PolynomCoef[i];

			if (degree % 2 != 0 && x < 0) co *= -1;
			for (int j = 1; j <= degree; ++j)
				tmp = (tmp * rem_x) % (long long) maxY;

			long long coef_rem = llabs(co) % (long long) maxY;
			tmp = (tmp * coef_rem) % (long long) maxY;
			if (co < 0) tmp *= -1;
			remainder += tmp;
			--degree;
		}

		int result = remainder % maxY;

		return result < 0 ? result + maxY : result;
	}

	long long f(long long x)
	{
		long long result = 0;
		long long Degreep = Degree;
		for (long long i = 0; i <= Degree; i++)
		{
			result += PolynomCoef[i] * (pow(x, Degreep--));
		}
		return result;
	}

	void readGraphS()
	{
		scanf("%lld", &Houses);
		scanf("%lld", &Cables);
		scanf("%lld", &Degree);
		scanf("%lld", &maxY);
		PolynomCoef.resize(Degree + 1);
		for (long long i = 0; i < PolynomCoef.size(); i++)
		{
			scanf("%lld", &PolynomCoef[i]);
		}
		Houseses.resize(Houses);
		for (long long i = 0; i < Houseses.size(); i++)
		{
			scanf("%lld", &Houseses[i].x);
			Houseses[i].y = find_remainder(Houseses[i].x);
		}
		used = new bool[Houses];

		Distances.resize(Houses);
		Previous.resize(Houses);

		for (long long i = 0; i < Houses; i++)
		{
			used[i] = false;
			Distances[i] = 9223372036854775807;
		}
		AdjList.resize(Houses);

		long long from, to, weight, xx, yy;
		for (long long i = 0; i < Cables; i++)
		{
			scanf("%lld", &from);
			scanf("%lld", &to);
			xx = llabs(Houseses[from].x - Houseses[to].x);
			yy = llabs(Houseses[from].y - Houseses[to].y);

			weight = xx + yy;
			this->AdjList[from].push_back(Edge(to, weight));
			this->AdjList[to].push_back(Edge(from, weight));
		}
	}

	void Dijkstra(long long from, long long to)
	{
		priority_queue<EdgeTo> MainQueue; // Distance + Vertex
		Distances[from] = 0;
		MainQueue.push(EdgeTo(from, Distances[from]));
		while (!MainQueue.empty())
		{

			long long currentDist = -MainQueue.top().weight;
			long long curVertex = MainQueue.top().from; MainQueue.pop();

			if (currentDist > Distances[curVertex])
			{
				continue;
			}
			if (curVertex == to)
			{
				//break;
			}

			for (long long i = 0; i < AdjList[curVertex].size(); i++)
			{
				long long nextV = AdjList[curVertex][i].to;
				long long PathWeight = AdjList[curVertex][i].weight + currentDist;
				if (PathWeight < Distances[nextV])
				{
					Distances[nextV] = PathWeight;
					MainQueue.push(EdgeTo(nextV, -PathWeight));
					Previous[nextV] = curVertex;
				}
			}
		}

	}

	~GraphS()
	{
		if (used)
		{
			delete [] used;
		}
	}
};

int main()
{
	
	GraphS G;
	G.readGraphS();
	G.Dijkstra(0, 9223372036854775807);
	for (long long i = 0; i < G.Distances.size(); i++)
	{
		if (G.Distances[i] == 9223372036854775807)
		{
			if (i == G.Distances.size() - 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("-1 ");
			}
			
		}
		else{
			if (i == G.Distances.size() - 1)
			{
				printf("%lld\n", G.Distances[i]);
			}
			else
			{
				printf("%lld ", G.Distances[i]);
			}
		}
	}
	return 0;
}
