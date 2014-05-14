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
//class GraphS
//{
//public:
//	int Verteces, Edges, Sofia, Kavarna, Magazina;
//	bool* used;
//	vector<vector<Edge> > AdjList;
//	vector<int> Distances;
//	vector<int> Previous;
//	//DFS usefull data
//
//
//	void readGraphS()
//	{
//		scanf("%d", &Verteces);
//		scanf("%d", &Edges);
//		Sofia = 1;
//		Kavarna = Verteces;
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
//			//AdjList[to].push_back(Edge(from, weight));
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
//	~GraphS()
//	{
//		if (used)
//		{
//			delete[] used;
//		}
//	}
//};
//
//int main()
//{
//	int tests;
//	scanf("%d", &tests);
//	while (tests > 0)
//	{
//		GraphS G;
//		G.readGraphS();
//		G.Dijkstra(G.Sofia, G.Kavarna);
//		if (G.Distances[G.Kavarna] == 2147483647)
//		{
//			printf("%d\n", -1);
//		}
//		else
//		{
//			printf("%d\n", G.Distances[G.Kavarna]);
//		}
//		tests--;
//	}
//	return 0;
//}
//
////5 5 1 3 5
////1 2 1
////1 3 2
////2 4 4
////3 4 4
////4 5 5