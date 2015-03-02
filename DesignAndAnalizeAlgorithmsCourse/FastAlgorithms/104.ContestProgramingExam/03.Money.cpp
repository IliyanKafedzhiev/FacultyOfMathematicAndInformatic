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


int maiWEWSn()
{
	int tests,cmd,value;
	scanf("%d", &tests);
	priority_queue<int> q;
	vector<vector<int > > res(tests);

	for (int i = 0; i < tests; i++)
	{
		cin >> cmd;
		for (int j = 0; j < cmd; j++)
		{
			cin >> value;
			if (value == 1)
			{
				cin >> value;
				q.push(value);
			}
			else
			{
				if (q.size() > 0)
				{
					res[i].push_back(q.top());
					q.pop();
				}
			}
		}
		while(!q.empty()) q.pop();
	}

	for (int i = 0; i < tests; i++)
	{
		for (int k = 0; k < res[i].size(); k++)
		{
			printf("%d\n", res[i][k]);
		}

		if (i != tests -1)
		{
			printf("\n");
		}
	}
	return 0;
}