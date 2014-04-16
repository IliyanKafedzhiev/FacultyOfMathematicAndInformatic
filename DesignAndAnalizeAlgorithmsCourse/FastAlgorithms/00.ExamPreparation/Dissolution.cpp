#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char > > Matrix;
bool Final = false;

void wave(int i, int j)
{

}

int mainZ()
{
	int N, Days = 0; scanf("%d\n", &N); Matrix.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Matrix[i].resize(N);
		for (size_t j = 0; j < N; j++)
		{
			char a;
			scanf("%c", &a);
			if (a != '\n')
			{
				Matrix[i][j] = a;
			}
			else
			{
				scanf("%c", &a);
				Matrix[i][j] = a;
			}
		}
	}

	//wave in
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (Matrix[i][j] == '#' && !Final)
			{
				wave(i, j);
				Days++;
			}
		}
	}
	printf("%d\n", Days);

	return 0;
}