#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "date.h"
#include "ccc_time.h"
#include <assert.h>
#include <iostream>

class Appointment
{
public:
	/**
		Default constructor, it constructs the appointment with empty discription
		date: 0/0/0, and time now
	*/
	Appointment();	
	/**
		Constructs an appointment with a description in a given date and time
		@param desc description of this appointment
		@param d date of the appointment
		@param start Start time of the appointment
		@param end End time of the appointment
	*/
	Appointment(const std::string desc, const Date& d, const Time& start, const Time& end);
	/**
		Checks if two appointments happen in the same time or not
		It also checks if the time of the first appointment conflicts with the second
		@param a appointment to compare with
		@return true if they happen in the same time
	*/
	bool in_same_time(const Appointment& a) const;
	/**
		Checks if two appointments happens before the given appointment or not
		@param a appointment to compare with
		@return true if *this happens before a
	*/
	bool happens_before(const Appointment& a) const;
	/**
		Prints the data of an appoinment
	*/
	void print_appointment() const;
	/**
		Operator == to test if a and *this happens in the same time
		@param a Appointment to compare with the implicit parameter
		@return true if they happen in the same time
	*/
	bool operator==(const Appointment & a) const;
	/**
		Operator == to test if *this happens before appointment a
		@param a Appointment to compare with the implicit parameter
		@return true if this happens before a
	*/
	bool operator<(const Appointment& a) const;
	/**
		Returns the date of the implicit appointment
		@return date 
	*/
	Date get_day() const;
	/**
		Reads appointment data from the console
	*/
	void read_appointment();
	/**
		Checks if an appointment is not re-initialized
		@return true if the appointment has empty date, empty description
	*/
	bool empty() const;
private:
	std::string description;
	Date day;
	Time starting_time, ending_time;
};
#endif // !APPOINTMENT_H
