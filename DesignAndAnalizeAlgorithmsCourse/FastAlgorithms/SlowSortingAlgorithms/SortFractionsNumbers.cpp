#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

struct Fraction
{
	int numerator;
	int denumenator;
	bool operator <(const Fraction& right) const
	{
		double thisFraction = (double) numerator / (double) denumenator;
		double rightFraction = (double) right.numerator / (double) right.denumenator;
		if (thisFraction < rightFraction)
		{
			return true;
		}
		return false;
	}
	friend ostream& operator <<(ostream& out, const Fraction& val)
	{
		out << val.numerator << "//" << val.denumenator;
	}
};

unsigned int GCD(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : GCD(n2, n1 % n2);
}

int mainMCM()
{
	int Gen;
	scanf("%d", &Gen);
	vector<Fraction> fractions;
	for (size_t numerator = 1; numerator < Gen; numerator++)
	{
		for (size_t denumerator = 2; (denumerator <= Gen); denumerator++)
		{
			if ((numerator < denumerator))
			{
				if (GCD(numerator, denumerator) == 1)
				{
					Fraction current = { numerator, denumerator };
					fractions.push_back(current);
				}
			}
		}
	}
	sort(fractions.begin(), fractions.end());
	printf("0");
	printf(" ");
	for (size_t i = 0; i < fractions.size(); i++)
	{
		printf("%d", fractions[i].numerator);
		printf("/");
		printf("%d", fractions[i].denumenator);
        if (i != fractions.size() - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

