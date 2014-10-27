#include "Stack.h";
template <typename T>
Stack::Stack()
{
}

template <typename T>
Stack::~Stack()
{
}

template <typename T>
void node::Push(T a)
{
	node<int>* p = new node<int>;
	p->data = a;
	p->next = top;
}