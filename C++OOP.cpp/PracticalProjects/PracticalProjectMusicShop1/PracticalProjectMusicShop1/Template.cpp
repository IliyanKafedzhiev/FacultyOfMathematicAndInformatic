template <typename T>
class Cont

{
public:
	Cont(int size=2);
	Cont(const Cont<T>& c);
	~Cont();
	void add(const T& obj);
private:
	T* items;
	int size;
};
template<typename T>
Cont<T>::Cont(const Cont<T>& c)
{
	this->items = new Cont<T>[c.size];
	this->size  = c.size;
	for (int i = 0; i < this-> size; i++)
	{
		this->items[i]=c.items[i];
	}
}
template <typename T>
Cont<T>::Cont(int size)
{
	this->items= new T[size];
	this->size = size;
}

template <typename T>
Cont<T>::~Cont()
{
	delete [] items;
}

template <typename T>
void Cont<T>::add(const T& obj)
{
	if (isFull())
	{
		//resize;
	}
	this->items[this-size] = obj;
}
Cont<int> c;