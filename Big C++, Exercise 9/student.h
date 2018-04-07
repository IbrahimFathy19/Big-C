#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <string>
#include <iostream>
#include <iomanip>

class Student
{
public:
	/**
	Constructor that initializes id to 0
	*/
	Student();

	/**
	Construct a new Student Object with id = 0
	@param ID the Identity document of the Student
	*/
	Student(double ID);

	/**
	Adds a new element (class) to the map
	@param class_name Name of the Class
	@param value the Studuent's grade in this class
	*/
	void add_class_value(const std::string& class_name, const std::string& value);

	/**
	Prints the Student object's data
	*/
	void print_student() const;
private:
	double id;
	std::map<std::string, std::string> class_value;
};
#endif // !STUDENT_H