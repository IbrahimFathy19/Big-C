#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
public:
	/**
		Constructs the square with two default corner points ar (0, 0)
	*/
	Square();
	/**
		Cosntructs the square object with two given corner points
		@param corner_lu the left up corner point
		@param corner_rd the right down corner point
	*/
	Square(const Point& corner_lu, const Point& corner_rd);
	/**
		Gets the area of the square
	*/
	virtual double area() const;
	/**
		Plots the square
	*/
	virtual void plot() const;
	/**
		Check whether this given points can construct a square
		@return true if the two given corner points can make up a square shape
	*/
	bool is_square() const;
	/**
		Moves this square
		@param dx the amount to move in the x-direction
		@param dy the amount to move in the y-direction
	*/
	void move(double dx, double dy);
	/**
		Gets a new shape of default size anchored at the point p.
		@return a pointer points to square of default size
	*/
	virtual Shape* make_shape(const Point& pos);
private:
	/**
		Gets the length of the square shape
		@return the length 
	*/
	double get_length() const;
private:
	Point corner_two;
};
#endif