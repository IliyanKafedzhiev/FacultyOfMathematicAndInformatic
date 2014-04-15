#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int ExeptElem = 0;

void readInput(vector<int>& Elems, vector<int>& Sums)
{
	int sizeElems;
	int sizeSums;

	scanf("%d", &sizeElems);
	scanf("%d", &sizeSums);

	Elems.resize(sizeElems);
	Sums.resize(sizeSums);

	for (size_t i = 0; i < sizeElems; i++)
	{
		int el;
		scanf("%d", &el);
		Elems[i] = el;
	}
	for (size_t i = 0; i < sizeSums; i++)
	{
		int el;
		scanf("%d", &el);
		Sums[i] = el;
	}

}


void  SumProblem()
{
	vector<int> Elements;
	vector<int> Sums;

	readInput(Elements, Sums);
	sort(Elements.begin(), Elements.end());

	for (size_t i = 0; i < Sums.size(); i++)
	{
		bool isThere = false;

		for (size_t j = 0; j < Elements.size(); j++)
		{

			int searchForItem = Sums[i] - Elements[j];
			int currElem = Elements[j];

			Elements[j] = 2147483647;

			isThere = binary_search<vector<int>::iterator, int>(Elements.begin(), Elements.end(), searchForItem);


			Elements[j] = currElem;

			if (isThere)
			{
				break;
			}
		}
		if (isThere)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
