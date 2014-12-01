#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
struct Student
{
	int f , b;

	bool operator < (const Student& r) const 
	{

	}
};
int frons[1000005], backs[1000005];
int n;
deque<int> qu;
void rec(int index)
{
	if (frons[qu[index]])
	{
		if (!qu[index + 2])
		{
			qu[index + 2] = frons[qu[index]];
			rec(index + 2);
		}
	}
	if (backs[qu[index]])
	{
		if (!qu[index - 2])
		{
			qu[index - 2] = backs[qu[index]];
			rec(index - 2);
		}
	}
}

//int main()
//{
//	cin >> n;
//	qu.resize(n);
//	int a,b;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a;
//		cin >> b;
//
//		frons[a] = b;
//		backs[b] = a;
//	}
//
//	int p1 = 1;
//	int p2 = qu.size() - 2;
//	qu[p1] = frons[0];
//	qu[p2] = backs[0];
//	rec(p1);
//	rec(p2);
//	
//	for (int i = 0; i < qu.size(); i++)
//	{
//		cout << qu[i] << " ";
//	}
//	return 0;
//}