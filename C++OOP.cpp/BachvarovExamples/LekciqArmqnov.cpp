#include <iostream>
#include <string>
#include <cmath>
using namespace std;  //Predifinirane na OPERACII
                    // nemojem da izmislqme operacii ,nemojem da smenqme preoritet, asocioativnost Da zapazvame povedenieto na operaciite
                    // nemojem da predifinirame operaciite :".", "?:","::","sizeof()","type_id"
                    // mojem da predifinirame operaciite :"->"- za rabota s obekti no -> raboti kakto ochakvame sas ukazateli,"&","&&","*",","
                    // a.operator+(b);3+b
                    // =     =#,vscihki simetrichni operacii,"[]","()","&","*","*","(cast)"-trqbva da sa implementirani vav klasa !
                    //==,!=,>,<,>=,<=; moje da sa vanshni
class Number
{
public:
    Number(int n=0)
    {
        this->n=n;
    }
    Number operator+(const Number&nr)const
    {
        return Number(n+nr.n);
    }
    Number operator+=(const Number&nr)const
    {
        *this=*this+nr;
        return *this;
    }
   // Number operator+(const Number&nr)const
   // {Number t(*this);return t+=nr;}
   // Number operator+=(const Number&nr)const
    //{n+=nr.n;return *this;}
    void setN (int n)
    {
        this ->n=n;
    }
    int getNum()const
    {
        return n;
    }
private:
    int n;
};
bool operator ==(const Number&nl,const Number&ar)
{
    return nl.getNum();
}
bool operator <(const Number&nl,const Number&nr)
{
    return nl.getNum()<nr.getNum();
}
bool operator >(const Number&nl,const Number&nr)
{
    return nl<nr;
}
bool operator !=(const Number&nl,const Number&nr)
{
    return !(nl==nr);
}
bool operator <=(const Number&nl,const Number&nr)
{
    return !(nl>nr); //return nl<nr || nl==nr;
}
bool operator <=(const Number&nl,const Number&nr)
{
    return !(nl<nr); //return nl>nr || nl==nr;
}
int main ()
{
    return 0;
}
