#include <iostream>
#include "Rational.h"

using namespace std;

// ������������ �������, ����� ��������� ��� ������������ ��
// ���������� ����� � ������������ �� � �������� �� 0

// ����������� �� ������������
// �������������� ��������� � 0, � ����������� � 1
Rational::Rational(int numer, int denom)
{
    numerator = numer;
    denominator = (0 == denom)? 1 : denom;
}

// ��������, ����� ����� ��������� �� ���. �����
int Rational::getNumerator() const
{
    return numerator;
}

// ��������, ����� ����� ����������� �� ���. �����
int Rational::getDenominator() const
{
    return denominator;
}

// ��������
void Rational::setNumerator(int numer)
{
    numerator = numer;
}

void Rational::setDenominator(int denom)
{
    denominator = (0 == denom)? 1 : denom;
}

// ������������� ���������
// �������� �� ���������� �����
const Rational Rational::operator + (const Rational& other) const
{
    int numer = numerator*other.denominator + denominator*other.numerator;
    int denom = denominator*other.denominator;

    return Rational(numer, denom);
}

// ��������� �� ���������� �����
const Rational Rational::operator - (const Rational& other) const
{
    int numer = numerator*other.denominator - denominator*other.numerator;
    int denom = denominator*other.denominator;

    return Rational(numer, denom);
}

// ��������� �� ���������� �����
const Rational Rational::operator * (const Rational& other) const
{
    return Rational(numerator*other.numerator, denominator*other.denominator);
}

// ������ �� ���������� �����
const Rational Rational::operator / (const Rational& other) const
{
    return Rational(numerator*other.denominator, denominator*other.numerator);
}

// ���������� �������, �����
// ���������� ���������� � ���� �����
// �������� �� ���������� ����� � ����
const Rational operator + (int number, const Rational& rat)
{
    // ���������� � �����������
    return rat + number;
    // return Rational(number*rat.denominator + rat.numerator, rat.denominator);
}

// ��������� �� ���������� ����� � ����
const Rational operator - (int number, const Rational& rat)
{
    return Rational(number*rat.denominator - rat.numerator, rat.denominator);
}

// ��������� �� ���������� ����� � ����
const Rational operator * (int number, const Rational& rat)
{
    return rat*number;
    // return Rational(number*rat.numerator, rat.denominator);
}

// ������ �� ���������� ����� � ����
const Rational operator / (int number, const Rational& rat)
{
    return Rational(number*rat.denominator, rat.numerator);
}

// ������� ������������ �����
ostream& operator << (ostream& out, const Rational& rat)
{
    out << rat.numerator << "/" << rat.denominator;

    return out;
}
