#include "appointment.h"

Appointment::Appointment()
{
}

Appointment::Appointment(const std::string desc, const Date & d, const Time & start, const Time & end)
	:description(desc), day(d), starting_time(start), ending_time(end)
{
	assert(ending_time > starting_time);
}


bool Appointment::in_same_time(const Appointment & a) const
{
	if (this->day.is_same_date((a.day))) 
	{
		//test if they are in the same time
		if (this->starting_time > a.ending_time ||
			(this->starting_time < a.starting_time && this->ending_time < a.starting_time))
			return false;
		else
			return true;
	}
	return false;
}

bool Appointment::happens_before(const Appointment& a) const
{
	if (this->day < a.day) // not in the same day
		return true;

	else if (this->day.is_same_date(day)) // same day but differnt times
		if (this->starting_time < a.starting_time && this->ending_time < a.starting_time)
			return true;
	return false;
}

void Appointment::print_appointment() const
{
	std::cout << "Appointment description: " << this->description << "\n"
		<< "Date: " << this->day << "\n"
		<< "Starting Time: " << this->starting_time << "\n"
		<< "Ending Time: " << this->ending_time << "\n";
}

bool Appointment::operator==(const Appointment & a) const
{
	if (this->in_same_time(a))
		return true;
	else
		return false;
}

bool Appointment::operator<(const Appointment & a) const
{
	if (this->happens_before(a))
		return true;
	else
		return false;
}

Date Appointment::get_day() const
{
	return day;
}

void Appointment::read_appointment()
{
	std::cout << "Description: ";
	std::cin >> description;
	std::cout << "Date: ";
	day.read_date();

	int h, m;
	std::cout << "Starting Time: \n"
		<< "Hours: ";
	std::cin >> h;
	std::cout << "Minutes: ";
	std::cin >> m;
	starting_time = Time(h, m, 0);

	std::cout << "Ending Time: \n"
		<< "Hours: ";
	std::cin >> h;
	std::cout << "Minutes: ";
	std::cin >> m;
	ending_time = Time(h, m, 0);

	assert(ending_time > starting_time);
}

bool Appointment::empty() const
{
	if (description.empty() && day.empty())
		return true;
	return false;
}
