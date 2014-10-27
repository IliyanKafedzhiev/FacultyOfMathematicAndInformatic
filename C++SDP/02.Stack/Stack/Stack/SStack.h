#ifndef SSTACK_H
#define SSTACK_H

#include "Stack.h"

template <typename T >
class Sstack :
	public Stack<T>
{
private:
	T* container;
	int top;
	int size;
public:
	Sstack(int size = 0);
	Sstack(const Sstack<T>&);
	Sstack<T>& operator=(const Sstack<T>&);
	~Sstack(void);
	//functions
	 bool Resize();
	 bool isFull()const;
	 bool empty() const ;
	 bool push(T const&);
	 bool pop(T&) ;
	 bool peek(T&) const ;
};

template <typename T>
Sstack<T>::Sstack(int size = 1)
{
	this->container = new T[size];
	this->size = size;
	this->top = 0;
}

template <typename T>
Sstack<T>::Sstack(const Sstack<T>& other)
{
	this->container = new T[other.size];
	this->size = other.size;
	this->top = other.top;
	for (int i = 0; i < other.top; i++)
	{
		container[i] = other.container[i];
	}
}

template <typename T>
Sstack<T>& Sstack<T>::operator=(const Sstack<T>& other)
{
	if (this != &other)
	{
		delete this->container[];
		this->container = new T[other.size];
		this->size = other.size;
		this->top = other.top;
		for (int i = 0; i < other.top; i++)
		{
			this->container[i] = other.container[i];
		}
	}
	return *this;
}

template <typename T>
Sstack<T>::~Sstack()
{
	delete [] this->container ;
}

template <typename T>
bool Sstack<T>::empty() const
{
	return top == 0;
}

template <typename T>
bool Sstack<T>::push(T const& elem) 
{
	if (isFull())
	{
		if (!this->Resize())
		{
			return false;
		}
	}
	this->container[top++] = elem;
	return true;
}

template <typename T>
bool Sstack<T>::isFull() const
{
	return this->size == this->top;
}

template <typename T>
bool Sstack<T>::Resize() 
{
	T* newConteiner = new T[2*((size == 0)?1:size)];
	if (newConteiner == NULL)
	{
		return false;
	}
	for (int i = 0; i < top; i++)
	{
		newConteiner[i] = this->container[i];
	}
	this->container = newConteiner;
	return true;
}

template <typename T>
bool Sstack<T>::pop(T& elem)
{
	if (top < 1)
	{
		return false;
	}
	elem = container[top--];
	return true;
}

template <typename T>
bool Sstack<T>::peek(T& elem) const
{
	if (top < 1)
	{
		return false;
	}
	elem = container[top];
	return true;
}

#endif

