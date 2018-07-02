#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:

	/**
		Constructs the integer poularity to 0 and the pointer Person to NULL
	*/
	Person();
	/**
		Constructs the Person object with a name and popularity and a pointer
		points to his best friend Person
		@param n Name of this Person
		@param pop Popularity of this person
		@param bf Pointer to the best friend of this Person
	*/
	Person(const std::string& n);
	/**
		Sets the best friend for this Person and updates the counter (popularity)
		@param bf Pointer to the best friend of this Person
	*/
	void set_best_friend(Person* bf);
	/**
		Get the name of this person
		@retun Name of this person
	*/
	std::string get_name();
	/**
		Prints out to the screen the data of this person
		Note we should protect the access of best_friend* in case it was not initialized
	*/
	void print_person();

private:
	std::string name;
	int popularity;
	Person* best_friend;
};
#endif