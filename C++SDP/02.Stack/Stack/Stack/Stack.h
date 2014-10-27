#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack
{
public:
	virtual bool empty() const = 0;
	virtual bool push(T const&) = 0;
	virtual bool pop(T&) = 0;
	virtual bool peek(T&) const = 0;
};
#endif;

