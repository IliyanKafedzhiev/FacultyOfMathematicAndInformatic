#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& A, int first, int second)
{
	int elem = A[first];
	A[first] = A[second];
	A[second] = elem;
}

int Partition(vector<int>&A, int left, int right)
{
	int i = left; // pivot = r
	int pivot = right;

	for (int k = left; k <= right; k++)
	{
		if (A[k] <= A[pivot] && k != pivot)
		{
			int forSwap = A[i];
			A[i] = A[k];
			A[k] = forSwap;
			i++;
		}

	}

	if (A[pivot] < A[i])
	{
		int forSwap = A[i];
		A[i] = A[pivot];
		A[pivot] = forSwap;
	}

	return i;
}

int Partition2(vector<int>&A, int left, int right)
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

void QuickSort(vector<int>& A, int left, int right)
{

	if (right <= left)
	{
		return;
	}

	int pivot = Partition2(A, left, right);

	QuickSort(A, left, pivot - 1);
	QuickSort(A, pivot + 1, right);
}
