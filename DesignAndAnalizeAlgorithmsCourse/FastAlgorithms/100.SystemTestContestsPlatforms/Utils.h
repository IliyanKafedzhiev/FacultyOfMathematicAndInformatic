#include <iostream>

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
};