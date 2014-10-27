#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long dinPro[501][501];
long long sums[501];
int A[501];


int mainHRW()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		if (i == 1)
		{
			sums[i] = A[i];
		}
		else
		{
			sums[i] = sums[i - 1] + A[i];
		}
		dinPro[i][i] = A[i];
	}

	for (size_t x = 1; x < n; x++)
	{
		dinPro[x][x + 1] = dinPro[x][x] + A[x + 1];
	}

	int y = 1;
	for (size_t iy = 2; iy <= n; iy++)
	{
		for (size_t x = 1; x <= n; x++)
		{
			y = x + iy;
			if (!(y <= n))
			{
				break;
			}
			long long mindinPro = 999999999;
			dinPro[x][y] = min(sums[y - 1] - sums[x - 1] + dinPro[x][y - 1] + A[y],
				sums[y] - sums[x] + dinPro[x + 1][y] + A[x]);
			if (dinPro[x][y] < mindinPro)
			{
				mindinPro = dinPro[x][y];
			}

			for (size_t k = x + 1; k < y; k++)
			{
				dinPro[x][y] = sums[y] - sums[x - 1] + dinPro[x][k] + dinPro[k + 1][y];
				if (dinPro[x][y] < mindinPro)
				{
					mindinPro = dinPro[x][y];
				}
			}
			dinPro[x][y] = mindinPro;
		}
	}




	cout << dinPro[1][n] << endl;
	return 0;
}