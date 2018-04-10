#include "bank.h"
#include <iostream>

void Bank::deposit(double amount, std::string account)
{
	if (account == ("S") || account == "s")//check for uppercase or lowercase letter
	{
		this->savings.add_money(amount);
	}
	else if (account == "C" || account == "c")
	{
		this->checking.add_money(amount);
	}
}
void Bank::withdraw(double amount, std::string account)
{
	if (account == ("S") || account == "s")//check for uppercase or lowercase letter
	{
		this->savings.withdraw_money(amount);
	}
	else if (account == "C" || account == "c")
	{
		this->checking.withdraw_money(amount);
	}
}
void Bank::transfer(double amount, std::string account)
{
	if (account == ("S") || account == "s")//check for uppercase or lowercase letter
	{
		this->savings.withdraw_money(amount);
		this->checking.add_money(amount);
	}
	else if (account == "C" || account == "c")
	{
		this->checking.withdraw_money(amount);
		this->savings.add_money(amount);
	}
}
void Bank::print_balances() const
{
	std::cout << "Checking account: " << checking.get_balance()
		<< "\n"
		<< "Savings account: " << savings.get_balance()
		<< "\n";
}