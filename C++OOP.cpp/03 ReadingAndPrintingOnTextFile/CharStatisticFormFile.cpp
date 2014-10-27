#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <strstream>
using namespace std;
int main()
{
    double chstat[256];
    for (int i=0;i<256;i++)
    {
        chstat[i]=0;
    }
    char c;
    char location[100],defLocation[99]="NumReadMinMax.txt";
    cout<<"Input Location"<<endl;
    cin.getline(location,99);
    fstream xxx;
    xxx.open(location,ios::in);

    if (!xxx)
    {
		cout<<"Input Location is not Valid"<<endl;
        for(int i=0;i<19;i++)
        {
            location[i]=defLocation[i];
        }
        xxx.open(location,ios::in);
    }
    if (!xxx)
    {
       cout<<"Input File Error"<<endl;
       return 0;
    }
    xxx.clear();
    double cnt=0;
	while (xxx>>c )
    {
        chstat[(int)c]++;
        cnt+=1;
    }
    double cnt1=0;
    xxx.close();
    for (int i=0;i<256;i++)
    {
        if (chstat[i]!=0)
        {
            cnt1=(chstat[i])/cnt;
            cout<<"Symbol:"<<(char)i<<"        Count matches:"<<chstat[i]<<"     Persent of matching:"<<cnt1*100<<"%"<<endl;


        }
		
    }
    return 0;
}

