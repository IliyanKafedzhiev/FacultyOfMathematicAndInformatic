#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
    Задача 4:
    Даден е текстов файл, в който са записани данните на клиенти на банка.
    Данните са в следния: /номер на клиент/ инт /фамилия/ инт /баланс/

    Пример: 1 Иванов 125.25
            2 Георгиев -2.50

    а. Да се прочете информацията от файла и да се изведе форматирана на екрана.
       Номер       Фамилия      Баланс
       1           Иванов       125.25
       2           Георгиев      -2.50

       Номерът и Фамилията се разполагат на поле с дължина 12, подравнени вляво.
       Балансът се разполагат на поле с дължина 7, подравнени вдясно.
    б. Да се напише функция, която по зададен номер на заявка многократно
       сканира файла и извежда справка за клиентите.

       Заявка: 1 - Клиенти с нулев баланс
               2 - Клиенти с положителен баланс
               3 - Клиенти с отризателен баланс
               4 - Край на справката
*/

const unsigned MAX_LENGTH = 20;
const unsigned MAX_LINE_LENGTH = 100;

struct Client
{
    int number;
    char name[MAX_LENGTH];
    double balance;
};

enum Query
{
    ZEROBALLANCE = 1, POSITIVEBALANCE, NEGATIVEBALANCE, END
};

void formattedOutput(const Client& client)
{
    // извежда данните на един запис в указания формат
    cout << setiosflags(ios::left) << setw(12) << client.number
         << setiosflags(ios::left) << setw(12) << client.name
         << setw(7) << setiosflags(ios::showpoint|ios::fixed)
         << setprecision(2) << resetiosflags(ios::left) << client.balance << endl;
}

void clearStream(ifstream& inputStream)
{
    inputStream.clear();

    // прочитаме останалата част от реда
    inputStream.ignore(MAX_LINE_LENGTH, '\n');
}

void rewindStream(ifstream& inputStream)
{
    // достигнали сме край на файла, трябва да изчистим потока
    inputStream.clear();

    // преди началото на зявките трябва да се върнем в началото на файла
    inputStream.seekg(ios::beg);
}

bool readClientRecord(ifstream& inputStream, Client& client)
{
     // прочитаме номера
     if(inputStream >> client.number >> client.name >> client.balance)
        return true;

    // ако е възникнала грешка, трябва да се обработи
    clearStream(inputStream);
    return false;
}

Query getRequest()
{
    unsigned request;

    cout << "Въведете число в интервала [" << ZEROBALLANCE
         << "; " << END << "]: ";

    while(cin >> request)
    {
        if(request >= ZEROBALLANCE && request <= END)
            return (Query)request;
    }

    // връщаме кода за прекъсване на заявките,
    // ако не сме успели да прочетем коректна стойност
    return END;
}

void printRequest(Query request)
{
    switch(request)
    {
        case ZEROBALLANCE:
            cout << "Клиенти с нулев баланс" << endl; break;
        case POSITIVEBALANCE:
            cout << "Клиенти с положителен баланс" << endl; break;
        case NEGATIVEBALANCE:
            cout << "Клиенти с отрицателен баланс" << endl; break;
        case END:
            cout << "Край на заявките!" << endl; break;

        default: cout << "Непознат код на заявка!" << endl;
    }
}

bool checkRecord(Query request, const Client& client)
{
    if(request == ZEROBALLANCE && client.balance == 0.0)
        return true;

    if(request == POSITIVEBALANCE && client.balance > 0)
        return true;

    if(request == NEGATIVEBALANCE && client.balance < 0)
        return true;

    return false;
}

int main()
{
    ifstream inputFile("Clients.txt", ios::in);

    // проверяваме дали файлът е отворен за четене успешно
    if(!inputFile)
    {
        cout << "Файлът не може да бъде отворен!\n";
        return 1;
    }

    // променливи, в които да четем данните
    Client client;

    // извеждане на заглавен ред
    cout << setiosflags(ios::left) << setw(12) << "Номер"
         << setiosflags(ios::left) << setw(12) << "Име"
         << setw(7) << resetiosflags(ios::left) << "Баланс" << endl;

    // докато не сме стигнали края на файла, четем запис
    while(!inputFile.eof())
    {
        bool successfulRead = readClientRecord(inputFile, client);

        if(successfulRead)
        {
            // четенето е успешно, извеждаме данните
            formattedOutput(client);
        }
    }

    // достигнали сме край на файла, трябва да изчистим потока
    // и да се върнем в началото на файла
    rewindStream(inputFile);

    // b. Извеждане на менюто
    cout << "Меню за заявки:\n"
         << "1 - Клиенти с нулев баланс\n"
         << "2 - Клиенти с положителен баланс\n"
         << "3 - Клиенти с отризателен баланс\n"
         << "4 - Край на справката\n";

    Query request = getRequest();

    // докато не сме въвели END за прекъсване на заявките
    while(request != END)
    {
        // да се изведе съобщението за заявката
        printRequest(request);

        // докато не сме стигнали края на файла, четем запис
        while(!inputFile.eof())
        {
            bool successfulRead = readClientRecord(inputFile, client);

            if(successfulRead)
            {
                // четенето е успешно, трябва да го обработим
                if(checkRecord(request, client))
                {
                    formattedOutput(client);
                }
            }
        }

        // връщаме се в началото
        rewindStream(inputFile);
        request = getRequest();
    }

    // затваряме файла
    inputFile.close();

    return 0;
}
