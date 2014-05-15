#include <stack>
#include <queue>
#include <iostream>

#include "LinkedList.h"
#include "Stack.h"

using namespace std;

template class LinkedList<int>;// check for compilation errors 
template class Stack<int>;// check for compilation errors 
void testStack()
{
	Stack<int> h;
	for (int i = 0; i < 10; i++)
	{
		h.Push(i);
	}
	Stack<int> z;
	z.Copy(h);
	for (int i = 0; i < 10; i++)
	{
		cout << z.Pop() << endl;
	}
}
void testListIterators()
{
	LinkedList<int> s;
	s.TestIterators(); 
}
int main()
{
	
	try
	{
		testListIterators();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}