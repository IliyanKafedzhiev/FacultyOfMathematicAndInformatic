#include "BankAccount.h"
#include <iostream>
#include <cstring>
using namespace std;

BankAccount::BankAccount(void)
{
	this->ownerName=NULL;
	strcpy(this->IBAN,"");
	this->Balance=0.0;
}
BankAccount::BankAccount(const char* ownerName , const char* IBAN,const double Balance)
{
	this->ownerName=new char [strlen(ownerName)+1];
	strcpy(this->ownerName,ownerName);
	strcpy(this->IBAN,IBAN);
	this->Balance=Balance;
}
BankAccount::BankAccount(const BankAccount* Banker)
{
	
}
BankAccount::~BankAccount(void)
{
}
