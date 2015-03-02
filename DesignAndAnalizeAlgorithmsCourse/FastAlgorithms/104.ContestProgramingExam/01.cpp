#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>
#include <stack>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define d 256
void search(char *pat, char *txt, int q,vector<int>& matches)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;  // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h*d) % q;

	// Calculate the hash value of pattern and first window of text
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++)
	{

		// Check the hash values of current window of text and pattern
		// If the hash values match then only check for characters on by one
		if (p == t)
		{
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			{
				matches.push_back( i);
			}
		}

		if (i < N - M)
		{
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

char A[100000];
char B[100000];

int mainWES()
{
	int tests;
	scanf("%d", &tests);

	vector<vector<int > > res(tests);

	for (int i = 0; i < tests; i++)
	{
		scanf("%s", A);
		scanf("%s",B);
		search(A, B, 101, res[i]);
	}

	for (int i = 0; i < res.size(); i++)
	{
		printf("%d\n", res[i].size());

		for (int j = 0; j < res[i].size(); j++)
		{
			if (j == res[i].size() - 1)
			{
				printf("%d\n", res[i][j]);
			}
			else
			{
				printf("%d ", res[i][j]);
			}
		}
	}
	return 0;
}