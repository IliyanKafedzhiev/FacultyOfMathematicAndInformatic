template<typename T> 
class Point
{
	T* x;
	T* y;
public:
	void print ()
	{
		cout<<*x<<" "<<*y<<endl;
	}
	Point (T* a, T* b)
	{
		x = a;
		y = b;
	}
};