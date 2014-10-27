#include <iostream>
#include <math.h>

using namespace std;

// Дефиниране и използване на структури
/*
    Задача 1
    Да се дефинира структура, която задача триъгълник чрез трите му страни.
    Да се напишат функции за създаване, извеждане, намиране на периметъра
    и лицето на триъгълник.
*/

// константа за края на реда
const int MAX_LINE_LENGTH = 100;

struct Triangle
{
    double a, b, c;
};

// прочинтане на положително реално число
double readPositiveDouble()
{
    double d;
    bool isCorrect = false;

    int countTries = 1;

    while(!isCorrect)
    {
        cout << "Моля, въведете реално положително число:\n";
        // за да се проследи коректността на функцията...
        cout << "Опит N " << countTries << "\n";
        countTries ++;

        cin >> d;

        if(!cin.good())
        {
            // вдигнат флаг за грешка, да се изчисти
            cin.clear();
            // за да се изчисти буфера
            cin.ignore(MAX_LINE_LENGTH, '\n');
        }

        isCorrect = (d > 0);

    }

    cout << "Прочетенето число е " << d << "\n";
    return d;
}

// Инициализиране на триъгълник
// Какви са изискванията за страните на триъгълника?
// (a > 0) && (b > 0) && (c > 0) &&(a + b > c) && (a + c > b) && (b + c > a)
void createTriangle(Triangle& newTriangle)
{
    bool correctInput = false;

    double a, b, c;

    while(!correctInput)
    {
        cout << "Моля, въведете страните на триъгълника...\n";

        a = readPositiveDouble();
        b = readPositiveDouble();
        c = readPositiveDouble();

        correctInput = (a + b > c) && (a + c > b) && (b + c > a);
    }

    newTriangle.a = a;
    newTriangle.b = b;
    newTriangle.c = c;
}

// Извеждане на триъгълник
void printTriangle(const Triangle* const tr)
{
    cout << "Триъгълник със страни (" << tr->a << ", " << tr->b << ", " << tr->c << ")\n";
}

// Намиране на периметъра на триъгълник
double perimeter(const Triangle& tr)
{
    return tr.a + tr.b + tr.c;
}

// Намиране на лице на триъгълник
// sqrt(p*(p - a)*(p - b)*(p - c))
double surface(const Triangle& tr)
{
    double p = perimeter(tr)/2;

    return sqrt(p*(p - tr.a)*(p - tr.b)*(p - tr.c));
}

int main()
{
    // равностранен триъгълник
    Triangle ABC;

    createTriangle(ABC);

    printTriangle(&ABC);

    cout << "Периметърът на този тригълник е " << perimeter(ABC) << "\n";
    cout << "Лицето на този тригълник е " << surface(ABC) << "\n";

    return 0;
}
