#include <istream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>& Marge(vector<int>& A , vector<int>& B)
{
	vector<int> * C = new vector<int>();
	int i = 0;
	int j = 0;

	while (i < (int) A.size() || j < (int) B.size())
	{
		if (i >= (int) A.size())
		{
			C->push_back(B[j]);
			j++;
		}

		else if (j >= (int) A.size())
		{
			C->push_back(A[i]);
			i++;
		}

		else
		{
			if (A[i] > B[j])
			{
				C->push_back(B[j]);
				j++;
			}

			else
			{
				C->push_back(A[i]);
				i++;
			}
		}
	}

	return *(C);
}

vector<int>& MargeFirstInA(vector<int>& A, vector<int>& B)
{
	int firstLenghtA = A.size();
	A.resize(A.size() + B.size());
	int i = firstLenghtA - 1;
	int j = B.size() - 1;
	int pnt = A.size() - 1;
	while (i > 0 || j > 0)
	{
		if (i < 0)
		{
			A[pnt] = B[j];
			j--;
			pnt--;
		}
		else if (j < 0)
		{
			A[pnt] = A[i];
			i--;
			pnt--;
		}
		else
		{

			if (A[i] < B[j])
			{
				A[pnt] = B[j];
				j--;
				pnt--;
			}
			else
			{
				A[pnt] = A[i];
				i--;
				pnt--;
			}
		}
	}

	return A;
}

void MergeSort(vector<int>& A)
{
	
}