#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
void putCoefInFile(char* );
double* getCoefFromFile(char*);
int main()
{
    char nameOfFile[40];
        cin.getline(nameOfFile,39); // Input name of new Dat File
    putCoefInFile(nameOfFile);
    double c[3];
    for (int i=0;i<3;i++)
    {
        c[i]=getCoefFromFile(nameOfFile)[i];
    }
    bool sb=false;
    string s;
    double x1,x2;
    if (c[0]!=0)
    {
        double d=c[1]*c[1]-4*c[0]*c[2];
        if (d<0)
        {
            s="NRK";
            sb=true;
        }
        else
        {
            x1=(-c[1]+sqrt(d))/(2*c[0]);
            x2=(-c[1]-sqrt(d))/(2*c[0]);
        }
    }
    else
    {

            s="NRK";
            sb=true;
    }
    if (sb)
    {
    fstream ffile;
    ffile.open("OutPutFile.dat",ios::binary | ios::out);
    if(!ffile)
    {
        cout<<"Error Creating File";
    }
    ffile.write((char*)&s,sizeof(string));
    ffile.close();
    }
    else
    {
    fstream ffile;
    ffile.open("OutPutFile.dat",ios::binary | ios::out);
    if(!ffile)
    {
        cout<<"Error Creating File";
    }
    ffile.write((char*)&x1,sizeof(double));
    ffile.write((char*)&x2,sizeof(double));
    ffile.close();
    }
   cout<<x1<<"  "<<x2<<endl;
   cout<<s;
    return 0;
}
double *getCoefFromFile(char* f)
{
    double c[3];
    fstream xx;
    xx.open(f,ios::binary|ios::out);
    xx.read((char*)&c,3*sizeof(double));
    return c;
}
void putCoefInFile(char* a)
{
    double num[3]={3,4,-5};
    fstream ffile;
    ffile.open(a,ios::binary | ios::out);
    if(!ffile)
    {
        cout<<"Error Creating File";
    }
    ffile.write((char*)&num,3*sizeof(double));
    ffile.close();
}
