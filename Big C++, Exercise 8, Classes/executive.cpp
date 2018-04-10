#include "executive.h"

Executive::Executive() // The default constructor of manager will be called
{
}

Executive::Executive(const std::string & manager_name, double initial_salary, const std::string & dept, const std::string & exeuct)
	:Manager(manager_name, initial_salary, dept)
{
	executive = exeuct;
}

void Executive::print() const
{
	std::cout << "Executive: " << executive << "\n";
	Manager::print();
}
