#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "ccc_win.h"

class Shape
{
public:
	/**
		Construct a shape with default corner point at (0, 0)
	*/
	Shape();
	/**
		Construct a shape with a given corner point
		@param a A Point on the shape
	*/
	Shape(const Point & a);
	/**
		Gets the area of this shape
		@return the area
	*/
	virtual double area() const;
	/**
		Plots this shape
	*/
	virtual void plot() const;
	/**
		Gets a new shape of default size anchored at the point p.
		@return Null
	*/
	virtual Shape* make_shape(const Point& pos);
protected:
	/**
		Gets one of the corners of this shape
		@return the corner
	*/
	Point get_corner() const;
private:
	Point corner;
};
#endif