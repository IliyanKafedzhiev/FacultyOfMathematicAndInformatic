#include <iostream>
#include <cstring>
using namespace std;
class Man
{
public:
    Man();
    Man(int,const char*,bool);
    Man (const Man&);
    Man& operator = (const Man&);
    ~Man();
    const char* getMan()const;
    void setName (const char*);
    int getAge()const;
private:
    int age;
    char*name;
    const bool live;
    void Clear();
    void Copy(const Man&);

};
int main()
{
    Man gosho()
    return 0;
}
Man::Man():age(0),name(NULL),live(true)
{
    setName(" ");
}
Man::Man(int age ,const char * name ,bool live):live(live),age(age>0?age:-age),name (NULL)
{
    setName(name);
}
int Man::getAge()const
{
    return age;
}
const char* Man::getMan()const
{
    return name;
}

Man::Man (const Man&n):live(n.live)
{
    Copy(n);
}

//Man::Man()
//{Clear();}
void Man::setName(const char*name)
{
    delete []this->name;
    this->name=strcpy(new char [strlen(name)+1],name);
    name=name?name:" ";
}
void Man::Clear()
{
    delete[]name;
}
void Man::Copy(const Man&n)
{
    age=n.age;
    this->name=new char[strlen(n.name)+1];
    strcpy(this->name,n.name);
}
Man & Man::operator =(const Man&m)
{
    if(&m!=this)
    {
        Clear();
        Copy(m);
    }
    return *this;
}
