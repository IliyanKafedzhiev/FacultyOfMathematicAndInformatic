/*
 * linked_list.cpp
 *
 *  Created on: 14.11.2012
 *      Author: trifon
 */

#include "list.h"

template <typename T>
struct elem
{
	T inf;
	elem* link;
};

// декларация на шаблон
template <typename T>
class LinkedList;

template <typename T=int>
class LinkedListIterator : public Iterator<T>
{
	friend class LinkedList<T>;

	elem<T>* p;
public:

	LinkedListIterator(elem<T>* _p = NULL) : p(_p) {}

	Iterator<T>& operator++() {
		if (p != NULL)
			p = p->link;
		return *this;
	}

	LinkedListIterator<T> operator++(int) {
		LinkedListIterator<T> it = *this;
		++(*this);
		return it;
	}

	T& operator*() const {
		return p->inf;
	}

	operator bool() const {
		return p != NULL;
	}

	bool operator==(Iterator<T> const& it) const {
		LinkedListIterator<T> const & llit =
					(LinkedListIterator<T> const &)it;
		return llit.p == p;
	}

};

template <typename T=int>
class LinkedList : public List<T, LinkedListIterator<T> >
{
elem<T>* start;
elem<T>* end;

private:
	void copyList(LinkedList<T> const& l)
	{
		start = end = NULL;
		for(I it = l.iteratorBegin(); it; ++it)
			toEnd(*it);
	}

	void deleteList()
	{
		elem<T>* p = start;
		while(start)
		{
			start = start->link;
			delete p;
			p = start;
		}
		end = NULL;
	}

public:
	LinkedList() : start(NULL), end(NULL) {}

	LinkedList(LinkedList<T> const& l) {
		copyList(l);
	}

	LinkedList<T>& operator=(LinkedList<T> const& l) {
		if (&l != this)
		{
			deleteList();
			copyList(l);
		}
		return *this;
	}

	~LinkedList() {
		deleteList();
	}

	typedef LinkedListIterator<T> I;

	bool empty() const { return start == NULL; }

	void toEnd(T const& x) { insertAfter(x, iteratorEnd()); }

	I iteratorBegin() const
	{
		return I(start);
	}

	I iteratorEnd() const
	{
		return I(end);
	}

	// O(n)
	void insertBefore(T const& x, I const& it)
	{
		I p = iteratorBegin();
		if (p == it)
		{
			start = new elem<T>;
			start->inf = x;
			start->link = it.p;
			if (end == NULL)
				end = start;
		} else {
			I q = p++;
			while (p && p != it)
			{
				q = p++;
			}
			// p == it
			if (p)
				insertAfter(x, q);
		}
	}

	// O(1)
	void insertAfter(T const& x, I const& it)
	{
		if (!it.p && start != NULL) return;
		elem<T>* p = new elem<T>;
		if (!p) return;
		p->inf = x;
		if (empty())
		{
			start = end = p;
			p->link = NULL;
		} else
		{
			p->link = it.p->link;
			it.p->link = p;
			if (end == it.p)
				end = p;
		}
	}

	// O(n)
	bool deleteBefore(T& x, I& it)
	{
		if (!it)
			return false;
		I p = iteratorBegin();
		if (p == it)
			return false;
		I q = p++;
		while (p && p != it)
			q = p++;
		if (p == NULL)
			return false;
		return deleteAt(x, q);
	}

	// O(1)
	bool deleteAfter(T& x, I& it)
	{
		if (!it)
			return false;
		elem<T>* q = it.p->link;
		if (q == NULL)
			return false;
		it.p->link = q->link;
		x = q->inf;
		if (end == q)
			end = it.p;
		delete q;
		return true;
	}

	// O(n)
	bool deleteAt(T& x, I& it)
	{
		if (!it)
			return false;
		I p = iteratorBegin();
		if (p == it)
		{
			if (end == start)
				end = NULL;
			start = start->link;
			x = it.p->inf;
			delete it.p;
			it.p = NULL;
			return true;
		} else {
			I q = p++;
			while (p && p != it)
			{
				q = p++;
			}
			// p == it
			if (p)
			{
				it.p = NULL;
				return deleteAfter(x, q);
			}
			return false;
		}
	}

//	friend ostream& operator<<(ostream&,LinkedList<T> const&);

	void print() const {
		for(I it = iteratorBegin(); it; ++it)
			cout << *it << ' ';
		cout << endl;
	}

};

/**
 * Предефиниране на оператор << за обекти от тип LinkedList. 
 * Целта е да може да се пише cout << list; вместо list.print();
 */
template <typename T>
ostream& operator<<(ostream& os, LinkedList<T> const& l)
{
	for(LinkedListIterator<T> it = l.iteratorBegin(); it; ++it)
		os << *it << ' ';
	os << endl;
	return os;
}












