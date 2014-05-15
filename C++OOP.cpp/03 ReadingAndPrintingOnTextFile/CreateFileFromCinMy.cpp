#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main ()
{
    fstream xxx ;
    xxx.open("FromCin.txt",ios::out);
    if (!xxx)
    {
        cout<<"Errror";
        return 0;
    }
    char buffer[20];
    while (cin>>buffer && strcmp(buffer,"end"))
    {
        cout << "CIN: " << cin.rdstate() << endl;
        cout << "BUFFER: " << buffer << endl;
        xxx<<" "<<buffer;
    }
    xxx.close();
    return 0;

}
