class Account
{
public:
	Account&operator=(const Account&);
	Account(char* clientName,char* IBAN,double balance=0);
	virtual ~Account(void);
	double getBalance()const;
	virtual void withdraw(double);
	void deposit(double);
	virtual void print()const;
private:
	char *setName();
	Account(const Account&);
	char* clientName;
	char IBAN[20];
	double balance;

};
class AccountPlus:public Account
{
public:
	AccountPlus(char* clientName,char* IBAN,double balance,double credit);
	~AccountPlus();

	virtual void print()const;
	virtual void withdraw(double);
	double getCredit() const;
	void payCredit(double) ;
private:
	double credit;
	AccountPlus& operator=(const AccountPlus&);
	AccountPlus(const AccountPlus&);
};


