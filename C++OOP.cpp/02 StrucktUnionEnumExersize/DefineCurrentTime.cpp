#include <iostream>
using namespace std;
class Time
{
    public:
        Time();
        void setTime (int h,int m,int s);
        void printMilitary ();
        void printStandart ();
    private :
        int hour;
        int minut;
        int second;
};
Time :: Time ()
{
    hour=minut=second=0;
}
void Time :: setTime(int h ,int m,int s)
{
    hour=(h>=0 && h<=24)?h:0;
    minut=(m>=0&& m<=60)?m:0;
    second=(s>=0 && s<=60)?s:0;
}
void Time :: printMilitary ()
{
    cout<<(hour<10?"0":"")<<hour<<":"<<(minut<10?"0":"")<<minut<<":"<<(second<10?"0":"")<<second<<endl;
}
int main ()
{
    Time S;
    S.printMilitary();
    cout<<endl;
    S.setTime(345,55,22);
    S.printMilitary();
    return 0;
}
