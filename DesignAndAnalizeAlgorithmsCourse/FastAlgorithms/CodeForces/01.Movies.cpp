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
  

int maiWen()
{
	int n, x ,l ,r , lr = 1;
	cin >> n;
	cin >> x;
	int WM = 0;
	if (n == 0)
	{
		WM = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		cin >> r; 
		int diff = l - lr;
		WM += r - l + 1 + (diff)%x;
		if (lr < r)
		{
			lr = r+1;
		}
	}
	 

	cout << WM << endl;
	//system("pause");
	return 0;
}