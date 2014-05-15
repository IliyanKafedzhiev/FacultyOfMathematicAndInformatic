#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
class Employee
{
public:
    Employee(const char* , const char* );
    ~Employee();
    const char * getFirstName ()const;
    const char * getLastName ()const;
    static int getCount (); //vrashta broq na sazdadenite obekti
private:
    char * firstName ;
    char * lastName ;
    static int count ; // sadarja broq na sazdadenite obekti
};
int Employee::count=0; //zadavane na nachalna stoinost na count . Ako sashtestvuva obekt Employee to do elementa count moje da ima dostap vsqka function ot obekta
                    // dostap do count ima v kostruktora i destruktora;
                    // ako ne sashtestvuva obekt ot klas Employee dostapa do count se usashtestvqva s "Employee::getCount();"
                    /*Employee e1, *e1Ptr=&e1;
                    e1.getCount();
                    e1Ptr->getCount() */  // funkciq moje da bade deklarirana kato static ako tq ima dostap samo  do statichni elementi na klasa.
                    // statichnite elementi nqmat ukazatel zashtoto statichnite danni el. i statichnite funkcii el. sashtestvuvat nezavisimo ot koito i da e bilo obekt na klasa
int Employee::getCount()  // static se zadava pri deklariraneto no ne i pri opisanieto
{
    return count;
}
Employee::Employee(const char* first, const char* last)
{
    firstName=new char [strlen(first)+1];// operaciq new avtomatichno razpredelq pamet za obekta ot saotvetniq razmer izvikva konstruktora na obekta
                                         // i vrashta ukazatel kam obekta ako new nemoje da nameri neobhodimiq obem pamet tq vrashta ukazatel null ili 0;
    assert (firstName!=0);               // assert proverqva stoinosta na argumenta ako argumenta e 0 assert dava saobshtenie za greshka i zavarshva programta operatorite za kontrol netrqbva da se otstranqvat ot programta sled zavarshvane na neinata proverka
                                         // # NDEBUG - ignorira vsichki operatori za kontrol kato assert
    strcpy(firstName,first);
    lastName=new char [strlen(last)+1];
    assert (lastName!=0);
    strcpy(lastName,last);
    ++count;
    cout<<"Konstruktor Employee za "<<firstName <<" "<<lastName<<"e izvikan"<<endl;
}
Employee::~Employee()
{
    cout<<"~Employee e izvikan za "<<firstName<<" "<<lastName<<endl;
    delete []firstName;             //osvobojdava pametta za obekt razpredelena predi tova sas new za sashtq obekt
    delete []lastName;              //delete avtomatichno izvikva destruktora na obekta
    --count;
}
const char* Employee::getFirstName()const
{
    return firstName;
}
const char* Employee::getLastName()const      // const pred tipa na vrashtaniq rezultat predotvratqva promqna na zakritite danni ot klienta
{                                             // ako jelae klienta moje da kopira imeto predi izvikavane na destruktora tova moje da se predotvrati ako funkcqta ima za argumenti masiv ot simvoli togava funkciite biha mogli da prekpirat imeto v masiva ot simvoli koito e zadaden ot klienta pri izvikvane na funkciite
    return lastName;
}
int main()
{
    cout<<Employee::getCount()<<endl;   //0
    Employee *e1Ptr=new Employee ("petar","radev");   // kostruktor Employee za petar radev e izvikan
    Employee *e2Ptr=new Employee ("ivan","mihailov");  //konstruktor Employee za ivan mihailov e izvikan
    cout<<e1Ptr->getCount()<<endl;                     //2
    cout<<"slujitel 1:"<<e1Ptr->getFirstName()<<e1Ptr->getLastName()<<endl;
    cout<<"slujitel 2:"<<e2Ptr->getFirstName()<<e2Ptr->getLastName()<<endl;
    delete e1Ptr;
    delete e2Ptr;
    cout<<Employee::getCount()<<endl;
    return 0;
}























