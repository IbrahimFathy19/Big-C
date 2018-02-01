#include "account.h"

Account::Account()
{
	balance = 0;
	account_ID = 0;
}

Account::Account(double initial_balance, unsigned long acc_ID)
{
	balance = initial_balance;
	account_ID = acc_ID;
}

void Account::deposit(double money)
{
	balance += money;
}

void Account::withdraw(double money)
{
	balance -= money;
}

double Account::get_balance() const
{
	return balance;
}

void Account::print() const
{
	std::cout << "Account ID: " << account_ID << "\n"
		<< "Balance is: " << balance << "\n";
}
