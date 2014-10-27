#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

struct Edge
{
	int to;
	int weight;
	Edge(int a, int b) :to(a), weight(b)
	{

	}
};

class GraphXX
{
public:
	bool* used;
	int* dist;
	vector<vector<Edge> > AdjList;
	void readGraphXX()
	{
		int Verteces;
		scanf("%d", &Verteces);

		used = new bool[Verteces + 1];
		dist = new int[Verteces + 1];
		for (size_t i = 0; i <= Verteces; i++)
		{
			used[i] = false;
		}
		AdjList.resize(Verteces + 1);

		int from, to ,weight;
		for (size_t i = 0; i < Verteces-1; i++)
		{
			scanf("%d", &from);
			scanf("%d", &to);
			scanf("%d", &weight);
			AdjList[from].push_back(Edge(to, weight));
			AdjList[to].push_back(Edge(from, weight));
		}
	}
	void dfs(int vertex, int& lenght, int& farrestVertex,int maxPath)
	{
		used[vertex] = true;
		// here we can use our Vertex;
		for (size_t i = 0; i < AdjList[vertex].size(); i++)
		{
			if (!used[AdjList[vertex][i].to])
			{
				int currentmaxPath = maxPath + AdjList[vertex][i].weight;
				
				if (currentmaxPath > lenght)
				{
					lenght = currentmaxPath;
					farrestVertex = AdjList[vertex][i].to;
				}

				this->dfs(AdjList[vertex][i].to, lenght, farrestVertex, currentmaxPath);
			}
		}
	}
	
	~GraphXX()
	{
		if (used)
		{
			delete[] used;
		}
		if (dist)
		{
			delete [] dist;
		}
	}
};

void findDiameter()
{
	GraphXX g;
	g.readGraphXX();
	int lenght = 0;
	int z = 0;
	int largestV = 0;
	g.dfs(1, lenght, largestV,0);
	lenght = 0;
	for (size_t i = 0; i < g.AdjList.size(); i++)
	{
		g.used[i] = false;
	}
	g.dfs(largestV, lenght, z,0);
	printf("%d\n", lenght);
}


