#include "UnionFind.h"
#include "Graph.h"

void testUnionFind(){
	UnionFind set(10);
	set.Union(1, 0);
	set.Union(1, 2);
	set.Union(1, 3);
	set.Union(1, 4);
	set.Union(9, 0);
	set.Union(9, 0);
	cout << set.connected(9, 5) << endl;
}
void TestKruskal()
{
	Graph network;
	network.readFromFile("input.txt");
	network.GoKruskalAlgorithm_MinSpanningTree("output.txt");
}


int main()
{
	//testUnionFind();
	TestKruskal();
	return 0;
}