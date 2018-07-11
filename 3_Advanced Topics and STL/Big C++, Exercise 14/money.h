#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money
{
public:
	/**
		Constructs a Money object with 0 dollars and cents
	*/
	Money();
	/**
		Constructs a Money object with given values of how many dollars and cents
		@param d how many dollars
		@param c how many cents
	*/
	Money(int d, int c);
	/**
		Updates a Money by adding in another Money value.
		@param right the Money to be added
		@return the updated Money value
	*/
	Money& operator+=(const Money& m);
	/**
		Updates a Money by subtracting from another Money value.
		@param right the Money to be subtracted
		@return the updated Money value
	*/
	Money& operator-=(const Money& m);
	/**
		Gets the value of dollars count
		@return dollars
	*/
	int get_dollars() const;
	/**
		Gets the value of cents count
		@return cents
	*/
	int get_cents() const;
	/**
		Compares Two Money values
		@param m Second value to compare with the implicit parameter
		@return 
			0 if they are equal
			1 if the left argument is larger than the right
		  -1 if the left argument is smaller than the right

	*/
	int compare(const Money& m) const;

private:
	int dollars, cents;
	void normalize();
};

Money operator+(const Money& m1, const Money& m2);
Money operator-(const Money& m1, const Money& m2);
Money operator%(double n, const Money& m);

bool operator<(const Money& m1, const Money& m2);
bool operator<=(const Money& m1, const Money& m2);
bool operator==(const Money& m1, const Money& m2);
bool operator!=(const Money& m1, const Money& m2);
bool operator>=(const Money& m1, const Money& m2);
bool operator>(const Money& m1, const Money& m2);

std::ostream& operator<<(std::ostream& out, const Money& value);
std::istream& operator>>(std::istream& in, Money& m);


inline Money::Money()
	:dollars(0), cents(0)
{
}

inline Money::Money(int d, int c)
	:dollars(d), cents(c)
{
	normalize();
}

inline Money& Money::operator+=(const Money & m)
{
	*this = (*this) + m;
	return (*this);
}

inline Money & Money::operator-=(const Money & m)
{
	*this = (*this) - m;
	return (*this);
}

inline int Money::get_dollars() const
{
	return this->dollars;
}

inline int Money::get_cents() const
{
	return this->cents;
}

inline bool operator<(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) < 0);
}

inline bool operator<=(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) <= 0);
}

inline bool operator==(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) == 0);
}

inline bool operator!=(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) != 0);
}

inline bool operator>=(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) >= 0);
}

inline bool operator>(const Money & m1, const Money & m2)
{
	return (m1.compare(m2) > 0);
}

#endif // !MONEY_H
