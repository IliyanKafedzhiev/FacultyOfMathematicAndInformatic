#include <iostream>
#include <fstream>

#include <string.h>

using namespace std;

/*
    ������ 3:
    �� �� ������ ��������, ����� �������� ����������� �� ����� .cpp ����.
    ���������� �� ������� � ��� ����.
*/

const unsigned MAX_LINE_LENGTH = 1024;

int main()
{
    // �������� ����� �� ������
    ifstream inputFile("ClientsBalance - Copy.cpp", ios::in);
    // ����������� ���� ������ � ������� �� ������ �������
    if(!inputFile)
    {
        cout << "������ �� ���� �� ���� ������� �� ������!\n";
        return 1;
    }

    ofstream outputFile("WithoutComments.cpp", ios::out);
    // ����������� ���� ������ � ������� �� ����� �������
    if(!outputFile)
    {
        cout << "������ �� ���� �� ���� ������� �� ������!\n";
        return 1;
    }

    bool isInString = false;

    // �������� ��� �������� �� ������
    char currentChar;

    // ������� ������� ������
    currentChar = inputFile.get();

    // ������ �� ���� ��������� ������ �� ������
    while(inputFile)
    {
        // ���������:
        // ��������� �� ��������� ������ � \", �.�. "escape"-���� �������
        // �.�. �� �� ���������
        if(currentChar == '\"')
        {
            // ��� ��� � ������� �� ���, ������� �����
            // ��� ���� ������� ����, ������� �����
            isInString = !isInString;

            // �������� ������ �� �� ������ � ����������� ����
            outputFile.put(currentChar);
        }
        else if(currentChar == '/')
        {
            // ��������� ���������, �� ����� ��� �������� /
            int posSlash = inputFile.tellg();

            // ���������� ���������� ������
            char nextChar = inputFile.peek();

            if(nextChar == '/')
            {
                if(!isInString)
                {
                    // ������ �� �������� �� ��� //

                    // ������� �� � �������� �� ���������
                    inputFile.seekg(posSlash, ios::beg);

                    // ���������� ������ ������� �� ���� �� ����
                    inputFile.ignore(MAX_LINE_LENGTH, '\n');

                    // � ����������� ���� ������ �� �� ������ '\n'
                    outputFile << endl;
                }
            }
            else if(nextChar == '*')
            {
                if(!isInString)
                {
                    // ������ �� �������� �� ��� /**/
                    // ���������� *
                    currentChar = inputFile.get();

                    // ���������� ������ ������� �� ���� �� ���������
                    do
                    {
                        currentChar = inputFile.get();
                        nextChar = inputFile.peek();
                    }
                    while (currentChar != '*' || nextChar != '/');

                    // ���������� /
                    currentChar = inputFile.get();
                }
            }
        }
        else
        {
            // �������� ������ �� �� ������ � ����������� ����
            outputFile.put(currentChar);
        }

        // ������� ��������� ������
        currentChar = inputFile.get();
    }

    // ��������� �� ���������
    inputFile.close();
    outputFile.close();

    return 0;
}
