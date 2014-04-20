#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <deque>
#include <queue>


using namespace std;

struct String
{
	string a;
	bool operator<(const String& other)const
	{
		return a > other.a;
	}
};

class GraphV
{
	map<string, pair<int, int > > Verteces; // map action ->(index,degeree)
	map<int, string> NameByID;
	set<string> VertecesIndependet;
	vector<int> indegArray;
	vector<vector<int > > AdjList;
	vector<bool> used;
	deque<int> TopSort;

public:
	void ReadGraphFromConsole()
	{
		int Lines; scanf("%d", &Lines);
		int VerId = 0;
		AdjList.push_back(vector<int>());
		for (size_t i = 0; i < Lines; i++)
		{
			char* FromAction = new char[17];
			scanf("%16s", FromAction);
			string from(FromAction);
			int fromID;

			char* ToAction = new char[17];
			scanf("%16s", ToAction);
			string to(ToAction);
			int toID;

			map<string, pair<int, int > >::iterator itFrom = Verteces.find(from);
			if (itFrom == Verteces.end())
			{
				Verteces.insert(pair<string, pair<int, int> >(from, pair<int, int>(++VerId, 0)));
				AdjList.push_back(vector<int>());
				fromID = VerId;
				NameByID.insert(pair<int, string>(fromID, from));
			}
			else
			{
				fromID = itFrom->second.first; //get Elem ID
			}

			map<string, pair<int, int > >::iterator itTo = Verteces.find(to);
			if (itTo == Verteces.end())
			{
				Verteces.insert(pair<string, pair<int, int> >(to, pair<int, int>(++VerId, 1)));
				AdjList.push_back(vector<int>());
				toID = VerId;
				NameByID.insert(pair<int, string>(toID, to));
			}
			else
			{
				toID = itTo->second.first;
				itTo->second.second++; // encrease Degree
			}
			AdjList[fromID].push_back(toID); //create Edge
		}

		used.resize(VerId + 1);
		for (map<string, pair<int, int > >::iterator i = Verteces.begin(); i != Verteces.end(); ++i)
		{
			used[VerId--] = false;
			if (i->second.second == 0)
			{
				VertecesIndependet.insert(i->first);
			}
		}
	}

	void RunTSWithPriorityQueue()
	{
		priority_queue<String> q;
		for (set<string>::iterator i = VertecesIndependet.begin(); i != VertecesIndependet.end(); ++i)
		{
			String a; a.a = *i;
			q.push(a);
		}
		while (!q.empty())
		{
			String ax = q.top();
			string action = ax.a;
			q.pop();
			

			for (size_t i = 0; i < AdjList[Verteces[action].first].size(); i++)
			{
				int idTo = AdjList[Verteces[action].first][i];
				if (Verteces[NameByID[idTo]].second == 1)
				{
					String a; a.a = NameByID[idTo];
					q.push(a);
				}
				else
				{
					Verteces[NameByID[idTo]].second--;
				}
			}
			TopSort.push_back(Verteces[action].first);
		}
	}

	void RunTopologicalSort()
	{
		for (set<string>::iterator i = VertecesIndependet.begin(); i != VertecesIndependet.end(); ++i)
		{
			dfs(*i);

		}
	}

	void dfs(const string& VertexName)
	{
		if (!used[Verteces[VertexName].first])
		{
			TopSort.push_back(Verteces[VertexName].first);
			used[Verteces[VertexName].first] = true;
			set<string> Childrens;
			for (size_t i = 0; i < AdjList[Verteces[VertexName].first].size(); i++)
			{
				int idTo = AdjList[Verteces[VertexName].first][i];
				if (Verteces[NameByID[idTo]].second == 1)
				{
					Childrens.insert(NameByID[idTo]);
				}
				else
				{
					Verteces[NameByID[idTo]].second--;
				}
			}
			for (set<string>::iterator i = Childrens.begin(); i != Childrens.end(); ++i)
			{
				dfs(*i);
			}

		}
	}

	void PrintTopologicalSortActions()
	{
		for (size_t i = 0; i < TopSort.size(); i++)
		{
			printf("%s", NameByID[TopSort[i]].c_str());
			if (i == TopSort.size() - 1)
			{
				printf(" ");
			}
			else
			{
				printf(" ");
			}
		}
	}
};

int mainQ()
{
	GraphV s;
	s.ReadGraphFromConsole();
	s.RunTSWithPriorityQueue();
	s.PrintTopologicalSortActions();
	return 0;
}