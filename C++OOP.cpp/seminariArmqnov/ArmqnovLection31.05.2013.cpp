#include <iostream>
#include <cstring>
using namespace std;
enum Category
{
    APP_GAME,
    APP_WP,
    APP_EDITOR,
    APP_PLAYER,
    APP_UNKNOWN=-1,
};
/*************************************************************************************/
class Phone
{
public:
    Phone():S(5*1024*1024)
    {
        strcpy(brand,"Pesho");
    }
    int getSpace()const
    {
        return 1000+s.getCapacity();
    }
    int getFree()const{return S.getFree()}
    int getCpuSpeed()const{return 200;}
    const char* getOS()const{return "android2.3";}
    void printInfo()const
    {
        cout<<"Space:"<<getFree();
        cout<<"OS:"<<getOS();
        s.listAllApps();
    }
    void AddApp(Application*app)
    {
        if(!app->ConBeInstaledOn(*this))
        {
            cout<<"Tha Aplication";
            app->print();
            cout<<"Could not ..";
        }
        else
        {
            if(S.hasApp(*app))
            {
                cout<<"Already installed";
            }
            else
            {
                if(!s.addApp(app))
                {
                    cout<<"Error";
                }
                else
                {
                    cout<<"Already Installed";
                }
            }
        }
    }
    void listALLapp();
    void deleteApp();
    void addApp();
private:
    char brand[100];
    Storage S;
};
/*************************************************************************************/
class  Application
{
public:
    virtual void print()const;
    virtual int getSize()const=0;
    bool operator ==(const Application& );
    Application(const char* name,Category c,int s);
    void setName(const char*);
    virtual bool canBeInstallOn(const Phone&)const=0;
    virtual ~Application();
    virtual Application* clone()const=0;
protected:
    Category cat;
    char Name[1024];
    int Size;


};
void Application::setName(const char* name)
{
    name=name?name:"";//proverka dali n==NULL
    strncpy(this->Name,name,sizeof(name));
}
Application::Application(const char* name,Category c,int s):cat(c)
{
    for(int i=0;i<1024;i++)
    {
        this->Name[i]=name[i];
    }
    Size=s;
}
/***************************************************************************************/
class Storage
{
public:
    int getCap()const;
    void printAllApps()const;
    bool hasApp(const App&)const;
    bool removeApp(const App&);
    bool addApp(const App*);
    unsigned getFreeSpace()const;
    Storage(unsigned Capacity):number(0),application(NULL)
    {
        totalCapacity=Capacity&(~1024);
    }
    ~Storage();
private:
    Storage(const Storage&);
    Storage& operator=(const Storage&);
    /data
    int capacity;
    int AppsCount;
    double totalCapacity;
    double FreeSpace;
    Application**apps;

};
bool Storage::addApp(const App*a)
{
    if(a->getSize()>getFreeSpace())
    {
        return false;
    }
    if(hasApp(*a))
        return false;
    if(appcnt==Size)
    {
        Size=Size?Size*2:8;  / size trqbva da e razlichen nula inache nese udvoqva i garmi rabotata
        App**t=new App*[size];
        for(int i=0;i<appCount;i++)
        {
            t[i]=apps[i];
        }
        delete[] apps;
        apps=t;
    return true;
    }
}
unsigned Storage::getFreeSpace()const
{
    unsigned total=0;
    for(int i;i<=appcnt;i++)
    {
            total+=apps[i]->get(size);
    }
    return totalCapacity-total;
}
bool Storage::removeApp(const App&a)
{
    int index=-1;
    for(int i=0;i<appCnt;i++)
    {
        if   (*apps[i]==a)
        {
            index =i;
            break;
        }
        if(index<0)
        {
            return 0;
        }
        App*t=apps[index];
        for(int i=index;i<appcnt-1;i++)
        {
            apps[i]=apps[i+1];
        }
        delete t;
        appcnt--;
        return 1;
    }
}

class Game:public Application
{
public:
    Game():Application("Game Name",APP_GAME,1764)
    {
        cout<<"Bravo!Chudesen Izbor";
    }
    int getSize()const
    {
        return 1767+gedSevadGamesSize();
    }
    bool CanBeInstalledOn(const Phone&a)const
    {
        if(p.getFree()>1764 && p.CPU>1000 && strstr(p.getOS),"iOS"==0)
            return true;
        if(strstr(p.getOS(),"iOS"))
        {
            cn=p.getCreditCardNum();
        }
    }
private:

};
int main ()
{


    return 0;
}
