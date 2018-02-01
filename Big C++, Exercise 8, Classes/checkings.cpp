#include "checkings.h"

Checkings::Checkings()
{
}

Checkings::Checkings(double initial_balance, unsigned long acc_ID)
	:Account(initial_balance, acc_ID)
{
}

double Checkings::daily_interst()
{
	double balance = Account::get_balance();
	const float percent = 0.03;
	double interst_monthly = (balance > 1000) ? balance * percent : 0;
	double interst_daily = interst_monthly / (double)30;
	Account::deposit(interst_daily); // To add the interest to the account
	return interst_daily;
}
