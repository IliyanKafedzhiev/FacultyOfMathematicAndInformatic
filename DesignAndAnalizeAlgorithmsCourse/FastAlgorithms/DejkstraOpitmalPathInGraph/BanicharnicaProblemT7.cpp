//#include <queue>
//#include <iostream>
//#include <stdio.h>
//#include <vector>
//#include <deque>
//
//using namespace std;
//
//struct Edge
//{
//	int to;
//	int weight;
//	Edge(int a, int b) :to(a), weight(b)
//	{
//
//	}
//};
//
//class Graph
//{
//public:
//	int Verteces, Edges, Blok, Banicharnica, Magazina;
//	bool* used;
//	vector<vector<Edge> > AdjList;
//	vector<int> Distances;
//	vector<int> Previous;
//	//DFS usefull data
//
//
//	void readGraph()
//	{
//		scanf("%d", &Verteces);
//		scanf("%d", &Edges);
//		scanf("%d", &Blok);
//		scanf("%d", &Banicharnica);
//		scanf("%d", &Magazina);
//
//		used = new bool[Verteces + 1];
//
//		Distances.resize(Verteces + 1);
//		Previous.resize(Verteces + 1);
//
//		for (size_t i = 0; i <= Verteces; i++)
//		{
//			used[i] = false;
//			Distances[i] = 2147483647;
//		}
//		AdjList.resize(Verteces + 1);
//
//		int from, to, weight;
//		for (size_t i = 0; i < Edges; i++)
//		{
//			scanf("%d", &from);
//			scanf("%d", &to);
//			scanf("%d", &weight);
//			AdjList[from].push_back(Edge(to, weight));
//			AdjList[to].push_back(Edge(from, weight));
//		}
//	}
//
//	void Dijkstra(int from, int to)
//	{
//		priority_queue<pair<int, int> > MainQueue; // Distance + Vertex
//		Distances[from] = 0;
//		MainQueue.push(make_pair(0, from));
//		while (!MainQueue.empty())
//		{
//
//			int currentDist = -MainQueue.top().first;
//			int curVertex = MainQueue.top().second; MainQueue.pop();
//
//			if (currentDist > Distances[curVertex])
//			{
//				continue;
//			}
//			if (curVertex == to)
//			{
//				//break;
//			}
//
//			for (size_t i = 0; i < AdjList[curVertex].size(); i++)
//			{
//				int nextV = AdjList[curVertex][i].to;
//				int PathWeight = AdjList[curVertex][i].weight + currentDist;
//				if (PathWeight < Distances[nextV])
//				{
//					Distances[nextV] = PathWeight;
//					MainQueue.push(make_pair(-PathWeight, nextV));
//					Previous[nextV] = curVertex;
//				}
//			}
//		}
//
//	}
//	~Graph()
//	{
//		if (used)
//		{
//			delete [] used;
//		}
//	}
//};
//
//int mainPP()
//{
//	Graph G;
//	int finalWeight = 0;
//	deque<int> path;
//	deque<int> path2;
//	G.readGraph();
//	G.Dijkstra(G.Blok, G.Banicharnica);
//	if (G.Distances[G.Banicharnica] == 2147483647)
//	{
//		printf("%d\n", -1);
//		return 0;
//	}
//	finalWeight += G.Distances[G.Banicharnica];
//
//	path.push_front(G.Banicharnica);
//	while (true)
//	{
//		int parent = G.Previous[path.front()];
//		path.push_front(parent);
//		if (parent == G.Blok)
//		{
//			break;
//		}
//
//	}
//
//
//	for (int i = 0; i < G.Distances.size(); ++i) G.Distances[i] = 2147483647;
//	G.Dijkstra(G.Banicharnica, G.Magazina);
//	if (G.Distances[G.Magazina] == 2147483647)
//	{
//		printf("%d\n", -1);
//		return 0;
//	}
//	finalWeight += G.Distances[G.Magazina];
//	path2.push_front(G.Magazina);
//	while (true)
//	{
//		int parent = G.Previous[path2.front()];
//		if (parent == G.Banicharnica)
//		{
//			break;
//		}
//		path2.push_front(parent);
//	}
//
//	printf("%d\n", finalWeight);
//	while (path.size()){
//		printf("%d ", path.front()); path.pop_front();
//	}
//	while (path2.size()){
//		printf("%d", path2.front()); path2.pop_front();
//		if (path2.size() !=0)
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
//
//	return 0;
//}
//
////5 5 1 3 5
////1 2 1
////1 3 2
////2 4 4
////3 4 4
////4 5 5