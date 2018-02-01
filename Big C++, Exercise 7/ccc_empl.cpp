#include "ccc_empl.h"

Employee::Employee()
{  
   salary = 0;
	acc = NULL;
}

Employee::Employee(string employee_name, double initial_salary)
{  
   name = employee_name;
   salary = initial_salary;
	acc = NULL;
}

Employee::Employee(string employee_name, double initial_salary, BankAccount * account)
	:name(employee_name)
{
	salary = initial_salary;
	acc = account;
	if (acc != NULL)
		acc->add_money(initial_salary);
}

void Employee::set_salary(double new_salary)
{  
   salary = new_salary;
	if (acc != NULL)
		acc->add_money(new_salary);
}

double Employee::get_salary() const
{  
   return salary;
}

string Employee::get_name() const
{  
   return name;
}

void Employee::set_account(BankAccount* account)
{
	acc = account;
}

BankAccount * Employee::get_account() const
{
	return acc;
}

void Employee::format(char buffer[], int buffer_maxlength)
{/*
	const char* string_name = "Name: ";
	int size_string_name = strlen(string_name);

	const char* this_name = this->name.c_str();
	int size_this_name = strlen(this_name);

	const char* string_salary = "\nSalary: ";
	int size_string_salary = strlen(string_salary);

	std::string s = std::to_string(this->salary);
	const char* this_salary = s.c_str();
	int size_this_salary = strlen(this_salary);

	strncpy(buffer, string_name, buffer_maxlength);
	strncat(buffer, this_name, size_this_name );
	strncat(buffer, string_salary, size_string_salary);
	strncat(buffer, this_salary, size_this_salary);

	buffer[buffer_maxlength - 1] = '\0';*/
}
