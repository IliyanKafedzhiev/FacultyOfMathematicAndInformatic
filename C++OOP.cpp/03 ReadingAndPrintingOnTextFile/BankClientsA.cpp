#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream inF,outF;
    inF.open("BankClientDetails.txt",ios::in);
    outF.open("OutPutClientDetails.txt",ios::out);
    if (!inF && !outF)
    {
        cout<<"Error Input of OutPut"<<endl;
        return 0;
    }
    outF<<"_______________________________________________________________________________"<<'\n';
    outF<<" Number                             Family                             Ballance"<<'\n';
    outF<<"_______________________________________________________________________________"<<'\n';

    inF.close();
    outF.close();
    return 0;
}
