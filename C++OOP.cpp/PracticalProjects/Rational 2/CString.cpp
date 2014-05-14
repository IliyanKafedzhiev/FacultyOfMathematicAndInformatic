#include "CString.h"
#include <string.h>


using namespace std;

// �������������� �� ���������� ����-�����
// ����� ������ (������������) �� �����
int String::countStrings = 0;

// ����������� � ������������ �� ���������
String::String(const char* otherString)
{
    setData(otherString);
    // ����������� ���������� �� ���������� ����-�����,
    // � ����� ����� ���� �� ����������� ������
    countStrings++;
}

// ����������� �� ��������
String::String(const String& other)
{
    // ������ ������ �� �� ������ ����� �� ����-�������,
    // � ��� �� ������� ����������� ��������� �� other
    setData(other.stringValue);
    // ������� ��� �������, ����� � ���� �� �����,
    // ��� ����� ������ �� ���������� � private ������

    // ����������� ���������� �� ���������� ����-�����,
    // � ����� ����� ���� �� ����������� ������
    countStrings++;
}

// ������������� �� �������� �� �����������
String& String::operator=(const String& other)
{
     // ��� ������� ���� � ��������, �������� � ����� �� �������� ����-�����
    // this e �������� ��� ������� �����
    if(&other != this)
    {
        // ��� �������� ����� (������ ������ �� ��������� =) � �������� ��
        // other (������ � ������� ������ �� ���������), �.�.
        // �� �� ��������� �� ��������� �������������� (� = �)

        // ����� ������ �� ��������� �������, ����� �� ����� � �������
        delete [] stringValue;
        setData(other.stringValue);
    }

    // ������� ������� �����
    return *this;
}

// ������������� �� �������� �� �����������, ����� ��������
// ���� ������ ��������� const char*
String& String::operator=(const char* otherValue)
{
    // ��� ������� ���� � ��������, �������� � ����� �� �������� ����-�����
    // ����� ������ �� ��������� �������, ����� �� ����� � �������
    delete [] stringValue;
    setData(otherValue);

    // ������� ������� �����
    return *this;
}

String::~String()
{
    // ����������� ����������� �����
    delete [] stringValue;
    // ���������� ���������� �� ���������� ����-�����,
    // � ����� ����� ���� �� ����������� ������
    countStrings--;
}

// ������� ����-�������, ����� �� ����� �� ���������� �� �����
void String::setData(const char* otherString)
{
    // �������� ��������� �� ��������� ������
    length = strlen(otherString);
    // ���������� ������������ �����,
    // + 1, ������ ������� '\0'
    stringValue = new char[length + 1];
    strcpy(stringValue, otherString);
}

// ������������� �� ���������� �� ����������� []
// ����� �� ��������� ���������� �� ��������� �������
// ������� �� � ������������ ����� �� �����
char& String::operator [](int index)
{
     // ���� index � ������� ������?
    if(index < 0 || index >= length)
    {
        cout << "The index is out of range!" << endl;
        index = 0;
    }

    // ������� ��������� �� ��������
    return stringValue[index];
}

// ������� const ���������, �.�. �������� �� ���� �� �� �������
// ������� �� � ���������� ����� �� �����
const char& String::operator [] (int index) const
{
    // ���� index � ������� ������?
    if(index < 0 || index >= length)
    {
        cout << "The index is out of range!" << endl;
        index = 0;
    }

    return stringValue[index];
}

// ������������� �� ���������� + � +=
const String String::operator + (const String& other) const
{
    String result(*this);
    result += other;

    return result;
}

String& String::operator += (const String& other)
{
    // ���������� ������ ������� �� �������
    int len = length + other.length;
    // �������� �������� �����, � ����� �� ��������� ����� �������
    char* temp = new char[len + 1];

    // �������� �������������� ����� � ������ ������
    strcpy(temp, stringValue);
    strcpy(temp + length, other.stringValue);

    // ������������� �������, � ����� � ������� ������� �����
    delete [] stringValue;

    // ����������� ���� ��������� �� ����-�������
    stringValue = temp;
    length = len;

    return *this;
}

// ������������� �� ���������� (), �� �� �����������
// ������� �� ������ �� ���������� ������� � ��������� ���� �������
String String::operator ()(int position, int len) const
{
    // ��������� �� �������� ���������
    if(position < 0 || position >= length || len <= 0)
        return ""; // �� �� ������ ������������ �� �����, �� �� ������� ����������� �����
        // ������ �������������

    // ����������� ��������� �� �������
    // ��� ����� ��� � ������� 5 ("�����") � ������ �� ������� ������
    // �� ������� 2 � ������� 4, 2 + 4 > 5 => ����� �� �������� ���� ��. �� ������
    // length - 1, �.�. ���� ������� � (length - 1) - position + 1 = length - position
    if(position + len > length)
        len = length - position;

    // �������� �������� �����, � ����� �� ��������� ����� �������
    char* temp = new char[len + 1];

    // �������� len ������ �������, �� ������� position � temp
    strncpy(temp, stringValue + position, len);
    temp[len] = '\0';

    // ��������� ��� �����, ����� �� ������ ���� ��������
    String result(temp);

    // ������������� ���������� �����
    delete [] temp;

    return result;
}

// ������������� �� ���������� �� ������������� �� ������ �� ����� �� �������
String::operator const char*() const
{
    return stringValue;
}

// ��������� ����� ��� �������
// ����� ������, ��� ������� ������ � ����� ��������� ���� ���������,
// ����������� � ��������������
bool String::operator < (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) < 0;
}

// ����� ������, ��� ������� ������ � ����� �� ��������� ���� ���������,
// ����������� � ��������������
bool String::operator == (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) == 0;
}

// ����� ������, ��� ������� ������ � ���� ��������� ���� ���������,
// ����������� � ��������������
bool String::operator > (const String& other) const
{
    return strcmp(this->stringValue, other.stringValue) > 0;
}

// ����� ������, ��� ������� ������ � �������� �� ��������� ���� ���������,
// ����������� � ��������������
bool String::operator != (const String& other) const
{
    return !(*this == other);
}

// ��������� �� �������
// ������������� �� ��������� <<, ���������� �� ���������� �������
ostream& operator << (ostream& out, const String& str)
{
    out << str.stringValue;
    return out;
}

// ��������� �� ������� �� ����������� ����,
// ���������� �� ������� ��� ������ ���������
istream& operator >> (istream& in, String& str)
{
    // �������� �����, � ����� �� �������� �������
    char temp[String::CIN_LIMIT];
    // ����� �� ����������� ���� ���-����� CIN_LIMIT �������
    // ��� �� ��������� �� ������� �� ��� ���
    in.getline(temp, String::CIN_LIMIT, '\n');
    // ��� �������� � �������
    if(in)
    {
        // ������� �� ��������������� �������� �� �����������
        str = temp;
    }

    // ������� ��������� �� ������, �� ����� �����
    // ����� �� ���������� �������� �������
    return in;
}

// �������� ����-�������, ����� ����� ���� �� ����������� ������
int String::getCountStrings()
{
    // ���������� ������ �� �� �������� �� ����������,
    // �������������� � �������� � ��������� this, �
    // ���������� ������ ����� �� �� �� �������� � ��������� �����,
    // � � ����� �� �����::
    return countStrings;
}
