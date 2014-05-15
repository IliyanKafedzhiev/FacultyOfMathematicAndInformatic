#pragma once
template <typename T>
struct Node{
	T value;
	Node<T>* nextNode;
};
template <typename T>
class Iterator
{
	
public:
	Iterator();
	~Iterator();
};

