#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

using namespace std;

// ������: �������� ��� � ����������� �����
class String
{
    public:
        // ����������� � ������������ �� ���������
        String(const char* = "");

        // ����������� �� ��������
        String(const String&);

        // ������������� �� �������� �� �����������
        String& operator=(const String&);
        String& operator=(const char*);

        // ����������
        ~String();

        // ����� ��������� �� �������
        int getLength() const
        {
            return length;
        }

//        const char* convertToChars() const
//        {
//            return stringValue;
//        }

        // ������������� �� ������ �������� !
        bool operator!() const
        {
            // ��������� ���� ������� ����� �� � ������ ���
            return length == 0;
        }

        // ������������� �� ���������� �� ����������� []
        // ����� �� ��������� ���������� �� ��������� �������
        char& operator [](int);
        // ������� const ���������, �.�. �������� �� ���� �� �� �������
        const char& operator [] (int) const;

        // ������������� �� ���������� + � +=
        const String operator + (const String&) const;
        String& operator += (const String&);

        // ������������� �� ���������� (), �� �� �����������
        // ������� �� ������ �� ���������� ������� � ��������� ���� �������
        String operator ()(int position, int len) const;

        // ������������� �� ���������� �� ������������� �� ������ �� ����� �� �������
        operator const char*() const;

        // ��������� ����� ��� �������
        // ������������� �� ���������� <, >, ==, != ���� ����-������� �� �����
        bool operator < (const String&) const;
        bool operator > (const String&) const;
        bool operator == (const String&) const;
        bool operator != (const String&) const;

        // ��������� �� �������
        // ������������� �� ��������� <<, ���������� �� ���������� �������
        friend ostream& operator << (ostream&, const String&);

        // ��������� �� ������� �� ����������� ����,
        // ���������� �� ������� ��� ������ ���������
        friend istream& operator >> (istream&, String&);

        // �������� ����-�������, ����� ����� ���� �� ����������� ������
        static int getCountStrings();

    private:
        char* stringValue;
        int length;

        // ���������� ����-�����, ����� �� ������������
        // ��� ������������� �, �������������� �� �����
        // ���������� ���� �������, ����� ����� ��� cin
        static const int CIN_LIMIT = 80;

        // �������� ����-�����, ����� ������ ���� �� �����������
        // ������ �� �����, ��������� �� � ��������������,
        // �������� �� � �������������
        static int countStrings;

        // ������� �������, ����� �� ����� �� ���������� �� �����
        void setData(const char*);
};

#endif // CSTRING_H
