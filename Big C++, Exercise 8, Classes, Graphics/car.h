#pragma once
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"	
#include "rectangle.h"

class Car : public Vehicle
{
public:
	/**
		Construct a vehicle with a default center position Point(0, 0)
	*/
	Car();
	/**
		Consrtuct a vrhicle with a given position
		@param p the position of the vehicle
	*/
	Car(const Point& p);
	/**
		Draw the car shape
	*/
	virtual void draw() const;
private:

};
#endif