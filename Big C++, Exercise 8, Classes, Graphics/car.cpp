#include "car.h"

Car::Car()
{
}

Car::Car(const Point & p)
	:Vehicle(p)
{
}

void Car::draw() const
{
	const double MAX_HEIGHT = 1,
		MAX_WIDTH = 4, radius = 0.5;
	int x = Vehicle::get_postion().get_x();
	int y = Vehicle::get_postion().get_y();

	//the middile rectangle
	Point a(x - MAX_WIDTH, y + MAX_HEIGHT);
	Point b(x + MAX_WIDTH, y - MAX_HEIGHT);
	rectangle r(a, b);
	r.plot();

	// the upper rectangle
	a = Point(x - MAX_WIDTH / 2.0, y + MAX_HEIGHT + MAX_HEIGHT);
	b = Point(x + MAX_WIDTH / 2.0, y + MAX_HEIGHT);
	r = rectangle(a, b);
	r.plot();

	// the tires
	a = Point(x + MAX_WIDTH / 2.0 + radius, y - MAX_HEIGHT - radius);
	Circle c(a, radius);
	cwin << c;

	a = Point(x - MAX_WIDTH / 2.0 - radius, y - MAX_HEIGHT - radius);
	c = Circle(a, radius);
	cwin << c;
}
