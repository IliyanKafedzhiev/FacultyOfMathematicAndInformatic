#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

using namespace std;

// стринг: символен низ в динамичната памет
class String
{
    public:
        // конструктор с подразбиращи се стойности
        String(const char* = "");

        // конструктор за копиране
        String(const String&);

        // предефиниране на оператор за присвояване
        String& operator=(const String&);
        String& operator=(const char*);

        // деструктор
        ~String();

        // връща дължината на стринга
        int getLength() const
        {
            return length;
        }

//        const char* convertToChars() const
//        {
//            return stringValue;
//        }

        // предефиниране на унарен оператор !
        bool operator!() const
        {
            // проверява дали текущия обект не е празен низ
            return length == 0;
        }

        // предефиниране на операциите за индексиране []
        // можем да променяме стойността на посочения елемент
        char& operator [](int);
        // връщаме const псевдоним, т.е. елемента не може да се променя
        const char& operator [] (int) const;

        // предефиниране на операциите + и +=
        const String operator + (const String&) const;
        String& operator += (const String&);

        // предефиниране на операцията (), за да реализираме
        // връщане на подниз от опреденена позиция с определен брой символи
        String operator ()(int position, int len) const;

        // предефиниране на операцията за преобразуване на стринг до масив от символи
        operator const char*() const;

        // сравнения между два стринга
        // предефиниране на операциите <, >, ==, != като член-функции на класа
        bool operator < (const String&) const;
        bool operator > (const String&) const;
        bool operator == (const String&) const;
        bool operator != (const String&) const;

        // извеждане на стринга
        // предефиниране на оператора <<, използване на приятелска функция
        friend ostream& operator << (ostream&, const String&);

        // прочитане на стринга от стандартния вход,
        // резултатът се записва във втория параметър
        friend istream& operator >> (istream&, String&);

        // статична член-функция, която връща броя на създадените обекти
        static int getCountStrings();

    private:
        char* stringValue;
        int length;

        // константна член-данна, която се инициализира
        // при декларирането й, характеристика на класа
        // максимален брой символи, които четем със cin
        static const int CIN_LIMIT = 80;

        // статична член-данна, която описва броя на създадените
        // обекти от класа, увеличава се в конструкторите,
        // намалява се в деструкторите
        static int countStrings;

        // помощна функция, която се грижи за заделянето на памет
        void setData(const char*);
};

#endif // CSTRING_H
