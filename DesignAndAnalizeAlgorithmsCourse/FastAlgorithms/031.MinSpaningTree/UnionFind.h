#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>
#include <iostream>
using namespace std;

class UnionFind
{
	vector<int> id;
	vector<int> sizeOfTree;
	int root(int i);
public:
	UnionFind(int N);
	~UnionFind(){};
	bool connected(int p, int q);
	void Union(int p, int q);
};

#endif
