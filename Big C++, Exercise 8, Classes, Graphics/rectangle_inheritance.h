#pragma once
#ifndef RECTANGLE_INHERITANCE_H
#define RECTANGLE_INHERITANCE_H
#include "shape.h"

class Rectangle_inheritance : public Shape
{
public:
	/**
		Constructs the rectangle with two default corner points ar (0, 0)
	*/
	Rectangle_inheritance();
	/**
		Cosntructs the rectangle object with two given corner points
		@param corner_lu the left up corner point
		@param corner_rd the right down corner point
	*/
	Rectangle_inheritance(const Point& corner_lu, const Point& corner_rd);
	/**
		Gets the area of the rectangle
	*/
	virtual double area() const;
	/**
		Plots the rectangle
	*/
	virtual void plot() const;
	/**
		Gets a new shape of default size anchored at the point p.
		@return a pointer points to rectangle of default size 
	*/
	virtual Shape* make_shape(const Point& pos);
private:
	/**
		Gets the length of the rectangle (the vertical distance)
		@return the length
	*/
	double get_length() const;
	/**
		Gets the width of the rectangle (the horizontal distance)
		@return the width
	*/
	double get_width() const;
private:
	Point corner_two;
};
#endif