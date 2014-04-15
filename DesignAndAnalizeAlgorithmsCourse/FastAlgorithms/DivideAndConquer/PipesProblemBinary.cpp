#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

void ReadInputAndDo();
long long OptimalLenght(vector<int>&, int);

bool midCanBeAnswer(vector<int>, int, int);

int main()
{
	ReadInputAndDo();
	return 0;
}

bool midCanBeAnswer(vector<int> Pipes, long long optimalSize, int K)
{
	int pipe = 0;
	while (K > 0)
	{
		if (pipe >= Pipes.size())
		{
			return false;
		}

		if (Pipes[pipe] < optimalSize)
		{
			pipe++;
			K++;
		}
		else
		{
			Pipes[pipe] -= optimalSize;
		}
		--K;
	}
	return true;
}

long long OptimalLenght(vector<int>& Pipes, int K)
{
	long long optimalLenght = 0;
	int leftBorder = 1;
	sort<vector<int >::iterator >(Pipes.begin(), Pipes.end());
	long long sum = 0;
	for (size_t i = 0; i < Pipes.size(); i++)
	{
		sum += Pipes[i];
	}
	int rightBorder = (sum / K) + 1;
	long long mid;
	while (rightBorder > leftBorder)
	{
		mid = (rightBorder + leftBorder) / 2;
		if (midCanBeAnswer(Pipes, mid, K))
		{
			leftBorder = mid + 1;
			optimalLenght = mid;
		}
		else
		{
			rightBorder = mid;
		}
	}

	return optimalLenght;
}

void ReadInputAndDo()
{
	int tasks = 0;
	scanf("%d", &tasks);
	vector<long long> solutions(tasks);
	for (size_t i = 0; i < tasks; i++)
	{
		vector<int> pipesData;
		int N, K;
		scanf("%d", &N);
		scanf("%d", &K);
		pipesData.resize(N);
		for (size_t j = 0; j < N; j++)
		{
			scanf("%d", &pipesData[j]);
		}
		solutions[i] = OptimalLenght(pipesData, K);
	}
	for (size_t i = 0; i < tasks; i++)
	{
		printf("%llu\n", solutions[i]);
	}
}