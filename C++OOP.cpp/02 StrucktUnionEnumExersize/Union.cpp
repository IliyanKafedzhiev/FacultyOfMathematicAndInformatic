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

// проверява дали низа съдържа цяло или реално число,
// преобразува низа в съответното число,
bool convertToNumber(Node& node)
{
    // node.type е STRING
    char* nodeValue = node.value.vString;
    if(nodeValue == NULL)
        return false;

    // cout << "NODE VALUE: " << nodeValue << endl;
    // cout << "FIRST CHAR: " << *nodeValue << endl;

    // ако първият символ не е +, - или цифра
    // низът не може да се преобразува до число
    if(*nodeValue != '+' && *nodeValue != '-' && !isDigit(*nodeValue))
        return false;

    // ЗАБЕЛЕЖКА
    // ако първият символ е + или -, не се проверява какво следва,
    // т.е. по-добре е да се провери дали всички следващи символи са цифри
    // при преобразуването на данните, ако след цифрата (цифрите)
    // има букви те ще се загубят (например 3asd -> 3)

    // проверяваме дали този низ съдържа точка
    char* ptrDot = strchr(nodeValue, '.');
    if(ptrDot)
    {
        // намерена е . в низа, опитваме да го преобразуваме до реално число
        node.type = DOUBLE;
        node.value.vDouble = atof(nodeValue);
    }
    else
    {
        // можем да преобразуваме низа до цяло число
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
            cout << "Неизвестен тип!";
    }
}

// прочита стринг и извежда всяки от елементите му на нов ред, в следния формат:
// тип на данните: самите данни
// данните са разделени с интервал, можем да различим:
// цяло число, реално число, дума (започва с латинска буква, последователност от символи)
void parseString(char* str)
{
    // strtok разделя низа на поднизове,
    // при срещане на посочения разделител/ и
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
