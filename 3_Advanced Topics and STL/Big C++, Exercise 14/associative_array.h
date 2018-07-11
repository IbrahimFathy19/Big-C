#pragma once
#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRAY_H

#include <string>
#include "double.h"
#include <cassert>
#include <vector>


//associative array that uses strings for keys and stores values of type double.
class AssociativeArray
{
public:
	/**
		Constructs array with empty Variables
	*/
	AssociativeArray();
	/**
		Construct array byy given variables
	*/
	AssociativeArray(const std::vector<Double>& v);
	/**
		Finds an element with key k
		@param k The key of the element to be found
		@reurn the index of the founded element 
		or return -1 if that element dowsn't exist
	*/
	int find(const std::string& k) const;
	
	/**
		Access an element through a key k
		if no element exists with that key, it add it to the back of the vector
	*/
	double& operator[](const std::string& k);
	double operator[](const std::string& k) const;

	/**
		Access an element through index while that index >=0 and index < size
	*/
	double& operator[](int i);
	double operator[](int i) const;
private:
	//array of type Double which consists of a double value and string key
	std::vector<Double> values;
};

#endif // !ASSOCIATIVE_ARRAY_H
