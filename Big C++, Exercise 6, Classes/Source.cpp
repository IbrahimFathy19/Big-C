#include <vector>
#include "bankstatement.h"
#include <iostream>

int main()
{
#if 1 //Test problem 13 Exercise 6

	std::vector<BankStatement> statements;
	bool more = true;
	int day;
	double amount;
	std::string description;
	char more_data;
	//while cin.fail() is not true for the first input (day)
	while (std::cin >> day && day <= 30 && day >= 1)
	{
		std::cin >> amount >> description;
		statements.push_back(BankStatement(day, amount, description));
	}

	double initial_balance = statements[0].get_amount();

	for (int i = 1, n = statements.size(); i < n; i++)
	{
		if (statements[i].get_amount() > 0) // then it's deposit
			std::cout << statements[i].get_amount() << "were deposited\n";
		else
			std::cout << statements[i].get_amount() << "were checked\n";
	}
#endif
}
