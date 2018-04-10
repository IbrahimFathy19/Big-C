#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ccc_win.h"

class rectangle
{
public:
	/**
		Constructs a rectangle whose corner points are the origin
	*/
	rectangle();

	/**
		Constructs a rectangle with given corner points
		@param a the corner point to the top left
		@param b the corner point to the down right
	*/
	rectangle(const Point& a, const Point& b);

	/**
		Plots the rectangle to the screen
	*/
	void plot() const;

	/**
		Moves this rectangle
		@param dx the amount to move in the x-direction
		@param dy the amount to move in the y-direction
	*/
	void move(double dx, double dy);

	/**
		Get the length of the rectangle
		@return the length (i.e. height)
	*/
	double get_length() const;

	/**
		Get the width of this rectangle
		@return the width
	*/
	double get_width() const;

	/**
		Get the area of this triangle
		@return the area
	*/
	double get_area() const;

	/**
		Get the perimeter of this triangle
		@return the perimeter.
	*/
	double get_perimeter() const;
private:
	Point left_corner, right_corner;
};


#endif