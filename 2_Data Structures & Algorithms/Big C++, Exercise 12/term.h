#pragma once
#ifndef TERM_H
#define TERM_H

#include <iostream>

class Term
{
public:
	/**
		Constructs a term with value of zero
		A term contains the coefficient and the power of x
	*/
	Term();
	/**
		Constructs a term with a coefficient and power of x
		@param c coefficient of the term
		@param p power of the term
	*/
	Term(double c, double p);
	/**
		Gets the coefficient of this term
		@return coefficient
	*/
	double get_coeff() const;
	/**
		Gets the power of this term
		@return power
	*/
	double get_power() const;
	/**
		Prints the coefficent of this term followed by the x and its power
	*/
	void print_term() const;
private: 
	double coeff, power;
};

#endif // !TERM_H
