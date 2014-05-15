# include <iostream>
# include <fstream>
# include <string.h>

using namespace std;

/*
    Задача 1:
    Да се напише програма, която чете низове от клавиатурата и ги записва
    във файл с име Тест.txt, разделени с инт. Четенето продължава, докато не въведем "end"
    или не натиснем Ctrl + Z.
*/

const unsigned MAX_LENGTH = 20;

int main()
{
    // опитваме се да отворим файлът Test.txt за запис
    ofstream outputFile("Test1.txt", ios::out);
    if(!outputFile)
    {
        cout << "Файлът не може да бъде отворен!\n";
        return 1;
    }

    // файлът успешно е отворен за запис
    // четем данни до срещането на низа "end" или до Ctrl + Z
    char buffer[MAX_LENGTH];

    cout << "Моля, въведете низове!\n"
            "Записването във файла спира при Ctrl+Z или при срещането на end\n";

    // функ. strcmp връща 0, ако двата низа са равни
    while(cin >> buffer && strcmp(buffer, "end"))
    {
        cout << "CIN: " << cin.rdstate() << endl;
        cout << "BUFFER: " << buffer << endl;

        //записваме във файла
        outputFile << buffer ;
    }

    // затваряне на файла
    outputFile.close();

    return 0;
}
