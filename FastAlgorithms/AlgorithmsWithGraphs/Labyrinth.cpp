#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int maxPaths = 0;

void StartSearching(vector<vector<bool> > &Matrix,int Xray, int Yray,int &maxXray, int &maxYray, int maxP)
{
	Matrix[Xray][Yray] = true;
	maxP++;
	if (maxPaths < maxP)
	{
		maxXray = Xray;
		maxYray = Yray;
		maxPaths = maxP;
	}
	if (Xray - 1 >= 0 && !Matrix[Xray -1][Yray])
	{
		StartSearching(Matrix, Xray - 1, Yray, maxXray, maxYray, maxP);
	}
	if (Xray + 1 < Matrix.size() && !Matrix[Xray + 1][Yray])
	{
		StartSearching(Matrix, Xray + 1, Yray, maxXray, maxYray, maxP);
	}
	if (Yray + 1  < Matrix[0].size() && !Matrix[Xray ][Yray + 1])
	{
		StartSearching(Matrix, Xray, Yray + 1, maxXray, maxYray, maxP);
	}
	if (Yray - 1  >= 0 && !Matrix[Xray][Yray - 1])
	{
		StartSearching(Matrix, Xray, Yray - 1, maxXray, maxYray, maxP);
	}
}

void readInput(vector<vector<bool> > &Matrix)
{
	int rows, cols;
	scanf("%d %d", &cols, &rows);

	Matrix.resize(rows);
	for (size_t i = 0; i < rows; i++)
	{
		Matrix[i].resize(cols);
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t z = 0; z < cols; z++)
		{
			char c = 'd';
			while (c != '#' && c != '.')
			{
				scanf("%c", &c);
			}

			if (c == '.')
			{
				Matrix[i][z] = false;
			}
			else
			{
				Matrix[i][z] = true;
			}
		}
	}
}

void labyrinth()
{
	vector<vector<bool> > Matrix;
	readInput(Matrix);
	
	int m = Matrix.size(), n = Matrix[0].size();

	for (size_t i = 0; i < m; i++)
	{
		for (size_t z = 0; z < n; z++)
		{
			if (!Matrix[i][z])
			{
				int Mx = i;
				int My = z;
				vector<vector <bool > > SecondMatrix = Matrix;
				StartSearching(Matrix, i, z,Mx,My, 0);
				StartSearching(SecondMatrix, Mx, My, Mx, My, 0);
			}
		}
	}
	printf("%d\n", --maxPaths);

}



