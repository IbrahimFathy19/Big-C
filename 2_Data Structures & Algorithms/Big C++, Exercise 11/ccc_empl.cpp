#include "ccc_empl.h"

Employee::Employee()
{  
   salary = 0;
}

Employee::Employee(std::string employee_name, double initial_salary)
{  
   name = employee_name;
   salary = initial_salary;
}

void Employee::set_salary(double new_salary)
{  
   salary = new_salary;
}

double Employee::get_salary() const
{  
   return salary;
}

std::string Employee::get_name() const
{  
   return name;
}

bool Employee::operator<(const Employee & a) const
{
	if (this->get_salary() < a.get_salary())
		return true;
	return false;
}
