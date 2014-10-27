#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
    ������ 4:
    ����� � ������� ����, � ����� �� �������� ������� �� ������� �� �����.
    ������� �� � �������: /����� �� ������/ ��� /�������/ ��� /������/

    ������: 1 ������ 125.25
            2 �������� -2.50

    �. �� �� ������� ������������ �� ����� � �� �� ������ ����������� �� ������.
       �����       �������      ������
       1           ������       125.25
       2           ��������      -2.50

       ������� � ��������� �� ���������� �� ���� � ������� 12, ���������� �����.
       �������� �� ���������� �� ���� � ������� 7, ���������� ������.
    �. �� �� ������ �������, ����� �� ������� ����� �� ������ �����������
       ������� ����� � ������� ������� �� ���������.

       ������: 1 - ������� � ����� ������
               2 - ������� � ����������� ������
               3 - ������� � ����������� ������
               4 - ���� �� ���������
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
    // ������� ������� �� ���� ����� � �������� ������
    cout << setiosflags(ios::left) << setw(12) << client.number
         << setiosflags(ios::left) << setw(12) << client.name
         << setw(7) << setiosflags(ios::showpoint|ios::fixed)
         << setprecision(2) << resetiosflags(ios::left) << client.balance << endl;
}

void clearStream(ifstream& inputStream)
{
    inputStream.clear();

    // ��������� ���������� ���� �� ����
    inputStream.ignore(MAX_LINE_LENGTH, '\n');
}

void rewindStream(ifstream& inputStream)
{
    // ���������� ��� ���� �� �����, ������ �� �������� ������
    inputStream.clear();

    // ����� �������� �� ������� ������ �� �� ������ � �������� �� �����
    inputStream.seekg(ios::beg);
}

bool readClientRecord(ifstream& inputStream, Client& client)
{
     // ��������� ������
     if(inputStream >> client.number >> client.name >> client.balance)
        return true;

    // ��� � ���������� ������, ������ �� �� ��������
    clearStream(inputStream);
    return false;
}

Query getRequest()
{
    unsigned request;

    cout << "�������� ����� � ��������� [" << ZEROBALLANCE
         << "; " << END << "]: ";

    while(cin >> request)
    {
        if(request >= ZEROBALLANCE && request <= END)
            return (Query)request;
    }

    // ������� ���� �� ���������� �� ��������,
    // ��� �� ��� ������ �� �������� �������� ��������
    return END;
}

void printRequest(Query request)
{
    switch(request)
    {
        case ZEROBALLANCE:
            cout << "������� � ����� ������" << endl; break;
        case POSITIVEBALANCE:
            cout << "������� � ����������� ������" << endl; break;
        case NEGATIVEBALANCE:
            cout << "������� � ����������� ������" << endl; break;
        case END:
            cout << "���� �� ��������!" << endl; break;

        default: cout << "�������� ��� �� ������!" << endl;
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

    // ����������� ���� ������ � ������� �� ������ �������
    if(!inputFile)
    {
        cout << "������ �� ���� �� ���� �������!\n";
        return 1;
    }

    // ����������, � ����� �� ����� �������
    Client client;

    // ��������� �� �������� ���
    cout << setiosflags(ios::left) << setw(12) << "�����"
         << setiosflags(ios::left) << setw(12) << "���"
         << setw(7) << resetiosflags(ios::left) << "������" << endl;

    // ������ �� ��� �������� ���� �� �����, ����� �����
    while(!inputFile.eof())
    {
        bool successfulRead = readClientRecord(inputFile, client);

        if(successfulRead)
        {
            // �������� � �������, ��������� �������
            formattedOutput(client);
        }
    }

    // ���������� ��� ���� �� �����, ������ �� �������� ������
    // � �� �� ������ � �������� �� �����
    rewindStream(inputFile);

    // b. ��������� �� ������
    cout << "���� �� ������:\n"
         << "1 - ������� � ����� ������\n"
         << "2 - ������� � ����������� ������\n"
         << "3 - ������� � ����������� ������\n"
         << "4 - ���� �� ���������\n";

    Query request = getRequest();

    // ������ �� ��� ������ END �� ���������� �� ��������
    while(request != END)
    {
        // �� �� ������ ����������� �� ��������
        printRequest(request);

        // ������ �� ��� �������� ���� �� �����, ����� �����
        while(!inputFile.eof())
        {
            bool successfulRead = readClientRecord(inputFile, client);

            if(successfulRead)
            {
                // �������� � �������, ������ �� �� ���������
                if(checkRecord(request, client))
                {
                    formattedOutput(client);
                }
            }
        }

        // ������� �� � ��������
        rewindStream(inputFile);
        request = getRequest();
    }

    // ��������� �����
    inputFile.close();

    return 0;
}
