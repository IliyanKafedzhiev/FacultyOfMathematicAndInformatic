#include <iostream>
#include "Rational.h"

using namespace std;

// единственото условие, което постав€ме при дефинирането на
// рационални числа е знаменател€т да е различен от 0

// конструктор по подразбиране
// инициализираме числител€ с 0, а знаменател€ с 1
Rational::Rational(int numer, int denom)
{
    numerator = numer;
    denominator = (0 == denom)? 1 : denom;
}

// селектор, който връща числител€ на рац. число
int Rational::getNumerator() const
{
    return numerator;
}

// селектор, който връща знаменател€ на рац. число
int Rational::getDenominator() const
{
    return denominator;
}

// мутатори
void Rational::setNumerator(int numer)
{
    numerator = numer;
}

void Rational::setDenominator(int denom)
{
    denominator = (0 == denom)? 1 : denom;
}

// предефинирани оператори
// събиране на рационални числа
const Rational Rational::operator + (const Rational& other) const
{
    int numer = numerator*other.denominator + denominator*other.numerator;
    int denom = denominator*other.denominator;

    return Rational(numer, denom);
}

// изваждане на рационални числа
const Rational Rational::operator - (const Rational& other) const
{
    int numer = numerator*other.denominator - denominator*other.numerator;
    int denom = denominator*other.denominator;

    return Rational(numer, denom);
}

// умножение на рационални числа
const Rational Rational::operator * (const Rational& other) const
{
    return Rational(numerator*other.numerator, denominator*other.denominator);
}

// делене на рационални числа
const Rational Rational::operator / (const Rational& other) const
{
    return Rational(numerator*other.denominator, denominator*other.numerator);
}

// при€телски функции, които
// реализират аритметика с ц€ло число
// събиране на рационално число с ц€ло
const Rational operator + (int number, const Rational& rat)
{
    // операци€та е комутативна
    return rat + number;
    // return Rational(number*rat.denominator + rat.numerator, rat.denominator);
}

// изваждане на рационално число и ц€ло
const Rational operator - (int number, const Rational& rat)
{
    return Rational(number*rat.denominator - rat.numerator, rat.denominator);
}

// умножение на рационално число с ц€ло
const Rational operator * (int number, const Rational& rat)
{
    return rat*number;
    // return Rational(number*rat.numerator, rat.denominator);
}

// делене на рационално число с ц€ло
const Rational operator / (int number, const Rational& rat)
{
    return Rational(number*rat.denominator, rat.numerator);
}

// извежда рационалното число
ostream& operator << (ostream& out, const Rational& rat)
{
    out << rat.numerator << "/" << rat.denominator;

    return out;
}
