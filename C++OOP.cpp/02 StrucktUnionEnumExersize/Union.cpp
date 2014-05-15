#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum Type
{
    INT,
    DOUBLE,
    STRING
};

union Value
{
    int vInt;
    double vDouble;
    char* vString;
};

struct Node
{
    Type type;
    Value value;
};

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// ��������� ���� ���� ������� ���� ��� ������ �����,
// ����������� ���� � ����������� �����,
bool convertToNumber(Node& node)
{
    // node.type � STRING
    char* nodeValue = node.value.vString;
    if(nodeValue == NULL)
        return false;

    // cout << "NODE VALUE: " << nodeValue << endl;
    // cout << "FIRST CHAR: " << *nodeValue << endl;

    // ��� ������� ������ �� � +, - ��� �����
    // ����� �� ���� �� �� ����������� �� �����
    if(*nodeValue != '+' && *nodeValue != '-' && !isDigit(*nodeValue))
        return false;

    // ���������
    // ��� ������� ������ � + ��� -, �� �� ��������� ����� ������,
    // �.�. ��-����� � �� �� ������� ���� ������ �������� ������� �� �����
    // ��� ��������������� �� �������, ��� ���� ������� (�������)
    // ��� ����� �� �� �� ������� (�������� 3asd -> 3)

    // ����������� ���� ���� ��� ������� �����
    char* ptrDot = strchr(nodeValue, '.');
    if(ptrDot)
    {
        // �������� � . � ����, �������� �� �� ������������� �� ������ �����
        node.type = DOUBLE;
        node.value.vDouble = atof(nodeValue);
    }
    else
    {
        // ����� �� ������������� ���� �� ���� �����
        node.type = INT;
        node.value.vInt = atoi(nodeValue);
    }

    return true;
}

void printDataNode(const Node& node)
{
    switch(node.type)
    {
        case INT:
            cout << "INT: " << node.value.vInt << endl; break;

        case DOUBLE:
            cout << "DOUBLE: " << node.value.vDouble << endl; break;

        case STRING:
            cout << "STRING: " << node.value.vString << endl; break;

        default:
            cout << "���������� ���!";
    }
}

// ������� ������ � ������� ����� �� ���������� �� �� ��� ���, � ������� ������:
// ��� �� �������: ������ �����
// ������� �� ��������� � ��������, ����� �� ��������:
// ���� �����, ������ �����, ���� (������� � �������� �����, ���������������� �� �������)
void parseString(char* str)
{
    // strtok ������� ���� �� ���������,
    // ��� ������� �� ��������� ����������/ �
    char* token = strtok(str, " ");

    while(token)
    {
       // cout << "TOKEN: " << token << endl;

       Node node;
       node.type = STRING;
       node.value.vString = token;

       convertToNumber(node);
       printDataNode(node);

       token = strtok(NULL, " ");
    }
}

int main()
{
    char str[] = " abc 23 7.45 a3s";
    parseString(str);

    return 0;
}
