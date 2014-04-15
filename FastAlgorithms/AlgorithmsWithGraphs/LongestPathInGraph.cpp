#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <set>

using namespace std;

struct Edge
{
	int to;
	int weight;
	Edge(int a, int b) :to(a), weight(b)
	{

	}
};

class Graphz
{
public:
	bool* used;
	vector<vector<Edge> > AdjList;
	vector<int> topologicalSortedVeteces;
	vector<long long > distance;
	void readGraph()
	{
		int Verteces, Edges;
		scanf("%d", &Verteces);
		scanf("%d", &Edges);

		used = new bool[Verteces + 1];
		for (size_t i = 0; i <= Verteces; i++)
		{
			used[i] = false;
		}
		AdjList.resize(Verteces + 1);

		int from, to, weight;
		for (size_t i = 0; i < Edges; i++)
		{
			scanf("%d", &from);
			scanf("%d", &to);
			scanf("%d", &weight);
			AdjList[from].push_back(Edge(to, weight));
		}
	}
	void dfs(int vertex)
	{
		used[vertex] = true;
		// here we can use our Vertex;
		for (size_t i = 0; i < AdjList[vertex].size(); i++)
		{
			if (!used[AdjList[vertex][i].to])
			{
				this->dfs(AdjList[vertex][i].to);
			}
		}
		this->topologicalSortedVeteces.push_back(vertex);
	}
	void bfs(int vertex)
	{
		queue<int> q;
		q.push(vertex);
		used[vertex] = true;

		while (!q.empty())
		{
			int cur = q.front();
			//here we can use our vertex
			q.pop();
			for (size_t i = 0; i < AdjList[cur].size(); i++)
			{
				if (!used[AdjList[cur][i].to])
				{
					used[AdjList[cur][i].to] = true;
					q.push(AdjList[cur][i].to);
				}
			}

		}
	}
	bool AllVerticisAreSorted()
	{
		for (size_t i = 1; i < AdjList.size(); i++)
		{
			if (!this->used[i])
			{
				return false;
			}
		}
		return true;
	}
	void topologicalSortWithoutRecursion()
	{
		vector<vector<bool > > AdjMatrix(this->AdjList.size());
		for (size_t i = 0; i < AdjMatrix.size(); i++)
		{
			AdjMatrix[i].resize(AdjMatrix.size());
			for (size_t z = 0; z < AdjMatrix.size(); z++)
			{
				AdjMatrix[i][z] = false;
			}
			for (size_t k = 0; k < AdjList[i].size(); k++)
			{
				AdjMatrix[i][AdjList[i][k].to] = true;
			}
		}


		set<int> NodesWithoutIncomingEdges;



		for (size_t i = 1; i < AdjMatrix.size(); i++)
		{
			bool hasIncomeEdje = false;
			for (size_t z = 1; z < AdjMatrix.size(); z++)
			{
				if (AdjMatrix[z][i] == true)
				{
					hasIncomeEdje = true;
				}
			}
			if (!hasIncomeEdje)
			{
				NodesWithoutIncomingEdges.insert(i);
			}
		}

		while (!NodesWithoutIncomingEdges.empty())
		{
			int a = *NodesWithoutIncomingEdges.begin();
			NodesWithoutIncomingEdges.erase(NodesWithoutIncomingEdges.begin());
			this->topologicalSortedVeteces.push_back(a);

			for (size_t i = 1; i < AdjMatrix.size(); i++)
			{
				if (AdjMatrix[a][i] == true)
				{
					AdjMatrix[a][i] = false;

					bool hasIncomeEdje = false;
					for (size_t z = 1; z < AdjMatrix.size(); z++)
					{
						if (AdjMatrix[z][i] == true)
						{
							hasIncomeEdje = true;
						}
					}
					if (!hasIncomeEdje)
					{
						NodesWithoutIncomingEdges.insert(i);
					}
				}
			}
		}
	}
	void topologicalSort()
	{
		dfs(1);
		reverse<vector<int>::iterator>(topologicalSortedVeteces.begin(), topologicalSortedVeteces.end());
	}
	~Graphz()
	{
		if (used)
		{
			delete [] used;
		}
	}
};

void LongestPath()
{
	long long LongestPath = 0;

	Graphz g;

	g.readGraph();
	g.topologicalSort();

	g.distance.resize(g.AdjList.size());

	for (size_t i = 0; i < g.distance.size(); i++)
	{
		g.distance[i] = 0;
	}

	for (size_t i = 0; i < g.topologicalSortedVeteces.size() - 1; i++)
	{
		for (size_t k = 0; k < g.AdjList[g.topologicalSortedVeteces[i]].size(); k++)
		{
			long long maxpaths = g.distance[g.topologicalSortedVeteces[i]] + g.AdjList[g.topologicalSortedVeteces[i]][k].weight;

			if (maxpaths > g.distance[g.AdjList[g.topologicalSortedVeteces[i]][k].to])
			{
				g.distance[g.AdjList[g.topologicalSortedVeteces[i]][k].to] = maxpaths;
				if (maxpaths > LongestPath)
				{
					LongestPath = maxpaths;
				}
			}
		}
	}
	//printf("%llu\n", g.distance[g.topologicalSortedVeteces[g.topologicalSortedVeteces.size() - 1]]);
	printf("%llu\n", LongestPath);
}

