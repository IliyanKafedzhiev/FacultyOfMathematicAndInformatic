#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    fstream in , out ;
    in.open("03.cpp",ios::in);
    out.open("mod03.cpp",ios::out);
    if (!in && !out)
    {
        cout<<endl<<"ErrorFile"<<endl;
        return 0;
    }
    char b;
    char c;
    while (in.get(b))
    {

        if (b=='/')
        {

                in.get(b);

                if (b=='/')
                {
                       while (b!='\n')
                    {
                        in.get(b);
                    }
                    out<<'\n';
                }
                 else
                {
                        out<<b;
                        cout<<"D";
                }

        }
        else
        {
                out<<b;
                cout<<"D";
        }

    }
    in.close();
    out.close();
    return 0;
}
