#include "appointment.h"

Appointment::Appointment()
{
}

Appointment::Appointment(const std::string & desc, const Date & date, const Time & t)
	:description(desc), appointment_date(date), appointment_time(t)
{
}

bool Appointment::occurs_on(int year, int month, int day) const
{
	if (appointment_date.get_year() == year && appointment_date.get_month() == month
		&& appointment_date.get_day() == day)
		return true;
	return false;
}
