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

typedef unsigned long long ll;
typedef long double ld;

int mainÂß()
{
	ll n, m = 0, mult = 1;

	cin >> n;
	while (n>0)
	{
		int cDig = n % 10;
		if (cDig  > 4 && !(n < 10 && cDig ==9))
		{
			cDig = 9 - cDig;
		}

		m += mult*cDig;
		mult *= 10;
		n /= 10;
	}
	cout << m << endl;
	//system("pause");
	return 0;
}