#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
public:
	/**
		Constructs the triangle whose corner points are the origin
	*/
	Triangle();

	/**
		Constructs the triangle with the three points given
		@param a is the first corner of the triangle (from the shape class)
		@param b is the second corner of the triangle
		@param c is the third corner of the triangle
	*/
	Triangle(const Point& a, const Point& b, const Point& c);

	/**
		Get the area of the teriangle
		@return the area
	*/
	virtual double area() const;

	/**
		Plots the three lines of the triangle to the screen
	*/
	virtual void plot() const;
	/**
		Gets a new shape of default size anchored at the point p.
		@return a pointer points to triangle of default size
	*/
	virtual Shape* make_shape(const Point & pos);
private:
	Point corner_one, corner_two;
};




#endif