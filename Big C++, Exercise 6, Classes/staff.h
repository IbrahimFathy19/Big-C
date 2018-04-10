#pragma once
#ifndef STAFF_H
#define STAFF_H
#include <vector>
#include "ccc_empl.h"
#include <iostream>

class Staff
{
public:
	/**
		Default constructor that do nothing
	*/
	Staff();
	/**
		Reads in some set of data of Employee type
		This function increases the size of the vector "members" and
		modifies it.
	*/
	void read();
	/**
		Finds the Employee of the given name from the members vector
		@param name is the name of the employee to be found
		@return the Employee with the given name
	*/
	Employee find(const std::string& name) const;
	/**
		Raises the salary of the Employee of the given name from the members vector
		@param name is the name of the employee to raise his salary
		@param new_salary the salary that will be replaced with the old salary
	*/
	void raise_salary(const std::string& name, double new_salary);

private:
	std::vector<Employee> members;
};




#endif