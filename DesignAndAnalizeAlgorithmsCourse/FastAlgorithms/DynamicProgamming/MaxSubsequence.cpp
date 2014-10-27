#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> memSums;

vector<int> inputSequence;

int mainMSS()
{
	int n;
	scanf("%d", &n);
	inputSequence.resize(n);
	memSums.resize(n);
	int maxSum = 0;
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &inputSequence[i]);
		memSums[i] = 0;
	}

	maxSum = memSums[0] = max(0, inputSequence[0]);
	for (size_t i = 1; i < n; i++)
	{
		memSums[i] = max(0, memSums[i - 1] + inputSequence[i]);
		if (maxSum < memSums[i])
		{
			maxSum = memSums[i];
		}
	}

	cout << maxSum << endl;
	return 0;
}