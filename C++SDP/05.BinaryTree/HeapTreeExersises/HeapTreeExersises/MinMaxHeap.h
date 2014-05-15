#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <vector>
using namespace std;
template <typename T, bool(*Comparator) (T&, T&)>
class MinMaxHeap
{
private:
	vector<T> data;
	void swap(size_t from, size_t to)
	{
		T temp = data[from];
		data[from] = data[to];
		data[to] = temp;
	}
	inline size_t Perent(size_t child)
	{
		if (child / 2 != 0)
		{
			return child / 2;
		}
		else
		{
			return -1;
		}
	}
	inline bool LeftChild(size_t index, size_t& child)
	{
		child = index * 2;
		if (Count() >= child)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	inline bool RightChild(size_t index, size_t& child)
	{
		child = index * 2 + 1;
		if (Count() >= child)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	int Count()
	{
		return data.size() - 1;
	}
	MinMaxHeap()
	{
		T a;
		data.push_back(a);
	}
	~MinMaxHeap(){ };
	void push(const T& elem){
		data.push_back(elem);
		size_t index = data.size() - 1;
		while (index > 1 && (*Comparator)(data[index], data[Perent(index)]))
		{
			size_t perentIndex = Perent(index);
			if (perentIndex > 0)
			{
				swap(index, Perent(index));
				index = Perent(index);
			}
		}
	}
	T* pop(){
		T* value = new T();
		*value = data[1];
		swap(1, data.size() - 1);
		data.pop_back();
		size_t index = 1;
		while (true)
		{
			size_t rightChildIndx;
			size_t leftChildIndx;
			size_t MaxOfChilds;
			if (!LeftChild(index, leftChildIndx))
			{
				break;
			}
			if (LeftChild(index, leftChildIndx) && !RightChild(index, rightChildIndx))
			{
				if ((*Comparator)(data[leftChildIndx], data[index]))
				{
					swap(index, leftChildIndx);
				}
				break;
			}
			if (!(*Comparator)(data[leftChildIndx], data[rightChildIndx]))
			{
				MaxOfChilds = rightChildIndx;
			}
			else
			{
				MaxOfChilds = leftChildIndx;
			}
			if ((*Comparator)(data[MaxOfChilds], data[index]))
			{
				swap(index, MaxOfChilds);
				index = MaxOfChilds;
			}
			else
			{
				break;
			}
		}
		return value;
	}
	void reOrder(){
		size_t index = 1;
		while (true)
		{
			size_t rightChildIndx;
			size_t leftChildIndx;
			size_t MaxOfChilds;
			if (!LeftChild(index, leftChildIndx))
			{
				break;
			}
			if (LeftChild(index, leftChildIndx) && !RightChild(index, rightChildIndx))
			{
				if ((*Comparator)(data[leftChildIndx], data[index]))
				{
					swap(index, leftChildIndx);
				}
				break;
			}
			if (!(*Comparator)(data[leftChildIndx], data[rightChildIndx]))
			{
				MaxOfChilds = rightChildIndx;
			}
			else
			{
				MaxOfChilds = leftChildIndx;
			}
			if ((*Comparator)(data[MaxOfChilds], data[index]))
			{
				swap(index, MaxOfChilds);
				index = MaxOfChilds;
			}
			else
			{
				break;
			}
		}
	}
};

//template <typename T>
//void MinMaxHeap<T>::swap(size_t from, size_t to)
//{
//	T temp = data[from];
//	data[from] = data[to];
//	data[to] = temp;
//}

//template <typename T>
//void MinMaxHeap<T>::push(const T& elem, bool(*Comparator) (T&, T&))
//{
//	data.push_back(elem);
//	size_t index = data.size() - 1;
//	while (index > 1 && (*Comparator)(data[index], data[Perent(index)]))
//	{
//		size_t perentIndex = Perent(index);
//		if (perentIndex > 0)
//		{
//			swap(index, Perent(index));
//			index = Perent(index);
//		}
//	}
//}

//template <typename T>
//T* MinMaxHeap<T>::pop(bool(*Comparator) (T&, T&))
//{
//	T* value = new T();
//	*value = data[1];
//	swap(1, data.size() - 1);
//	data.pop_back();
//	size_t index = 1;
//	while (true)
//	{
//		size_t rightChildIndx;
//		size_t leftChildIndx;
//		size_t MaxOfChilds;
//		if (!LeftChild(index, leftChildIndx))
//		{
//			break;
//		}
//		if (LeftChild(index, leftChildIndx) && !RightChild(index, rightChildIndx))
//		{
//			if ((*Comparator)(data[leftChildIndx] , data[index]))
//			{
//				swap(index, leftChildIndx);
//			}
//			break;
//		}
//		if (!(*Comparator)(data[leftChildIndx], data[rightChildIndx]))
//		{
//			MaxOfChilds = rightChildIndx;
//		}
//		else
//		{
//			MaxOfChilds = leftChildIndx;
//		}
//		if ((*Comparator)(data[MaxOfChilds], data[index]))
//		{
//			swap(index, MaxOfChilds);
//			index = MaxOfChilds;
//		}
//		else
//		{
//			break;
//		}
//	}
//	return value;
//}

#endif // !MINMAXHEAP_H
