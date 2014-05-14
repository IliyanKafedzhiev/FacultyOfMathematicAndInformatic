//Текстов файл извежда статистика за файла, брой символи с без интервали, брой редове, брой думи;
#include<fstream>
#include<iostream>
using namespace std;

int main(){
ifstream in("NumReadMinMax.txt", ios::in);

if(!in){
    cout << "Cannot open thefile " << endl;
    return 0;
}

int countChar=0, countRow=0, countWords=0;
bool isInWord = false;
char curChar = in.get();
while(in){
    if(curChar==' ' || '\t' || '\n'){
        if(isInWord) {
            countWords++;
        }
        isInWord = false;

        if(curChar=='\n')
            countRow++;
        countChar++;
        in.get(curChar);
    }else{
        isInWord = true;
    }

}

cout << countChar << endl;
cout << ++countRow << endl;
cout << countWords << endl;

in.close();

return 0;
}
