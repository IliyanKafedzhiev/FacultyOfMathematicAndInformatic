/*
 * lstack.cpp
 *
 *  Created on: 24.10.2012
 *      Author: trifon
 */

#include "stack.h"
using namespace std;

template <typename T = int>
class LStack : public Stack<T>
{
public:
	template <typename U = int>
	struct elem {
		U inf;
		elem<U>* link;
	};

private:
	elem<T>* top;

	void delstack()
	{
		T tmp;
		while (pop(tmp));
	}

	// O(n)
	void copystack(LStack<T> const& stack)
	{
		if (stack.top == NULL)
		{
			top = NULL;
			return;
		}
		// stack.top != NULL
		elem<T>* p = stack.top;
		top = new elem<T>;
		top->inf = p->inf;
		elem<T>* r = top;
		elem<T>* q;
		p = p->link;
		// p - елементът, който ще копираме
		// q - елементът, който създаваме
		// r - последно създаденият елемент
		while (p)
		{
			q = new elem<T>;
			q->inf = p->inf;
			r->link = q;
			p = p->link;
			r = q;
		}
		r->link = NULL;
	}

public:
	LStack() : top(NULL) {}

	// O(n)
	LStack(LStack const& stack)
	{
		copystack(stack);
	}

	// O(n)
	LStack& operator=(LStack const& stack)
	{
		if (this != &stack)
		{
			delstack();
			copystack(stack);
		}
		return *this;
	}

	~LStack() {
		delstack();
	}

	bool empty() const {
		return top == NULL;
	}

	bool push(T const& x) {
		elem<T>* p = new elem<T>;
		if (p == NULL)
			return false;
		p->inf = x;
		p->link = top;
		top = p;
		return true;
	}

	bool peek(T& x) const {
		if (empty())
			return false;
		x = top->inf;
		return true;
	}

	bool pop(T& x) {
		if (!peek(x))
			return false;
		elem<T>* p = top;
		top = top->link;
		delete p;
		return true;
	}

	// O(n)
	void print() const
	{
		elem<T>* p = top;
		while (p)
		{
			cout << p->inf << endl;
			p = p->link;
		}
	}









};
