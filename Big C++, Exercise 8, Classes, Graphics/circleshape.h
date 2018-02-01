#pragma once
#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "shape.h"
#define PI 3.141592654
class CircleShape : public Shape
{
public:
	/**
		Construct a shape with default center point at (0, 0)
	*/
	CircleShape();
	/**
		Construct a shape with a given center point and radius
		@param center the center of this circle
	*/
	CircleShape(const Point& center, double r);
	/**
		Calculates the area of this circle
		@return the area
	*/
	virtual double area() const;
	/**
		Plots the circle
	*/
	virtual void plot() const;
	/**
		Gets a new shape of default size anchored at the point p.
		@return a pointer points to circle of default size
	*/
	virtual Shape* make_shape(const Point& pos);
private:
	double radius;
};
#endif