#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> nums;
	for (size_t i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	for (size_t i = 0; i < N; i++)
	{
		cout << nums[i];
		if (i != nums.size())
		{
			cout << endl;
		}
	}
	return 0;
}