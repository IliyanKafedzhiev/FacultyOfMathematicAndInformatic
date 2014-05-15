#include <iostream>
#include <cstring>
using namespace std;
class Vector
{
private:
    friend ostream& operator<<(ostream&,const Vector);
    friend istream& operator>>(istream&,Vector&);
    double x , y;
    friend class A; // klasa A stava priqtel na A
    friend void F(); //funkciq priqtel na vsichki chlen danni
    //friend void A::fun();
public:
    Vector(double x=0,double y=0):x(x),y(y){}
    Vector&operator+=(const Vector &);
    Vector&operator-=(const Vector &);
    Vector&operator^=(const Vector &);
    Vector&operator*(const Vector&)const;
    Vector& operator *=(double x);
    double operator ()()const;
    double operator ()(const Vector&)const;
    Vector operator_ ()const;
    bool operator  ==(const Vector&)const;
    bool operator  <(const Vector&)const;
    double operator [](unsigned)const;
    double& operator [](unsigned);
    Vector &operator ++();
    Vector &operator ++(int);
    Vector &operator --();
    Vector &operator --(int);

};
int main()
{
    return 0;
}
