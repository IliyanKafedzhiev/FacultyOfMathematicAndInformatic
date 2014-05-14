#include <iostream>
#include <fstream>

using namespace std;

/*
    Задача 2:
    Даден е текстов файл Тест.txt. Да се напише програма,
    която извежда следната статистика за файла:
    а. брой символи (без инт.);
    б. брой символи (с инт.);
    в. брой думи във файла;
    г. брой редове.
*/

int main()
{
    // ще се опитаме да отворим текстовият файл за четене
    ifstream inputFile("Test.txt", ios::in);

    // проверяваме дали сме успели да отворим файла
    if(!inputFile.is_open())
    {
        cout << "Файлът не може да бъде отворен!\n";
        return 1;
    }

    // брой прочетене символи, различни от инт.
    unsigned countChars = 0;

    // брой интервали
    unsigned countSpaces = 0;

    // брой думи във файла
    unsigned countWords = 0;

    // брой редове
    unsigned countRows = 0;

    // флаг, който се вдига, когато сме в дума
    bool isInWord = false;

    // ще четем съдържанието на файла символ по символ,
    // до достигане на края на файла
    char currentChar = inputFile.get();

    while(inputFile)
    {
        // ако сме срещнали инт, редтабулация или нов
        if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
        {
            if(currentChar == ' ' || currentChar == '\t')
            {
                countSpaces ++;
            }

            if(currentChar == '\n')
            {
                // прочели сме символ за нов ред, можем да увеличим броя на редовете
                countRows ++;
            }

            // ако флагът за дума е вдигнат, сме в рамките на дума
            // преброяваме текущата дума
            if(isInWord)
            {
                countWords ++;

                // сваляме флага, думата е свършила
                isInWord = false;
            }
        }
        else
        {
            // друг символ, който поставя началото на дума
            countChars++;

            isInWord = true;
        }

        inputFile.get(currentChar);
    }

    // затваряне на файла
    inputFile.close();

    cout << "\nSTATISTICS\n";
    cout << "Брой символи: " << countChars << endl;
    cout << "Брой символи (вкл. инт.): " << countChars + countSpaces << endl;
    cout << "Брой думи: " << countWords << endl;
    cout << "Брой редове: " << countRows << endl;

    return 0;
}
