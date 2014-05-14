#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Element.h"

template <typename T >
class LinkedStack :
	public Stack<T>
{
private:
	Element<T>* top;
public:
	LinkedStack();
	LinkedStack(LinkedStack<T> &right); 
	~LinkedStack(void);
	//functions
	virtual bool empty() const ;
	virtual bool push(T const&) ;
	virtual bool pop(T&) ;
	virtual bool peek(T&) const ;
	void print () const;
	void cpyStack(LinkedStack<T> &);
};


template <typename T>
LinkedStack<T>::LinkedStack()
{
	top = NULL;
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T> &right)
{
	cpyStack(right);
}

template <typename T>
void LinkedStack<T>::cpyStack(LinkedStack<T> & stack)
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

template <typename T>
bool LinkedStack<T>::empty() const
{
	if (this->top == NULL)
	{
		return true;
	}
	return false;
}

template <typename T>
bool LinkedStack<T>::push(T const& element) 
{
	
	Element<T>* elem = new Element<T>();
	elem->data = element;
	elem->pointer = top;
	top = elem;
	return true;
}

template <typename T>
bool LinkedStack<T>::pop(T& element) 
{
	
	element = this->top->data;
	Element<T>* point = this->top->pointer;
	top = point;
	
	return true;
}

template <typename T>
bool LinkedStack<T>::peek(T& element) const
{
	
	element = this->top->data;
	return true;
}

template <typename T>
void LinkedStack<T>::print() const
{
	Element<T>* curr = top;
	while (curr)
	{
		cout<<curr->data<<endl;
		curr=curr->pointer;
	}
}

#endif