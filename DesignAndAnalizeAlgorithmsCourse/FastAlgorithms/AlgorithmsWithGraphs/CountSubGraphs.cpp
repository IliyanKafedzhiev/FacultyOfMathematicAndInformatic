#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

struct Edge
{
	int to;
	int weight;
	Edge(int a, int b) :to(a), weight(b)
	{

	}
};

class Graph
{
public:
	bool* used;
	vector<vector<Edge> > AdjList;
	void readGraph()
	{
		int Verteces,Edges;
		scanf("%d", &Verteces);
		scanf("%d", &Edges);

		used = new bool[Verteces+1];
		for (size_t i = 0; i <= Verteces; i++)
		{
			used[i] = false;
		}
		AdjList.resize(Verteces+1);

		int from, to;
		for (size_t i = 0; i < Edges; i++)
		{
			scanf("%d", &from);
			scanf("%d", &to);
			AdjList[from].push_back(Edge(to,0));
			AdjList[to].push_back(Edge(from, 0));
		}
	}
	void dfs(int vertex)
	{
		used[vertex] = true;
		// here we can use our Vertex;
		for (size_t i = 0; i < AdjList[vertex].size(); i++)
		{
			if (!used[ AdjList[ vertex ][ i ].to ])
			{
				this->dfs(AdjList[ vertex ][ i ].to);
			}
		}
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
	~Graph()
	{
		if (used)
		{
			delete [] used;
		}
	}
};


void FindSubGraphs(){
	Graph g;
	g.readGraph();
	int subGraphs = 0;
	for (size_t i = 1; i < g.AdjList.size(); i++)
	{
		if (!g.used[i])
		{
			++subGraphs;
			g.dfs(i);
		}
	}
	printf("%d\n", subGraphs);
}
