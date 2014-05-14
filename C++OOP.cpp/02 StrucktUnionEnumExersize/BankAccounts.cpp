#include <iostream>
#include <iomanip>

using namespace std;

/*
    �� �� ��������� �����������:
    Person , ���������� ���� �� ��������� � ������� ���;
    Client, ���������� ������ ���� ����, ����������� ������� ������ � ������ ����.

    �� �� ��������� �������, ����� �������� � �������� ����� �� ���� � ������.
    �� �� ������ ��������, �����:
    �. ������� ������� � ��������� ������ �� ��������� �� �������, �������� ���� ��������� �����;
    �. ������� ������� � ��������� ������ �� ��������� �� �����������;
    �. ������ ������ �� ������������ �� ��������� �� �����������.

    ���������: ������������ �� ����� ������ �� ���������� � ����������� ������ �� ��������� ������.
*/

// ���������� ������� �� �����
const unsigned MAX_LENGTH = 20;

// ���������� ���� ������� � �����������
const unsigned MAX_COUNT = 20;

struct Person
{
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
};

// ��������� �� ����� �� ����,
// ����������� �� ������� �� ���������, �� ���� �������� ��� ���������
void readPerson(Person& person)
{
    cout << "����, �������� ��������� ���: ";
    cin >> person.firstName;

    cout << "����, �������� �������: ";
    cin >> person.lastName;
}

// ��������� �� ������� �� ����
void printPerson(const Person& person)
{
    cout << "��������� ���: " << person.firstName << endl;
    cout << "�������: " << person.lastName << endl;
}

struct Client
{
    // ������� ���������
    Person name;
    double balance;
};

// ��������� �� ������
void readClient(Client& client)
{
    cout << "����, �������� ��� �� �������: ";
    readPerson(client.name);

    cout << "����, �������� ������ �� ��������: ";
    cin >> client.balance;
}

// ��������� �� ������� �� ������
void printClient(const Client& client)
{
    cout << "��� �� �������: ";
    printPerson(client.name);

    cout << "������ �� ������: ";
    // �������� �� �������� �� �� ������� � ��� ������� ���� ����������� �������
    cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);
    cout << client.balance;
}

void useBankAccounts()
{
    // ��������� �� ����������� �� �������
    // ���� �������
    unsigned countClients;

    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "����, �������� ���� �� ��������� � ��������� (1, " << MAX_COUNT << ")\n";
        cin >> countClients;

        if(countClients >= 1 && countClients <= MAX_COUNT)
        {
            isCorrect = true;
        }
    }

    // ����������� �� ����������� �� �������
    Client bankClients[MAX_COUNT];

    unsigned i;
    for(i = 0; i <= countClients - 1; i++)
    {
        // ��������� �� ������� ������
        readClient(bankClients[i]);
    }

    // ��������� �� ���������
    for(i = 0; i <= countClients - 1; i++)
    {
        // ��������� �� ������� ������
        printClient(bankClients[i]);
    }

    // �������� �� ����� �� ������������ �� ���������
    double debt = 0;
    for(i = 0; i <= countClients - 1; i++)
    {
        // ��������� �� ������� ������
        if(bankClients[i].balance < 0)
        {
            debt += bankClients[i].balance;
        }
    }

    cout << "������ �������� �� ������������ �� ��������� �: ";
    cout << debt;
}

void checkEqual()
{
    Person a;
    readPerson(a);
    printPerson(a);

    Person b;
    // ���������� = ����� ����� �� �������� � Person
    b = a;
    printPerson(b);

    a.firstName[0] = 'A';

    printPerson(a);
    printPerson(b);
}

int main()
{
    // ������ 4: ������� ���������. ������� ������.
    useBankAccounts();

    // checkEqual();


    return 0;
}
