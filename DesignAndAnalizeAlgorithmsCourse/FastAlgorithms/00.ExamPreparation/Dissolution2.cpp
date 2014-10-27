#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int N, Days = 0;
char Matrix[1005][1005];

deque<pair<int, int > > ExecutionQ;

bool HasTwoSolutionSides(int x, int y)
{
	int sides = 0;
	if (Matrix[x - 1][y] == '.')
	{
		sides++;
	}
	if (Matrix[x + 1][y] == '.' )
	{
		sides++;
	}
	if (Matrix[x][y - 1] == '.' )
	{
		sides++;
	}
	if (Matrix[x][y + 1] == '.' )
	{
		sides++;
	}
	if (sides >= 2)
	{
		return true;
	}
	return false;
}

int main()
{
	scanf("%d\n", &N);
	char a;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			scanf("%c", &a);
			if (a != '\n')
			{
				Matrix[i][j] = a;
			}
			else
			{
				scanf("%c", &a);
				Matrix[i][j] = a;
			}
		}
	}
	pair<int, int> cur;
	pair<int, int> tmp;
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < N-1; j++)
		{
			if (Matrix[i][j] == '#' && HasTwoSolutionSides(i, j))
			{
				cur.first = i;
				cur.second = j;
				ExecutionQ.push_back(cur);
				Matrix[i][j] = 'Y';
			}

		}
	}
	int sizeQ;
	while (!ExecutionQ.empty())
	{
		Days++;
		sizeQ = ExecutionQ.size();
		for (size_t i = 0; i < sizeQ; i++)
		{
			cur = ExecutionQ.front(), ExecutionQ.pop_front();
			Matrix[cur.first][cur.second] = '.';
			if (Matrix[cur.first - 1][cur.second] == '#' && HasTwoSolutionSides(cur.first - 1, cur.second))
			{
				tmp.first = cur.first - 1;
				tmp.second = cur.second;
				Matrix[tmp.first][tmp.second] = 'Y';
				ExecutionQ.push_back(tmp);
			}
			if (Matrix[cur.first + 1][cur.second] == '#' && HasTwoSolutionSides(cur.first + 1, cur.second))
			{
				tmp.first = cur.first + 1;
				tmp.second = cur.second;
				Matrix[tmp.first][tmp.second] = 'Y';
				ExecutionQ.push_back(tmp);
			}
			if (Matrix[cur.first][cur.second - 1] == '#' && HasTwoSolutionSides(cur.first, cur.second - 1))
			{
				tmp.first = cur.first;
				tmp.second = cur.second - 1;
				Matrix[tmp.first][tmp.second] = 'Y';
				ExecutionQ.push_back(tmp);
			}
			if (Matrix[cur.first][cur.second + 1] == '#' && HasTwoSolutionSides(cur.first, cur.second + 1))
			{
				tmp.first = cur.first;
				tmp.second = cur.second + 1;
				Matrix[tmp.first][tmp.second] = 'Y';
				ExecutionQ.push_back(tmp);
			}
			
		}
	}
	printf("%d\n", Days);
	return 0;
}