#pragma once
#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <cmath>
#include "ccc_win.h"

#define PI 3.14159265
#define GRAVITY 9.8
class Cannonball
{
public:
	/**
		Constructs a Cannonball with zero value of x, y,  
		intial velocit, and alpha.
	*/
	Cannonball();
	/**
		Constructs a cannonball with a position of x and y = 0 
		@param new_x the position of the launch 
		@param angle the angle of launch (alpha)
		@param vel the initial velocity (V0)
	*/
	Cannonball(double new_x, double angle, double vel);
	/**
		Moves a point for amount of time, i.e. updates the position of the 
		cannonball depending on the time sec
		@param sec the time of movement
	*/
	void move(double sec);
	/**
		Plots a point indicates the position of the cannonball
	*/
	void plot() const;
	/**
		Moves the cannonball until it hits the earth again
		@param angle the angle of launch (alpha)
		@param vel the initial velocity (V0)
	*/
	void shoot(double angle, double vel);

private:
	double x, y,
		alpha, initial_velocity;
};




#endif