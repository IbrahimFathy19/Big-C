#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
public:
	/**
		Default constructor to initialize the balance and ID to 0
	*/
	Account();
	/**
		Constructs the Account object with the given balance and ID
		@param initial_balance the balance of this account
		@param acc_ID the ID of this account
	*/
	Account(double initial_balance, unsigned long acc_ID);
	/**
		Deposits some money to the current balance
		@param money the money to be added to the balance
	*/
	void deposit(double money);
	/**
		Withdraw some money from the current balance
		@param money the money to be withdrawn from the balance
	*/
	void withdraw(double money);
	void print() const;
protected:
	/**
		Gets the current balance of this account
		@return the current balance
	*/
	double get_balance() const;
private:
	double balance;
	unsigned long account_ID;
};


#endif