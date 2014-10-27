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
	Werewolf Pesho();

	return 0;
}