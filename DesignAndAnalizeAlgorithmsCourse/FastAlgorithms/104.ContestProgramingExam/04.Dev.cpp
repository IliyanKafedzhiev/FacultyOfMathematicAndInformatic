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


int mainQWER()
{
	int T, N, K;
	scanf("%d", &T);
	vector<int> A,R;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		A.resize(N);
		cin >> K;
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];
		}
		sort(A.begin(), A.begin()+N);
		R.push_back(A[N - K]);
	}

	for (int k = 0; k < R.size(); k++)
	{
		printf("%d\n", R[k]);
	}
	return 0;
}