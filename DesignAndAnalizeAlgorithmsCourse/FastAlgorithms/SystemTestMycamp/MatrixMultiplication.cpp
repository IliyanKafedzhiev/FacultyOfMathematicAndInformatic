#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <cmath>

using namespace std;



int main()
{
	int M,N,K;
	scanf_s("%d", &M);
	scanf_s("%d", &N);
	scanf_s("%d", &K);
	long long**f=new long long*[M];
	for (size_t i = 0; i < M; i++)
	{
		f[i] = new long long[N];
	}
	long long**s = new long long*[N];
	for (size_t i = 0; i < N; i++)
	{
		s[i] = new long long[K];
	}

	//readfirst
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			scanf_s("%lld", &f[i][j]);
		}
	}
	
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < K; j++)
		{
			scanf_s("%lld", &s[i][j]);
		}
	}

	long long** result = new long long* [M];
	for (size_t i = 0; i < M; i++)
	{
		result[i] = new long long[K];
		for (size_t j = 0; j < K; j++)
		{
			result[i][j] = 0;

			for (size_t z = 0; z < N; z++)
			{
				result[i][j] +=f[i][z]*s[z][j] ;
			}
			if (j == K-1)
			{
				printf_s("%lld", result[i][j]);
			}
			else
			{
				printf_s("%lld ", result[i][j]);
			}
			
		}
		printf_s("\n");
	}
	return 0;
} 