#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	/**
		Constructs the age to zero, and the name is automatically initialized 
		by the string constructor
	*/
	Person();
	/**
		Constructs the string name to the input strin pname (stands for person name)
		and the integer age to the input integer page (stands for person age)
		@param pname is the name of the person
		@param page is the age of the person
	*/
	Person(std::string pname, int page);
	/**
		Returns the name of the implicit parameter (i.e. "this") the parameter which
		calls the function
		&return the name of the given (Person)
	*/
	std::string get_name() const;
	/** 
		Returns the age of the implicit parameter (i.e. "this") the parameter which
		calls the function
		@return the age of the given (Person). i.e. "this" Person
	*/
	int get_age() const;

private:
	std::string name;
	int age; // 0 if unknown
};

#endif