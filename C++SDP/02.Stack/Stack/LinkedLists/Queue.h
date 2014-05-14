#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();


	void Push(const T&);
	T Pop();
private:
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
T Queue<T>::Pop()
{
	if (tail == NULL)
	{
		throw new exception();
	}
	Node<T>* newNode = new Node<T>;
	newNode->value = v;
	newNode->linkToNextNode = NULL;
	
}

template <typename T>
void Queue<T>::Push(const T& v)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = v;
	newNode->linkToNextNode = NULL;
	if (tail != NULL)
	{
		tail->linkToNextNode = newNode;
	}
	tail = newNode;
	if (head == NULL)
	{
		head = newNode;
	}
}

template <typename T>
Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	if (head != NULL)
	{
		Node<T>* tmp = head;
		while (head)
		{
			head = tmp->linkToExNode;
			delete tmp;
		}
	}
}

#endif // !QUEUE_H
