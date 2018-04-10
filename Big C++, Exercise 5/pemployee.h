#ifndef PEMPLOYEE_H
#define PEMPLOYEE_H

#include "person.h"
#include <string>

class PEmployee
{
public:
	/**
		Constructs the salary to zero and //the Person object 
		will be initilaized by its own default constructor
	*/
	PEmployee();
	/**
		Constructs the name of the employee by calling the second constructor of Person class
		and the age is set to zero, then constructs the salary to be initial salary
		@param employee_name is the name of the Person object (person_data)
		@param initail salary is the salary if the PEmployee
	*/
	PEmployee(std::string employee_name, double initial_salary);
	/**
		Sets the salary of the implicit parameter "this" to the new salary
		@param new_salary is the new salry for the implicit parameter (object) 
	*/
	void set_salary(double new_salary);
	/**
		Gets the salary of the implicit parameter "this", the function is constant
		@return the (double) salary of the implicit parameter
	*/
	double get_salary() const;
	/**
	Gets the name of the implicit parameter "this", the function is constant
	@return the (string) name of the implicit parameter
	*/
	std::string get_name() const;

private:
	Person person_data;
	double salary;
};

#endif