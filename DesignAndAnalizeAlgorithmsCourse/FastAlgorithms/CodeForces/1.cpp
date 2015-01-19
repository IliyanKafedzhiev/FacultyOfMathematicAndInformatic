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
	scanf("%s", input);
	int sizeI = strlen(input);
	string in(input);
	int iNsertCnt = 0;
	for (int i = 0; i < sizeI/2; i++)
	{
		if (input[i] != input[sizeI-1-i])
		{
			iNsertCnt++;
			in.insert(i-1, &input[sizeI - 1 - i]);
			sizeI++;
		}
	}
	
	return 0;
}