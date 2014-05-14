#include "Account.h"


Account::Account(char* clientName,char* IBAN,double balance)
{
}


Account::~Account(void)
{
}

AccountPlus::AccountPlus(char* clientName,char* IBAN,double balance,double credit)
	:Account(clientName,IBAN,balance)
{
	this->credit=(credit>0)?credit:0;
}

AccountPlus::~AccountPlus()
{
}
