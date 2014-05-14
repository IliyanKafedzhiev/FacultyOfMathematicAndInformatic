#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/*
    �� �� �������� �������, ����� ������ ������������ �����
    ��� ����� � ���������. ���� �� �������� ���� �������, �� ��
    ������ ��������, ����� ������� ������������ �� n ����� � ���������
    (2 <= n <= 100), ������ � ������� ���-�������� ���������� ����� ���.

    �� �� �������� ��������� ���������, ����� ��������� ����� � ���������
    � ��������� ����������.
*/

// ������������ ���� �����, ����� ���� �� ��� ������
const unsigned MAX_COUNT = 100;

// ���������� �� ��������� Point, �����������
// ����� � ��������� � ��������� ����������
struct Point
{
    double x, y;
};

// ��������� �� ������������ �� �����
void createPoint(Point& point)
{
    cout << "����, �������� �������: ";
    cin >> point.x;

    cout << "����, �������� ��������: ";
    cin >> point.y;
}

// ��������� �� ������������ �� ����� � ���������
void printPoint(const Point& point)
{
    cout << "(" << point.x << ", " << point.y << ")\n";
}

// �������� �� ������������ ����� ��� �����
double segmentDistance(const Point& p1, const Point& p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

// ��������� �� ����� �� �����
void readPoints(unsigned n, Point* points)
{
    for(unsigned i = 0; i <= n - 1; i++)
    {
        createPoint(points[i]);
    }
}

// ��������� �� ����� �� �����
void printPoints(unsigned n, const Point* points)
{
    for(unsigned i = 0; i <= n - 1; i++)
    {
        printPoint(points[i]);
    }
}

// �������� �� ���-�������� ���������� ����� �������
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
    // ��������� �� ����������� �� �����
    // ���� �����
    unsigned countPoints;

    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "����, �������� ���� �� ������� � ��������� (2, " << MAX_COUNT << ")\n";
        cin >> countPoints;

        if(countPoints >= 2 && countPoints <= MAX_COUNT)
        {
            isCorrect = true;
        }
    }

    // ����������� �� ����������� �� �����
    Point points[MAX_COUNT];

    // ��������� �� ������� � ������
    readPoints(countPoints, points);

    // ��������� �� ������� �� ������
    printPoints(countPoints, points);

    // �������� �� ��-�������� ���������� ����� �������
    double maxDist = maxDistance(countPoints, points);

    // ������������ �� �� ������ � ��� ����� ���� ����������� �������
    cout << setiosflags(ios::fixed|ios::showpoint) << setprecision(2);
    cout << "���-�������� ���������� ����� ����� �� ����������� � " << maxDist;
}

int main()
{
    // ������ 2: �����, ���������� ����� ��� �����
    usePoints();

    return 0;
}

