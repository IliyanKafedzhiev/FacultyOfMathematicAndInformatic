#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char > > Matrix;
bool Final = false;

bool HasTwoSolutionSides(int x, int y,char sol)
{
	int sides = 0;
	if (x - 1 >= 0 && Matrix[x - 1][y] == sol)
	{
		sides++;
	}
	if (x + 1 < Matrix.size() && Matrix[x + 1][y] == sol)
	{
		sides++;
	}
	if (y - 1 >= 0 && Matrix[x][y - 1] == sol)
	{
		sides++;
	}
	if (y + 1 < Matrix.size() && Matrix[x][y + 1] == sol)
	{
		sides++;
	}
	if (sides >=2)
	{
		return true;
	}
	return false;
}

bool HasOneSolutionSideOrBorder(int x, int y)
{
	int sides = 0;
	if (x - 1 >= 0)
	{
		if (Matrix[x - 1][y] == '.')
		{
			sides++;
		}
	}
	else
	{
		sides++;
	}
	if (x + 1 < Matrix.size())
	{
		if (Matrix[x + 1][y] == '.')
		{
			sides++;
		}
	}
	else
	{
		sides++;
	}
	if (y - 1 >= 0)
	{
		if (Matrix[x][y - 1] == '.')
		{
			sides++;
		}
	}
	else
	{
		sides++;
	}
	if (y + 1 < Matrix.size())
	{
		if (Matrix[x][y + 1] == '.')
		{
			sides++;
		}
	}
	else
	{
		sides++;
	}
	if (sides >= 1 )
	{
		return true;
	}
	return false;
}



int main()
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
	int Xmin = 0, Xmax = N - 1;
	int Ymin = 0, Ymax = N - 1;
	char sol = '.';
	//wave in
	while (!Final)
	{
		bool xmin = false;
		int XXmax = Xmax;
		int YYmin = 30000000;
		int YYmax = 0;
		for (int i = Xmin; i <= Xmax; i++)
		{
			int YCurMin = 3000;
			int YcurMax = 0;
			bool ycurMin = false;
			for (int j = Ymin; j < Ymax; j++)
			{
				if (Matrix[i][j] == '#'  && HasTwoSolutionSides(i,j,sol))
				{
					Matrix[i][j] = sol + 1;
					if (!xmin)
					{
						Xmin = i;
						xmin = true;
					}
					XXmax = i;
					if (!ycurMin)
					{
						YCurMin = j;
						ycurMin = true;
					}
					YcurMax = j;
				}
			}
			if (ycurMin)
			{
				if (YYmin > YCurMin)
				{
					YYmin = YCurMin;
				}
			}
			if (YcurMax > YYmax)
			{
				YYmax = YcurMax;
			}
		}
		if (YYmin == 30000000)
		{
			break;
		}
		Ymax = YYmax;
		Ymin = YYmin;
		Xmax = XXmax;
		Days++;
		sol = sol + 1;
	}
	

	return 0;
}