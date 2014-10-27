#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee
{
    public:
        // �����������
        Employee(const char*, const Date&, const char*, double);
        // ����������� �� ��������
        Employee(const Employee&);
        // ������������� �� ���������� �� �����������
        Employee& operator=(const Employee&);
        // ����������
        ~Employee();

        // ���������
        // ����������� �� �������� ����������� �� ����-�������
        // �� ������� �����, ��������� �� �� ����������
        const char* getLastName() const;
        // ������� ������ �� ��������, ������� �� ����������� ��
        // ��������, ����� �� ������� ������, ����� �� ����� ���� ��������
        Date getEmploymentDate() const;
        // ������� �������� ��� ����-������� department, ��
        // ���������� �� ���� �� �� �������� �� ������� ��
        // ���������� �� ����-�������
        const char* getDepartment() const;
        double getPayment() const;

        // ��������
        void setEmploymentDate(const Date&);
        void setPayment(double);

        // ��������� �� ������������ �� ��������
        void print() const;

        // �������� ����-�������, ����� �� ����� ���������� �� countEmployees
        static unsigned getCountEmployees();

    private:
        // ��� �� ���������
        char* lastName;
        // ���� �� ���������� �� ������
        Date employmentDate;
        // �����, � ����� � ��������
        char* department;
        // �������
        double payment;

        // �������� ����-����� �� ���� �� ����������� ������
        static unsigned countEmployees;

        // ������� �������, ����� �� ������� ����� � �� � ������������
        void clearDymanicData();
        void setDynamicData(const char*, const char*);
};

#endif // EMPLOYEE_H
