#pragma once
#ifndef DATE_H
#define DATE_H

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
private:
	unsigned int day, month, year;
};
#endif