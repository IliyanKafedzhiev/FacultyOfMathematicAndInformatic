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
    fstream File ;
    File.open("investors.dat",ios::binary | ios::in);
    if(!File)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    int i=0;
    while (!File.eof())
    {
        File.read((char*)&invertor[i],sizeof(Invertors));
        cout<<"ID:"<<invertor[i].ID<<endl;
        for (int j=0;invertor[i].Name[j]!='\0';j++)
        {
            cout<<invertor[i].Name[j];
        }
        cout<<endl<<"Capital"<<fixed<<invertor[i].capital<<endl;
        cout<<endl<<"position"<<File.tellg()<<endl;
        i++;
    }
    File.seekg(ios::beg);
    File.read((char*)&invertor[i],sizeof(Invertors));
        cout<<"ID:"<<invertor[i].ID<<endl;
        for (int j=0;invertor[i].Name[j]!='\0';j++)
        {
            cout<<invertor[i].Name[j];
        }
        cout<<endl<<"Capital"<<fixed<<invertor[i].capital<<endl;

    File.close();
    return 0;
}
