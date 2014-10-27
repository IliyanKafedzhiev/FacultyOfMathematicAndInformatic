#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<long long> memSumss;

int matrix[401][401];


int mainMSM()
{
	int n;
	cin >> n;
	memSumss.resize(n++);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (i == 0)
			{
				matrix[i][j] = 0;
			}
			else
			{
				cin >> matrix[i][j];
				if (i != 0)
				{
					matrix[i][j] += matrix[i - 1][j];
				}
			}

		}
	}

	long long maxSum = -99999999;

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < n - 1; k++)
			{
				matrix[400][k] = matrix[j][k] - matrix[i - 1][k];
			}

			memSumss[0] = matrix[400][0];
			if (maxSum < memSumss[0])
			{
				maxSum = (long long) memSumss[0];
			}
			for (size_t z = 1; z < n - 1; z++)
			{
				if (memSumss[z - 1] + matrix[400][z] < 0)
				{
					memSumss[z] = matrix[400][z];
				}
				else
				{
					memSumss[z] = memSumss[z - 1] + matrix[400][z];
				}

				if (maxSum < memSumss[z])
				{
					maxSum = memSumss[z];
				}
			}
		}
	}
	cout << maxSum << endl;
	return 0;
}