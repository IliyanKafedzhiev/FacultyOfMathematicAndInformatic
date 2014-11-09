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

template <typename Ty>
class Vector
{
public:
	Ty* m_vector;

	Ty& operator [] (int index)
	{
		return m_vector[index];
	}
};

template <typename Ty>
class Matrix {
private:
	int N, M;
	Ty** m_matrix;
	Ty* m_flatten;

	
public:
	Matrix(int N, int M) :N(N), M(M), m_matrix(new Ty*[N])
	{
		for (size_t i = 0; i < N; i++)
		{
			m_matrix[i] = new Ty[M];
		}
 	}

	Matrix(const Matrix& source) :N(source.N), M(source.M)
	{
		m_matrix = new Ty*[N];
		for (size_t i = 0; i < N; i++)
		{
			m_matrix[i] = new Ty[M];
			for (size_t k = 0; k < M; k++)
			{
				m_matrix[i][k] = source[i][k];
			}
		}
	}

	Matrix(const Matrix&& source) :N(source.N), M(source.M), m_matrix(source.m_matrix)
	{
		source.m_matrix = NULL;
	}

	~Matrix()
	{
		if (m_matrix)
		{
			for (size_t i = 0; i < N; i++)
			{
				delete [] m_matrix[i];
			}
		}
		if (m_flatten)
		{
			delete [] m_flatten;
		}
	}
	// Access with bounds checking
	Ty& operator()(int r, int c) 
	{
		return m_matrix[r][c];
	}

	Vector<Ty>& operator[](int idn)
	{
		Vector<Ty> a;
		a.m_vector = m_matrix[idn];
		return a;
	}

	// Return matrix transpose
	Matrix<Ty> T() const 
	{
		Matrix<Ty> result(N,M);
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				result.element[c][r] = element[r][c];
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
					accum += this->operator[r][i] * b[i][c];
				}
				result[r][c] = accum;
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


void MultiplyMatrix(NMatrix& matrix, ll power, ll mod,NMatrix& res)
{

}

int main()
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
		cout << cMatrix << endl;
	}

	system("pause");
	return 0;
}