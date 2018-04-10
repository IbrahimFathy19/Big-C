#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "ccc_time.h"
#include "date.h"

class Appointment
{
public:
	/**
		Constructs the appointment object with an empty description
		and 00/00/0000 date and with the current time (default constructor of
		Time class)
	*/
	Appointment();
	/**
		Constructs the appointment object with a given description, date, and time
		@param desc the description of this appointment
		@param date the date of this appointment
		@param t the time of this appointment
	*/
	Appointment(const std::string& desc, const Date& date, const Time& t);
	/**
		Chechs whether the appointment occurs on that date
		@param year the year of the date that will be checked
		@param month the month of the date that will be checked
		@param day the day of the date that will be checked
		@return true if both dates are the same
	*/
	virtual bool occurs_on(int year, int month, int day) const;
private:
	std::string description;
	Date appointment_date;
	Time appointment_time;
};
#endif