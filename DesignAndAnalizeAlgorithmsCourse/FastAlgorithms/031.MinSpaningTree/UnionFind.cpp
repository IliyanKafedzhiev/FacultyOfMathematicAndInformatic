#include "UnionFind.h"


UnionFind::UnionFind(int N)
{
	id.resize(N);
	sizeOfTree.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		id[i] = i;
		sizeOfTree[i] = 1;
	}
}


bool UnionFind::connected(int p, int q)
{
	return this->root(p) == this->root(q);
}

void UnionFind::Union(int p, int q)
{
	int i = root(p);
	int j = root(q);
	if (i == j)
	{
		return;
	}
	if (sizeOfTree[i] < sizeOfTree[j])
	{
		id[i] = j;
	}
	else
	{
		id[j] = i;
		if (sizeOfTree[j] == sizeOfTree[i])
		{
			sizeOfTree[i] += 1;
		}
	}
}

int UnionFind::root(int i)
{
	while (i != id[i])
	{
		id[i] = id[id[i]]; // optimaize the tree
		i = id[i];
	}
	return i;
}