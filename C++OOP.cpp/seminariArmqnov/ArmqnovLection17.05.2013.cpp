#include <iostream>
#include <cstring>
using namespace std;
class Pet
{
    const char gender;
    char * name;

    void setName(const char*n)
    {
        name=new char [strlen(n)+1];
        strcpy(name,n);
    }
    char* getName()
    {
        return name;
    }
public:
    void printPet(const Pet&p)  //Polimorfizam vzima metoda Speak na naslednicite(ako ima) i go izpalnqva !
    {                           //Mnogo e vajno "p" da e psevdonim toest da vzeme adresa na nasledeniq obekt bez da pravi kopie
        cout<<p.getName();
        p.speak();
    }
    Pet(const char* name,bool male):gender(male?'m':'f')
    {
        setName(name);
    }
    virtual~Pet() // trqbva a e virtual za da izpolzva nasledenite destruktori pri izvikavaneto ,my
    {
        delete [] name;
    }
    Pet(const Pet&p):gender(p.gender),name(NULL)
    {
        setName(p.name);
    }
    Pet* createPet() //fabrika sazdava OBEKTI
    {
        char c;
        cin>>c;
        switch(c)
        {
            case 'c':return new Cat("maca",false);
            case 'd':return new Dog("gosho",true);
        }
        return NULL;
    }
    virtual void speak()const=0; //Ako se pqvi drug naslednik koito ima sashtiq metod tazi metod vzima metoda na naslednika
            // nemoje da se sazdavat obekti ot Pet zashotto funkciqta sochi kum 0 nqma implementaciq i tq razchita na naslednicite za sazdavane na implementaciq taka Klasa Pet ni se vodi Abstrakten !
    Pet&operator=(const Pet&p)
    {
        if(this==&p)
        {
            return *this;
        }
        else
        {
            if(gender!=p.gender)
            {
                throw "invalid assignment";
            }
            setName(p.name);
            return *this;
        }
    }

};
class Cat :public Pet
{
public:
    Cat(const char* name,bool male):Pet(name, male)
    {

    }
    void climb()const
    {
        cout<<"Gore na chereshta";
    }
    virtual void speak ()const
    {
        cout<<"Mqyyy";
    }
};
class Dog :public Pet
{
    char* breеd;
public:
    Dog(const char* name,bool male,const char* bread):Pet(name, male),bread(NULL)
    {
        setBread(bread);
    }
    ~Dog()
    {
        delete[] bread;
    }
    Dog(const Dog&d):Pet(d)
    {
        setBread(d.bread);
    }
    Dog& operator=(const Dog&d)
    {
        assert(d.getGender()==getGender());
        if(this!=&d)
        {
           Pet::operator=(d);
           setBread(d.bread);
        }
        return *this;
    }
    char getGender(const Dog&d);
    {
        return d.gender;
    }
    void setBread(const char*b);
    const char* getBread()const;
    virtual void speak()const
    {
        cout<<"Djaff"
    }
};
int main()
{
    const char* gosho=new const char*[6]={"gosho"};
   // Pet pesho(gosho,false);
   // Cat c("shushi",false);
   // Dog d("Viktor","haski",true);
   // Pet* zoo[]={&c,&d};
   // zoo[1].speak();
   //Cat c("Maca",false);
   //Dog d("Joro",true);
   //info(c);
   //info(d);
   //Pet* zoo[20];int c=0;while(c<20){zoo[c]=create Pet();if(zoo[c])c++}
   //for(int i=0;i<c;i++)
   {
       cout<<zoo[i]->getName();
       if(zoo[i]->getGender()=='m')
            zoo[i]->speak();
   }
   for (int i=0,i<c;i++)
   {
       delete[]zoo[i];
   }
    return 0;
}
