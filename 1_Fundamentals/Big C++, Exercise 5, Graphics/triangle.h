#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "ccc_win.h"
class Triangle
{
public:
	/**
		Constructs the triangle whose corner points are the origin 
	*/
	Triangle();

	/**
		Constructs the triangle with the three points given
		@param a is the first corner of the triangle
		@param b is the second corner of the triangle
		@param c is the third corner of the triangle
	*/
	Triangle(const Point& a, const Point& b, const Point& c);

	/**
		Plots the three lines of the triangle to the screen
	*/
	void plot() const;

	/**
		Moves the triangle a given dx and dy
		@param dx the amount to move in the x-direction
		@param dy the amount to move in the y-direction
	*/
	void move(double dx, double dy);

	/**
		Get the area of the teriangle
		@return the area
	*/
	double get_area() const;

	/**
		Get the perimeter of the teriangle
		@return the perimeter
	*/
	double get_perimeter() const;

private:
	Point corner_one, corner_two, corner_three;//R & L stands for right and left
};




#endif