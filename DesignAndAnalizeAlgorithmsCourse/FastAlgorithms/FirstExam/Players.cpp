#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>

using namespace std;

/*DFS fist get value from childrens DFS(childs) then set win value for the NOde by this whose player is on move*/
struct Node
{
	int ID;
	int parent;
	bool isLeave;
	int value;
};
int N;
vector<vector<int > > AdjList(N + 1);
vector<Node> Tree(N + 1);


void DFS(Node& curNode,int level)
{
	int min = 3;
	int max = -3;
	for (size_t i = 0; i < AdjList[curNode.ID].size(); i++)
	{
		int childNode = AdjList[curNode.ID][i];
		DFS(Tree[childNode],level+1);

		if (Tree[childNode].value >= max)
		{
			max = Tree[childNode].value;
		}
		if (Tree[childNode].value <= min)
		{
			min = Tree[childNode].value;
		}
	}
	if (!curNode.isLeave)
	{
		if (level % 2 != 0)
		{
			curNode.value = min;
		}
		else
		{
			curNode.value = max;
		}
	}
}

void task3()
{
	scanf("%d", &N);
	AdjList.resize(N + 1);
	Tree.resize(N + 1);

	Tree[1].isLeave = false;
	Tree[1].parent = 0;
	Tree[1].value = -2;
	Tree[1].ID = 1;

	for (int i = 2; i <= N; i++)
	{
		char Type;
		cin >> Type;
		Tree[i].isLeave = (Type == 'N') ? false : true;
		Tree[i].ID = i;
		int parent;
		cin >> parent;
		AdjList[parent].push_back(i);

		Tree[i].parent = parent;
		if (Tree[i].isLeave)
		{
			int value;
			cin >> value;
			Tree[i].value = value;
		}
		else
		{
			Tree[i].value = -2;
		}
	}
	vector<bool> used(N + 1, false);

	DFS(Tree[1],0);
	if (Tree[1].value == -1)
	{
		cout << -1 << endl;
	}
	else if (Tree[1].value == 1)
	{
		cout << "+1" << endl;
	}
	else
	{
		cout << Tree[1].value << endl;
	}
	
}

