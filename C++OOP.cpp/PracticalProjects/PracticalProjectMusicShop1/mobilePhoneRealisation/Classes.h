enum Category
{
    APP_GAME,
    APP_WP,
    APP_EDITOR,
    APP_PLAYER,
    APP_UNKNOWN=-1,
};
#include <iostream>
using namespace std;
#ifndef CLASSES_H
#define CLASSES_H
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
/***********************************************************************/
/*************************************************************************************/
class Phone
{
public:
    Phone():s(5*1024*1024)
    {
        strcpy(brand,"Pesho");
    }
    int getSpace()const
    {
        return 1000+s.getCap();
    }
	int getFree()const{return s.getFreeSpace();}
    int getCpuSpeed()const{return 200;}
    const char* getOS()const{return "android2.3";}
    void printInfo()const
    {
        cout<<"Space:"<<getFree();
        cout<<"OS:"<<getOS();
		s.printAllApps();
    }
    void AddApp(Application*app)
    {
        if(!app->canBeInstallOn(*this))
        {
            cout<<"Tha Aplication";
            app->print();
            cout<<"Could not ..";
        }
        else
        {
            if(s.hasApp(*app))
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
    Storage s;
};
/***************************************************************************************/
class Storage
{
public:
    int getCap()const;
    void printAllApps()const;
    bool hasApp(const Application&)const;
    bool removeApp(const Application&);
    bool addApp(const Application*);
    unsigned getFreeSpace()const;
	Storage(unsigned Capacity):apps(nullptr)
    {
        totalCapacity=Capacity&(~1024);//zakraglqne na 1024
		capacity=0;
		AppsCount=0;
    };
    ~Storage();
private:
    Storage(const Storage&);
    Storage& operator=(const Storage&);
    //data
    int capacity;
    int AppsCount;
    double totalCapacity;
    double FreeSpace;
    Application**apps;
};
#endif 

