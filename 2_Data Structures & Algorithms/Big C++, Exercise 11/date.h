#pragma once
#ifndef DATE_H
#define DATE_H

#include <assert.h>
#include <iostream>

class Date
{
public:
	/**
		Constructs the Date elements with 0
	*/
	Date();
	/**
		Constructs the Date object with a given date
		@param m the month
		@param d the day
		@param y the year
	*/
	Date(unsigned int m, unsigned int d, unsigned int y);
	/**
		Gets the day of this date
		@return the day 
	*/
	unsigned int get_day() const;
	/**
		Gets the month of this date
		@return the month
	*/
	unsigned int get_month() const;
	/**
		Gets the year of this date
		@return the year
	*/
	unsigned int get_year() const;
	/**
		Reads date data from console
	*/
	void read_date();
	/**
	   	Checks if the given date d occurs in the same date of the implicit parameter
		@param d date to compare with
		@return true if the two dates match
	*/
	bool is_same_date(const Date& d) const;
	/**
		Checks which date comes before the other
		@param d Date to compare with
		@return true if *this comes before d
	*/
	bool operator<(const Date& d) const;
	friend std::ostream& operator<<(std::ostream& stream, const Date& d);
	/**
		checks if the date has been re-initialized or not
		@return true if date is 0/0/0
	*/
	bool empty() const;
private:
	unsigned int day, month, year;
};
#endif