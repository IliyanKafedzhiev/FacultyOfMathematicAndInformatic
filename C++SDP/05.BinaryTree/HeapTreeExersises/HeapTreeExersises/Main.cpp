#include <iostream>

#include "Iterator.h";
#include "MinMaxHeap.h";

using namespace std;

template class Iterator<int>;
template class MinMaxHeap<int>;

int main()
{
	MinMaxHeap<int> heap;
	heap.push(4);
	heap.push(3);
	heap.push(7);
	heap.push(2);
	heap.push(11);
	heap.push(0);
	heap.push(77);
	heap.push(99);
	heap.push(13);
	while (heap.Count() > 0)
	{
		cout << *(heap.pop()) << endl;
	}
	return 0;
}