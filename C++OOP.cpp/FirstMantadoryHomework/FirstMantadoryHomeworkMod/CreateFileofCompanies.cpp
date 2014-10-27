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
    fstream File,txtf;
    File.open("company.dat",ios::binary |ios::in);
    txtf.open("company.txt",ios::out);
    if(!File)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    for (int i=0;!File.eof();i++)
    {
        File.read((char*)&compani[i],sizeof(com));
        txtf<<"ID:"<<compani[i].ID<<endl;
        for (int j=0;compani[i].Name[j]!='\0';j++)
        {
            txtf<<compani[i].Name[j];
        }
        txtf<<endl<<"Capital"<<fixed<<compani[i].StockPrice<<endl;
    }
    txtf.close();
    File.close();
    return 0;
}
