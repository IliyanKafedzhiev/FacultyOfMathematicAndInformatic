#include <iostream>
#include <iomanip>

using namespace std;

/*
    Да се дефинират структурите:
    Person , определяща лице по собствено и фамилно име;
    Client, определяща клиент като лице, притежаващо банкова сметка с дадена сума.

    Да се дефинират функции, които въвеждат и извеждат данни за лице и клиент.
    Да се напише програма, която:
    а. въвежда имената и банковите сметки на множество от клиенти, зададено чрез едномерен масив;
    б. извежда имената и банковите сметки на клиентите от множеството;
    в. намира сумата от задълженията на клиентите от множеството.

    Забележка: задълженията на даден клиент се отбелязват с отрицателен баланс на бамковата сметка.
*/

// максимална дължина на името
const unsigned MAX_LENGTH = 20;

// максимална брой клиенти в множеството
const unsigned MAX_COUNT = 20;

struct Person
{
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
};

// въвеждане на данни за лице,
// параметърът се предава по псевдоним, ще бъде променен във функцията
void readPerson(Person& person)
{
    cout << "Моля, въведете собствено име: ";
    cin >> person.firstName;

    cout << "Моля, въведете фамилия: ";
    cin >> person.lastName;
}

// извеждане на данните за лице
void printPerson(const Person& person)
{
    cout << "Собствено име: " << person.firstName << endl;
    cout << "Фамилия: " << person.lastName << endl;
}

struct Client
{
    // вложена структура
    Person name;
    double balance;
};

// въвеждане на клиент
void readClient(Client& client)
{
    cout << "Моля, въведете име на клиента: ";
    readPerson(client.name);

    cout << "Моля, въведете баланс по сметката: ";
    cin >> client.balance;
}

// извеждане на данните за клиент
void printClient(const Client& client)
{
    cout << "Име на клиента: ";
    printPerson(client.name);

    cout << "Баланс по сметка: ";
    // балансът по сметката да се извежда с две позиции след десетичната запетая
    cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);
    cout << client.balance;
}

void useBankAccounts()
{
    // въвеждане на множеството от клиенти
    // брой клиенти
    unsigned countClients;

    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "Моля, въведете броя на клиентите в интервала (1, " << MAX_COUNT << ")\n";
        cin >> countClients;

        if(countClients >= 1 && countClients <= MAX_COUNT)
        {
            isCorrect = true;
        }
    }

    // деклариране на множеството от клиенти
    Client bankClients[MAX_COUNT];

    unsigned i;
    for(i = 0; i <= countClients - 1; i++)
    {
        // прочитане на текущия клиент
        readClient(bankClients[i]);
    }

    // извеждане на клиентите
    for(i = 0; i <= countClients - 1; i++)
    {
        // прочитане на текущия клиент
        printClient(bankClients[i]);
    }

    // намиране на сбора от задълженията на клиентите
    double debt = 0;
    for(i = 0; i <= countClients - 1; i++)
    {
        // прочитане на текущия клиент
        if(bankClients[i].balance < 0)
        {
            debt += bankClients[i].balance;
        }
    }

    cout << "Общата стойност на задълженията на клиентите е: ";
    cout << debt;
}

void checkEqual()
{
    Person a;
    readPerson(a);
    printPerson(a);

    Person b;
    // операторът = прави копие на масивите в Person
    b = a;
    printPerson(b);

    a.firstName[0] = 'A';

    printPerson(a);
    printPerson(b);
}

int main()
{
    // Задача 4: Вложени структури. Банкови сметки.
    useBankAccounts();

    // checkEqual();


    return 0;
}
