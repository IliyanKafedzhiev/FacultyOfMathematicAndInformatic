#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
    string line;
    ifstream text;
    text.open("ntbtlog.txt");
    if (text.is_open())
    {
        while (text.good())
        {
            getline (text,line);
            cout<<line<<endl;
        }
    }
    text.close();
    return 0;
}
