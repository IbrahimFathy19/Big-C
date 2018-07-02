#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include "ccc_win.h"

class Vehicle
{
public:
	/**
		Construct a vehicle with a default center position Point(0, 0)
	*/
	Vehicle();
	/**
		Consrtuct a vrhicle with a given position
		@param p the position of the vehicle
	*/
	Vehicle(const Point& p);
	/**
		Virtual function to draw the vehicle
	*/
	virtual void draw() const;
protected:
	/**
		Gets the position of this vehicle
		@return the position of this vehicle
	*/
	Point get_postion() const;
private:
	Point position;
};
#endif