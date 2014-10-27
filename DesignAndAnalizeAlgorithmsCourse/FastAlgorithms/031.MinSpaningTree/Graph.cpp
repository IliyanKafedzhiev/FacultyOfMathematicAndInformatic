#include "Graph.h"

Graph::Graph()
{
}

bool compare(std::pair<std::pair<int, int>, int > &a, std::pair<std::pair<int, int>, int > &b)
{
	return  a.second <  b.second;
}

Graph::~Graph()
{
}

bool Graph::readFromFile(const char* fileName)
{
	std::ifstream file(fileName, std::ios::in);
	if (!file)
	{
		return false;
	}
	int vertices;
	file >> vertices;
	this->vertices = vertices;
	
	while (!file.eof())
	{
		int from;
		file >> from;
		int to;
		file >> to;
		int weight;
		file >> weight;
		std::pair<int, int> edge(from, to);
		std::pair<std::pair<int, int>, int> weightedEdge(edge, weight);
		this->weightedEdges.push_back(weightedEdge);
		
	}
	file.close();
	return true;
}

void Graph::sortVertices()
{
	std::sort(this->weightedEdges.begin(), this->weightedEdges.end(), compare);
}

void Graph::GoKruskalAlgorithm_MinSpanningTree(const char* outputFileName)
{
	std::ofstream file(outputFileName, std::ios::out);
	if (!file)
	{
		return;
	}
	if (this->vertices - 1 > this->weightedEdges.size())
	{
		file << "There isn't spanning three Graph is not connected !";
		return;
	}
	this->sortVertices();
	UnionFind trees(this->vertices);
	std::vector<std::pair<std::pair<int, int>, int >>  spanningEdges;
	std::vector<std::pair<std::pair<int, int>, int >>::iterator currentEdge = this->weightedEdges.begin();
	std::vector<std::pair<std::pair<int, int>, int >>::iterator end = this->weightedEdges.end();
	for (; currentEdge != end; ++currentEdge)
	{
		if (spanningEdges.size() >= this->vertices - 1)
		{
			break; //we found the tree
		}
		if (!trees.connected(currentEdge->first.first, currentEdge->first.second))
		{
			trees.Union(currentEdge->first.first, currentEdge->first.second);
			spanningEdges.push_back(*(currentEdge));
		}
	}
	if (spanningEdges.size() >= this->vertices - 1)
	{
		file << "Spanning tree is found !" << std::endl;
		int sum = 0;
		for (size_t i = 0; i < spanningEdges.size(); i++)
		{
			file << spanningEdges[i].first.first << " - " << spanningEdges[i].first.second << ", weight: " << spanningEdges[i].second << std::endl;
			sum += spanningEdges[i].second;
		}
		file << "Final Weight of Spanning Tree :" << sum << std::endl;
	}
	
	file.close();
}