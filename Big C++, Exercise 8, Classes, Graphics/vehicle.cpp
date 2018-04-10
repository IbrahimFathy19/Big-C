#include "vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(const Point & p)
	:position(p)
{
}

void Vehicle::draw() const
{
}

Point Vehicle::get_postion() const
{
	return position;
}
