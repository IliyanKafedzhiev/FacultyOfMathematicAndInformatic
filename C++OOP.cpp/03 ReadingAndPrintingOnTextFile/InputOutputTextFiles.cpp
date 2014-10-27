#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
    string line;
    ifstream myFile;
    myFile.open("Example.txt");
    if(myFile.is_open())
    {
        while (myFile.good())
        {
            getline (myFile,line);
            cout<<line<<endl;
        }

        myFile.close();
    }
    else{cout<<"Unable to open a file";}
    return 0;
}
