#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <strstream>
using namespace std;
int main ()
{                                  //FILE* f=fopen("..","rba")     int m[10]; int i; fread(f,&i,sizeof(int),1) ; close(f);
    char bufferr [20],c[19];
    int min=9999,max=0;
    fstream xxx;
    xxx.open("NumReadMinMax.txt",ios::in);
    if (!xxx)
    {
        cout<<"file is not open"<<endl;
        return 0;
    }
    xxx.clear();
    while (!xxx.eof())
    {

          xxx.getline(bufferr,19);
          strstream ss;
          ss << bufferr;
          while (!ss.eof())
          {
              int entry;
              ss >> entry;
              if (entry >= max)
                        max=(entry);
                  if ((entry)<= min)
                        min=(entry);
          }
          /*for (int i=0;i<20;i++)
          {
              int x=0;
              for (int j=0;bufferr[i]!=' ' && bufferr[i+j]!=' ';j++)
              {
                  c[j]=bufferr[i+j];
                  x=j;
              }
              if(x>=0)
              {
                  if ((atoi (c)) >= max)
                        max=(atoi (c));n
                  if ((atoi(c))<= min)
                        min=(atoi (c));
              }
              for (int k=0;k<19;k++)
              {
                    c[k]=NULL;
              }
              i=i+x;
          }*/
          cout<<"Min/Max:  "<<min<<"/"<<max<<endl;
          min=9999;
          max=-9999;
    }

    xxx.close();
    return 0;
}
