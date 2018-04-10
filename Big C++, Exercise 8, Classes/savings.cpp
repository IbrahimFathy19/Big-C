#include "savings.h"

Savings::Savings() /* The default constructor of Account class will be called here
 No need for further implementation*/
{
}

Savings::Savings(double initial_balance, unsigned long acc_ID)
	:Account(initial_balance, acc_ID)
{
}

double Savings::daily_interst()
{
	const float percent = 0.06;
	double interst_monthly = Account::get_balance() * percent;
	double interst_daily = interst_monthly / (double)30;
	Account::deposit(interst_daily); // To add the interest to the account
	return interst_daily;
}
