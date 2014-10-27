#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Pair.h"

template <typename T, typename V>
class HashTable
{
public:
	virtual void  Insert(Pair<T, V>& c) = 0;
	virtual bool  Countain(Pair<T, V>& v) = 0;
	virtual void  Delete(Pair<T, V>& c) = 0;
private:

};

#endif // !HASHTABLE_H
