#include "onetime.h"

Onetime::Onetime()
{
}

Onetime::Onetime(const std::string & desc, const Date & date, const Time & t)
	:Appointment(desc, date, t)
{
}
