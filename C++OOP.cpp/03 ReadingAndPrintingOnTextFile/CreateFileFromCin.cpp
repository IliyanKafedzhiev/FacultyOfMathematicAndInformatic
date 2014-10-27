# include <iostream>
# include <fstream>
# include <string.h>

using namespace std;

/*
    ������ 1:
    �� �� ������ ��������, ����� ���� ������ �� ������������ � �� �������
    ��� ���� � ��� ����.txt, ��������� � ���. �������� ����������, ������ �� ������� "end"
    ��� �� �������� Ctrl + Z.
*/

const unsigned MAX_LENGTH = 20;

int main()
{
    // �������� �� �� ������� ������ Test.txt �� �����
    ofstream outputFile("Test1.txt", ios::out);
    if(!outputFile)
    {
        cout << "������ �� ���� �� ���� �������!\n";
        return 1;
    }

    // ������ ������� � ������� �� �����
    // ����� ����� �� ��������� �� ���� "end" ��� �� Ctrl + Z
    char buffer[MAX_LENGTH];

    cout << "����, �������� ������!\n"
            "����������� ��� ����� ����� ��� Ctrl+Z ��� ��� ��������� �� end\n";

    // ����. strcmp ����� 0, ��� ����� ���� �� �����
    while(cin >> buffer && strcmp(buffer, "end"))
    {
        cout << "CIN: " << cin.rdstate() << endl;
        cout << "BUFFER: " << buffer << endl;

        //��������� ��� �����
        outputFile << buffer ;
    }

    // ��������� �� �����
    outputFile.close();

    return 0;
}
