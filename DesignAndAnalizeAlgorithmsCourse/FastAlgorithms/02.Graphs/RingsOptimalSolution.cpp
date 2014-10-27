#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

void OreadGraph(vector<vector<int > >&);
int OFloppyPoints(vector<vector<int > >&, pair<int, int>&);
void OBFS(vector<vector<int > >&, pair<int, int>&, vector<int>&, vector<bool>&, int&);
void ORun();

int main()
{
	ORun();
	return 0;
}

void ORun()
{
	int rings;
	scanf("%d", &rings);
	vector<vector<int > > Graph(rings + 1);
	OreadGraph(Graph);
	pair<int, int> test1, test2;
	scanf("%d %d %d %d", &test1.first, &test1.second, &test2.first, &test2.second);
	printf("%d ", OFloppyPoints(Graph, test1));
	printf("%d\n", OFloppyPoints(Graph, test2));
}

void OBFS(vector<vector<int > >& Graph, pair<int, int>& test, vector<int>& distance, vector<bool>& used, int & maxLenght)
{
	queue<int> Queue;
	Queue.push(test.first);
	used[test.first] = true;

	while (!Queue.empty())
	{

		int ring = Queue.front(); Queue.pop();
		
		for (size_t i = 0; i < Graph[ring].size(); i++)
		{
			if (!used[Graph[ring][i]])
			{
				distance[Graph[ring][i]] = distance[ring] + 1;
				Queue.push(Graph[ring][i]);
				used[Graph[ring][i]] = true;
			}
		}
	}
}


int OFloppyPoints(vector<vector<int > >& Graph, pair<int, int>& test)
{
	vector<bool> usedBA(Graph.size(), false);
	vector<int> DistA(Graph.size(), 0);
	vector<int> DistB(Graph.size(), 0);

	int shortestPathA = 0;
	int shortestPathB = 0;

	OBFS(Graph, test, DistA, usedBA, shortestPathA);

	int tmp = test.first;
	test.first = test.second; test.second = tmp;
	fill(usedBA.begin(), usedBA.end(), false);
	OBFS(Graph, test, DistB, usedBA, shortestPathB);

	int OFloppyPointss = 0;
	for (int i = 1; i < usedBA.size(); i++)
	{

		if ((DistA[i] + DistB[i] == DistA[test.first]))
		{
			usedBA[i] = true;
		}
		else
		{
			OFloppyPointss++;
		}

	}
	return OFloppyPointss;
}

void OreadGraph(vector<vector<int> >& Graph)
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