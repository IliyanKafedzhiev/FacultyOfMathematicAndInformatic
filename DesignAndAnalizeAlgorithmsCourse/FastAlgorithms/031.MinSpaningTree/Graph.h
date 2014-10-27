#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "UnionFind.h"

class Graph
{
	std::vector<std::pair<std::pair<int, int>, int >>  weightedEdges;
	int vertices;

	
	void sortVertices();
public:
	Graph();
	~Graph();
	bool readFromFile(const char* fileName);
	void GoKruskalAlgorithm_MinSpanningTree(const char* outputFile);

};
#endif
