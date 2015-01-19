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
  

int maiSdasn()
{ 
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	int mishaP = std::max((3 * a) / 10, a - (a / 250)*c);
	int vasyaP = std::max((3 * b) / 10, b - (b / 250)*d);

	if (mishaP > vasyaP)
	{
		cout << "Misha" << endl;
	}
	else if (vasyaP > mishaP)
	{
		cout << "Vasya" << endl;
	}
	else
	{
		cout << "Tie" << endl;
	}
	//system("pause");
	return 0;
}