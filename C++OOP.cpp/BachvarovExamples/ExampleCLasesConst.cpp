#include <iostream>
using namespace std;
class Increment
{
public:
    static int i;
    Increment (int c=0,int i=0);
    void addIncrement ()
    {
        count+=increment;
    }
    void print() const;
private:
    int count;
    const int increment;
};
Increment::Increment(int c,int i)
:increment (i)
{
    count=c;
}
void Increment::print()const
{
    cout<<"Count= "<<count<<"Increment="<<increment<<endl;
}
int Increment :: i=5;
int main()
{
    Increment value (10,5);
    value.print();
    for (int j=1;j<=3;j++ )
    {
        value.addIncrement();
        value.print();
    }
    cout<<endl<<value.i<<endl;
    return 0;
}
