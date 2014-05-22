#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> memSums;

vector<int> inputSequence;

int ff(int left)
{
	if (left > 0)
	{
		return memSums[left] = (ff(left - 1) + inputSequence[left] > 0) ? (memSums[left - 1] + inputSequence[left]) : 0;
	}
	return inputSequence[left] ;
}

int main()
{
	int n;
	scanf("%d", &n);
	inputSequence.resize(n);
	memSums.resize(n);
	int maxSum = -999999999;
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &inputSequence[i]);
	}
	ff(n - 1);
	for (size_t i = 0; i < n; i++)
	{
		if (memSums[i] > maxSum )
		{
			maxSum = memSums[i];
		}
	}
	cout << maxSum << endl;
	return 0;
}