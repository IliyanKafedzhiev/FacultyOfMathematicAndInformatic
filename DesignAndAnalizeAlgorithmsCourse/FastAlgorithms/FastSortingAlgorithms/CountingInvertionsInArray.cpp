#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

long long invertions;
int LeftPartPointer;
int RightPartPointer;
int z;
size_t k;

void Merge(vector<int>&A, int& left, int& middle, int& right, vector<int>& LeftPart)
{
	z = 0;
	for (k = left; k <= middle; ++k)
	{
		LeftPart[z++] = A[k]; //cpy leftArray
	}
	LeftPartPointer = 0;
	RightPartPointer = middle + 1;

	for (k = left; k <= right; ++k)
	{
		if (RightPartPointer > right || (LeftPartPointer <= (middle - left) && LeftPart[LeftPartPointer] <= A[RightPartPointer]))
		{
			A[k] = LeftPart[LeftPartPointer++];
		}
		else
		{
			invertions += middle - left - LeftPartPointer + 1;
			A[k] = A[RightPartPointer++];
		}
	}
}

void InvesionCountUsingMergeSort(vector<int>&A, int left, int right, vector<int>& LeftPart)
{
	if (right > left)
	{
		int middle = (right + left) / 2;
		InvesionCountUsingMergeSort(A, left, middle, LeftPart);
		InvesionCountUsingMergeSort(A, (middle + 1), right, LeftPart);
		Merge(A, left, middle, right, LeftPart);
	}
}


int main()
{
	int number;
	scanf("%d\n", &number);
	vector<int> LeftPart((number / 2) + 1);

	vector<int> Array(number);
	for (size_t i = 0; i < number; i++)
	{
		long long elem;

		scanf("%d", &elem);

		Array[i] = elem;
	}
	invertions = 0;

	InvesionCountUsingMergeSort(Array, 0, number - 1, LeftPart);

	printf("%llu \n", invertions);
	return 0;
}