#include "pemployee.h"

PEmployee::PEmployee()
{
	salary = 0;
}
PEmployee::PEmployee(std::string employee_name, double initial_salary)
	:person_data(employee_name, 0)
{
	salary = initial_salary;
}

void PEmployee::set_salary(double new_salary)
{
	salary = new_salary;
}

double PEmployee::get_salary() const
{
	return this->salary;
}

std::string PEmployee::get_name() const
{
	return this->person_data.get_name();
}
