#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>
#include <stack>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char C[100000];

int maSin()
{
	int tests;
	scanf("%d", &tests);

	vector<int > res(tests);
	int set[42];
	for (int j = 0; j < 42; j++)
	{
		set[j] = 0;
	}
	for (int i = 0; i < tests; i++)
	{
		scanf("%s", C);
		int sizeA = strlen(C);
		for (int j = 0; j < sizeA; j++)
		{
			set[C[j] - 'a']++;
		}

		int max = 0;
		for (int j = 0; j < 42; j++)
		{
			if (max < set[j])
			{
				max = set[j];
			}
			set[j] = 0;
		}
		res[i] = max;
	}

	for (int i = 0; i < tests; i++)
	{
		printf("%d\n", res[i]);
	}
	return 0;
}