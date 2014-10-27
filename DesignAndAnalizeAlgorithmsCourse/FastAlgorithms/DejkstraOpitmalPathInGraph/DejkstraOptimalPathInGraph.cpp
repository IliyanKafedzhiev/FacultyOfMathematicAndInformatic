//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//struct Vertex{
//	int id;
//	int distance;
//};
//
//class Graph
//{
//public:
//	std::vector<Vertex> vertices;
//	std::vector < std::vector<std::pair<int, int> > > weightedEdgesAdj;
//	struct MinComparator
//	{
//		bool operator()(Vertex*& first, Vertex*& secont)
//		{
//			if ((*first).distance < (*secont).distance)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//	};
//	void FindShortestPath(int fromVertex, int toVertex)
//	{
//		stack<Vertex> bestPath;
//		std::vector<Vertex*> previous(this->vertices.size());
//		for (size_t i = 0; i < previous.size(); i++)
//		{
//			previous[i] = NULL;
//		}
//
//		this->vertices[fromVertex].distance = 0;
//
//		std::priority_queue<Vertex*, vector<Vertex*>, MinComparator> Q;
//
//		for (size_t i = 0; i < this->vertices.size(); i++)
//		{
//			Q.push(&this->vertices[i]);
//		}
//		while (Q.size() > 0)
//		{
//			Vertex* u = Q.top();
//			Q.pop();
//
//			if ((*u).id == toVertex)
//			{
//				Vertex target = this->vertices[toVertex];
//
//				while (previous[target.id] != NULL)
//				{
//					bestPath.push(target); 
//					target = *previous[target.id];
//				}
//			}
//
//			if ((*u).distance == INT_MAX)
//			{
//				break;
//			}
//
//			for (size_t i = 0; i < this->weightedEdgesAdj[(*u).id].size(); i++)
//			{
//				int alt = (*u).distance + this->weightedEdgesAdj[(*u).id][i].second;
//				if (alt < this->vertices[this->weightedEdgesAdj[(*u).id][i].first].distance)
//				{
//					int id = weightedEdgesAdj[(*u).id][i].first;
//					this->vertices[id].distance = INT_MAX;
//					previous[id] = u;
//					vector<Vertex*> temp;
//					while (!Q.empty())
//					{
//						temp.push_back(Q.top());
//						Q.pop();
//					}
//					for (size_t i = 0; i < temp.size(); i++)
//					{
//						Q.push(temp[i]);
//					}
//
//				}
//			}
//		}
//		std::cout << fromVertex << " -> ";
//		while (!bestPath.empty())
//		{
//			Vertex current = bestPath.top();
//			bestPath.pop();
//			std::cout << current.id;
//			if (!bestPath.empty())
//			{
//				std::cout << " -> ";
//			}
//		}
//	}
//	bool Graph::readDataFromConsole()
//	{
//
//		int vertices;
//		cin >> vertices;
//		this->vertices.resize(vertices);
//		for (size_t i = 0; i < vertices; i++)
//		{
//			this->vertices[i].id = i;
//			this->vertices[i].distance = INT_MAX;
//		}
//		this->weightedEdgesAdj.resize(vertices);
//		cin >> vertices;
//
//		for (size_t i = 0; i < vertices; i++)
//		{
//			int from;
//			cin >> from;
//			int to;
//			cin >> to;
//			int weight;
//			cin >> weight;
//
//			std::pair<int, int> edgeIn(to-1, weight);
//			this->weightedEdgesAdj[from-1].push_back(edgeIn);
//
//			std::pair<int, int> edgeInRev(from-1, weight);
//			this->weightedEdgesAdj[to-1].push_back(edgeInRev);
//
//		}
//		return true;
//	}
//
//};
//
//struct Node
//{
//	int formVertex;
//	int toVertex;
//	int weight;
//	int currentWeight;
//};
//
//void ReadInput(vector<Node>& Paths, int& numOfDifferentObjects)
//{
//	cin >> numOfDifferentObjects;
//
//	int sizeOfVectorPaths;
//	cin >> sizeOfVectorPaths;
//
//	Paths.resize(sizeOfVectorPaths);
//
//	for (size_t i = 0; i < sizeOfVectorPaths; i++)
//	{
//		cin >> Paths[i].formVertex;
//		cin >> Paths[i].toVertex;
//		cin >> Paths[i].weight;
//	}
//}
//
//int LenghtOfOptimalPath(vector<Node>& Paths, int& numOfDifferentObjects)
//{
//	int lenght = -1;
//	if (numOfDifferentObjects < 3)
//	{
//		return lenght;
//	}
//
//	for (size_t i = 1; i <= numOfDifferentObjects; i++)
//	{
//		for (size_t indexPaths = 0; indexPaths < Paths.size(); indexPaths++)
//		{
//			if (Paths[indexPaths].formVertex == i) // we got path form Vertex i 
//			{
//				int target = Paths[indexPaths].toVertex;
//			}
//		}
//	}
//
//	return lenght;
//}
//
//
//int mainWW()
//{
//	Graph veryBigGraph;
//	veryBigGraph.readDataFromConsole();
//	veryBigGraph.FindShortestPath(1, 3);
//	return 0;
//}
//
///*
//5 7
//1 4 1
//1 3 300
//3 1 10
//1 2 16
//2 3 100
//2 5 15
//5 3 20
//*/