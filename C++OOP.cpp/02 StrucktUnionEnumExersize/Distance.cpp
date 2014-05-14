#include <iostream>
#include <iomanip>

using namespace std;

/*
    �� �� �������� ���������, ����� ������ �������, ���� �������� ����������� ����� ������� ��� � ���.
    �� �� ��������� �������, ����� �������� � �������� ���������.
    �� �� �������� �������, ����� ������ ��� �������.

    �� �� ������� ���������, ����� ������ ��������� �� ����������� ���� (������ � �������).
    �� �� ��������� �������, ����� �������� � �������� ��������� �� ����.
    �� �� ������ ��������, ����� �������� ������ �� ������ ���� (������� ������� � ��.���).
*/

const unsigned INCHES_IN_FOOT = 12;

// ���������, ����� ������ �������
struct Distance
{
    unsigned feet;
    float inches;
};

// �������, ����� ������� ���������
void readDistance(Distance& dist)
{
    cout << "Feet: "; cin >> dist.feet;

    // inches ������ �� ���� ������ ����� � ��� (0, 12)
    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "Inches (0, 12): ";
        cin >> dist.inches;
        // �� �� ��������� �� �������� ��������� �� double...

        isCorrect = (dist.inches > 0 && dist.inches < 12);
    }
}

// �������, ����� ������� ���������
void printDistance(const Distance& dist)
{
    cout << "Feet: " << dist.feet << ", Inches: " << dist.inches << endl;
}

// �������,����� ������ ��� �������,
// ���������� �� ��������� � ���������
Distance sum(const Distance& lhs, const Distance& rhs)
{
    Distance sumDist;

    float sumInches = lhs.inches + rhs.inches;
    sumDist.feet = lhs.feet + rhs.feet;

    if(sumInches >= INCHES_IN_FOOT)
    {
        sumInches = sumInches - INCHES_IN_FOOT;
        sumDist.feet ++;
    }

    sumDist.inches = sumInches;

    // ��� �� ������� ���������� ������� �����������,
    // ����� ������ ������� �� ������������ ���������� ��������
    return sumDist;
}

// ���������, ����� ������ ����
struct Room
{
    Distance length;
    Distance width;
};

// �������, ����� ������� ��������� � �������� �� ����
void readRoom(Room& room)
{
    cout << "Room\n";
    cout << "\tLength: \n";
    readDistance(room.length);

    cout << "\tWidth: \n";
    readDistance(room.width);
}

// �������, ����� ������� ��������� �� ����
void printRoom(const Room& room)
{
    cout << "Room\n";

    cout << "\tLength: \n\t\t";
    printDistance(room.length);

    cout << "\tWidth: \n\t\t";
    printDistance(room.width);
}

// �������, ����� ��������� ������ �� ����
// ������� ������� � ��. ���
float area(const Room& room)
{
    // �������� ������ �� ����� ������������� ��� ������
    float lengthInFeet = room.length.feet + room.length.inches / INCHES_IN_FOOT;
    float widthInFeet = room.width.feet + room.width.inches / INCHES_IN_FOOT;

    return lengthInFeet * widthInFeet;
}

void useRoomDistance()
{
    Room livingRoom;

    // ��������� �� ���������
    readRoom(livingRoom);

    // ��������� �� ���������
    printRoom(livingRoom);

    // ��������� �� ������ �� ������
    float roomArea = area(livingRoom);

    // ����������� �� ������, ��� ����� ���� ����������� �����
    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
    cout << "The room area is: " << roomArea << " sq. ft.\n";

    // �������� �� �������
    Distance lhs;
    readDistance(lhs);

    Distance rhs;
    readDistance(rhs);

    Distance sumDist = sum(lhs, rhs);
    cout << "The sum of the two distances is:\n\t";
    printDistance(sumDist);
}

int main()
{
    // ������ 3: ������� ���������. �������. ����.
    useRoomDistance();

    return 0;
}
