#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
    public:
        // Конструктор по подразбиране
        Rational(int = 0, int = 1);

        // селектори
        // връща числителя на рац. число
        int getNumerator() const;
        // връща знаменателя на рац. число
        int getDenominator() const;

        // мутатори
        void setNumerator(int);
        void setDenominator(int);

        // предефинирани оператори
        // събиране на рационални числа
        const Rational operator + (const Rational&) const;
        const Rational operator - (const Rational&) const;
        const Rational operator * (const Rational&) const;
        const Rational operator / (const Rational&) const;

        // приятелски функции, които
        // реализират аритметика с цяло число
        friend const Rational operator + (int, const Rational&);
        friend const Rational operator - (int, const Rational&);
        friend const Rational operator * (int, const Rational&);
        friend const Rational operator / (int, const Rational&);

        // извежда рационалното число
        friend ostream& operator << (ostream&, const Rational&);

    private:
        int numerator;
        int denominator;
};

#endif // RATIONAL_H
