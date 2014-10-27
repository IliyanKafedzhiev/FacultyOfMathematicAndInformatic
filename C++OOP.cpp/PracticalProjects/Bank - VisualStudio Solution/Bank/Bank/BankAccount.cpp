#include <iostream>
#include <cstring>
#include "BankAccount.h"
using namespace std;


BankAccount::BankAccount()
{
        this->ownerName = NULL;
        strcpy(this->IBAN, "");
        this->balance = 0.0;
}

BankAccount::BankAccount(const char* ownerName, const char* IBAN)
{
        this->ownerName = new char[strlen(ownerName) + 1];
        strcpy(this->ownerName, ownerName);
        strcpy(this->IBAN, IBAN);
        this->balance = 0.0;
}


BankAccount::BankAccount(const char* ownerName, const char* IBAN, double balance)
{
        this->ownerName = new char[strlen(ownerName) + 1];
        strcpy(this->ownerName, ownerName);
        strcpy(this->IBAN, IBAN);
        this->balance = balance;
}


BankAccount::BankAccount(const char* ownerName, const char* IBAN, double balance)
{
        this->ownerName = new char[strlen(ownerName) + 1];
        strcpy(this->ownerName, ownerName);
        strcpy(this->IBAN, IBAN);
        this->balance = balance;
}

BankAccount::~BankAccount()
{
	delete[] this->ownerName;
}

char* BankAccount::GetOwnerName() const
{
	return this->ownerName;
}

char* BankAccount::GetIBAN()
{
	return this->IBAN;
}

double BankAccount::GetBalance() const
{
	return this->balance;
}

void BankAccount::SetOwnerName(const char* ownerName)
{
	delete[] this->ownerName;
	this->ownerName = new char[strlen(ownerName) + 1];
    strcpy(this->ownerName, ownerName);
}

bool BankAccount::SetIBAN(const char* IBAN)
{
	if (strlen(IBAN) != 13)
	{
		cout << "Error";

		return false;
	}

	strcpy(this->IBAN, IBAN);

	return true;
}

bool BankAccount::SetBalance(double balance)
{
	if (balance < 0)
	{
		cout << "Error\n";

		return false;
	}

	this->balance = balance;

	return true;
}

bool BankAccount::Depositing(double deposit)
{
	if (deposit <= 0)
	{
		cout << "Error\n";

		return false;
	}

	this->balance += deposit;

	return true;
}

bool BankAccount::Draw(double money)
{
	if (money < 0 && this->balance < money)
	{
		cout << "Error\n";

		return false;
	}

	this->balance -= money;

	return true;
}

void BankAccount::Balance() const
{
	cout << this->ownerName << endl
		<< this->IBAN << endl
		<< this->balance << endl;
}