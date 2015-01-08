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


int main()
{
	int n, m, l, r, lr = 1;
	cin >> n;
	cin >> m;
	map<string, string> Dic;
	string Fl,Sl;
	for (int i = 0; i < m; i++)
	{
		cin >> Fl;
		cin >> Sl;
		Dic[Fl] = Sl;
	}
	vector<string> res(n);
	for (int i = 0; i < n; i++)
	{
		cin >> Fl;
		if (Dic[Fl].size()  < Fl.size())
		{
			res[i] = Dic[Fl];
		}
		else
		{
			res[i] = Fl;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i];
		if (i != n -1)
		{
			cout << " ";
		}
	}
	cout << endl;

	//system("pause");
	return 0;
}