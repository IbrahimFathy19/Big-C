#pragma once
#ifndef SAVINGS_H
#define SAVINGS_H
#include "account.h"
class Savings : public Account
{
public:
	/**
		Default constructor to initialize the balance and ID to 0
		// The default constructor of Account class will do that
	*/
	Savings();
	/**
		Constructs the Account object with the given balance and ID
		@param initial_balance the balance of this account
		@param acc_ID the ID of this account
	*/
	Savings(double initial_balance, unsigned long acc_ID);
	/**
		Calculates the daily interst of this account and modifies the current balance
		@return the daily interst
	*/
	double daily_interst();
};

#endif