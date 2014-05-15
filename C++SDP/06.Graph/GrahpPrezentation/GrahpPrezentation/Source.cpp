#include <iostream>

#include "Graph.h"

using namespace std;

int main()
{
	int NodesCount = 10;
	vector<vector<int>> graph;

	graph.resize(NodesCount);

	int edgesCount = 8;
	for (size_t i = 0; i < edgesCount; i++)
	{
		int from;
		int to;
		
		cout << "from";
		cin >> from;
		cout << "to:" << endl;
		cin >> to;
		graph[from].push_back(to);
	}
	return 0;
}