#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &A, int from, int to)
{
	int Obj = A[from];
	A[from] = A[to];
	A[to] = Obj;
}

void shift_down(vector<int>& A, int root,int size)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left >= size)
	{
		return;
	}
	if (right >= size)
	{
		if (A[left] > A[root])
		{
			swap(A, root, left);
		}
		return;
	}


	if (A[left] <= A[root] && A[right] <= A[root])
	{
		return;
	}
	if (A[left] >= A[right])
	{
		swap(A, left, root);
		shift_down(A,left,size);
	}
	else 
	{
		swap(A, right, root);
		shift_down(A, right,size);
	}
	return;
}

void BuildHeap(vector<int>& A)
{
	for (int i = A.size()/2 - 1 ; i >= 0; i--)
	{
		shift_down(A, i,A.size()); 
	}
}

void HeapSort(vector<int>& A)
{
	BuildHeap(A);
	for (int i = A.size() - 1; i > 0; i--)
	{
		swap(A, 0, i);
		shift_down(A, 0,i);
	}
}

int mainBB()
{
	vector<int> A = { 2, 4, 2, 1, 5, 4, 3, 63, 42, 22 };
	HeapSort(A);
	return 0;
}