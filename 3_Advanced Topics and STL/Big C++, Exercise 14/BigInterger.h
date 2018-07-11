#pragma once
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <string>
#include <iostream>

class BigInteger
{
public:
	BigInteger();
	BigInteger(const std::string& s);
	std::vector<int> get_digits() const;
	bool is_negative() const;
private:
	std::vector<int> digits;
	bool negative;
};

void resize(std::vector<int>& d, size_t desired_size);


BigInteger operator+(const BigInteger& a, const BigInteger& b);
BigInteger operator-(const BigInteger& a, const BigInteger& b);
//BigInteger operator*(const BigInteger& a, const BigInteger& b);

std::ostream& operator<<(std::ostream& out, const BigInteger& a);


#endif // !BIGINTEGER_H
