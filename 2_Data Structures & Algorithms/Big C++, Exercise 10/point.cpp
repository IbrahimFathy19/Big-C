#include "point.h"

Point::Point()
{
	x = y = 0;
}

Point::Point(double new_x, double new_y)
{
	x = new_x;
	y = new_y;
}

double Point::get_x() const
{
	return x;
}

double Point::get_y() const
{
	return y;
}