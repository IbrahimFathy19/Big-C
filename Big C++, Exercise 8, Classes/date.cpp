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
