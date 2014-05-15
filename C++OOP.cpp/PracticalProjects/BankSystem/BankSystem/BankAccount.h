#pragma once
class BankAccount
{
private:
	char * ownerName;
	char IBAN [13];
	double Balance;
public:
	BankAccount(void);
	BankAccount(const char* ownerName , const char* IBAN,const double Balance);
	BankAccount(const BankAccount* Banker);
	~BankAccount(void);
};

