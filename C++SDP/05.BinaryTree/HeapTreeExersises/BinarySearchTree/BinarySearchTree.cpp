// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

template class BinarySearchTree<int>;

int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree<int> tree;
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	tree.Insert(2);
	tree.Insert(7);
	tree.Insert(12);
	tree.Insert(20);
	tree.Insert(9);
	//tree.LeftLeaf();
	tree.Remove(10);
	return 0;
}

