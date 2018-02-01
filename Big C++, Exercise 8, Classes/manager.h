#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "ccc_empl.h"
#include <iostream>
class Manager : public Employee
{
public:
	/**
		Default constructor to initialize salary with 0 and empty name string
	*/
	Manager();
	/**
		Constructs a manager with a given name, salary, and department.
      @param manager_name the manager name
      @param initial_salary the initial salary
		@param dept the manager department 
	*/
	Manager(const std::string& manager_name, double initial_salary, 
		const	std::string& dept);
	/**
		Prints the manager's data (name, salary, and department) in seperate lines
	*/
	void print() const;

private:
	std::string department;
};

#endif