//Чете низове от клавиятурата и ги записва във файл, разделя ги
//с интервали, четенето спира при ctrl + z или ако въведем end;

#include <fstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
using namespace std;
const unsigned lenght=20;
int main(){

char buffer[lenght];
ofstream out("Test.txt",ios::out);

if(!out.is_open()){ // if(!out)
    cout << "File is not open";
    return 0;
}

while(cin >> buffer && strcmp(buffer,"end")){ //ctrcmp връща null ako съвпадат стринговете

           cout << "CIN: " << cin.rdstate() << endl;
        cout << "BUFFER: " << buffer << endl;
    out << buffer << " ";

}

out.close();
return 0;
}
