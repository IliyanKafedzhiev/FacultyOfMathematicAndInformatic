#include <iostream>
#include <iomanip>

using namespace std;

/*
    Да се дефинира структура, която описва дължина, като използва английските мерни единици фут и инч.
    Да се дефинират функции, които въвеждат и извеждат дължината.
    Да се дефинира функция, която събира две дължини.

    Да се създаде структура, която описва размерите на правоъгълна стая (ширина и дължина).
    Да се дефинират функции, които въвеждат и извеждат размерите на стая.
    Да се напише програма, която пресмята площта на дадена стая (мерната единица е кв.фут).
*/

const unsigned INCHES_IN_FOOT = 12;

// структура, която описва дължина
struct Distance
{
    unsigned feet;
    float inches;
};

// функция, която въвежда дължината
void readDistance(Distance& dist)
{
    cout << "Feet: "; cin >> dist.feet;

    // inches трябва да бъде реално число в инт (0, 12)
    bool isCorrect = false;
    while(!isCorrect)
    {
        cout << "Inches (0, 12): ";
        cin >> dist.inches;
        // не се проверява за коректно въвеждане на double...

        isCorrect = (dist.inches > 0 && dist.inches < 12);
    }
}

// функция, която извежда дължината
void printDistance(const Distance& dist)
{
    cout << "Feet: " << dist.feet << ", Inches: " << dist.inches << endl;
}

// функция,която събира две дължини,
// резултатът от функцията е структура
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

    // тук се включва системният копиращ конструктур,
    // който копира данните на структурната променлива побитово
    return sumDist;
}

// структура, която описва стая
struct Room
{
    Distance length;
    Distance width;
};

// функция, която въвежда дължината и ширината на стая
void readRoom(Room& room)
{
    cout << "Room\n";
    cout << "\tLength: \n";
    readDistance(room.length);

    cout << "\tWidth: \n";
    readDistance(room.width);
}

// функция, която извежда размерите на стая
void printRoom(const Room& room)
{
    cout << "Room\n";

    cout << "\tLength: \n\t\t";
    printDistance(room.length);

    cout << "\tWidth: \n\t\t";
    printDistance(room.width);
}

// функция, която изчислява площта на стая
// мерната единица е кв. фут
float area(const Room& room)
{
    // инчовете трябва да бъдат преобразувани във футове
    float lengthInFeet = room.length.feet + room.length.inches / INCHES_IN_FOOT;
    float widthInFeet = room.width.feet + room.width.inches / INCHES_IN_FOOT;

    return lengthInFeet * widthInFeet;
}

void useRoomDistance()
{
    Room livingRoom;

    // прочитане на размерите
    readRoom(livingRoom);

    // извеждане на размерите
    printRoom(livingRoom);

    // извеждане на площта на стаята
    float roomArea = area(livingRoom);

    // форматиране на изхода, две цифри след десетичната точка
    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
    cout << "The room area is: " << roomArea << " sq. ft.\n";

    // събиране на дължини
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
    // Задача 3: Вложени структури. Размери. Стая.
    useRoomDistance();

    return 0;
}
