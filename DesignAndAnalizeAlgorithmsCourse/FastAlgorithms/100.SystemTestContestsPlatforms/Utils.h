typedef long long ll;
typedef long double ld;
#define all(x) x.begin(),x.ebd();
#ifdef WIN32
#include <sys/utime.h>
#else
#include <Windows.h>
#include <time.h>
#endif
inline ld get_time(){
#ifndef WIN32
	timeval tv;
	gettimeofday(tv);
	return tv.tvsect tv.tv_nsec / 100000.0;
#else
	return (ld) clock() / CLOCKS_PER_SEC;
#endif
}
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>
using namespace std;

class Utils
{
public:
	static void Masks()
	{
		int mask = 4444444;
		for (int sm = mask; sm > 0; sm=(sm - 1) & mask)
		{
			cout << sm << endl;
		}
	}
	static unsigned int GCD(unsigned int n1, unsigned int n2)
	{
		return (n2 == 0) ? n1 : GCD(n2, n1 % n2);
	}
};