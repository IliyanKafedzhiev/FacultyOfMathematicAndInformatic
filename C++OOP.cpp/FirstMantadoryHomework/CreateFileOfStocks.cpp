#include <iostream>
#include <fstream>
using namespace std;

struct Stocks
{
    unsigned InvID;
    unsigned ComID;
    double Count;
};
int main()
{   Stocks stock[200];
    fstream File,txtT;
    File.open("stocks.dat",ios::binary|ios::in);
    txtT.open("stocks.txt",ios::out);

    if(!File)
    {
        cout<<"Error";
        return 0;
    }
    for (int i=0;!File.eof();i++)
    {
    File.read((char*)&stock[i],sizeof(Stocks));
    txtT<<"InvID:"<<stock[i].InvID<<endl;
    txtT<<"ComID:"<<stock[i].ComID<<endl;
    txtT<<"$:"<<fixed<<stock[i].Count<<endl;

    }
    txtT.close();
    File.close();
    return 0;
}
