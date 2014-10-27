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
#include "Utils.h"

using namespace std;

int main()
{
	Utils::Masks();
	system("pause");
	return 0;
}