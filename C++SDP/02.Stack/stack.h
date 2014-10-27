/*
 * stack.h
 *
 *  Created on: 24.10.2012
 *      Author: trifon
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename T>
class Stack {
public:
	virtual bool empty() const = 0;
	virtual bool push(T const&) = 0;
	virtual bool pop(T&) = 0;
	virtual bool peek(T&) const = 0;
};

#endif /* STACK_H_ */
