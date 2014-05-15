#include <iostream>
using namespace std;
class G
{
public:
    static int x;
    static int getx(); //nemoje da e const STatichen metod !
};
int G::x=5;
class A
{
public:
    static A* getA();
    static void freeA(A*&);
private:
    static const int MAX_INST=10;
    static int cnt;
    A()
    {
        ++cnt;
    };
    ~A()
    {
        --cnt;
    };
    A(const A&);
    void operator=(const A&);
};
class Seg
{
public:
    static Seg& getInstance();
private:
    Seg (){}
    Seg (const Seg&);
};
Seg& Seg::getInstance()
{
    static Seg theInstance;
    return theInstance;
}
int main ()
{
    cout<<G::x<<endl;
    A g;
    g.getA();
    g.freeA();
}

int A::cnt=0;
A *A::getA()
{
    cout<<cnt<<endl;
    if(cnt<A::MAX_INST)
    {
        return new A;
    }
    else
    {
        return NULL;

    }
}
void A::freeA(A*&a)
{

    delete a;
    a=NULL;
    cout<<cnt<<endl;
}
