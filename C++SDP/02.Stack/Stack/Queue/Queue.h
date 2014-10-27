#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue
{
private:
	T* elements;
	int cap;
	int head;
	int tail;
public:
	Queue(int cap = 10);
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	~Queue(void);

	//functions
	bool isFull()
	{
		return (tail + 1) % cap == head;
	}
	Queue<T>& Push(cosnt T& newEl)
	{
		if (isFull())
		{
			Resize();
		}
		tail=(tail+1)%cap;
		elements[tail] = newEl;
		return *this;
	}
	Queue<T>& Pop(T& elm)
	{
		if (empty())
		{
			return *this;
		}
		elm = elements[head];
		head = (head + 1)%cap;
		return *this;
	}
	Queue<T>& Peek(T& elm)
	{
		if (empty())
		{
			return *this;
		}
		elm = elements[head];
		return *this;
	}
};
#endif