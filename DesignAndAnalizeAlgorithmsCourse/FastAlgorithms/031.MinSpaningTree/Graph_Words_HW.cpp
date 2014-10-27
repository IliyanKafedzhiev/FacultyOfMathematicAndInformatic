#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include <functional>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;

const int MAXN = 1002;
int uf[MAXN];
string words[MAXN];


struct Tup
{
	int first;
	int second;
	Tup(int f = 0, int s = 0)
	{
		first = f;
		second = s;
	}

	bool operator<(const Tup &other) const
	{
		int f = words[first].compare(words[other.first]);
		if (f > 0) return false;
		if (f < 0) return true;
		f = words[second].compare(words[other.second]);
		if (f > 0) return false;
		return true;
	}
};

int getCost(int a, int b)
{
	int minSize = min(words[a].length(), words[b].length());
	int cost = 0;
	for (int i = 0; i < minSize; i++)
	{
		cost += abs(words[a][i] - words[b][i]);
	}
	return cost;
}


int find(int x)
{
	int root, savex = x;
	while (uf[x] != x){
		x = uf[x];
	}
	root = x;
	x = savex;
	while (uf[x] != x){
		savex = x;
		x = uf[x];
		uf[savex] = root;
	}
	return root;
}

void setUnion(int a, int b)
{
	uf[find(a)] = find(b);
}

struct Edge
{
	int from;
	int to;
	int value;

	Edge(int f = 0, int t = 0, int v = 0)
	{
		from = f;
		to = t;
		value = v;
	}
};

class Cmp
{
public:

	bool operator()(Edge &a, Edge &b)
	{
		if (a.value > b.value) return true;
		if (a.value < b.value) return false;
		int f = words[a.from].compare(words[b.from]);
		if (f > 0) return true;
		if (f < 0) return false;
		f = words[a.to].compare(words[b.to]);
		if (f > 0) return true;
		return false;
	}


};



int lexiSortEdges(Tup &a, Tup &b)
{
	int f = words[a.first].compare(words[b.first]);
	if (f != 0) return f;
	return words[a.second].compare(words[b.second]);
}

void testEdgeCmp();

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
	}
	for (int i = 0; i < N; i++) uf[i] = i;

	priority_queue<Edge, vector<Edge>, Cmp> pq;
	//Edge pq[MAXN * MAXN / 2];
	int counter = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (words[i].compare(words[j]) < 0) pq.push(Edge(i, j, getCost(i, j)));
			//if(words[i].compare(words[j]) < 0) pq[counter++] = Edge(i, j, getCost(i, j));
			//else pq[counter++] = Edge(j, i, getCost(i, j));
			else pq.push(Edge(j, i, getCost(i, j)));
		}
	}

	//sort(pq, pq + counter, edgeCmp);


	//Edge MST[MAXN];
	Tup MST[MAXN];
	int edgesCounter = 0;

	int AZZZ = 0;
	while (!pq.empty())
		//for(int i = 0; i < counter; i++)
	{
		Edge current = pq.top();
		pq.pop();
		//Edge current = pq[i];
		if (find(current.from) != find(current.to))
		{
			setUnion(current.from, current.to);
			//MST[edgesCounter] = current;
			MST[edgesCounter] = Tup(current.from, current.to);
			edgesCounter++;
			AZZZ += current.value;
			if (edgesCounter == N - 1) break;
		}
	}

	//sort(MST, MST + N - 1, lexiSortEdges);
	sort(MST, MST + N - 1);

	for (int i = 0; i < N - 1; i++)
	{
		//cout << words[MST[i].from] << " " << words[MST[i].to] << " " << MST[i].value << endl;
		cout << words[MST[i].first] << " " << words[MST[i].second] << endl;
	}
	//cout << AZZZ << endl;
	return 0;

}