#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <algorithm>

class Polynomial
{
public:
	Polynomial();
	Polynomial(const std::vector<double>& coeff);
	std::vector<double> get_coeff() const;
private:
	//coefficents[0] represents the coeff of the heighst power of x
	std::vector<double> coefficents;
};

Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
Polynomial operator-(const Polynomial& p1, const Polynomial& p2);
Polynomial operator*(const Polynomial& p1, const Polynomial& p2);

std::ostream& operator<<(std::ostream& out, const Polynomial& p);

#endif // !POLYNOMIAL_H
