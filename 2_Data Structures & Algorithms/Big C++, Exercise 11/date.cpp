#include "date.h"

Date::Date()
{
	day = month = year = 0;
}

Date::Date(unsigned int m, unsigned int d, unsigned int y)
{
	month = m;
	day = d;
	year = y;

	//assert wrong dates
	assert(month <= 12);//if the expression is true, do nothing
	assert(month > 0);
	assert(year > 0);
	assert(day <= 31);
	assert(day > 0);
}

unsigned int Date::get_day() const
{
	return day;
}

unsigned int Date::get_month() const
{
	return month;
}

unsigned int Date::get_year() const
{
	return year;
}

void Date::read_date()
{
	std::cout << "month: ";
	std::cin >> month;
	std::cout << "day: ";
	std::cin >> day;
	std::cout << "year: ";
	std::cin >> year;

	assert(month <= 12);//if the expression is true, do nothing
	assert(month > 0);
	assert(year > 0);
	assert(day <= 31);
	assert(day > 0);
}

bool Date::is_same_date(const Date &d) const
{
	if (this->year == d.year && this->month == d.month && this->day == d.day)
		return true;
	return false;
}

bool Date::operator<(const Date & d) const
{
	if (this->year < d.year)
		return true;
	else if (this->year == d.year)
	{
		if (this->month < d.month)
			return true;
		else if (this->month == d.month)
		{
			if (this->day < d.day)
				return true;
		}
	}
	return false;
}

bool Date::empty() const
{
	if (year == month == day == 0)
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & stream, const Date & d)
{
	stream << d.get_month() << "/" << d.get_day() << "/" << d.get_year();
	return stream;
}
