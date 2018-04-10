#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person
{
public:
	/**
		Default constructor of the Person class
		do nothing :-D 
	*/
	Person();
	/**
		Constructs the person object with name and birth date
		@param person_name the name
		@param month the month of the birth date
		@param day the day of the birth date
		@param year the year of the birth date
	*/
	Person(const std::string& person_name, int month, int day, int year);
	/**
		Prints the data of the person (name and birth date)
	*/
	virtual void print() const;
private:
	std::string name;
	std::vector<int> birthdate; // mm/dd/yy
};

#endif