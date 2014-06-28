#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool IsPalindrom(int j, int i, string& input)
{
	while (j < i)
	{
		if (input[j++] != input[i--])
		{
			return false;
		}
	}
	return true;
}

int mainCSP()
{
	std::ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	input = " " + input;

	vector<int> minCntPalindroms(input.size());
	vector<vector<bool  > > isPal(input.size());
	for (int i = 1; i < input.size(); i++)
	{
		isPal[i].resize(input.size());
	}

	for (int i = 1; i < input.size(); i++)
	{
		isPal[i][i] = true;
	}

	for (int i = 1; i < input.size() - 1; i++)
	{
		if (input[i] == input[i + 1])
		{
			isPal[i][i + 1] = true;
		}
	}

	int k = 2;
	for (int k = 2; k < input.size(); k++)
	{
		for (int j = 1; j < input.size() - k; j++)
		{
			if ((input[j] == input[j + k]) && (isPal[j + 1][j + k - 1]))
			{
				isPal[j][j + k] = true;
			}
		}
	}

	minCntPalindroms[1] = 1;

	for (int i = 2; i < input.length(); i++)
	{
		minCntPalindroms[i] = minCntPalindroms[i - 1] + 1;

		for (int j = 1; j<i; ++j)
		{
			if (isPal[j][i])
			{
				minCntPalindroms[i] = min(minCntPalindroms[i], 1 + minCntPalindroms[j - 1]);
			}
		}
	}
	cout << minCntPalindroms[minCntPalindroms.size() - 1] << endl;
	return 0;
}