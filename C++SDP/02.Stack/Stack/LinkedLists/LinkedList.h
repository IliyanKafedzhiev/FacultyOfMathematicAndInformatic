#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList
{
public:
	// methods
	void pushFront(T& element);
	void insertBefore(Node<T>* node, const T& value);
	void insertAfter(Node<T>* node, const T& value);
	void pushBack(T&);
	void Print();
	T getFront();
	T getBack();
	bool removeFront();
	bool removeBack();
	// constructors
	LinkedList(LinkedList<T>&);
	LinkedList();
	~LinkedList();
	// operators
	LinkedList<T>& operator=(LinkedList<T>&);
	void TestIterators();
private:
	Node<T>* start;
	Node<T>* end;
	int size;
	void Delete();
	void Copy(LinkedList<T> &);
	class iterator;
	iterator begin()
	{
		iterator beg;
		beg.node = start;
		return beg;
	}
	iterator endOfList()
	{
		iterator beg;
		beg.node = NULL;
		return beg;
	}
	class iterator
	{
	public:
		Node<T>* node;
		iterator(){ node = NULL; }
		iterator(const iterator& other){ node = other.node; }
		iterator& operator=(const iterator& other)
		{
			if (other.node != node )
			{
				this->node = other.node;
			}
			return *this;
		}
		iterator& operator ++()
		{
			if (node)
			{
				node = node->linkToNextNode;
				return *this;
			}
			else
			{
				throw new exception("invalid interator");
			}
		}
		iterator& operator ++(int)
		{
			if (node)
			{
				iterator curr = *this;
				++*this;
				return curr;
			}
			else
			{
				throw new exception("invalid interator");
			}
		}
		bool operator ==(iterator & other)
		{
			if (node != NULL && other.node != NULL)
			{
				if (node == other.node)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				throw new exception("Invalid iterator");
			}
			return false;
		}
		bool operator !=(iterator & other)
		{
			if (node != NULL && other.node != NULL)
			{
				if (node != other.node)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				throw new exception("Invalid iterator");
			}
			return false;
		}
		T& operator *()
		{
			if (node)
			{
				return node->value;
			}
			else
			{
				throw new exception("invalid iterator");
			}
		}
		T* operator ->()
		{
			if (node)
			{
				return &(node->value);
			}
			else
			{
				throw new exception("invalid iterator");
			}
		}

		~iterator(){}
	};
};

template <typename T>
void LinkedList<T>::TestIterators()
{
	Node<int>* some = new Node<int>();
	some->value = 69;
	start = some;
	cout << *(this->begin()) << endl;
	cout << (this->endOfList()).node << endl;

}

template <typename T>
bool LinkedList<T>::removeBack()
{
	if (start != NULL)
	{
		Node<T>* toRemove = end;
		end = end->linkToExNode;
		end->linkToNextNode = NULL;
		delete toRemove;
		return true;
	}
	return false;
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	if (start !=NULL)
	{
		Node<T>* toRemove = start;
		start = start->linkToNextNode;
		start->linkToExNode = NULL;
		delete toRemove;
		return true;
	}
	return false;
}

template <typename T>
T LinkedList<T>::getBack()
{
	if (end == NULL)
	{
		throw exception("List is empty!");
	}
	return end->value;
}

template <typename T>
T LinkedList<T>::getFront()
{
	if (start == NULL)
	{
		throw exception("List is empty!");
	}
	return start->value;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T>& other)
{
	if (this != &other)
	{
		this->Delete();
		this->Copy(other);
	}
	return *this;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList& other)
{
	this->Copy(other);
}

template <typename T>
void LinkedList<T>::Print()
{
	int counter = 0;
	Node<T>* currNode = start;
	while (currNode)
	{
		cout << "Position " << counter++ << " : " << currNode->value << endl;
		currNode = currNode->linkToNextNode;
	}
}

template <typename T>
void LinkedList<T>::pushFront(T& element)
{
	if (this->start != NULL)
	{
		this->insertBefore(this->start, element);
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->value = element;
		newNode->linkToNextNode = NULL;
		newNode->linkToExNode = NULL;
		start = newNode;
		end = newNode;
	}
}

template <typename T>
void LinkedList<T>::insertBefore(Node<T>* node, const T& value)
{
	Node<T>* newNode = new Node<T>();
	*newNode = *node;
	node->value = value;
	node->linkToNextNode = newNode;
	newNode->linkToExNode = node;
	
	if (node == this->end)
	{
		this->end = newNode;
	}
	else
	{
		newNode->linkToNextNode->linkToExNode = newNode;
	}
	
}

template <typename T>
void LinkedList<T>::insertAfter(Node<T>* node, const T& value)
{
	Node<T>* newNode = new Node<T>();
	newNode->value = value;
	newNode->linkToNextNode = node->linkToNextNode;
	newNode->linkToExNode = node;
	if (node == end)
	{
		this->end = newNode;
	}
	else
	{
		newNode->linkToNextNode->linkToExNode = newNode;
	}
	node->linkToNextNode = newNode;
}

template <typename T>
LinkedList<T>::LinkedList()
{
	start = NULL;
	end = NULL;
	size = 0;
}

template <typename T>
void LinkedList<T>::pushBack(T& element)
{
	if (this->start != NULL)
	{
		this->insertAfter(this->end, element);
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->value = element;
		newNode->linkToNextNode = NULL;
		newNode->linkToExNode = NULL;
		start = newNode;
		end = newNode;
	}
}

template <typename T>
void LinkedList<T>::Copy(LinkedList<T> &list)
{
	this->start = this->end = NULL;
	Node<T>* temp = list.start;
	while (temp)
	{
		this->pushBack(temp->value);
		temp = temp->linkToNextNode;
	}
}

template <typename T>
void LinkedList<T>::Delete()
{
	Node<T>* temp;
	temp = start;
	while (temp)
	{
		start = temp->linkToNextNode;
		delete temp;
		temp = start;
	}
	start = NULL;
	end = NULL;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	this->Delete();
}

#endif // !LINKEDLIST_H
