/*
 * list.h
 *
 *  Created on: 14.11.2012
 *      Author: trifon
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

template <typename T, typename I>
class List
{
public:
	virtual bool empty() const = 0;

	virtual void toEnd(T const&) = 0;
	virtual void insertAfter(T const&, I const&) = 0;
	virtual void insertBefore(T const&, I const&) = 0;

	virtual I iteratorBegin() const = 0;
	virtual I iteratorEnd() const = 0;

	virtual bool deleteAt(T&, I&) = 0;
	virtual bool deleteBefore(T&, I&) = 0;
	virtual bool deleteAfter(T&, I&) = 0;

	virtual void print() const = 0;

	virtual ~List() {}
};

template <typename T>
class Iterator
{
public:
	virtual Iterator& operator++() = 0;
	// ++p
//	virtual Iterator operator++(int) = 0;
	// p++
	virtual T& operator*() const = 0;
	// cout << *p;
	// *p = x;
	virtual operator bool() const = 0;
	// if (p) { cout << *p; }
	virtual bool operator==(Iterator const&) const = 0;
	// if (p == q)
	virtual bool operator!=(Iterator const& i) const
	{ return !operator==(i); }
};







#endif /* LIST_H_ */

