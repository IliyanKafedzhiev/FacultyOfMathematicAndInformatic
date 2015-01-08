#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
int STEPS[105];//, DIST[105];

int mainWE()
{ 
	int n;
	cin >> n; 
	int maxHoldDist = 4111;
	int current, before;
	int maxDist = -1;
	for (int i = 0; i < n; i++)
	{
 		cin >> STEPS[i];
		if (i > 0)
		{
			current = STEPS[i] - STEPS[i - 1];
			if (current > maxDist)
			{
				maxDist = current;
			}
		}
		if (i > 1)
		{
			current = STEPS[i] - STEPS[i - 1];
			before = STEPS[i - 1] - STEPS[i - 2];
			if (maxHoldDist > current + before)
			{
				maxHoldDist = current + before;
			}
		}
	} 

	cout << max(maxDist, maxHoldDist) << endl;
	//system("pause");
	return 0;
}