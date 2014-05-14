#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    fstream xx;
    xx.open("OutPutFile.dat",ios::binary |ios::in);
    double x1,x2;
    xx.read((char*)&x1,sizeof(double));
    xx.read((char*)&x2,sizeof(double));
    xxñ.close();
    cout<<"x1="<<x1<<endl<<"x2="<<x2<<endl;
    return 0;
}
