#include "Employee.h"

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

// инициализиране на статичната член-данна
// извън тялото (декларацията) на класа
unsigned Employee::countEmployees = 0;

// конструктор
// член-данната employmentDate е обект от класа Date,
// за да избегнем нейната повторна инициализация, използваме инициализиращия списък
Employee::Employee(const char* lastName, const Date& hireDate, const char* department, double payment)
            : employmentDate(hireDate)
{
    // заделяне на динамична памет за част от член-данните
    // и инициализирането им
    setDynamicData(lastName, department);

    // използваме мутатора, за да има проверка за коректност
    setPayment(payment);

    // увелиличаваме стойността на статичната член-данна
    countEmployees++;
}

// конструктор за копиране
// член-данната обект се инициализира в инициализиращ списък
Employee::Employee(const Employee& otherEmployee):employmentDate(otherEmployee.employmentDate)
{
    setDynamicData(otherEmployee.lastName, otherEmployee.department);

    // данните са коректни, извличаме ги от вече съществуващ обект
    this->payment = otherEmployee.payment;

    // увелиличаваме стойността на статичната член-данна
    countEmployees++;
}

// предефиниране на операцията за присвояване
Employee& Employee::operator=(const Employee& otherEmployee)
{
    // тук обектът вече е създаден, заделена е памет за неговите член-данни
    // this e указател към текущия обект
    if(&otherEmployee != this)
    {
        // ако текущият обект (лявата страна на оператора =) е различен от
        // otherAccount (обекта в дясната страна на оператора), т.е.
        // не се опитаваме да напраавим самоприсояване (а = а)

        // освобождаваме заетата динамична памет
        clearDymanicData();

        // заделяме нова динамична памет и я инициализираме
        setDynamicData(otherEmployee.lastName, otherEmployee.department);

        // операция за присвояване на Date
        employmentDate = otherEmployee.employmentDate;

        payment = otherEmployee.payment;
    }

    return *this;
}

// деструктор
Employee::~Employee()
{
    cout << "~Employee " << lastName << endl;
    // освобождаване на динамичната памет
    clearDymanicData();

    // намаляваме стойността на статичната член-данна
    countEmployees--;
    // извиква се и деструкторът на класа Date...
}

// селектори
// селекторите не променят стойностите на член-данните
// на текущия обект, обявяваме ги за константни
const char* Employee::getLastName() const
{
    return lastName;
}

// връщаме датата по стойност, включва се конструктор за
// копиране, който да създаде обекта, който се връща като резултат
Date Employee::getEmploymentDate() const
{
    return employmentDate;
}

// връщаме указател към член-данната department, но
// указателят не може да се използва за промяна на
// стойността на член-данната
const char* Employee::getDepartment() const
{
    return department;
}

double Employee::getPayment() const
{
    return payment;
}

// мутатори
void Employee::setEmploymentDate(const Date& newEmploymentDate)
{
    // включва се операцията за присвояване
    employmentDate = newEmploymentDate;
}

void Employee::setPayment(double newPayment)
{
    payment = (newPayment > 0)? newPayment : 0;
}

// извеждане на информацията за служител
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
     // заделяме толкова памет, колкото е дължината на входния параметър
    // + 1, за да можем да запишем символа за край на низ '\0'
    this->lastName = new char[strlen(lastName) + 1];
    // копираме съдържанието
    strcpy(this->lastName, lastName);

    this->department = new char[strlen(department) + 1];
    strcpy(this->department, department);
}

void Employee::clearDymanicData()
{
    // ако при заделянето на памет се използват [],
    // то и при освобождаването на паметта трябва да използваме []
    delete [] lastName;
    delete [] department;
}

// статична член-функция, която да връща стойността на countEmployees
unsigned Employee::getCountEmployees()
{
    // статичните методи не се обявяват за константни,
    // константността е свързана с указателя this, а
    // статичните методи могат да не се извикват с конкретен обект,
    // а с името на класа::
    return countEmployees;
}
