#include "cannonball.h"

Cannonball::Cannonball()
{
	x = 0, y = 0;
	alpha = 0, initial_velocity = 0;
}

Cannonball::Cannonball(double new_x, double angle, double vel)
{
	x = new_x;
	y = 0;
	alpha = angle;
	initial_velocity = vel;
}

void Cannonball::move(double sec)
{
	//double Vy = initial_velocity * sin(alpha * PI / 180.0) - GRAVITY * sec;
//	double Vx = initial_velocity * cos(alpha * PI / 180.0);
	x = initial_velocity * cos(alpha * PI / 180.0) * sec;
	y = initial_velocity * sin(alpha * PI / 180.0) * sec -
		0.5 * GRAVITY * sec * sec;
}

void Cannonball::plot() const
{
	Point p(x, y);
	//Circle c(p, 0.5);
	cwin << p;
}

void Cannonball::shoot(double angle, double vel)
{
	double delta_t = 0.01;
	alpha = angle, initial_velocity = vel;
	while (y >= 0)
	{
		plot();
		move(delta_t);
		delta_t += 0.01;
	}
}
