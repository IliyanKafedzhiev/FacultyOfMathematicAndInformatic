//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//vector<vector <pair<bool, int> > >  Graph;
//
//void ReadInput()
//{
//	int vertex;
//	cin >> vertex;
//
//	int sizeOfVectorPaths;
//	cin >> sizeOfVectorPaths;
//
//	Graph.resize(vertex);
//	for (size_t i = 0; i < Graph.size(); i++)
//	{
//		Graph[i].resize(vertex);
//		for (size_t k = 0; k < Graph.size(); k++)
//		{
//			Graph[i][k].first = false;
//			Graph[i][k].second = INT_MAX;
//		}
//	}
//
//	for (size_t i = 0; i < sizeOfVectorPaths; i++)
//	{
//		int from, to,weight;
//		cin >> from;
//		cin >> to;
//		cin >> weight;
//		Graph[from][to].first = true;
//		Graph[from][to].second = weight;
//	}
//}
//
//void  Floid()
//{
//	for (size_t i = 0; i < Graph.size(); i++)
//	{
//		for (size_t j = 0; j < Graph.size(); j++)
//		{
//			for (size_t k = 0; k < Graph.size(); k++)
//			{
//				int NewPath = Graph[i][k].second + Graph[k][j].second;
//				if (Graph[i][j].second > NewPath)
//				{
//					Graph[i][j].second = NewPath;
//				}
//			}
//		}
//	}
//}
//
//int mainWE()
//{
//	ReadInput();
//	Floid();
//	return 0;
//}
//
///*
//5 7
//1 4 1
//1 3 300
//3 1 10
//1 2 16
//2 3 100
//2 5 15
//5 3 20
//*/