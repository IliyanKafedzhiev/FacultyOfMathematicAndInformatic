#include <iostream>
#include "Werewolf.h"

using namespace std;

class A
{
protected:
	int a;

public:
	A(int a = 1)
	{
		this->a = a;
		cout << "A()\n";
	}
	
	~A()
	{
		cout << "~A()\n";
	}
};

class B
{
protected:
	int b;

public:
	B(int b = 2)
	{
		this->b = b;
		cout << "B()\n";
	}

	~B()
	{
		cout << "~B()\n";
	}
};

class C : public B, public A
{
protected:
	int c;

public:
	C(int c = 3) : A(), B()
	{
		this->c = c;
		cout << "C()\n";
	}

	~C()
	{
		cout << "~C()\n";
	}
};

int main()
{
	Pets* zoo[10];
	int c=0;
	while (c<10)
	{
		zoo[c]=zoo[c]->createPets();
		if(zoo[c])
			c++;
	}
	for (int i = 0; i < c; i++)
	{
		cout<<zoo[i]->getName()<<endl;
		if(zoo[i]->getGender()=='m')
		{
			zoo[i]->speak();
		}
	}
	for (int i = 0; i < c; i++)
	{
		delete  zoo[i];
	}
	cout<<44877%3<<endl;
	return 0;
}