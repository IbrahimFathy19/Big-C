#pragma once
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <cmath>
class BankAccount
{
public:
	/**
		Constructs the balance to zero.
	*/
	BankAccount();

	/**
		Adds more money to the balance
		@param money is the extra money tht will be added to current balance
	*/
	void add_money(double money);

	/**
		Withdrow some money from the current balance
		@param money is the amount of money to be withdrown
	*/
	void withdraw_money(double money);

	/**
		Gets the current balance of the implicit parameter ("this")
		@return the balance of the account
	*/
	double get_balance() const;


private:
	double balance;
};




#endif