#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

/*
    Задача 5:
    Дадени са два файла Orders.txt и OrderDetails.txt.
    Файлът Orders, съдържа следната информация:
    ИД_Поръчка Дата Служител

    Форматът на датата е дд-мм-гггг.

    Файлът OrderDetails съдържа следната информация:
    ИД_Поръчка Продукт Количество Ед.Цена

    Да се напише програма, която слива информацията от двата файла,
    в нов файл със следния формат:
    ИД_Поръчка Дата Служител ОбщаСтойност

    Данните в двата файла са сортирани във възходящ ред по ИД_Поръчка.
    Имената на двата изходящи файла се подават от командния ред.
*/

const unsigned MAX_LINE_LENGTH = 1024;

// структура, която описва поръчка
struct Order
{
    int ID;
    char orderDate[11];
    char employee[20];
    double totalPrice;

    // член-функция, която да прочита член-данните
    // на структурата от стандартния вход или от файл
    bool read(istream&);
    ostream& print(ostream&);
};

// дефиниция на член-функцията
bool Order::read(istream& inputStream)
{
    // очаква се, че данните пристигат в следния формат:
    // ИД Дата Служител
    // Общата стойност на поръчката ще бъде пресметната по-късно
    totalPrice = 0;

    if(inputStream >> ID >> orderDate >> employee)
        return true;

    // прочитането е неуспешно
    return false;
}

// функция, която да извежда на стандартния изход
// или да записва във файл съдържанието на структурата
ostream& Order::print(ostream& outputStream)
{
    // ID подравнено отляво, дължина на полето 7
    // Дата, подравнена отляво, дължина на полето 14
    // Служител, подравнено отляво, дължина на полето 24
    // Обща стойност, подравнена отдясно, с две позиции след дес. точка
    outputStream << setiosflags(ios::left) << setw(7) << ID
                 << setw(14) << orderDate << setw(24) << employee
                 << setiosflags(ios::fixed|ios::showpoint) << setprecision(2)
                 << resetiosflags(ios::left)<< setw(12) << totalPrice << endl;

    return outputStream;
}

// структура, която описва детайлите в една поръчка
struct OrderDetails
{
    int orderID;
    char product[24];
    double quantity;
    double unitPrice;

    // член-функция, която прочита от файл или от
    // стандартния вход данните на структурата
    bool read(istream&);
    ostream& print(ostream&);
};

// дефиниция на член-функцията
bool OrderDetails::read(istream& inputStream)
{
    // очакваме данните в следния формат
    // ИД_Поръчка Продукт Количество Ед.Цена

    if(inputStream >> orderID >> product >> quantity >> unitPrice)
        return true;

    // прочитането е неуспешно
    return false;
}

// функция, която да извежда на стандартния изход
// или да записва във файл съдържанието на структурата
ostream& OrderDetails::print(ostream& outputStream)
{
    // ID подравнено отляво, дължина на полето 7
    // Дата, подравнена отляво, дължина на полето 14
    // Служител, подравнено отляво, дължина на полето 24
    // Обща стойност, подравнена отдясно, с две позиции след дес. точка
    outputStream << setiosflags(ios::left) << setw(7) << orderID
                 << setw(24) << product << setiosflags(ios::fixed|ios::showpoint)
                 << setprecision(2) << setw(7) << resetiosflags(ios::left) << quantity
                 << setprecision(2) << setw(10) << unitPrice << endl;

    return outputStream;
}

void mergeFiles(ifstream& ordersFile, ifstream& orderDetailsFile, ofstream& sumOrdersFile)
{
     // прочитаме първият запис от файла Orders и OrderDetails
    Order order;
    if(!order.read(ordersFile))
    {
        cout << "Неуспешно прочитане на поръчка!\n";
        return;
    }

    OrderDetails orderDetails;
    if(!orderDetails.read(orderDetailsFile))
    {
        cout << "Неуспешно прочитане на детайлите на поръчка!\n";
        return;
    }

     while(ordersFile.good() && orderDetailsFile.good())
    {
        // чете до достигане до състояние fail() или bad()
        // т.е. ако достигне края на файла и се опита да чете след него
        // или възникне друга грешка повреме на четене

        if(order.ID == orderDetails.orderID)
        {
            order.totalPrice += orderDetails.unitPrice*orderDetails.quantity;

            // прочитаме запис от файла OrderDetails
            orderDetails.read(orderDetailsFile);

            //orderDetails.print(cout);
        }
        else if(order.ID < orderDetails.orderID)
        {
            // записваме натрупаното до момента в резултатния файл
            order.print(sumOrdersFile);
            //cout << "-----------------------" << endl;
            //order.print(cout);

            // прочитаме запис от файла Order
            order.read(ordersFile);
        }
        else
        {
            // order.ID > orderDetails.orderID
            // прочитаме запис от файла OrderDetails
            orderDetails.read(orderDetailsFile);
        }
    }

    // cout << "-- LAST ORDERS --" << endl;
    // ако има необработени поръчки
    while(ordersFile)
    {
        // свършил е файлът с детайлите на поръчките
        // трябва да се обработят останалите поръчки
        order.print(sumOrdersFile);
        // order.print(cout);
        order.read(ordersFile);
    }

    // ако има необработени детайли на поръчки на това ниво,
    // те не са свързани с никоя поръчка
}

int main(int argc, char* argv[])
{
    // входен файлов поток, ще бъде свързан с файл за четене
    ifstream ordersFile(argv[1], ios::in);
    if(!ordersFile)
    {
        cout << "Файлът " << argv[1] << " не може да бъде отворен!\n";
        return 1;
    }

    ifstream orderDetailsFile(argv[2], ios::in);
    if(!orderDetailsFile)
    {
        cout << "Файлът " << argv[2] << " не може да бъде отворен!\n";
        return 1;
    }

    // изходен файлов поток, ще бъде свързан с файл за запис
    ofstream sumOrdersFile("SumOrders.txt", ios::out);
    if(!orderDetailsFile)
    {
        cout << "Файлът " << "SumOrders.txt" << " не може да бъде отворен!\n";
        return 1;
    }

    mergeFiles(ordersFile, orderDetailsFile, sumOrdersFile);

    // затваряне на файловете
    ordersFile.close();
    orderDetailsFile.close();
    sumOrdersFile.close();

    return 0;
}
