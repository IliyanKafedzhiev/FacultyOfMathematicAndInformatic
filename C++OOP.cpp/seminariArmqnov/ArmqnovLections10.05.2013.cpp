#include <iostream>
#include <cstring>
#include <exeption>
using namespace std; //Exeption //Mnojestveno nasledqvane //Virtual nasledqvane
int main ()
{
    // slagame *const* na vseki metod koito ne promenq klasa
    //Exeptions - izlizat ot
    //...f(){
       // x=g();ako ne varne stoinost Vrashta "Izkliuchenie"Exeption
    throw 5;            //hvarlqne na Exeption -vsqkakav tip Exeption moje da hvarlqme

    }
    Array a;
    try
    {
        x=a[i];
    }catch(int error Code)
    {
        cout<<errorCode;
        throw ...;
    }catch(const char*msg)
    {
        ....
    }catch(...)//hvashta absoliutno vsichko
    {
        throw;//-hvarlq tova koeto e prihvanalo
    }
    return 0;
}
class Array
{
    int&operator[](unsigned index)
    {
            if(index>=size)
            {
                throw "invalid index";
            }
        return data[index];
    }
};
class A
{
public:
    A(int x)
    {
        if(...)
        {
            throw ..;
        }
    }
    ~A()
    {
        //nikoga ne hvaelqme izkliuchenie
    }
};
try
{
  A a(5);
}catch(...);
try
{
    x=new int[50];
}catch(bad_alloc)
{
    cout<<"nqma pamet";
}
    x=new(nothrow) int[50];//izpalnqva sashtiq kod
    if(!x)
    {
        cout<<"nqma pamet";
    }



class C:public A,public B   //mnojestveno nasledqvane
{
    C():B(6),A(7),X(2);-izpalnqva se parvo A posle be B, sled tova X
};
class Student
{
public:
    voide Print()const;
};
class Worker
{
public:
    void print()const;
};
class WS:public Student,public Worker
{
public:
    void print()
};
    WS w;
    w.print()//??
    w.Worker::print();

class Student:virtual public Person //deklarirane na virtualen klass leka vrazka(obsht)
{

};
class Worker:virtual public Person //deklarirane na virtualen klass leka vrazka(obsht)ima znachenie za naslednicite

{

};
class WS:public Student,public Worker //WS naslednik koito polzva edin obekt Person chrez bazovite klasove Student,Worker
{
    WS():Worker("Pesho",60),Student("Gosho",20),Person("sasho",40) //V sluchaq shte dade Greshka Konstruktora moje da se izvikva samo vednaj
    {

    }
};
