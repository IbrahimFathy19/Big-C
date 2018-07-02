#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"
#include <list>

class Polynomial
{
public:
	/**
		Constructs an empty polynomial
	*/
	Polynomial();
	/**
		Constructs a polynomial with a single term
		A term contains the coefficient and the power of x.
		@param t Term to be added to the constructor
	*/
	Polynomial(Term t);
	/**
		Adds a new polynomial to this polyomial
		If p contains a term of power = 1 for example, and so does this polynomial
		It will adds them and result in one term
		i.e. 5x - 2x = 3x
		@param p Polynomial to be appended to this polynomial
	*/
	void add(Polynomial p);
	/**
		Multiplies two polynomials and return the result
		@param p Ploynomial to be multiplied with this
		@return the result
	*/
	Polynomial multiply(Polynomial p);
	/**
		Print the terms of this polynomial
	*/
	void print_polynomial();
private:
	std::list<Term> poly;
};

#endif // !POLYNOMIAL_H

