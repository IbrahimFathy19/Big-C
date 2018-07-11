#include "money.h"

Money operator+(const Money& m1, const Money& m2)
{
	return Money(m1.get_dollars() + m2.get_dollars(), m1.get_cents() + m2.get_cents());
}

Money operator-(const Money& m1, const Money& m2)
{
	return Money(m1.get_dollars() - m2.get_dollars(), m1.get_cents() - m2.get_cents());
}

int Money::compare(const Money & m) const
{
	int first_in_cents = this->dollars * 100 + this->cents,
		second_in_cents = m.get_dollars() * 100 + m.get_cents();

	if (first_in_cents > second_in_cents)
		return 1;
	else if (first_in_cents == second_in_cents)
		return 0;
	else
		return -1;
}

void Money::normalize()
{
	while (cents > 100)
	{
		dollars++;
		cents -= 100;
	}
}

std::ostream& operator<<(std::ostream& out, const Money& value)
{
	out << value.get_dollars() << "$, " << value.get_cents() << " cents.";
	return out;
}

std::istream& operator>>(std::istream& in, Money& m)
{
	int d, c;
	in >> d >> c;
	m = Money(d, c);
	return in;
}

Money operator%(double n, const Money & m)
{
	double percent = n / 100;
	return Money(m.get_dollars() * percent, m.get_cents() * percent);
}