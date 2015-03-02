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

ll DP[500000];

int mAaAin()
{
	int T, N, M;
	scanf("%d", &T);
	vector<ll> res(0);

	for (int z = 0; z < T; z++)
	{
		scanf("%d", &N);
		scanf("%d", &M);

		DP[0] = 0;
		cin >>DP[1];
		for (int k = 2; k <= N; k++)
		{
			cin >> DP[k];
			DP[k] = DP[k] + DP[k - 1];
		}
		int f, l;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &f);
			scanf("%d", &l);
			res.push_back(DP[l] - DP[f - 1]);
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}