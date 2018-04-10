#include "programmer.h"

Programmer::Programmer(const std::string & name, double salary)
	:Employee(name, salary)
{
}

std::string Programmer::get_name() const
{
	std::string n = Employee::get_name();
	n = n + " (programmer)";
	return n;
}
