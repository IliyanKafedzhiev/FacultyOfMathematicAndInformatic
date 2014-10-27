#include <iostream>
#include <strstream>
#include <string.h>
#include <fstream>
using namespace std;
int wordCount(char *string3)
{
	int numWords = 1;
	while(*string3 != '\0')
	{
		if(*string3 == ' ' && *(1+string3)!='\0' && *(1+string3)!=' ' && *(string3-1))
        {
           numWords++;
        }
		string3++;
	}
	return numWords;

}
int main ()
{
    fstream xxx ("NumReadMinMax.txt",ios::in);
    if (!xxx)
    {
        cout<<"Cannot Read File"<<endl;
        return 0;
    }
    xxx.clear();
    char buffer[100];
    int countLine=0;
    int countSymbol=0;
    int countSymbolOne=0;
    int countWords=0;
    while (!xxx.eof())
    {
        xxx.getline(buffer,99);
        countLine++;
        countSymbol+=strlen(buffer);
        countWords+=wordCount(buffer);
       strstream sss;
       sss<<buffer;
       while(!sss.eof())
       {
           char c;
           if(sss>>c)
           {
              countSymbolOne++;
           }

       }
    }
    xxx.clear();

    xxx.close();
    cout<<endl<<"CountLine:"<<countLine<<"CountSymbols(whit intervals):  "<<countSymbol<<"CountSymbols(whitout intervals):  "<<countSymbolOne<<"CountWords:  "<<countWords<<endl;
    return 0;
}
