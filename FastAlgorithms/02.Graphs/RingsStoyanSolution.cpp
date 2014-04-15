#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int> >& v, vector<bool>& visited, vector<int>& dist, int index)
{
	queue<int> q;
	q.push(index);
	visited[index] = true;

	while (!q.empty())
	{
		int curr = q.front();

		q.pop();
		for (int i = 0; i < v[curr].size(); ++i)
		{
			if (!visited[v[curr][i]])
			{
				dist[v[curr][i]] = dist[curr] + 1;
				visited[v[curr][i]] = true;
				q.push(v[curr][i]);
			}
		}
	}

}
int mainS()
{
	int n, m, a1, b1, a2, b2;
	scanf("%d %d", &n, &m);
	vector<vector<int> > v(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	scanf("%d %d", &a1, &b1);
	scanf("%d %d", &a2, &b2);

	vector<int> distA1(n + 1, 0), distB1(n + 1, 0), distA2(n + 1, 0), distB2(n + 1, 0);
	vector<bool> visited(n + 1, false);

	bfs(v, visited, distA1, a1);
	fill(visited.begin(), visited.end(), false);
	bfs(v, visited, distB1, b1);

	int count_of_nodes1 = 0, count_of_nodes2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (distA1[i] + distB1[i] != distA1[b1])
			++count_of_nodes1;
	}

	fill(visited.begin(), visited.end(), false);

	bfs(v, visited, distA2, a2);
	fill(visited.begin(), visited.end(), false);
	bfs(v, visited, distB2, b2);

	for (int i = 1; i <= n; ++i)
	{
		if (distA2[i] + distB2[i] != distA2[b2])
			++count_of_nodes2;
	}

	printf("%d %d\n", count_of_nodes1, count_of_nodes2);
	return 0;
}