#include "bankstatement.h"

BankStatement::BankStatement()
{
	day = 0;
	amount = 0;
}

BankStatement::BankStatement(int d, double a, const std::string & desc)
	:description(desc)
{
	day = d;
	amount = a;
}

void BankStatement::print_statement() const
{
	std::cout << day << "   " << amount << "   " << description;
}

double BankStatement::get_amount() const
{
	return amount;
}

