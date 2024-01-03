
class BankAccount {
private:
	int balance;
	static int total;
public:

	BankAccount()
	{
		this->balance = 0;
	}

	// construct a BankAccount where the balance is input
	BankAccount(int input) {
		this->balance = input;
		total += input;
	}

	// withdraw money in the bank with the value of output
	void withdraw(int output)
	{
		this->balance -= output;
		total -= output;
	}

	// save money in the bank with the value of input
	void save(int input)
	{
		this->balance += input;
		total += input;
	}

	// return the current balance of this account
	int getBalance()
	{
		return this->balance;
	}

	// return the value of the total money amount in the bank
	static int getAllMoneyInBank()
	{
		return total;
	}
};

int BankAccount::total;