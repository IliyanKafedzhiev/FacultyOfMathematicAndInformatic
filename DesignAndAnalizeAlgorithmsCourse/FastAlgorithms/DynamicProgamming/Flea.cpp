#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool LCD[1501][1501];
int dpM[1501][1501];

int transition(int a, int b, int x, int y)
{
	if (a < 0 || b < 0)
	{
		return 999999999;
	}
	bool changed = dpM[a][b] % 2;
	bool pixel;
	if (changed)
	{
		pixel = !LCD[x][y];
	}
	else
	{
		pixel = LCD[x][y];
	}
	int seconds;
	if (pixel) // is pixel white
	{
		seconds = 2 + dpM[a][b];
	}
	else
	{
		seconds = 1 + dpM[a][b];
	}
	return seconds;
}

int mainFL()
{
	int N = 0;
	cin >> N;

	for (size_t x = 0; x < N; x++)
	{
		for (size_t y = 0; y < N; y++)
		{
			scanf("%d", &LCD[x][y]);
			if (x == 0 && y == 0)
			{
				dpM[0][0] = 1;

			}
			else
			{
				dpM[x][y] = min(transition(x - 1, y, x, y),
					transition(x, y - 1, x, y));
			}
		}
	}
	cout << dpM[N - 1][N - 1] << endl;

	return 0;
}