#pragma once


class Point
{
public:
	Point();
	Point(double new_x, double new_y);
	double get_x() const;
	double get_y() const;

private: 
	double x, y;
};