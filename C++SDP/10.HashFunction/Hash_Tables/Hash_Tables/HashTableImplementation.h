#include "Pair.h"
#include <vector>
#include <list>
#include <iostream>
#include "HashTable.h"

using namespace std;

//offset 1+hash(key)/2 
//hash 
//lenght of aray should be prime number
template <typename T,typename V>
class HashSet :public HashTable<T,V>
{
private:
	int lenght;
	vector<list<Pair<T,V>>> table;
	int hash(T key)
	{
		return key % this->lenght;
	}
public:
	HashSet(int lenght) :lenght(0), table(lenght)
	{
	}

	virtual void Insert(Pair<T, V>& object)
	{
		this->lenght++;
		int positionByHash = this->hash(object.key);
		table[positionByHash].push_back(object);
		table[positionByHash].unique();
	}
	virtual bool  Countain(Pair<T, V>& object)
	{
		int positionByHash = this->hash(object.key);
		list<Pair<T, V>>::iterator beg = table[positionByHash].begin();
		list<Pair<T, V>>::iterator end = table[positionByHash].end();
		for (; beg != end; ++beg)
		{
			if (object == *(beg))
			{
				return true;
			}
		}
		return 0;
	}
	virtual void  Delete(Pair<T, V>& object)
	{
		int positionByHash = this->hash(object.key);
		table[positionByHash].remove(object);
	}
};