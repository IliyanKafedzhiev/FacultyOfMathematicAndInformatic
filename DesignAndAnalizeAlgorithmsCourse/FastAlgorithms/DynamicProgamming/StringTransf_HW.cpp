#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int mainHWT()
{
	int** dp = new int*[1001]; // 
	for (size_t i = 0; i < 1001; i++)
	{
		dp[i] = new int[1001];
	}

	string source;
	cin >> source;
	string target;
	cin >> target;
	int Insert, Delete, Replace;
	cin >> Insert;
	cin >> Delete;
	cin >> Replace;
	dp[0][0] = 0;
	for (size_t i = 1; i <= source.size(); i++)
	{
		dp[i][0] = dp[i - 1][0] + Delete;
	}
	for (size_t i = 1; i <= target.size(); i++)
	{
		dp[0][i] = dp[0][i - 1] + Insert;
	}
	for (size_t x = 1; x <= source.size(); x++)
	{
		for (size_t y = 1; y <= target.size(); y++)
		{
			if (source[x - 1] == target[y - 1])
			{
				dp[x][y] = dp[x - 1][y - 1];
			}
			else
			{
				dp[x][y] = min(min(dp[x - 1][y] + Delete,
					dp[x][y - 1] + Insert),
					dp[x - 1][y - 1] + Replace);
			}
		}
	}

	cout << dp[source.size()][target.size()] << endl;
	return 0;
}