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

int mainWW()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	stack < char > brackets;
	string as;
	cin >> as;
	char a;
	for (size_t i = 0; i < as.size(); i++)
	{
		a = as[i];
		if (a == '(')
		{
			brackets.push(a);
		}else if(a == '[')
		{
			brackets.push(a);
		}
		else if (a == '{')
		{
			brackets.push(a);
		}
		else if (a == '<')
		{
			brackets.push(a);
		}
		else if (a == ')')
		{
			if (brackets.top() == '(')
			{
				brackets.pop();
			}
			else
			{
				cout << 0 << endl;
				brackets.empty();
				return 0;

			}
		}
		else if (a == ']')
		{
			if (brackets.top() == '[')
			{
				brackets.pop();
			}
			else
			{
				cout << 0;
				brackets.empty();
				return 0;

			}
		}
		else if (a == '>')
		{
			if (brackets.top() == '<')
			{
				brackets.pop();
			}
			else
			{
				cout << 0 ;
				brackets.empty();
				return 0;
			}
		}
		else if (a == '}')
		{
			if (brackets.top() == '{')
			{
				brackets.pop();
			}
			else
			{
				cout << 0;
				brackets.empty();

				return 0;

			}
		}
	}
	cout << 1 ;

	//system("pause");
	return 0;
}