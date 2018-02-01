#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#include "rectangle.h"
#include "vehicle.h"

class Truck : public Vehicle
{
public:
	/**
		Construct a vehicle with a default center position Point(0, 0)
	*/
	Truck();
	/**
		Consrtuct a vrhicle with a given position
		@param p the position of the vehicle
	*/
	Truck(const Point& p);
	/**
		Draw the truck shape 
	*/
	virtual void draw() const;
private:

};
#endif