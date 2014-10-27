#include "BankAccount.h"

class Bank
{
private:
	char* bankName;
	int maxBankAccountsCount;
	int bankAccountsCount;
	BankAccount* bankAccounts;

public:
	Bank();
	~Bank();
};

