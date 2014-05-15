#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(const T&);
	T Pop();
	T Peek()const;
	void Copy(const Stack<T>&);
	void Delete();

private:
	Node<T>* top;
};

template <typename T>
void Stack<T>::Copy(const Stack<T> &other)
{
	Delete();
	Node<T>* currObject = other.top;
	Node<T>* newObject = new Node<T>();
	newObject->value = currObject->value;
	newObject->linkToNextNode = NULL;
	top = newObject;
	Node<T>* temp = top;
	currObject = currObject->linkToNextNode;
	while (currObject)
	{
		Node<T>* newObject = new Node<T>();
		newObject->value = currObject->value;
		newObject->linkToNextNode = NULL;
		temp->linkToNextNode = newObject;
		temp = newObject;
		currObject = currObject->linkToNextNode;
	}

}

template <typename T>
void Stack<T>::Delete()
{
	Node<T>* tmp = top;
	while (top)
	{
		top = tmp->linkToNextNode;
		delete tmp;
		tmp = top;
	}
	top = NULL;
}

template <typename T>
T Stack<T>::Pop()
{
	if (top == NULL)
	{
		throw new exception("Stack is empty");
	}
	Node<T>* val = top;
	top = top->linkToNextNode;
	T value = val->value;
	delete val;
	return value;
}

template <typename T>
void Stack<T>::Push(const T& var)
{
	Node<T>* cur = new Node<T>;
	cur->value = var;
	cur->linkToNextNode = top;
	top = cur;
}

template <typename T>
Stack<T>::Stack()
{
	this->top = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	Delete();
}

#endif // !STACK_H
