#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/*
    Да се дефинира функция, която намира разстоянието между
    две точки в равнината. Като се използва тази функция, да се
    напише програма, която въвежда координатите на n точки в равнината
    (2 <= n <= 100), намира и извежда най-голямото разстояние между тях.

    Да се дефинира подходяща структура, която представя точка в равнината
    с декартови координати.
*/

// максималният брой точки, които може да има масива
const unsigned MAX_COUNT = 100;

// декларация на структура Point, представяща
// точка в равнината с декартови координати
struct Point
{
    double x, y;
};

// прочитане на координатите на точка
void createPoint(Point& point)
{
    cout << "Моля, въведете абсциса: ";
    cin >> point.x;

    cout << "Моля, въведете ордината: ";
    cin >> point.y;
}

// извеждане на координатите на точка в равнината
void printPoint(const Point& point)
{
    cout << "(" << point.x << ", " << point.y << ")\n";
}

// намиране на разстоянието между две точки
double segmentDistance(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

// въвеждане на масив от точки
void readPoints(unsigned n, Point* points)
{
    for(unsigned i = 0; i <= n - 1; i++)
    {
        createPoint(points[i]);
    }
}

// извеждане на масив от точки
void printPoints(unsigned n, const Point* points)
{
    for(unsigned i = 0; i <= n - 1; i++)
    {
        printPoint(points[i]);
    }
}

// намиране на най-голямото разстояние между точките
double maxDistance(unsigned n, const Point* points)
{
    double maxDistance = 0;
    double currentDistance = 0;

    for(unsigned i = 0; i <= n - 2; i++)
    {
        for(unsigned j = i + 1; j <= n - 1; j++)
        {
            currentDistance = segmentDistance(points[i], points[j]);
            if(currentDistance > maxDistance)
            {
                maxDistance = currentDistance;
            }
        }
    }

    return maxDistance;
}

void usePoints()
{
    // въвеждане на множеството от точки
    // брой точки
    unsigned countPoints;

    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "Моля, въведете броя на точките в интервала (2, " << MAX_COUNT << ")\n";
        cin >> countPoints;

        if(countPoints >= 2 && countPoints <= MAX_COUNT)
        {
            isCorrect = true;
        }
    }

    // деклариране на множеството от точки
    Point points[MAX_COUNT];

    // въвеждане на точките в масива
    readPoints(countPoints, points);

    // извеждане на точките от масива
    printPoints(countPoints, points);

    // намиране на на-голямото разстояние между точките
    double maxDist = maxDistance(countPoints, points);

    // разстоянието да се изведе с две цифри след десетичната запетая
    cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);
    cout << "Най-голямото разстояние между точки от множеството е " << maxDist;
}

int main()
{
    // Задача 2: Точки, разстояние между две точки
    usePoints();

    return 0;
}

