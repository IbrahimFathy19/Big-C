#pragma once
#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "ccc_empl.h"

class Programmer : public Employee
{
public:
	/**
		Constructs the Programmer with a name and salary
		@param name the programmer name
		@param salary the initial salary
	*/
	Programmer(const std::string& name, double salary);
	/**
		Gets the name of the programmer
		@return the name of the programmer in a specific format
	*/
	std::string get_name() const;
};


#endif

