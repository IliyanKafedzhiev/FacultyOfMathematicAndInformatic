#include <iostream>
#include <algorithm>

using namespace std;

long long dp2[71][71][71];
int A[71][71];

int mainTR()
{

	int N, M;
	cin >> N;
	cin >> M;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}

	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			for (size_t k = 1; (k <= N); k++)
			{
				int p = i + j - k;

				if ((p <= M) && (p >= 1))
				{
					dp2[i][j][k] = (max(max(max(
						dp2[i - 1][j][k - 1],
						dp2[i - 1][j][k]),
						dp2[i][j - 1][k - 1]),
						dp2[i][j - 1][k]) +

						(((i == k) && (j == p)) ? A[k][p] : (A[i][j] + A[k][p]))
						);
				}
			}
		}
	}
	cout << dp2[N][M][N] << endl;
	return 0;
}