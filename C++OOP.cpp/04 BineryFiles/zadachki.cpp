#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream F,out ;
    F.open("File.dat",ios::binary | ios::in | ios::out);
    if (!F)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    char* b=new char ;
    char* e=new char ;
    F.seekg(7,ios::beg);
    F.read(b,2);
    F.seekg(-7,ios::end);
    F.read(e,2);
    F.seekp(7,ios::beg);
    F.put (e[0]);
    F.seekp(-7,ios::end);
    F.put(b[0]);
    F.close();
    cout<<"Begin:"<<b[0]<<"    End:"<<e[0]<<endl;

    return 0;
}
    /*istream&  read(char*str,int size);
    ofstream& write(const char* str,int size);
    out.write(reinterpret cast <const char * >(number),int size);
    istream &seekg(long p,seek_dir r=ios::beg);
    tellg();
    good();
    fail();
    bad();
    eof();*/
