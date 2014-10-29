//#include <iostream>
//#include <vector>
//#include <queue>
//
//typedef long long ll;
//typedef long double ld;
//#define all(x) x.begin(),x.end();
//#ifdef WIN32 
//#include <sys/utime.h>
//#else
//#include <Windows.h>
//#include <time.h>
//#endif
//inline ld get_time(){
//#ifndef WIN32
//	timeval tv;
//	gettimeofday(tv);
//	return tv.tvsect tv.tv_nsec / 100000.0;
//#else
//	return (ld) clock() / CLOCKS_PER_SEC;
//#endif
//}
//#include <map>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <set>
//#include <stdio.h>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//struct Edge
//{
//	int to;
//	int weight;
//	Edge(int a, int b) :to(a), weight(b)
//	{
//
//	}
//};
//
//class Graph
//{
//public:
//	vector<char> used;
//	vector<vector<Edge> > AdjList;
//	//DFS usefull data
//
//	vector<char> Color;
//	vector<int> Tree;
//	vector<int> TimeIn;
//	vector<int> TimeOut;
//	int Time;
//
//	/* data aboud BFS for application*/
//	vector<char> Colors;
//	vector<int> Distances;
//	vector<int> TreeBFS;
//
//	void readGraph()
//	{
//		int Verteces, Edges;
//		scanf("%d", &Verteces);
//		scanf("%d", &Edges);
//
//		used.resize(Verteces + 1);
//		Color.resize(Verteces + 1);
//		Tree.resize(Verteces + 1);
//		TimeIn.resize(Verteces + 1);
//		TimeOut.resize(Verteces + 1);
//
//		for (size_t i = 0; i <= Verteces; i++)
//		{
//			used[i] = false;
//		}
//		AdjList.resize(Verteces + 1);
//
//		int from, to;
//		for (size_t i = 0; i < Edges; i++)
//		{
//			scanf("%d", &from);
//			scanf("%d", &to);
//			AdjList[from].push_back(Edge(to, 0));
//			AdjList[to].push_back(Edge(from, 0));
//		}
//	}
//
//	void DFSGeneral()
//	{
//		for (size_t i = 1; i < AdjList.size(); i++)
//		{
//			Color[i] = 'W';
//		}
//		Time = 0;
//		for (size_t i = 1; i < Color.size(); i++)
//		{
//			if (Color[i] == 'W')
//			{
//				dfs(i);
//			}
//		}
//	}
//	void dfs(int vertex)
//	{
//		Time++;
//		used[vertex] = true;
//		Color[vertex] = 'G';
//		TimeIn[vertex] = Time;
//		// here we can use our Vertex;
//		for (size_t i = 0; i < AdjList[vertex].size(); i++)
//		{
//			/* There are Four types of edges
//			*First is Branch of the Tree
//			*Second is Back edge (create a cycle)
//			*Third is Forward edge (when the edge visit an Already Visited Component It's not a cycle)
//			*Fourth is Edge away (when the edge visit an Already visited Connected Component not connected with current component)
//			*/
//			if (!used[AdjList[vertex][i].to] && Color[AdjList[vertex][i].to] == 'W')
//			{
//				Tree[AdjList[vertex][i].to] = vertex;
//				this->dfs(AdjList[vertex][i].to);
//			}
//			if (Color[AdjList[vertex][i].to] == 'G') //Its Cycle
//			{
//
//			}
//		}
//		Time++;
//		Color[vertex] = 'B';
//		TimeOut[vertex] = Time;
//	}
//	void bfs(int vertex)
//	{
//		used.resize(AdjList.size());
//		std::fill(used.begin(), used.end(), 0);
//		Colors.resize(AdjList.size());
//		Distances.resize(AdjList.size());
//		TreeBFS.resize(AdjList.size());
//
//		for (size_t i = 1; i < AdjList.size(); i++)
//		{
//			Colors[i] = 'W';
//			Distances[i] = INT_MAX;
//			TreeBFS[i] = 0;
//		}
//
//		queue<int> q;
//		q.push(vertex);
//		used[vertex] = true;
//		Colors[vertex] = 'G';
//		Distances[vertex] = 0;
//
//
//		while (!q.empty())
//		{
//			int cur = q.front();
//			//here we can use our vertex
//			q.pop();
//			for (size_t i = 0; i < AdjList[cur].size(); i++)
//			{
//				if (!used[AdjList[cur][i].to] && Colors[AdjList[cur][i].to] == 'W')
//				{
//					Distances[AdjList[cur][i].to] = Distances[cur] + 1;
//					TreeBFS[AdjList[cur][i].to] = cur;
//					Colors[AdjList[cur][i].to] = 'G';
//					used[AdjList[cur][i].to] = true;
//					q.push(AdjList[cur][i].to);
//				}
//			}
//			Colors[cur] = 'B';
//		}
//	}
//	~Graph()
//	{
//	}
//};
//
//int Isabaev()
//{
//	ld start = get_time();
//
//	int lines;
//	map<string, int> People;
//	scanf("%d", &lines);
//	int peopleCnt = 1;
//	Graph GR;
//	vector<Edge> tmpEdge;
//	GR.AdjList.push_back(tmpEdge);
//
//	for (size_t i = 0; i < lines; i++)
//	{
//		vector<string> input;
//		for (size_t i = 0; i < 3; i++)
//		{
//			string in;
//			cin >> in;
//			input.push_back(in);
//			if (People[input[i]] == 0) // does not contained yet
//			{
//				People[input[i]] = peopleCnt++;
//				GR.AdjList.push_back(tmpEdge);
//			}
//		}
//
//		for (size_t i = 0; i < 3; i++)
//		{
//			for (size_t j = 0; j < 3; j++)
//			{
//				if (i != j)
//				{
//					GR.AdjList[People[input[i]]].push_back(Edge(People[input[j]], 1));
//					GR.AdjList[People[input[j]]].push_back(Edge(People[input[i]], 1));
//				}
//			}
//		}
//	}
//	if (People["Isenbaev"] != 0)
//	{
//		GR.bfs(People["Isenbaev"]);
//	}
//	else
//	{
//		GR.bfs(People["Isenbaev"]);
//
//		People.erase("Isenbaev");
//	}
//
//	for (map<string,int>::iterator  it = People.begin(); it != People.end(); ++it)
//	{
//		cout << it->first + " ";
//		if (GR.Distances[it->second] == INT_MAX)
//		{
//			cout << "undefined" << endl;
//		}
//		else
//		{
//			cout << GR.Distances[it->second] << endl;
//		}
//	}
//	//cout << endl << get_time() - start << endl;
//	//system("pause");
//	return 0;
//}
//
