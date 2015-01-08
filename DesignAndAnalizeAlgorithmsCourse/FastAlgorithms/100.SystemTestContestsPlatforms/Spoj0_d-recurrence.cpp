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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > NMatrix;

#include <iostream>
#include <cstdlib>

int MOD = 9929;
template <typename Ty>
class Matrix {
public:
	int N, M;
	vector< vector<Ty> >  m_matrix;
	Ty* m_flatten;


public:
	Matrix(int N, int M) :N(N), M(M)
	{
		m_matrix.resize(N);
		for (size_t i = 0; i < N; i++)
		{
			m_matrix[i].resize(M);
		}
 	}

	Matrix(const Matrix& source) :N(source.N), M(source.M)
	{
		m_matrix.resize(N);
		for (size_t i = 0; i < N; i++)
		{
			m_matrix.resize(M);
			for (size_t k = 0; k < M; k++)
			{
				m_matrix[i][k] = source.m_matrix[i][k];
			}
		}
	}

	// Access with bounds checking
	Ty& operator()(int r, int c)
	{
		return m_matrix[r][c];
	}


	// Return matrix transpose
	Matrix<Ty> T() const
	{
		Matrix<Ty> result(N,M);
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				result.m_matrix[c][r] = m_matrix[r][c];
			}
		}
		return result;
	}

	///
	//  Matrix operations
	///
	// Matrix product
	Matrix<Ty> operator*(const Matrix<Ty>& b)
	{
		Matrix<Ty> result(this->N, b.M);

		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < b.M; ++c)
			{
				Ty accum = Ty(0);
				for (int i = 0; i < M; ++i) {
					accum += (this->m_matrix[r][i] * b.m_matrix[i][c]);
				}
				result(r,c) = accum%MOD;
			}
		}
		return result;
	}

	friend std::ostream& operator<< (std::ostream& pliuqch, Matrix<Ty>&m)
	{
		for (size_t i = 0; i < m.N; i++)
		{
			for (size_t k = 0; k < m.M; k++)
			{
				pliuqch << m(i, k);
				if (k != m.M - 1)
				{
					pliuqch << ", ";
				}
			}
			pliuqch << endl;
		}

		return pliuqch;
	}
};


void MatrixPower(Matrix<int>& a, int power, ll mod, Matrix <int> &res)
{
	res.N = a.N;
	res.M = a.M;
	res.m_matrix.resize(a.N);
	for (size_t i = 0; i < a.N; i++)
	{
		res.m_matrix.resize(a.M);
		for (size_t k = 0; k < a.M; k++)
		{
			res.m_matrix[i][k] = (i == k)? 1:0;
		}
	}
	while (power > 0)
	{
		if ((power % 2) == 1)
		{
			res = (a * res);
			//n -= 1;
		}

		a = (a*a);
		power /= 2;
	}
}


void testMatrix()
{
	Matrix<int> A(2, 3);
	Matrix<int> B(3, 2);
	A(0, 0) = 1;
	A(0, 1) = 0;
	A(0, 2) = -2;
	A(1, 0) = 0;
	A(1, 1) = 3;
	A(1, 2) = -1;
	B(0, 0) = 0;
	B(0, 1) = 3;
	B(1, 0) = -2;
	B(1, 1) = -1;
	B(2, 0) = 0;
	B(2, 1) = 4;

	Matrix<int> product = A*B;
	cout << product;
}
int recurrence()
{
	int tests,k,n,coef;
	cin >> tests;

	for (size_t i = 0; i < tests; i++)
	{
		cin >> k;
		cin >> n;
		vector<int> cvec(k);
		for (size_t j = 0; j < k; j++)
		{
			cin >> coef;
			cvec[j] = coef;
		}
		vector<int> avec(k);//F vec
		for (size_t j = 0; j < k; j++)
		{
			cin >> coef;
			avec[j] = coef;
		}
		//reverse(cvec.begin(), cvec.end());
		//reverse(avec.begin(), avec.end());
		Matrix<int> cMatrix(k,k);
		for (int j = 0; j < k; j++)
		{
			if (j != k - 1)
			{
				for (int z = 0; z < k; z++)
				{
					if (z == j + 1)
					{
						cMatrix(j,z) = 1;
					}
					else
					{
						cMatrix(j,z) = 0;
					}
				}
			}
			else
			{
				for (size_t z = 0; z < k; z++)
				{
					cMatrix(j, z) = cvec[z];
				}
			}
		}
		Matrix<int> Tn(k,k);

		MatrixPower(cMatrix, n - 1, 2, Tn);

		Matrix<int> F(k,1);
		for (size_t w = 0; w < k; w++)
		{
			F.m_matrix[w][0] = avec[w];
		}

		Matrix<int> Res(Tn*F);
		cout << Res.m_matrix[0][0] << endl;
	}
	return 0;
}

//int main()
//{
//	recurrence();
//	//system("pause");
//		return 0;
//}
