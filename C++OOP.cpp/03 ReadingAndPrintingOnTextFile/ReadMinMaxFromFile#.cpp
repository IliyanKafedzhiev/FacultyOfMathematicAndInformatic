#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
const unsigned BuffL=20;
int main ()
{
    char Bufferr[BuffL];
    int min=9999;
    int  max=0 ;
    ifstream fls ;
    fls.open("ReadNumber.txt");
    if (!fls)
    {
        cout<<"Input File Error"<<endl;
        return 0;
    }
    while (!fls.eof())
    {
        fls>>Bufferr;
        if (!(Bufferr[0]=='#'))
        {
            if ((atoi (Bufferr)) >= max)
                max=(atoi (Bufferr));
            if ((atoi(Bufferr))<= min)
                min=(atoi (Bufferr));
        }
        else
        {
            cout<<"Min/Max:  "<<min<<"/"<<max<<endl;
            max=0;
            min=999;
        }
    }


    fls.close();
    return 0;
}
