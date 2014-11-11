#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
typedef long double ld;

#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>

//using namespace std;
//
//class UnionFind
//{
//	vector<int> id;
//	vector<int> sizeOfTree;
//	int root(int i);
//public:
//	UnionFind(int N);
//	~UnionFind(){};
//	bool connected(int p, int q);
//	void Union(int p, int q);
//};
//
//UnionFind::UnionFind(int N)
//{
//	id.resize(N);
//	sizeOfTree.resize(N);
//	for (size_t i = 0; i < N; i++)
//	{
//		id[i] = i;
//		sizeOfTree[i] = 1;
//	}
//}
//
//
//bool UnionFind::connected(int p, int q)
//{
//	return this->root(p) == this->root(q);
//}
//
//void UnionFind::Union(int p, int q)
//{
//	int i = root(p);
//	int j = root(q);
//	if (i == j)
//	{
//		return;
//	}
//	if (sizeOfTree[i] < sizeOfTree[j])
//	{
//		id[i] = j;
//	}
//	else
//	{
//		id[j] = i;
//		if (sizeOfTree[j] == sizeOfTree[i])
//		{
//			sizeOfTree[i] += 1;
//		}
//	}
//}
//
//int UnionFind::root(int i)
//{
//	while (i != id[i])
//	{
//		id[i] = id[id[i]]; // optimaize the tree
//		i = id[i];
//	}
//	return i;
//}
//
//class Graph
//{
//
//public:
//	std::vector<std::pair<std::pair<int, int>, int > >  weightedEdges;
//	int vertices;
//
//
//	void sortVertices();
//	Graph();
//	~Graph();
//	bool readFromFile(const char* fileName);
//	void GoKruskalAlgorithm_MinSpanningTree();
//
//};
//
//
//Graph::Graph()
//{
//}
//
//bool compare(const std::pair<std::pair<int, int>, int > &a,const std::pair<std::pair<int, int>, int > &b)
//{
//	return  a.second <  b.second;
//}
//
//Graph::~Graph()
//{
//}
//
//
//
//void Graph::sortVertices()
//{
//	std::sort(this->weightedEdges.begin(), this->weightedEdges.end(), compare);
//}
//
//void Graph::GoKruskalAlgorithm_MinSpanningTree()
//{
//	this->sortVertices();
//	UnionFind trees(this->vertices);
//	std::vector<std::pair<std::pair<int, int>, int > >  spanningEdges;
//	std::vector<std::pair<std::pair<int, int>, int > >::iterator currentEdge = this->weightedEdges.begin();
//	std::vector<std::pair<std::pair<int, int>, int > >::iterator end = this->weightedEdges.end();
//	for (; currentEdge != end; ++currentEdge)
//	{
//		if (spanningEdges.size() >= this->vertices - 2)
//		{
//			break; //we found the tree
//		}
//		if (!trees.connected(currentEdge->first.first, currentEdge->first.second))
//		{
//			trees.Union(currentEdge->first.first, currentEdge->first.second);
//			spanningEdges.push_back(*(currentEdge));
//		}
//	}
//	if (spanningEdges.size() >= this->vertices - 2)
//	{
//		int sum = 0;
//		for (size_t i = 0; i < spanningEdges.size(); i++)
//		{
//			sum += spanningEdges[i].second;
//		}
//		cout << sum << std::endl;
//	}
//
//}
//int Heating()
//{
//	int tests;
//	scanf("%d", &tests);
//	for (size_t i = 0; i < tests; i++)
//	{
//		int n, m;
//		scanf("%d", &n);
//		scanf("%d", &m);
//		Graph GR;
//		GR.vertices = n+1;
//		for (size_t j = 0; j < m; j++)
//		{
//			int x, y, l;;
//			scanf("%d", &x);
//			scanf("%d", &y);
//			scanf("%d", &l);
//			GR.weightedEdges.push_back(make_pair(make_pair(x,y), l));
//		}
//		GR.GoKruskalAlgorithm_MinSpanningTree();
//		
//	}
//	//system("pause");
//	return 0;
//}