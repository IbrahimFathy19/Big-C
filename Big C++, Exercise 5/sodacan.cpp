#include "sodacan.h"
#define PI 3.14159265359

SodaCan::SodaCan()
{
	height = 0, radius = 0;
}
SodaCan::SodaCan(double new_height, double new_radius)
{
	height = new_height, radius = new_radius;
}
double SodaCan::get_surface_area() const
{
	double area = 2 * PI * radius * height + 2 * PI * radius * radius;
	return area;
}
double SodaCan::get_volume() const
{
	double volume = PI * radius * radius * height;
	return volume;
}