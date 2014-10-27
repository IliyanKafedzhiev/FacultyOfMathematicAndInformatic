#include <iostream>
#include <cstring>
using namespace std;
// Nasledqvane i Exeptions
class Base:
{
public:
    Base();
    Base(const Base&);
    ~Base();
    Base (int x);
    Base &operator=(const Base&);
    int getX() const;
protected:
    int p;
private:
    int x;
};
class Det:public Base
{
public:
    Der():Base(13) //izvikvane na konstruktora na Base
    {
        y=5;
    }
    Der(const Der&d):Base (d)
    {
        y=d.y;
    }
    ~Der()
    {
        cout<<"GoodBuy";
    }
    Der& operator=(const Der&d)
    {
        if(this!=&d)
        {
            Base::operator=(d);
            (Base)(*this)=d;
        }
    }
    void print () const
    {
        cout<<p<<y<<getx()<<endl;// nemoga da izveda x.edinstveno sas aksesori
    }
    int getX()const {return 0;} //promenqm metod ot nasledeniq klas
private:
    int y;

};
class Rect
{
private:
    int w,h;
public:
    int geth()const;
    int getw()const;
    void seth(int x);
    void setw(int x);
    int P()const;
    int Area()const;
    void draw()const;
    Rect(int,int);
};
class Sq:private Rect
{
public:
    Sq(inta):Rect (a,a){}
    int P() const{return getW()<<r;}
    int getSize(){return getW();}
    void SetA(int a)
    {
        setW(a);
        setH(a);
    }
    int Area()
    {
        Rect::Area ();
    }
    void Rect::Draw()const // pravim metoda Draw publichen
    void

};
int main ()
{
    Det d;
    d.Base::operator=();
    d.getX();
    d.print(); // razshirqvame klasa i mu dobavqme novi funkcionalnosti
    return 0;
}
