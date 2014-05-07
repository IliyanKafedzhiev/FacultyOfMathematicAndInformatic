#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

struct Edge
{
	int to;
	int weight;
	Edge(int a, int b) :to(a), weight(b)
	{

	}
};

struct House
{
	long long x;
	long long y;
};

class GraphS
{
public:
	long long Houses, Cables, Degree, maxY, Magazina;
	vector<long long> PolynomCoef;
	vector<House> Houseses;
	bool* used;
	vector<vector<Edge> > AdjList;
	vector<int> Distances;
	vector<int> Previous;
	//DFS usefull data

	long long f(long long x)
	{
		long long result = PolynomCoef[Degree];
		long long Degreep = Degree;
		for (size_t i = 0; i < Degree; i++)
		{
			result += PolynomCoef[i] * pow(x, Degreep--);
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
		for (size_t i = 0; i < PolynomCoef.size(); i++)
		{
			scanf("%lld", &PolynomCoef[i]);
		}
		Houseses.resize(Houses + 1);
		for (size_t i = 1; i < Houseses.size(); i++)
		{
			scanf("%lld", &Houseses[i].x);
			Houseses[i].y = f(Houseses[i].x) % maxY;
		}
		used = new bool[Houses + 1];

		Distances.resize(Houses + 1);
		Previous.resize(Houses + 1);

		for (size_t i = 0; i <= Houses; i++)
		{
			used[i] = false;
			Distances[i] = 2147483647;
		}
		AdjList.resize(Houses + 1);

		long long from, to, weight;
		for (size_t i = 0; i < Cables; i++)
		{
			scanf("%lld", &from);
			scanf("%lld", &to);
			weight = (Houseses[from].x - Houseses[to].x < 0) ? -(Houseses[from].x - Houseses[to].x) : (Houseses[from].x - Houseses[to].x) + ((Houseses[from].y - Houseses[to].y) < 0) ? -(Houseses[from].y - Houseses[to].y) : (Houseses[from].y - Houseses[to].y);
			AdjList[from].push_back(Edge(to, weight));
			AdjList[to].push_back(Edge(from, weight));
		}
	}

	void Dijkstra(int from, int to)
	{
		priority_queue<pair<int, int> > MainQueue; // Distance + Vertex
		Distances[from] = 0;
		MainQueue.push(make_pair(0, from));
		while (!MainQueue.empty())
		{

			int currentDist = -MainQueue.top().first;
			int curVertex = MainQueue.top().second; MainQueue.pop();

			if (currentDist > Distances[curVertex])
			{
				continue;
			}
			if (curVertex == to)
			{
				//break;
			}

			for (size_t i = 0; i < AdjList[curVertex].size(); i++)
			{
				int nextV = AdjList[curVertex][i].to;
				int PathWeight = AdjList[curVertex][i].weight + currentDist;
				if (PathWeight < Distances[nextV])
				{
					Distances[nextV] = PathWeight;
					MainQueue.push(make_pair(-PathWeight, nextV));
					Previous[nextV] = curVertex;
				}
			}
		}

	}
	~GraphS()
	{
		if (used)
		{
			delete[] used;
		}
	}
};

int main()
{
	int tests;
	scanf("%d", &tests);
	while (tests > 0)
	{
		GraphS G;
		G.readGraphS();
		G.Dijkstra(G.Degree, G.maxY);
		if (G.Distances[G.maxY] == 2147483647)
		{
			printf("%d\n", -1);
		}
		else
		{
			printf("%d\n", G.Distances[G.maxY]);
		}
		tests--;
	}
	return 0;
}

//5 5 1 3 5
//1 2 1
//1 3 2
//2 4 4
//3 4 4
//4 5 5