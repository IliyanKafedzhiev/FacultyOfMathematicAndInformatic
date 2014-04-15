#include <iostream>
#include"QuickSort.h"
#include"MargeSort.h"

using namespace std;

void TestMarge()
{
	vector<int> A = { 1, 2, 5, 6, 8, 55, 88, 123, 665 };
	vector<int> B = { 3, 7, 9, 11, 24, 55 };
	vector<int> *result = &MargeFirstInA(A, B);
	for (size_t i = 0; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
}

void TestQuickSort()
{
	vector<int> A = { 666, 2, 88, 44, 8, 4324,-11, 5, -7, 665 };
	QuickSort(A, 0, A.size() - 1);
	for (size_t i = 0; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
}
int main()
{
	TestQuickSort();
	return 0;
}

