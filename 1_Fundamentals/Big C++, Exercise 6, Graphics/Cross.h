#pragma once
#ifndef _CROSS_
#define _CROSS_

#include "ccc_win.h"

class Cross
{
public:
	/**
		Constructs the implementation of Cross using the default constructor 
		of Point class
	*/
	Cross();
	/**
		Constructs the Cross using two corners, the down_right corner and the upper_left
		corner
		@param p The down_right corner 
		@param c The upper_left corner
	*/
	Cross(Point p, Point c);
	/**
		Constructs the Cross using an intersection point and width and height
		@param intersect The intersection point of the two lines of Cross
		@param height The vertical height of each line of Cross
		@param width The horizontal width between the two lines at the end of each of them
	*/
	Cross(Point intersect, double height, double width);
	/**
		Plots the two lines of the Cross
	*/
	void plot() const;


private:
	Point right_down_corner;
	Point left_up_corner;
};




#endif