#include <iostream>
#include <math.h>

using namespace std;

// ���������� � ���������� �� ���������
/*
    ������ 1
    �� �� �������� ���������, ����� ������ ���������� ���� ����� �� ������.
    �� �� ������� ������� �� ���������, ���������, �������� �� ����������
    � ������ �� ����������.
*/

// ��������� �� ���� �� ����
const int MAX_LINE_LENGTH = 100;

struct Triangle
{
    double a, b, c;
};

// ���������� �� ����������� ������ �����
double readPositiveDouble()
{
    double d;
    bool isCorrect = false;

    int countTries = 1;

    while(!isCorrect)
    {
        cout << "����, �������� ������ ����������� �����:\n";
        // �� �� �� �������� ������������ �� ���������...
        cout << "���� N " << countTries << "\n";
        countTries ++;

        cin >> d;

        if(!cin.good())
        {
            // ������� ���� �� ������, �� �� �������
            cin.clear();
            // �� �� �� ������� ������
            cin.ignore(MAX_LINE_LENGTH, '\n');
        }

        isCorrect = (d > 0);

    }

    cout << "����������� ����� � " << d << "\n";
    return d;
}

// �������������� �� ����������
// ����� �� ������������ �� �������� �� �����������?
// (a > 0) && (b > 0) && (c > 0) &&(a + b > c) && (a + c > b) && (b + c > a)
void createTriangle(Triangle& newTriangle)
{
    bool correctInput = false;

    double a, b, c;

    while(!correctInput)
    {
        cout << "����, �������� �������� �� �����������...\n";

        a = readPositiveDouble();
        b = readPositiveDouble();
        c = readPositiveDouble();

        correctInput = (a + b > c) && (a + c > b) && (b + c > a);
    }

    newTriangle.a = a;
    newTriangle.b = b;
    newTriangle.c = c;
}

// ��������� �� ����������
void printTriangle(const Triangle* const tr)
{
    cout << "���������� ��� ������ (" << tr->a << ", " << tr->b << ", " << tr->c << ")\n";
}

// �������� �� ���������� �� ����������
double perimeter(const Triangle& tr)
{
    return tr.a + tr.b + tr.c;
}

// �������� �� ���� �� ����������
// sqrt(p*(p - a)*(p - b)*(p - c))
double surface(const Triangle& tr)
{
    double p = perimeter(tr)/2;

    return sqrt(p*(p - tr.a)*(p - tr.b)*(p - tr.c));
}

int main()
{
    // ������������ ����������
    Triangle ABC;

    createTriangle(ABC);

    printTriangle(&ABC);

    cout << "����������� �� ���� ��������� � " << perimeter(ABC) << "\n";
    cout << "������ �� ���� ��������� � " << surface(ABC) << "\n";

    return 0;
}
