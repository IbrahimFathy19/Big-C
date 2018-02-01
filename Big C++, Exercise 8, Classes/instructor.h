#pragma once
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "person.h"

class Instructor : public Person
{
public:
	/**
		Default Constructor to initialize the salary to 0
	*/
	Instructor();
	/**
		Constructs the Instructor object with a name, birthdate, and a salary
		@param instructor_name the name
		@param month the month of the birth date
		@param day the day of the birth date
		@param year the year of the birth date
		@param instructor_salary the salary of this instructor
	*/
	Instructor(const std::string& instructor_name, int month, int day,
		int year, double instructor_salary);
	/**
		Prints the data of the instructor (name, birth date, and the salary)
	*/
	virtual void print() const;

private:
	double salary;
};



#endif