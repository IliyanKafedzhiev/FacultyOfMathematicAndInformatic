#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void swap(vector<int>& A, int first, int second)
{
	int elem = A[first];
	A[first] = A[second];
	A[second] = elem;
}

int OptPartition(vector<int>& A, int from, int to)
{
	int pivot = A[to];
	int smallerFromBigPart = from;
	for (size_t i = from; i < to; i++)
	{
		if (A[i] < pivot)
		{
			swap(A, smallerFromBigPart, i);
			smallerFromBigPart++;
		}
	}
	swap(A, smallerFromBigPart, to);
	return smallerFromBigPart;
}

int Partition(vector<int>&A, int left, int right)
{
	int i = left;
	int j = right + 1;

	while (true)
	{
		while (A[++i] < A[left])
		{
			if (i == right)
			{
				break;
			}
		}

		while (A[left] < A[--j])
		{
			if (j == left)
			{
				break;
			}
		}

		if (i >= j)
		{
			break;
		}

		swap(A, i, j);
	}

	swap(A, left, j);
	return j;
}

void QuickSort(vector<int>& A, int left, int right) // less recursion
{

	while (right > left)
	{
		int pivot = OptPartition(A, left, right);

		if (pivot - left < right - pivot)
		{
			QuickSort(A, left, pivot - 1);
			left = pivot + 1;
		}
		else
		{
			QuickSort(A, pivot + 1, right);
			right = pivot - 1;
		}
	}
} // Less recursion

void Print(vector<int>& Array)
{
	for (size_t i = 0; i < Array.size(); i++)
	{
		printf("%d", Array[i]);
		if (i != Array.size() - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int mainBA()
{
	int number;
	scanf("%d\n", &number);

	vector<int> Array(number);
	for (size_t i = 0; i < number; i++)
	{
		unsigned long long elem;

		if (!i == number - 1)
		{
			scanf("%llu ", &elem);
		}
		else
		{
			scanf("%llu", &elem);
		}
		Array[i] = elem;
	}

	QuickSort(Array, 0, Array.size() - 1);

	Print(Array);

	return 0;
}
