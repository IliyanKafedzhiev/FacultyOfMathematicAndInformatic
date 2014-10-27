#include <iostream>
#include <vector>
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
	//DFS usefull data

	vector<char> Color;
	vector<int> Tree;
	vector<int> TimeIn;
	vector<int> TimeOut;
	int Time;

	/* data aboud BFS for application*/
	vector<char> Colors;
	vector<int> Distances;
	vector<int> TreeBFS;

	void readGraph()
	{
		int Verteces, Edges;
		scanf("%d", &Verteces);
		scanf("%d", &Edges);

		used = new bool[Verteces + 1];
		Color.resize(Verteces + 1);
		Tree.resize(Verteces + 1);
		TimeIn.resize(Verteces + 1);
		TimeOut.resize(Verteces + 1);

		for (size_t i = 0; i <= Verteces; i++)
		{
			used[i] = false;
		}
		AdjList.resize(Verteces + 1);

		int from, to;
		for (size_t i = 0; i < Edges; i++)
		{
			scanf("%d", &from);
			scanf("%d", &to);
			AdjList[from].push_back(Edge(to, 0));
			AdjList[to].push_back(Edge(from, 0));
		}
	}

	void DFSGeneral()
	{
		for (size_t i = 1; i < AdjList.size(); i++)
		{
			Color[i] = 'W';
		}
		Time = 0;
		for (size_t i = 1; i < Color.size(); i++)
		{
			if (Color[i] == 'W')
			{
				dfs(i);
			}
		}
	}
	void dfs(int vertex)
	{
		Time++;
		used[vertex] = true;
		Color[vertex] = 'G';
		TimeIn[vertex] = Time;
		// here we can use our Vertex;
		for (size_t i = 0; i < AdjList[vertex].size(); i++)
		{
			/* There are Four types of edges
				*First is Branch of the Tree
				*Second is Back edge (create a cycle)
				*Third is Forward edge (when the edge visit an Already Visited Component It's not a cycle)
				*Fourth is Edge away (when the edge visit an Already visited Connected Component not connected with current component)
			*/
			if (!used[AdjList[vertex][i].to] && Color[AdjList[vertex][i].to] == 'W')
			{
				Tree[AdjList[vertex][i].to] = vertex;
				this->dfs(AdjList[vertex][i].to);
			}
			if (Color[AdjList[vertex][i].to] == 'G') //Its Cycle
			{

			}
		}
		Time++;
		Color[vertex] = 'B';
		TimeOut[vertex] = Time;
	}
	void bfs(int vertex)
	{
		Colors.resize(AdjList.size());
		Distances.resize(AdjList.size());
		TreeBFS.resize(AdjList.size());

		for (size_t i = 1; i < AdjList.size(); i++)
		{
			Colors[i] = 'W';
			Distances[i] = 2, 147, 483, 647;
			TreeBFS[i] = 0;
		}

		queue<int> q;
		q.push(vertex);
		used[vertex] = true;
		Colors[vertex] = 'G';
		Distances[vertex] = 0;


		while (!q.empty())
		{
			int cur = q.front();
			//here we can use our vertex
			q.pop();
			for (size_t i = 0; i < AdjList[cur].size(); i++)
			{
				if (!used[AdjList[cur][i].to] && Colors[AdjList[cur][i].to] == 'W')
				{
					Distances[AdjList[cur][i].to] = Distances[cur] + 1;
					TreeBFS[AdjList[cur][i].to] = cur;
					Colors[AdjList[cur][i].to] = 'G';
					used[AdjList[cur][i].to] = true;
					q.push(AdjList[cur][i].to);
				}
			}
			Colors[cur] = 'B';
		}
	}
	~Graph()
	{
		if (used)
		{
			delete[] used;
		}
	}
};




