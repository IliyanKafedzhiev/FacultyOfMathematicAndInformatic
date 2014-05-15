#include <iostream>
#include <fstream>
using namespace std;

struct com
{
    unsigned ID;
    char Name [31];
    double StockPrice;
};
int main(int i,const char* p[])
{
    com compani[200];
    fstream File;
    File.open("company.dat",ios::binary |ios::in);
    if(!File)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    for (int i=0;!File.eof();i++)
    {
        File.read((char*)&compani[i],sizeof(com));
        cout<<"ID:"<<compani[i].ID<<endl;
        for (int j=0;compani[i].Name[j]!='\0';j++)
        {
            cout<<compani[i].Name[j];
        }
        cout<<endl<<"Capital"<<fixed<<compani[i].StockPrice<<endl;
    }

    File.close();
    return 0;
}
