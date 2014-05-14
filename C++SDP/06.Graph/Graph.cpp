#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> GetChildren(const vector<vector<int>>& graph, int node)
{
	return graph[node];
}

void DFS(const vector<vector<int>>& graph, int node, bool used[])
{
	cout << node << " ";
	
	used[node] = true;

	vector<int> children = GetChildren(graph, node);

	for (int i = 0; i < children.size(); i++)
	{
		if (!used[children[i]])
		{
			DFS(graph, children[i], used);
		}
	}
}

void BFS(const vector<vector<int>>& graph, bool used[], queue<int> next)
{
	if (next.size() == 0)
	{
		return;
	}

	int node = next.front();
	used[node] = true;
	next.pop();

	cout << node << " ";

	vector<int> children = GetChildren(graph, node);

	for (int i = 0; i < children.size(); i++)
	{
		if (!used[children[i]])
		{
			next.push(children[i]);
		}
	}

	BFS(graph, used, next);
}

int main()
{
	// Read and construct the graph using adjacency list representation

	int nodesCount;
	cout << "NodesCount: ";
	cin >> nodesCount;

	vector<vector<int>> graph;

	graph.resize(nodesCount);

	int edgesCount;
	cout << "EdgesCount: ";
	cin >> edgesCount; 


	cout << "Enter edges: \n";
	for (int i = 0; i < edgesCount; i++)
	{
		int from;
		int to;

		cin >> from;
		cin >> to;

		graph[from].push_back(to);
	}

	// Print the graph

	for (int i = 0; i < nodesCount; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	// DFS Test

	bool* used = new bool[nodesCount];
	for (int i = 0; i < nodesCount; i++)
	{
		used[i] = false;
	}

	cout << "DFS: ";
	DFS(graph, 0, used);
	cout << endl;

	// BFS Test

	for (int i = 0; i < nodesCount; i++)
	{
		used[i] = false;
	}

	queue<int> next;
	next.push(0);

	cout << "BFS: ";
	BFS(graph, used, next);
	cout << endl;

	return 0;
}