#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
using namespace std;
template <typename T>
class BinarySearchTree
{
	struct Node
	{
		Node()
		{
			left = NULL;
			right = NULL;
			
		}
		T value;
		Node* left;
		Node* right;
		
	};
	Node* root;
	void deleteAll(Node* root)
	{
		if (root)
		{
			if (root->left)
			{
				deleteAll(root->left);
			}
			if (root->right)
			{
				deleteAll(root->right);
			}
			delete root;
			root = NULL;
		}
	}
	Node*& findLeftLeaf(Node* node)
	{
		Node* current = node;
		while (current->left)
		{
				current = current->left;
		}
		return current;
	}
	Node* PerentOfLeftLeaf(Node* node)
	{
		Node* current = node;
		while (current->left)
		{
			if (current->left->left == NULL)
			{
				return current;
			}
			current = current->left;
		}
		return current;
	}
public:
	void LeftLeaf()
	{
		cout << (this->findLeftLeaf(root))->value << endl;
	}
	bool Find(const T& elem)
	{
		if (root)
		{
			Node* current = root;
			while (current)
			{
				if (current->value == elem)
				{
					return true;
				}
				else if (current->value > elem)
				{
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
		}
		else
		{
			return false;
		}
		return false;
	}
	bool Insert(const T& elem)
	{

		if (root)
		{
			Node* current = this->root;

			while (current)
			{
				if (elem == current->value)
				{
					return false;
				}
				else if (elem < current->value)
				{
					if (current->left == NULL)
					{
						current->left = new Node();
						current->left->value = elem;
						return true;
					}
					current = current->left;
				}
				else
				{
					if (current->right == NULL)
					{
						current->right = new Node();
						current->right->value = elem;
						return true;
					}
					current = current->right;
				}
			}

		}
		else
		{
			root = new Node();
			root->value = elem;
			return true;
		}
		return false;
	}
	bool Remove(const T& elem)
	{
		if (root)
		{
			Node* current = root;
			if (current->value == elem)
			{
				Node* Perent = PerentOfLeftLeaf(current->right);
				current->value = Perent->left->value;
				delete Perent->left;
				Perent->left = NULL;
			}
			while (current)
			{
				if (current->value == elem)
				{
					return true;
				}
				else if (current->value > elem)
				{
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
		}
		else
		{
			return false;
		}
		return false;
	}
	BinarySearchTree();
	~BinarySearchTree();

};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	this->deleteAll(this->root);
}
#endif // !BINARYSEARCHTREE_H
