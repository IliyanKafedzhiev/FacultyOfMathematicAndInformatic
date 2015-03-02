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
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	string s, t;
	cin >> s;
	cin >> t;


	
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] != 'z' && (s[i]+1) < t[i] )
			{
				s[i]++;
				cout << s << endl;
				return 0;
			}
		} 
			cout << "No such string" << endl;
 
	return 0;
}