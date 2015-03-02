#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
char mx[52][52];

bool dfs(int fx, int fy, int tx, int ty)
{
	bool res = false;
	char VC = mx[tx][ty];
	mx[tx][ty] = 'g';
	if (tx - 1 != fx || ty != fy)
	{
		if (mx[tx-1][ty] == 'g')
		{
			return true;
		}
		if (mx[tx - 1][ty] == VC)
		{
			if (dfs(tx,ty,tx-1,ty))
			{
				res = true;
			}
		}
	}
	if (tx  != fx || ty + 1 != fy)
	{
		if (mx[tx ][ty + 1] == 'g')
		{
			return true;
		}
		if (mx[tx ][ty+1] == VC)
		{
			if (dfs(tx, ty, tx, ty+1))
			{
				res = true;
			}
		}
	}
	if (tx + 1 != fx || ty  != fy)
	{
		if (mx[tx + 1][ty ] == 'g')
		{
			return true;
		}
		if (mx[tx + 1][ty] == VC)
		{
			if (dfs(tx, ty, tx + 1, ty))
			{
				res = true;
			}
		}
	}
	if (tx  != fx || ty - 1 != fy)
	{
		if (mx[tx ][ty - 1] == 'g')
		{
			return true;
		}
		if (mx[tx ][ty - 1] == VC)
		{
			if (dfs(tx, ty, tx, ty - 1))
			{
				res = true;
			}
		}
	}
	mx[tx][ty] = 'b';
	return res;
}

int maiWESdn()
{
	int n, m, max = 1,min = 1;

	scanf("%d", &n);
	scanf("%d\n", &m);
	
	bool right = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &mx[i][j]);
		}
		if (i != n)
			scanf("\n");
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mx[i][j] != 'b')
			{
				char Ch = mx[i][j];
				mx[i][j] = 'g';
				if (mx[i+1][j] == Ch && dfs(i,j,i+1,j))
				{
					cout << "Yes" << endl; 
					//system("pause");
					return 0;
				}
				if (mx[i - 1][j] == Ch && dfs(i, j, i - 1, j))
				{
					cout << "Yes" << endl; 
					//system("pause");
					return 0;
				}
				if (mx[i][j + 1] == Ch && dfs(i, j, i, j + 1))
				{
					cout << "Yes" << endl;
					//system("pause");
					return 0;
				}
				if (mx[i][j - 1] == Ch && dfs(i, j, i, j - 1))
				{
					cout << "Yes" << endl; 
					//system("pause");
					return 0;
				}
				mx[i][j] = 'b';
			}
		}
	}
	
	cout << "No" << endl;
	//system("pause");
	return 0;
}