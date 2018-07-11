#include "BigInterger.h"

BigInteger::BigInteger()
{
	negative = false;
}

BigInteger::BigInteger(const std::string& s)
{
	negative = false;
	size_t i = 0, n = s.length(), j = 0;
	digits.resize(s.length());
	if (s[0] == '-')
	{
		negative = true;
		j = 1;
		digits.resize(s.length() - 1);
	}
	
	for (i = 0; i < n, j < n; i++, j++)
		digits[i] = s[j] - '0';
}

std::vector<int> BigInteger::get_digits() const
{
	return digits;
}

bool BigInteger::is_negative() const
{
	return negative;
}

void resize(std::vector<int>& d, size_t desired_size)
{
	std::vector<int>::iterator i;
	for (size_t j = 0, length = desired_size - d.size(); j < length; j++)
	{
		i = d.begin();
		d.insert(i, 0);
	}
}

BigInteger operator+(const BigInteger & a, const BigInteger & b)
{
	std::vector<int> digits_a = a.get_digits(),
		digits_b = b.get_digits();

	size_t size_a = digits_a.size(),
		size_b = digits_b.size();

	if (size_a > size_b)
		resize(digits_b, size_a);
	else
		resize(digits_a, size_b);

	// update size, one size for both
	size_t size = digits_a.size();

	std::string result_str;
	int i = size - 1;

	while (i >= 0)
	{
		if ((digits_a[i] + digits_b[i]) > 9)
		{
			if (i > 0)
			{
				digits_a[i - 1]++;
				result_str = std::to_string(digits_a[i] + digits_b[i]).substr(1, 1) + result_str;
			}
			else
				result_str = std::to_string(digits_a[i] + digits_b[i]) + result_str;
		}
		else
			result_str = std::to_string(digits_a[i] + digits_b[i]) + result_str;
		i--;
	}
	
	return BigInteger(result_str);
}

BigInteger operator-(const BigInteger & a, const BigInteger & b)
{
	std::vector<int> digits_a = a.get_digits(),
		digits_b = b.get_digits();

	size_t size_a = digits_a.size(),
		size_b = digits_b.size();

	if (size_a > size_b)
		resize(digits_b, size_a);
	else
		resize(digits_a, size_b);

	// update size, one size for both
	size_t size = digits_a.size();

	std::string result_str;
	int i = size - 1;

	int j = 0;
	bool negative = false;
	while (j < size  - 1)
	{
		if (digits_b[j] > digits_a[j])
		{
			digits_b.swap(digits_a);
			negative = true;
			break;
		}
		else if (digits_b[j] < digits_a[j])
		{
			break;
		}
		j++;
	}

	while (i >= 0)
	{
		if ((digits_a[i] - digits_b[i]) < 0)
		{
			while (i > 0)
			{
				int previous = 1;
				if (digits_a[i - previous] > 0)
				{
					digits_a[i - previous]--;
					result_str = std::to_string((digits_a[i] + 10) - digits_b[i]) + result_str;
					break;
				}
				previous++;
			}
		}
		else
			result_str = std::to_string(digits_a[i] - digits_b[i]) + result_str;
		i--;
	}
	if (negative)
	{
		result_str.insert(result_str.begin(), '-');
	}
	return BigInteger(result_str);
}

std::ostream & operator<<(std::ostream & out, const BigInteger & a)
{
	if (a.is_negative())
		out << '-';
	std::vector<int> digits = a.get_digits();
	size_t i, n;
	//find the first digit of the actual value of the number
	//i.e. it finds where the number begins
	//e.g. 00012, here the number begins at 1
	for (i = 0, n = digits.size(); i < n; i++)
		if (digits[i] == 0)
			;
		else
			break;

	for (size_t j = i, n = digits.size(); j < n; j++)
		out << digits[j];
	return out;
}
