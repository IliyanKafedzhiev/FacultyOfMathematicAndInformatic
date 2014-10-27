#include <iostream>
#include <cmath>
using namespace std;
// exersize 1 to define Triangle
struct triangle
{
    double a,b,c;
};
triangle t ;
void  ReadTriangle (triangle &t)
{
    cin>>t.a;
    cout<<endl;
    cin>>t.b;
    cout<<endl;
    cin>>t.c;
    cout<<endl;
    if (!((t.a+t.b)>t.c &&(t.b+t.c)>t.a &&(t.c+t.a)>t.b))
    {
        ReadTriangle(t);
    }
}
void printTriangle (const triangle &t)
{
    cout<<t.a<<","<<t.b<<","<<t.c<<endl;
}
double perimether (const triangle &t)
{
    return t.a+t.b+t.c;
}
double suface (const triangle &t)
{
    double p=perimether(t)/2;
    return sqrt(p*(p-t.a)*(p-t.b)*(p-t.c));
}
int main ()
{
    ReadTriangle (t);
    printTriangle (t);
    cout<<perimether(t)<<endl;
    cout<<suface(t)<<endl;
    return 0;
}
