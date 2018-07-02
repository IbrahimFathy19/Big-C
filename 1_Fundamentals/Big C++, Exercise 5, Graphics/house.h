#pragma once
#ifndef HOUSE_H
#define HOUSE_H
#include "ccc_win.h"
#include "rectangle.h"
#include "triangle.h"


class House
{
public:
	/**
		Constructs the house number with 0 and location (0,0)
	*/
	House();

	/**
		Constructs the House with house number and new location
		@param h_n the house number
		@param loc the location of the house (x and y) are >= -10 and <=10
		and it is the up reight of the house
	*/
	House(int h_n, const Point& loc);

	/**
		Plots the house and it's a rectangle and teriangle
	*/
	void plot() const;

	/**
		Returns the house number of this object
		@return the house number
	*/
	int get_houseNumber() const;

	Point get_location() const;
private:
	int house_number;
	Point location;//the up reight of the house
};






#endif