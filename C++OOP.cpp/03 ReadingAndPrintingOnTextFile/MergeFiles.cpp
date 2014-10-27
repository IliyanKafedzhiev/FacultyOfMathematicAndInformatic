#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

/*
    ������ 5:
    ������ �� ��� ����� Orders.txt � OrderDetails.txt.
    ������ Orders, ������� �������� ����������:
    ��_������� ���� ��������

    �������� �� ������ � ��-��-����.

    ������ OrderDetails ������� �������� ����������:
    ��_������� ������� ���������� ��.����

    �� �� ������ ��������, ����� ����� ������������ �� ����� �����,
    � ��� ���� ��� ������� ������:
    ��_������� ���� �������� ������������

    ������� � ����� ����� �� ��������� ��� �������� ��� �� ��_�������.
    ������� �� ����� �������� ����� �� ������� �� ��������� ���.
*/

const unsigned MAX_LINE_LENGTH = 1024;

// ���������, ����� ������ �������
struct Order
{
    int ID;
    char orderDate[11];
    char employee[20];
    double totalPrice;

    // ����-�������, ����� �� ������� ����-�������
    // �� ����������� �� ����������� ���� ��� �� ����
    bool read(istream&);
    ostream& print(ostream&);
};

// ��������� �� ����-���������
bool Order::read(istream& inputStream)
{
    // ������ ��, �� ������� ��������� � ������� ������:
    // �� ���� ��������
    // ������ �������� �� ��������� �� ���� ����������� ��-�����
    totalPrice = 0;

    if(inputStream >> ID >> orderDate >> employee)
        return true;

    // ����������� � ���������
    return false;
}

// �������, ����� �� ������� �� ����������� �����
// ��� �� ������� ��� ���� ������������ �� �����������
ostream& Order::print(ostream& outputStream)
{
    // ID ���������� ������, ������� �� ������ 7
    // ����, ���������� ������, ������� �� ������ 14
    // ��������, ���������� ������, ������� �� ������ 24
    // ���� ��������, ���������� �������, � ��� ������� ���� ���. �����
    outputStream << setiosflags(ios::left) << setw(7) << ID
                 << setw(14) << orderDate << setw(24) << employee
                 << setiosflags(ios::fixed|ios::showpoint) << setprecision(2)
                 << resetiosflags(ios::left)<< setw(12) << totalPrice << endl;

    return outputStream;
}

// ���������, ����� ������ ��������� � ���� �������
struct OrderDetails
{
    int orderID;
    char product[24];
    double quantity;
    double unitPrice;

    // ����-�������, ����� ������� �� ���� ��� ��
    // ����������� ���� ������� �� �����������
    bool read(istream&);
    ostream& print(ostream&);
};

// ��������� �� ����-���������
bool OrderDetails::read(istream& inputStream)
{
    // �������� ������� � ������� ������
    // ��_������� ������� ���������� ��.����

    if(inputStream >> orderID >> product >> quantity >> unitPrice)
        return true;

    // ����������� � ���������
    return false;
}

// �������, ����� �� ������� �� ����������� �����
// ��� �� ������� ��� ���� ������������ �� �����������
ostream& OrderDetails::print(ostream& outputStream)
{
    // ID ���������� ������, ������� �� ������ 7
    // ����, ���������� ������, ������� �� ������ 14
    // ��������, ���������� ������, ������� �� ������ 24
    // ���� ��������, ���������� �������, � ��� ������� ���� ���. �����
    outputStream << setiosflags(ios::left) << setw(7) << orderID
                 << setw(24) << product << setiosflags(ios::fixed|ios::showpoint)
                 << setprecision(2) << setw(7) << resetiosflags(ios::left) << quantity
                 << setprecision(2) << setw(10) << unitPrice << endl;

    return outputStream;
}

void mergeFiles(ifstream& ordersFile, ifstream& orderDetailsFile, ofstream& sumOrdersFile)
{
     // ��������� ������� ����� �� ����� Orders � OrderDetails
    Order order;
    if(!order.read(ordersFile))
    {
        cout << "��������� ��������� �� �������!\n";
        return;
    }

    OrderDetails orderDetails;
    if(!orderDetails.read(orderDetailsFile))
    {
        cout << "��������� ��������� �� ��������� �� �������!\n";
        return;
    }

     while(ordersFile.good() && orderDetailsFile.good())
    {
        // ���� �� ��������� �� ��������� fail() ��� bad()
        // �.�. ��� �������� ���� �� ����� � �� ����� �� ���� ���� ����
        // ��� �������� ����� ������ ������� �� ������

        if(order.ID == orderDetails.orderID)
        {
            order.totalPrice += orderDetails.unitPrice*orderDetails.quantity;

            // ��������� ����� �� ����� OrderDetails
            orderDetails.read(orderDetailsFile);

            //orderDetails.print(cout);
        }
        else if(order.ID < orderDetails.orderID)
        {
            // ��������� ����������� �� ������� � ����������� ����
            order.print(sumOrdersFile);
            //cout << "-----------------------" << endl;
            //order.print(cout);

            // ��������� ����� �� ����� Order
            order.read(ordersFile);
        }
        else
        {
            // order.ID > orderDetails.orderID
            // ��������� ����� �� ����� OrderDetails
            orderDetails.read(orderDetailsFile);
        }
    }

    // cout << "-- LAST ORDERS --" << endl;
    // ��� ��� ������������ �������
    while(ordersFile)
    {
        // ������� � ������ � ��������� �� ���������
        // ������ �� �� ��������� ���������� �������
        order.print(sumOrdersFile);
        // order.print(cout);
        order.read(ordersFile);
    }

    // ��� ��� ������������ ������� �� ������� �� ���� ����,
    // �� �� �� �������� � ����� �������
}

int main(int argc, char* argv[])
{
    // ������ ������ �����, �� ���� ������� � ���� �� ������
    ifstream ordersFile(argv[1], ios::in);
    if(!ordersFile)
    {
        cout << "������ " << argv[1] << " �� ���� �� ���� �������!\n";
        return 1;
    }

    ifstream orderDetailsFile(argv[2], ios::in);
    if(!orderDetailsFile)
    {
        cout << "������ " << argv[2] << " �� ���� �� ���� �������!\n";
        return 1;
    }

    // ������� ������ �����, �� ���� ������� � ���� �� �����
    ofstream sumOrdersFile("SumOrders.txt", ios::out);
    if(!orderDetailsFile)
    {
        cout << "������ " << "SumOrders.txt" << " �� ���� �� ���� �������!\n";
        return 1;
    }

    mergeFiles(ordersFile, orderDetailsFile, sumOrdersFile);

    // ��������� �� ���������
    ordersFile.close();
    orderDetailsFile.close();
    sumOrdersFile.close();

    return 0;
}
