#include <iostream>
#include <fstream>
using namespace std;
struct Invertors
{

    unsigned int ID;
    char Name[31];
    double capital;

};
int main()
{
    Invertors invertor[200];
    fstream File,txtf;
    File.open("investors.dat",ios::binary | ios::in);
    txtf.open("investors.txt",ios::out);
    if(!File)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    int i=0;
    while (!File.eof())
    {
        File.read((char*)&invertor[i],sizeof(Invertors));
        txtf<<"ID:"<<invertor[i].ID<<endl;
        for (int j=0;invertor[i].Name[j]!='\0';j++)
        {
            txtf<<invertor[i].Name[j];
        }
        txtf<<endl<<"Capital"<<fixed<<invertor[i].capital<<endl;
        txtf<<endl<<"position"<<File.tellg()<<endl;
        i++;
    }
    txtf.close();
    File.close();
    return 0;
}
