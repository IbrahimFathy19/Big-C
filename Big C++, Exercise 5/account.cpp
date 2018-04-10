#include "account.h"

account::account()
{
	balance = 0;
}

void account::add_money(double money)
{
	balance = balance + money;
}

void account::withdraw_money(double money)
{
	if (money > balance)
		balance = balance - 5;
	else
		balance = balance - money;
}

double account::get_balance() const
{
	return balance;
}