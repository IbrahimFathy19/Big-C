#pragma once

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <sstream>

class Complex
{
public:
	/**
		Constructs a complex object with value of zero
	*/
	Complex();
	/**
		Constructs a Complex object with given real and imaginary values
		@param r real value
		@param i imaginary value
	*/
	Complex(double r, double i);
	/**
		Gets the real part of this complex number
		@return the real part
	*/
	double get_real() const;
	/**
		Gets the imaginary part of this complex number
		@return the imaginary part
	*/
	double get_img() const;
	/**
		Updates the implicit parameter (the left argument) by adding the complex number c
		@param c Complex number to be added to this
		@return the updated value
	*/
	Complex& operator+=(const Complex& c);
	/**
		Updates the implicit parameter (the left argument) by subtracting the complex number c
		@param c Complex number to be subtracted from this
		@return the updated value
	*/
	Complex& operator-=(const Complex& c);
	/**
		Updates the implicit parameter (the left argument) by multiplying by the complex number c
		@param c Complex number to be multiplyied by this
		@return the updated value
	*/
	Complex& operator*=(const Complex& c);
	/**
		Updates the implicit parameter (the left argument) by dividing over the complex number c
		@param c Complex number to be divided over this
		@return the updated value
	*/
	Complex& operator/=(const Complex& c);

private:
	double real, img;
};

inline Complex operator+(const Complex& c1, const Complex& c2);
inline Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex & c1, const Complex & c2);
Complex operator/(const Complex & c1, const Complex & c2);

std::ostream& operator<<(std::ostream& out, const Complex& c);
/**
	This stream accebts any form of complex numbers
	For instance you can type:
	5 + 2i
	5 - 2i
	5 - 2
	5 + 2
	5 + 0
*/
std::istream& operator>>(std::istream& in, Complex& c);

inline Complex::Complex()
{
	real = img = 0;
}

inline Complex::Complex(double r, double i)
	:real(r), img(i)
{
}

inline double Complex::get_real() const
{
	return real;
}

inline double Complex::get_img() const
{
	return img;
}

inline Complex& Complex::operator+=(const Complex & c)
{
	*this = *this + c;
	return *this;
}

inline Complex& Complex::operator-=(const Complex & c)
{
	*this = (*this) - c;
	return *this;
}

inline Complex& Complex::operator*=(const Complex & c)
{
	*this = *this * c;
	return *this;
}

inline Complex& Complex::operator/=(const Complex & c)
{
	*this = *this / c;
	return *this;
}

inline Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.get_real() + c2.get_real(), c1.get_img() + c2.get_img());
}

inline Complex operator-(const Complex& c1, const Complex& c2)
{
	return Complex(c1.get_real() - c2.get_real(), c1.get_img() - c2.get_img());
}

#endif // !COMPLEX_H 

