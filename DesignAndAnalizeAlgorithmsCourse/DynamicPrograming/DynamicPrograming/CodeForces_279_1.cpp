#include <iostream>
#include <vector>
#include <string>
#include <map> 

using namespace std; 

struct Team
{
	int f;
	int s;
	int l;
};

int masdain1()
{
	int n;
	vector<Team*> teams;
	vector<int> f;
	vector<int> s;
	vector<int> l;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		switch (t)
		{
		case 1:
			f.push_back(i + 1);
			break;
		case 2:
			s.push_back(i + 1);
			break;
		case 3:
			l.push_back(i + 1);
			break;
		default:
			break;
		}
	}
	while (f.size() && s.size() && l.size())
	{
		Team c;
		c.f = f[0];
		c.s = s[0];
		c.l = l[0];
		teams.push_back(&c);
		f[0] = f[f.size() - 1];
		s[0] = s[s.size() - 1];
		l[0] = l[l.size() - 1];
		f.pop_back();
		s.pop_back();
		l.pop_back();
	}
	cout << teams.size() << endl;

	for (int i = 0; i < teams.size(); i++)
	{
		cout << teams[i]->f << " " << teams[i]->s << " " << teams[i]->l << endl;
	}
	return 0;
}