/*
 * sstack.cpp
 *
 *  Created on: 24.10.2012
 *      Author: trifon
 */

#include "stack.h"

const int MAX = 100;
const int INVALID = -1;

template <typename T = int>
class SStack : public Stack<T>
{
private:
	T* s;
	int top;
	int size;

	// O(n)
	void copystack(SStack const& stack) {
		s = new T[stack.size];
		top = stack.top;
		size = stack.size;
		for(int i = 0; i <= stack.top; i++)
			s[i] = stack.s[i];
	}

public:
	SStack(int _size = MAX) :
		top(INVALID), size(_size) {
		s = new T[size];
	}

	~SStack()
	{
		delete[] s;
	}

	// O(n)
	SStack(SStack const& stack) {
		copystack(stack);
	}

	// O(n)
	SStack& operator=(SStack const& stack)
	{
		if (this != &stack) {
			delete[] s;
			copystack(stack);
		}
		return *this;
	}

	bool empty() const {
		return top == INVALID;
	}

	bool full() const {
		return top == size - 1;
	}

	bool push(T const& x) {
		if (full())
			return false;
		s[++top] = x;
		return true;
	}

	bool pop(T& x) {
		if (empty())
			return false;
		x = s[top--];
		return true;
	}

	bool peek(T& x) const {
		if (empty())
			return false;
		x = s[top];
		return true;
	}







};
