#pragma once
#ifndef SET_H
#define SET_H

#include <vector>
#include <iostream>


class Set
{
public:
	/**
		Constrcut empty Set of finite integers, where those integers are stored in a vector
	*/
	Set();
	/**
		Adds new element to the set iff it doesn't already exists in this set
		@param x Value to be appended to the set
	*/
	void add(int x);
	/**
		Removes an element of the set iff that element really exists
		@param Value of the element to be removed
	*/
	void remove(int x);
	/**
		Counts how many a specific element (x here) occures in the set
		@param x element to count
		@return 0 if this element doesn't exist
	*/
	int count(int x) const;
	/**
		Counts how many a specific element (x here) occures in the set
		@param x element to count
		@param index of the element that exist in the set
		@return 0 if this element doesn't exist
	*/
	int count(int x, size_t& index) const;
	/**
		returns the vector that contains the elements of the set
	*/
	std::vector<int> get_elements() const;
private:
	std::vector<int> elements;
};

/**
	Calaculates the intersection of two sets
*/
Set operator&(const Set& s, const Set& s2);

/**
	Calaculates the union of two sets
*/
Set operator|(const Set& s, const Set& s2);

/**
	Calaculates the complement of a set
	The complement start with the minimum value of s and ends with the maximum value of s
	It's a finite set
*/
Set operator~(const Set& s);


std::ostream& operator<<(std::ostream& out, const Set& s);

#endif // !SET_H