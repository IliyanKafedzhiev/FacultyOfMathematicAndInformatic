#include <iostream>
using namespace std;
struct Distance
{
    int foot;
    double inch;
};
void ReadDistance (const Distance &x)
{
    cout<<"Daljinata e "<<x.foot<<"foots and "<<x.inch<<"inch"<<endl;
}
void setDistance(Distance &a)
{
    cout<<"Vavedi daljina na inch<=12"<<endl;
    cin>>a.inch;
    cout<<endl<<"Vavedi daljina na foot"<<endl;
    cin>>a.foot;
}
struct Room
{
    Distance width;
    Distance lenght;
};
Distance sum (const Distance &lhs , const Distance &rhs)
{
    Distance s;
    s.foot=lhs.foot+lhs.foot;
    s.inch=rhs.inch+rhs.inch;
    while (s.inch>12)
    {
        s.foot++;
        s.inch-=12;
    }
    return s;
}
Distance perimeter (const Room &R)
{
    Distance s = sum (R.width ,R.lenght );
    return sum (s,s);
}



Distance surface (const Room &R)
{
    Distance s;
    s.foot=R.width.foot*R.lenght.foot;
    s.inch=R.width.inch*R.lenght.inch;
    while (s.inch>12)
    {
        s.foot++;
        s.inch-=12;
    }
    return s;
}
int main ()
{
    Room my;
    setDistance(my.lenght);
    setDistance(my.width);
    cout<<"Room Perimetar"<<endl;
    ReadDistance(perimeter(my));
    cout<<"Surface Room"<<endl;
    ReadDistance(surface (my));
    return 0;
}
