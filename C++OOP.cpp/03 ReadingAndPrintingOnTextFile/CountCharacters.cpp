#include <iostream>
#include <fstream>

using namespace std;

/*
    ������ 2:
    ����� � ������� ���� ����.txt. �� �� ������ ��������,
    ����� ������� �������� ���������� �� �����:
    �. ���� ������� (��� ���.);
    �. ���� ������� (� ���.);
    �. ���� ���� ��� �����;
    �. ���� ������.
*/

int main()
{
    // �� �� ������� �� ������� ���������� ���� �� ������
    ifstream inputFile("Test.txt", ios::in);

    // ����������� ���� ��� ������ �� ������� �����
    if(!inputFile.is_open())
    {
        cout << "������ �� ���� �� ���� �������!\n";
        return 1;
    }

    // ���� ��������� �������, �������� �� ���.
    unsigned countChars = 0;

    // ���� ���������
    unsigned countSpaces = 0;

    // ���� ���� ��� �����
    unsigned countWords = 0;

    // ���� ������
    unsigned countRows = 0;

    // ����, ����� �� �����, ������ ��� � ����
    bool isInWord = false;

    // �� ����� ������������ �� ����� ������ �� ������,
    // �� ��������� �� ���� �� �����
    char currentChar = inputFile.get();

    while(inputFile)
    {
        // ��� ��� �������� ���, ������������ ��� ���
        if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
        {
            if(currentChar == ' ' || currentChar == '\t')
            {
                countSpaces ++;
            }

            if(currentChar == '\n')
            {
                // ������� ��� ������ �� ��� ���, ����� �� �������� ���� �� ��������
                countRows ++;
            }

            // ��� ������ �� ���� � �������, ��� � ������� �� ����
            // ����������� �������� ����
            if(isInWord)
            {
                countWords ++;

                // ������� �����, ������ � ��������
                isInWord = false;
            }
        }
        else
        {
            // ���� ������, ����� ������� �������� �� ����
            countChars++;

            isInWord = true;
        }

        inputFile.get(currentChar);
    }

    // ��������� �� �����
    inputFile.close();

    cout << "\nSTATISTICS\n";
    cout << "���� �������: " << countChars << endl;
    cout << "���� ������� (���. ���.): " << countChars + countSpaces << endl;
    cout << "���� ����: " << countWords << endl;
    cout << "���� ������: " << countRows << endl;

    return 0;
}
