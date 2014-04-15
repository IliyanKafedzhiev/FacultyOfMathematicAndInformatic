#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;


int M, N;
queue<pair<int, int > > q;
class Graph
{
public:
	vector<vector<bool > > used;
	void bfs(int Days)
	{
		while (!q.empty() && Days>0)
		{
			int size = q.size();

			for (size_t i = 0; i < size; i++)
			{
				pair<int, int > cur = q.front();
				q.pop();
				int x = cur.first, y = cur.second;
				
				

				if (x - 1 >= 0 && used[x - 1][y] != true)
				{
					q.push(pair<int, int>(x - 1, y));
					used[x - 1][y] = true;
				}

				if (x + 1 < N && used[x + 1][y] != true)
				{
					q.push(pair<int, int>(x + 1, y));
					used[x + 1][y] = true;
				}

				if (y - 1 >= 0 && used[x ][y - 1] != true)
				{
					q.push(pair<int, int>(x , y - 1));
					used[x ][y - 1] = true;
				}

				if (y + 1 < M && used[x ][y + 1] != true)
				{
					q.push(pair<int, int>(x , y + 1));
					used[x ][y + 1] = true;
				}

			}

			--Days;
		}
	}
	void readGraphContreteAndSolve()
	{
		int Days;
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &Days);

		used.resize(N);
		for (size_t i = 0; i < N; i++)
		{
			used[i].resize(M);
		}
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				used[i][j] = false;
			}
		}

		int x, y;

		while (scanf("%d%d",&x,&y) == 2)
		{
			used[x-1][y-1] = true;
			q.push(pair<int, int>(x-1, y-1));
		}
		bfs(Days);

		unsigned long long goodApples = 0;

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (used[i][j] == false)
				{
					goodApples++;
				}
			}
		}
		printf("%llu\n", goodApples);
	}

};

void GoodApples()
{
	Graph a;
	a.readGraphContreteAndSolve();
}

