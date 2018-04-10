#pragma once
#ifndef ONETIME_H
#define ONETIME_H

#include "appointment.h"

class Onetime : public Appointment
{
public:
	Onetime();
	Onetime(const std::string& desc, const Date& date, const Time& t);
private:

};
#endif