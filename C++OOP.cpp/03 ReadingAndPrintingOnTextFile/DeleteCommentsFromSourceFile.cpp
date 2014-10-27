#include <iostream>
#include <fstream>

#include <string.h>

using namespace std;

/*
    Задача 3:
    Да се напише програма, която изчиства коментарите от даден .cpp файл.
    Резултатът се записва в нов файл.
*/

const unsigned MAX_LINE_LENGTH = 1024;

int main()
{
    // отваряме файла за четене
    ifstream inputFile("ClientsBalance - Copy.cpp", ios::in);
    // проверяваме дали файлът е отворен за четене успешно
    if(!inputFile)
    {
        cout << "Файлът не може да бъде отворен за четене!\n";
        return 1;
    }

    ofstream outputFile("WithoutComments.cpp", ios::out);
    // проверяваме дали файлът е отворен за запис успешно
    if(!outputFile)
    {
        cout << "Файлът не може да бъде отворен за писане!\n";
        return 1;
    }

    bool isInString = false;

    // указател към началото на буфера
    char currentChar;

    // взимаме първият символ
    currentChar = inputFile.get();

    // файлът ще бъде обработен символ по символ
    while(inputFile)
    {
        // ЗАБЕЛЕЖКА:
        // Решението не разглежда случая с \", т.е. "escape"-ната кавичка
        // Д.Р. Да се преработи
        if(currentChar == '\"')
        {
            // ако сме в рамките на низ, сваляме флага
            // ако сега започва низа, вдигаме флага
            isInString = !isInString;

            // символът трябва да се запише в резултатния файл
            outputFile.put(currentChar);
        }
        else if(currentChar == '/')
        {
            // записваме позицията, на която сме срещнали /
            int posSlash = inputFile.tellg();

            // поглеждаме следващият символ
            char nextChar = inputFile.peek();

            if(nextChar == '/')
            {
                if(!isInString)
                {
                    // начало на коментар от тип //

                    // връщаме се в началото на коментара
                    inputFile.seekg(posSlash, ios::beg);

                    // игнорираме всички символи до края на реда
                    inputFile.ignore(MAX_LINE_LENGTH, '\n');

                    // в резултатния файл трябва да се добави '\n'
                    outputFile << endl;
                }
            }
            else if(nextChar == '*')
            {
                if(!isInString)
                {
                    // начало на коментар от тип /**/
                    // пропускаме *
                    currentChar = inputFile.get();

                    // игнорираме всички символи до края на коментара
                    do
                    {
                        currentChar = inputFile.get();
                        nextChar = inputFile.peek();
                    }
                    while (currentChar != '*' || nextChar != '/');

                    // пропускаме /
                    currentChar = inputFile.get();
                }
            }
        }
        else
        {
            // символът трябва да се запише в резултатния файл
            outputFile.put(currentChar);
        }

        // взимаме следващия символ
        currentChar = inputFile.get();
    }

    // затваряне на файловете
    inputFile.close();
    outputFile.close();

    return 0;
}
