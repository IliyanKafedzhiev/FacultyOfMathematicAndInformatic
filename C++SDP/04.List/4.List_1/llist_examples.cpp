/*
 * llist_examples.cpp
 *
 *  Created on: 21.11.2012
 *      Author: trifon
 */

#include <iostream>
#include "linked_list.cpp"
using namespace std;

typedef LinkedList<> TestList;

/**
 * Копира елементите на даден списък към края на друг даден списък, т.е. l += l2.
 */
template <typename T, typename I>
void concatenate(List<T, I>& l, List<T, I> const& l2)
{
	for(I it = l2.iteratorBegin(); it; ++it)
		l.toEnd(*it);
}

void concatLists() {
	TestList l1, l2;
	int i;
	for(i = 1; i <= 5; i++)
		l1.toEnd(i);
	for(;i <= 10; i++)
		l2.toEnd(i);
	concatenate(l1, l2);
	l1.print();
}

template <typename T, typename I>
void reverse(List<T, I>& l)
{
	I it = l.iteratorBegin();
	// it към началото на оригиналния списък
	T x;
	while (l.deleteAfter(x, it))
		l.insertBefore(x, l.iteratorBegin());
}

void reverseList() {
	TestList l;
	int i;
	for(i = 1; i <= 5; i++)
		l.toEnd(i);
	reverse(l);
	l.print();
}

int main()
{
//	concatLists();
//	reverseList();
	return 0;
}

