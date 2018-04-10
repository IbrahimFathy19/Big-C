#pragma once
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "manager.h"

class Executive : public Manager
{
public:
	/**
		Default constructor to initialize the salary with 0 and to construct
		the executive name and executive string with empty strings
	*/
	Executive();
	/**
		Constructs an executive with a given name, salary, department, and executive string
		@param manager_name the manager name
		@param initial_salary the initial salary
		@param dept the manager department
		@param executive the manager's jop
	*/
	Executive(const std::string& manager_name, double initial_salary,
		const	std::string& dept, const std::string& exeuct);
	/**
		Prints the manager's data (executive string, name, salary, and department)
		in seperate lines
	*/
	void print() const;
private:
	std::string executive;
};

#endif