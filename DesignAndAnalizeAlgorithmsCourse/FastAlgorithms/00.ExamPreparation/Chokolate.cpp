#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Chocolate
{
	int n;
	int weight;
	bool operator < (const Chocolate& other) const
	{
		if (weight != other.weight)
		{
			return weight < other.weight;
		}
		return n < other.n;
	}
};

void Chokolates()
{
	int Chocolateses, Battles;
	scanf("%d %d", &Chocolateses, &Battles);
	vector<Chocolate> Chokos(Chocolateses);
	for (size_t i = 0; i < Chocolateses; i++)
	{
		scanf("%d", &Chokos[i].weight);
		Chokos[i].n = i;
	}
	vector<int> Battleses(Battles);
	for (size_t i = 0; i < Battles; i++)
	{
		scanf("%d", &Battleses[i]);
	}

	sort(Chokos.begin(), Chokos.end());

	for (size_t i = 0; i < Battles; i++)
	{
		vector<Chocolate>::iterator low = lower_bound(Chokos.begin(), Chokos.end(), Chocolate{ 0, Battleses[i] });

		int chok = low - Chokos.begin();
		if (chok == Chocolateses)
		{
			printf("-1\n");
		}
		else if ((*low).weight >= Battleses[i])
		{
			printf("%d\n", Chokos[chok].n);
		}
		else
		{
			printf("-1\n");
		}
	}
}

//int main()
//{
//	int max = INT_MAX;
//	int min = INT_MIN;
//	if (++max == min)
//	{
//		cout << "Happy joy" << endl;
//	}
//	return 0;
//}