#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

class Student
{
public:
	/**
		Constructs the imolementation details, more speciffically the birthday variables (day,
		month, year) to zero
	*/
	Student();
	/**
		Reads form the user the data of a single student using the streams std::cin and 
		std::cout
	*/
	void read_student();
	/**
		Gets the month of the birthday date of the implicit parameter (student)
		@return the month in which the student was born
	*/
	int get_month() const;
	/**
		Prints out the student's data to the screen using the stream std::cout
	*/
	void print_student() const;
private:
	int birthDay_day, birthDay_month, birthDay_year;
	std::string name;
};
	/**
		Non-member function used to get out all friends whose birthday 
		falls in the current month.
		@param friends vector contains a number of students
		@return the students whose birthday falls in the current month.
	*/
std::vector<Student> find_friends(const std::vector<Student>& friends);

#endif