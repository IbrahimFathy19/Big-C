#include "manager.h"

Manager::Manager()
	:Employee(std::string(), 0)
{
}

Manager::Manager(const std::string & manager_name, double initial_salary, const std::string & dept)
	:Employee(manager_name, initial_salary)
{
	department = dept;
}

void Manager::print() const
{
	std::cout << "Name: " << Employee::get_name() << "\n"; // or simply get_name()
	std::cout << "Department: " << department << "\n";
	std::cout << "Salary: " << Employee::get_salary() << "$\n";
}
