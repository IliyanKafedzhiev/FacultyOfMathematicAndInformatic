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

using namespace std;
typedef long long ll;
typedef long double ld;
char buff[1512];

int main()
{
	
	int n, m,s;
	cin >> n;
	cin >> m;
	cin >> s; 

	int steps = std::abs((double) n) + std::abs((double) m);
	if (steps > s)
	{
		cout << "NO" << endl;
	}
	else
	{
		if (steps == s)
		{
			cout << "YES" << endl;
		}
		else if (steps %2 == 0)
		{
			if (s % 2 == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else 
		{
			if (s % 2 != 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
		 
	//system("pause");
	return 0;
}