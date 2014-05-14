class BankAccount
{
private:
        char* ownerName;
        char IBAN[14];
        double balance;

public:
        /*
        BankAccount();
        BankAccount(const char* ownerName, const char* IBAN);
        BankAccount(const char* ownerName, const char* IBAN, double balance);
        */

        BankAccount(const char* ownerName = "", const char* IBAN = "", double balance = 0);
		~BankAccount();

		char* GetOwnerName() const;
		char* GetIBAN();
		double GetBalance() const;

		void SetOwnerName(const char* ownerName);
		bool SetIBAN(const char* IBAN);
		bool SetBalance(double balance);
		
		bool Depositing(double deposit);
		bool Draw(double money);
		void Balance() const;
};