
template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T);

private:

};

//Linked representation
template <typename T>
struct node
{
	T data;
	node* next;
};
