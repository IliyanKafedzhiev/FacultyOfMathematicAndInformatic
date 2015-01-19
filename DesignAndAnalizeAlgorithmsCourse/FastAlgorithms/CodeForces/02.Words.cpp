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
char input[21];
char input2[21];


int mainWQ()
{
	int n;
	cin >> n; 
	map<string, string> Dic;
	string Fl,Sl;
	vector<string> res;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", input, input2);

		Fl = input;
		Sl = input2; 
		Dic[Fl] = Sl;
		res.push_back(Fl);
	} 
	vector<pair<string, string > > output;
	for (int i = 0; i < res.size(); i++)
	{
		Fl = res[i];
		int changes = 0;
		pair<string, string> p;
		p.first = Fl;
		while (Dic.find(Fl) != Dic.end())
		{
			changes++;
			Sl = Dic[Fl];
			Dic.erase(Dic.find(Fl));
			Fl = Sl;
		}
		if (changes > 0)
		{
			p.second = Fl;
			output.push_back
				(p);
		}
	}

	printf("%d\n", output.size());
	for (size_t i = 0; i < output.size(); i++)
	{
		printf("%s %s\n", output[i].first.c_str(), output[i].second.c_str());
	}
	//system("pause");
	return 0;
}