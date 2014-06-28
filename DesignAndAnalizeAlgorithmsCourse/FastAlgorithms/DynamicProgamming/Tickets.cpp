#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[51][501];
const int MAX_VALUE = 5741;

int mainT()
{

	int N, S;
	cin >> N;
	cin >> S;
	if (S % 2 == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	S = S / 2;

	for (int i = 0; i <= S; i++)
	{
		dp[1][i] = i < 10 ? 1 : 0;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int s = 0; s <= S; s++)
		{
			int length = min(9, s); // 
			long long ways = 0;

			for (int newNum = 0; newNum <= length; newNum++)
			{
				ways += (dp[i - 1][s - newNum] % MAX_VALUE);
			}

			dp[i][s] = ways % MAX_VALUE;
		}
	}
	cout << (dp[N][S] * dp[N][S]) % MAX_VALUE << endl;

	return 0;
}