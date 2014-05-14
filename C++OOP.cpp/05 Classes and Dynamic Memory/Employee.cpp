#include "Employee.h"

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

// �������������� �� ���������� ����-�����
// ����� ������ (������������) �� �����
unsigned Employee::countEmployees = 0;

// �����������
// ����-������� employmentDate � ����� �� ����� Date,
// �� �� �������� ������� �������� �������������, ���������� ��������������� ������
Employee::Employee(const char* lastName, const Date& hireDate, const char* department, double payment)
            : employmentDate(hireDate)
{
    // �������� �� ��������� ����� �� ���� �� ����-�������
    // � ���������������� ��
    setDynamicData(lastName, department);

    // ���������� ��������, �� �� ��� �������� �� ����������
    setPayment(payment);

    // ������������� ���������� �� ���������� ����-�����
    countEmployees++;
}

// ����������� �� ��������
// ����-������� ����� �� ������������ � ������������� ������
Employee::Employee(const Employee& otherEmployee):employmentDate(otherEmployee.employmentDate)
{
    setDynamicData(otherEmployee.lastName, otherEmployee.department);

    // ������� �� ��������, ��������� �� �� ���� ����������� �����
    this->payment = otherEmployee.payment;

    // ������������� ���������� �� ���������� ����-�����
    countEmployees++;
}

// ������������� �� ���������� �� �����������
Employee& Employee::operator=(const Employee& otherEmployee)
{
    // ��� ������� ���� � ��������, �������� � ����� �� �������� ����-�����
    // this e �������� ��� ������� �����
    if(&otherEmployee != this)
    {
        // ��� �������� ����� (������ ������ �� ��������� =) � �������� ��
        // otherAccount (������ � ������� ������ �� ���������), �.�.
        // �� �� ��������� �� ��������� �������������� (� = �)

        // ������������� ������� ��������� �����
        clearDymanicData();

        // �������� ���� ��������� ����� � � ��������������
        setDynamicData(otherEmployee.lastName, otherEmployee.department);

        // �������� �� ����������� �� Date
        employmentDate = otherEmployee.employmentDate;

        payment = otherEmployee.payment;
    }

    return *this;
}

// ����������
Employee::~Employee()
{
    cout << "~Employee " << lastName << endl;
    // ������������� �� ����������� �����
    clearDymanicData();

    // ���������� ���������� �� ���������� ����-�����
    countEmployees--;
    // ������� �� � ������������ �� ����� Date...
}

// ���������
// ����������� �� �������� ����������� �� ����-�������
// �� ������� �����, ��������� �� �� ����������
const char* Employee::getLastName() const
{
    return lastName;
}

// ������� ������ �� ��������, ������� �� ����������� ��
// ��������, ����� �� ������� ������, ����� �� ����� ���� ��������
Date Employee::getEmploymentDate() const
{
    return employmentDate;
}

// ������� �������� ��� ����-������� department, ��
// ���������� �� ���� �� �� �������� �� ������� ��
// ���������� �� ����-�������
const char* Employee::getDepartment() const
{
    return department;
}

double Employee::getPayment() const
{
    return payment;
}

// ��������
void Employee::setEmploymentDate(const Date& newEmploymentDate)
{
    // ������� �� ���������� �� �����������
    employmentDate = newEmploymentDate;
}

void Employee::setPayment(double newPayment)
{
    payment = (newPayment > 0)? newPayment : 0;
}

// ��������� �� ������������ �� ��������
void Employee::print() const
{
    cout << "Employee: " << lastName << endl;
    cout << "Department: " << department << endl;
    cout << "Hire Date: "; employmentDate.print();
    cout << "Payment: " << setiosflags(ios::fixed|ios::showpoint)
         << setprecision(2) << payment << endl;
}

void Employee::setDynamicData(const char* lastName, const char* department)
{
     // �������� ������� �����, ������� � ��������� �� ������� ���������
    // + 1, �� �� ����� �� ������� ������� �� ���� �� ��� '\0'
    this->lastName = new char[strlen(lastName) + 1];
    // �������� ������������
    strcpy(this->lastName, lastName);

    this->department = new char[strlen(department) + 1];
    strcpy(this->department, department);
}

void Employee::clearDymanicData()
{
    // ��� ��� ���������� �� ����� �� ��������� [],
    // �� � ��� ��������������� �� ������� ������ �� ���������� []
    delete [] lastName;
    delete [] department;
}

// �������� ����-�������, ����� �� ����� ���������� �� countEmployees
unsigned Employee::getCountEmployees()
{
    // ���������� ������ �� �� �������� �� ����������,
    // �������������� � �������� � ��������� this, �
    // ���������� ������ ����� �� �� �� �������� � ��������� �����,
    // � � ����� �� �����::
    return countEmployees;
}
