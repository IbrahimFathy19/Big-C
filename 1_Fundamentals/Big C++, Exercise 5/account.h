#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cmath>
class account
{
public:
	/**
		Constructs the balance to zero.
	*/
	account();

	/**
		Adds more money to the balance
		@param money is the extra money tht will be added to current balance
	*/
	void add_money(double money);

	/**
		Withdrow some money from the current baalance
		@param money is the amount of money to be withdrown
	*/
	void withdraw_money(double money);

	/**
		Gets the current balance of the implicit parameter ("this")
		@return is the balance of the account
	*/
	double get_balance() const;


private:
	double balance;

};




#endif