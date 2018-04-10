#pragma once
#ifndef polygon_h
#define polygon_h

#include "ccc_win.h"
#include <vector>

class polygon
{
public:
	/**
		Default constructor of polygon
	*/
	polygon();
	/**
		Adds new point to the corners vector of the polygon
		Note that you have to add_points in the right sequence so that you
		print it right
		@param p Corner point that will be added to the corners vector
	*/
	void add_point(Point p);
	/**
		Plots the polygon
	*/
	void plot() const;
	/**
		Get the perimeter of the given polygon (this polygon)
		@return Perimeter value
	*/
	double perimeter() const;
	/**
		Get the area of the given polygon (this polygon)
		@return Area value
	*/
	double area() const;
	void move(double dx, double dy);
	void scale(double factor);
private:
	std::vector<Point> corners;
};

#endif