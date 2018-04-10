#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
public:
	/**
		Default constructor of the Student class
	*/
	Student();
	/**
		Constructs the student object with name, birth date, and major
		@param student_name the name
		@param month the month of the birth date
		@param day the day of the birth date
		@param year the year of the birth date
		@param major the major of the student
	*/
	Student(const std::string& student_name, int month, int day,
		int year, const std::string& student_major);
	/**
		Prints the data of the student (name, birth date, and the major)
	*/
	virtual void print() const;
private:
	std::string major;
};




#endif
