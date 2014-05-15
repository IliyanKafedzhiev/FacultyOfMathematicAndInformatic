template <typename T>
struct Node
{
	T value;
	Node<T>* linkToNextNode;
	Node<T>* linkToExNode;
};