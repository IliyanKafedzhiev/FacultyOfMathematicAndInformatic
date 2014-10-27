#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
    public:
        // ����������� �� ������������
        Rational(int = 0, int = 1);

        // ���������
        // ����� ��������� �� ���. �����
        int getNumerator() const;
        // ����� ����������� �� ���. �����
        int getDenominator() const;

        // ��������
        void setNumerator(int);
        void setDenominator(int);

        // ������������� ���������
        // �������� �� ���������� �����
        const Rational operator + (const Rational&) const;
        const Rational operator - (const Rational&) const;
        const Rational operator * (const Rational&) const;
        const Rational operator / (const Rational&) const;

        // ���������� �������, �����
        // ���������� ���������� � ���� �����
        friend const Rational operator + (int, const Rational&);
        friend const Rational operator - (int, const Rational&);
        friend const Rational operator * (int, const Rational&);
        friend const Rational operator / (int, const Rational&);

        // ������� ������������ �����
        friend ostream& operator << (ostream&, const Rational&);

    private:
        int numerator;
        int denominator;
};

#endif // RATIONAL_H
