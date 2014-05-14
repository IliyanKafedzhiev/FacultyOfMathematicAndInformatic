#include <iostream>
using namespace std;
class Time
{
public:
    Time (int=0,int=0,int=0);
    void setTime(int,int,int);
    int getHour();
    int &badSetHour (int);
private:
    int hour,minute,second;
};
Time ::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    second=s;
}
int &Time :: badSetHour (int hh)
{
    hour=(hh>=0 && hh<24)?hh:0;
    return hour;
}
int Time ::getHour()
{
    return hour;
}
int main()
{
    Time t;
    int &hourRef=t.badSetHour(20); // hourRef stawa psevdonim na hour zobikalq dostapa do private
    cout<<endl<<t.getHour()<<endl;
    hourRef=30;
    cout<<endl<<t.getHour()<<endl;
    t.badSetHour((28))=74;
    cout<<endl<<t.getHour()<<endl;
    return 0;
}
