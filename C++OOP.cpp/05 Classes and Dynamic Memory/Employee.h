#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee
{
    public:
        // конструктор
        Employee(const char*, const Date&, const char*, double);
        // конструктор за копиране
        Employee(const Employee&);
        // предефиниране на операцията за присвояване
        Employee& operator=(const Employee&);
        // деструктор
        ~Employee();

        // селектори
        // селекторите не променят стойностите на член-данните
        // на текущия обект, обявяваме ги за константни
        const char* getLastName() const;
        // връщаме датата по стойност, включва се конструктор за
        // копиране, който да създаде обекта, който се връща като резултат
        Date getEmploymentDate() const;
        // връщаме указател към член-данната department, но
        // указателят не може да се използва за промяна на
        // стойността на член-данната
        const char* getDepartment() const;
        double getPayment() const;

        // мутатори
        void setEmploymentDate(const Date&);
        void setPayment(double);

        // извеждане на информацията за служител
        void print() const;

        // статична член-функция, която да връща стойността на countEmployees
        static unsigned getCountEmployees();

    private:
        // име на служителя
        char* lastName;
        // дата на постъпване на работа
        Date employmentDate;
        // отдел, в който е назначен
        char* department;
        // заплата
        double payment;

        // статична член-данна за броя на създадените обекти
        static unsigned countEmployees;

        // помощни функции, които да заделят памет и да я освобождават
        void clearDymanicData();
        void setDynamicData(const char*, const char*);
};

#endif // EMPLOYEE_H
