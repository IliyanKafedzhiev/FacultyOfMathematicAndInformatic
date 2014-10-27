#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int Coloms, Floors, CountBombs;
	cin >> Coloms;
	cin >> Floors;
	int* bombs = new int[Coloms + 1];
	int* dp = new int[Coloms + 1];
	cin >> CountBombs;
	for (size_t i = 0; i < Coloms + 1; i++)
	{
		dp[i] = 0;
		bombs[i] = 0;
	}
	int colom, floor;
	for (size_t i = 0; i < CountBombs; i++)
	{
		cin >> colom;
		cin >> floor;
		if (bombs[colom] < floor)
		{
			bombs[colom] = floor;
		}
	}
	dp[1] = bombs[1];
	dp[2] = max(dp[1], bombs[2]);
	dp[3] = max(dp[2], bombs[3]);

	for (size_t i = 4; i < Coloms + 1; i++)
	{
		dp[i] = min(min(bombs[i] + dp[i - 1], max(bombs[i], bombs[i - 1]) + dp[i - 2]),
			max(max(bombs[i], bombs[i - 1]), bombs[i - 2]) + dp[i - 3]);
	}
	cout << dp[Coloms] << endl;
	return 0;
}