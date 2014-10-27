#include <iostream>
#include <cmath>
using namespace std;
struct coordinate
{
    double x,y;
};
void setCoordinate (coordinate &xy)
{
    cout<<endl<<"x=";
    cin>>xy.x;
    cout<<endl<<"y=";
    cin>>xy.y;
    cout<<endl;
}
double findDistance(const coordinate &c1,const coordinate &c2)
{
    double c;
    c=sqrt(((c2.x-c1.x)*(c2.x-c1.x))-((c2.y-c1.y)*(c2.y-c1.y)));
    return c;
}
int main ()
{
    coordinate c1,c2;
    setCoordinate (c1);
    setCoordinate (c2);
    cout<<endl<<"Distance is :"<<findDistance (c1,c2)<<endl;
    return 0;
}
