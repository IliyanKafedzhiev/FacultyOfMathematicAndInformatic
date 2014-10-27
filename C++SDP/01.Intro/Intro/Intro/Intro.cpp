// Intro.cpp : Defines the entry point for the console application.
//

#include <iostream>;

#include "Functions.h";
#include "Stack.h";
#include "stdafx.h"

using namespace std;
 

int _tmain(int argc, _TCHAR* argv[])
{
	node<int>* p = new node<int>;
	p->data = 5;
	p->next = top;
	return 0;
}

