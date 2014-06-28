#include <iostream>
#include <vector>

using namespace std;

int mainMU()
{
	vector<long long> elements;
	int N;
	cin >> N;
	elements.resize(N);
	for (int i = 0; i < elements.size(); i++)
	{
		cin >> elements[i];
	}

	vector<long long> rdp(N);
	vector<long long> ldp(N);

	ldp[0] = elements[0];
	for (int i = 1; i < N; i++)
	{
		ldp[i] = (ldp[i - 1] * elements[i]) % 1000000007;
	}

	rdp[N - 1] = elements[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		rdp[i] = (rdp[i + 1] * elements[i]) % 1000000007;
	}

	cout << (rdp[1]) % 1000000007 << " ";
	for (int i = 1; i < N - 1; i++)
	{
		cout << (rdp[i + 1] * ldp[i - 1]) % 1000000007 << " ";
	}
	cout << (ldp[N - 2]) % 1000000007 << endl;
	return 0;
}