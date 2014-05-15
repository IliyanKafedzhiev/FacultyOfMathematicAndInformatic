#include <iostream>
using namespace std;
  class A
    {
    public:
        A* operator &()
        {
            return this;
        }
        const A* operator&()const
        {
            return this;
        }
        void f(const A&a)
        {
            const A*pa=&a;
        }
        A();
        A(float);
        A(const A&);
        ~A();
        A* operator=(const A&);
        A (int); // konstryktor s edinstven argument
        A &operator =(double x);
        A &operator =(float x);
        A operator +(int) const;
        A operator +(const A&)const; //const v skobite ne promenq b cosnt sled skobite ne promenq a pri izraza a+b
        A (const A&) ? //koga se polzva copy construktora ?
            1) A a,b;
            A (a);
            2) f(A a) f(c))
            3) A p ()
                {
                    return c;
                }

    };
A A::operator +(const A&a)const // nikoga ne vrashtame psevdonim ot lokalen obekt  &
{
    A result;
    result.x=x+a.x;
    return result;
}
class Array
{
    int *a;
    int len;
public:
    operator int* ()
    {
        return a;
    }
    operator const int * () const
    {
        return a;
    }

    int &operator [](int index);
    const & operator [](int index)const;// za konstrantni psevdonimi / obekti
};
int & Array:: operator [](int index)// - vrashta psevdonim
{
    int validpos = getValidPoss(index);
    return a[validpos];
}
const int Array ::GetValidPoss(int i )const
{
    assert(i>=0 && i<size); // proverqva usloviqta ako sa validni prodaljava ako nesa validni Izliza proroche .. Abort Ignore pri debugvane
    if(i>=0 && i<size)
        return i;
    return 0;
}
int main ()
{
    return 0;
}
class B
{
public:
    B(int);
    operator int () // operator za kastvane  (int)a
    {
        return x;
    }
};
ostream & operator<<(ostream&os,const Vector&V)
{
    os<<v.x<<"  "<<x.y;
    return os;
}
istream & operator >>(istream&is,Vector&V)
{
    is>>v.x>>v.y;
    return is;
}
Vector& Vector :: operator+=(const Vector&v)
{
   this->x+=v.x;
    this->y+=v.y;
    return *this;
}
Vector operator +(const Vector&l,const Vector &r)
{
    Vector res(l);
    res+=r;
    return res;
}
