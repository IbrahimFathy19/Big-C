#pragma once
#ifndef STREET_H
#define STREET_H
#include "house.h"

class Street
{
public:
	/**
		Constructs the street with 0 number of houses
	*/
	Street();
	Street(House f_h, House l_h, int n);
	/**
		Plots the street according to the number of houses
	*/
	void plot() const;



private:
	House first_house, last_house;
	int number_houses;
};



#endif