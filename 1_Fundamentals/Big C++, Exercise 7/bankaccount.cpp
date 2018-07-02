#include "BankAccount.h"
BankAccount::BankAccount()
{
	balance = 0;
}

void BankAccount::add_money(double money)
{
	balance = balance + money;
}

void BankAccount::withdraw_money(double money)
{
		balance = balance - money;
}

double BankAccount::get_balance() const
{
	return balance;
}