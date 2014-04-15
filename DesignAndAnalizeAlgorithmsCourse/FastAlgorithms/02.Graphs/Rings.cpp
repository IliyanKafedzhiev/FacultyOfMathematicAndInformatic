#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

void readGraph(vector<vector<int > >&);
int FloppyPoints(vector<vector<int > >&, pair<int, int>&);
void DFS(vector<vector<int > >&, pair<int, int>, vector<bool>&, vector<bool>, int, int&);
void Run();



void Run()
{
	int rings;
	scanf("%d", &rings);
	vector<vector<int > > Graph(rings + 1);
	readGraph(Graph);
	pair<int, int> test1, test2;
	scanf("%d %d %d %d", &test1.first, &test1.second, &test2.first, &test2.second);
	printf("%d ", FloppyPoints(Graph, test1));
	printf("%d\n", FloppyPoints(Graph, test2));
}

void DFS(vector<vector<int > >& Graph, pair<int, int> test, vector<bool>& stretchedRings, vector<bool> used, int pathLenght, int& currentShortestPath)
{
	bool AreWeReachTotheDestination = false;
	used[test.first] = true;

	if (test.first == test.second)
	{
		AreWeReachTotheDestination = true;
	}
	if (test.first == test.second && pathLenght <= currentShortestPath)
	{
		if (pathLenght == currentShortestPath)
		{
			for (size_t i = 1; i < stretchedRings.size(); i++)
			{
				if (used[i] && !stretchedRings[i])
				{
					stretchedRings[i] = true;
				}
			}
		}
		else
		{
			currentShortestPath = pathLenght;
			for (size_t i = 1; i < stretchedRings.size(); i++)
			{
				stretchedRings[i] = used[i];
			}
		}

	}
	if (!AreWeReachTotheDestination)
	{
		for (size_t i = 0; i < Graph[test.first].size(); i++)
		{
			if (!used[Graph[test.first][i]])
			{
				DFS(Graph, pair<int, int>(Graph[test.first][i], test.second), stretchedRings, used, pathLenght + 1, currentShortestPath);
			}
		}
	}
}

int FloppyPoints(vector<vector<int > >& Graph, pair<int, int>& test)
{
	vector<bool> stretchedRings(Graph.size(), false);
	vector<bool> used(Graph.size(), false);
	int shortestPath = 2000000000;

	DFS(Graph, test, stretchedRings, used,0,shortestPath);
	int FloppyPointss = 0;
	for (size_t i = 1; i < stretchedRings.size(); i++)
	{
		if (!stretchedRings[i])
		{
			FloppyPointss++;
		}
	}
	return FloppyPointss;
}

void readGraph(vector<vector<int> >& Graph)
{
	int d;
	scanf("%d", &d);
	for (size_t i = 0; i < d; i++)
	{
		int ring1, ring2;
		scanf("%d %d", &ring1, &ring2);
		Graph[ring1].push_back(ring2);
		Graph[ring2].push_back(ring1);
	}
}