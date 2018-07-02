#ifndef BANK_H
#define BANK_H
#include "account.h"
#include <string>
class Bank
{
	//The objects of this class have two accounts: checking and saving 
	//no nead for constructor because all of the account objects have their own constructor
public:
	/**
		Deposit some money for one of the two accounts: Checking or saving
		@param amount is the amount of money to be deposited
		@param string account is to distinguish between the two accounts: "S" for Saving
		and "C" for Checking, it indicates which account is affected
	*/
	void deposit(double amount, std::string account);

	/**
		withdraw some money for one of the two accounts: Checking or saving
		@param amount is the amount of money to be withdrawn
		@param string account is to distinguish between the two accounts: "S" for Saving
		and "C" for Checking, it indicates which account is affected
	*/
	void withdraw(double amount, std::string account);

	/**
		Transfer an amount of money from one account to the other
		@param amount is the amount of money to be transferred
		@param string account is to distinguish between the two accounts: "S" for Saving
		and "C" for Checking, it indicates the account from which the
		money is taken
	*/
	void transfer(double amount, std::string account);

	/**
		Prints the balnces of each account
	*/
	void print_balances() const;

private:
	account checking;
	account savings;
};



#endif