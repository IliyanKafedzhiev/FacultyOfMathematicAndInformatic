#include "linked_list.cpp"
#include <iostream>
using namespace std;

/**
 * Слива два сортирани във възходящ ред списъка.
 */
template <typename T, typename I>
List<T, I>& merge(List<T, I> const& l1, List<T, I> const& l2,
		           List<T, I>& l)
{
	I p = l1.iteratorBegin(), q = l2.iteratorBegin();
	while (p && q)
	{
		if (*p < *q)
			l.toEnd(*p++);
		else
			l.toEnd(*q++);
	}
	while (p)
		l.toEnd(*p++);
	while (q)
		l.toEnd(*q++);
	return l;
}

/**
 * Сортира даден свързан списък, прилагайки алгоритъма "сортиране със сливане".
 */
template <typename T>
void mergeSort(LinkedList<T>& list)
{
	LinkedListIterator<T> it = list.iteratorBegin();
	if (! it || it == list.iteratorEnd()) // ако е празен или съдържа само един елемент
	{
		return;
	}
	LinkedList<T> l1, l2;
	while (it)
	{
		l1.toEnd(*it);
		++it;
		if (it)
		{
			l2.toEnd(*it);
			++it;
		}
	}
	// cout << list << l1 << "and " << l2 << endl;
	mergeSort(l1);
	mergeSort(l2);
	LinkedList<T> result;
	merge(l1, l2, result);
	list = result;
}

/*int main()
{
	LinkedList<int> list;
	list.toEnd(1);
	list.toEnd(5);
	list.toEnd(3);
	list.toEnd(8);
	list.toEnd(7);
	list.toEnd(2);

	mergeSort(list);

	cout << list << endl;

	return 0;
}
*/

