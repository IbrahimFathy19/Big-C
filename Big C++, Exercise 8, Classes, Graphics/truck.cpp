#include "truck.h"

Truck::Truck()
{
}

Truck::Truck(const Point & p)
	:Vehicle(p)
{
}

void Truck::draw() const
{
	const double MAX_HEIGHT = 3,
		MAX_WIDTH = 6, radius = 0.5;

	int x = Vehicle::get_postion().get_x();
	int y = Vehicle::get_postion().get_y();

	//the Big rectangle
	Point a(x - MAX_WIDTH, y + MAX_HEIGHT);
	Point b(x + MAX_WIDTH, y - MAX_HEIGHT);
	rectangle r(a, b);
	r.plot();

	// the smaller rectangle
	a = Point(x - MAX_WIDTH - MAX_WIDTH / 2, y + MAX_HEIGHT - radius * 2 );
	b = Point(x - MAX_WIDTH - radius / 2, y - MAX_HEIGHT);
	r = rectangle(a, b);
	r.plot();

	// the tires
	a = Point(x + MAX_WIDTH - radius, y - MAX_HEIGHT - radius);
	b = Point(x + MAX_WIDTH - radius * 3.5, y - MAX_HEIGHT - radius);
	Circle tire1(a, radius);
	Circle tire2(b, radius);
	cwin << tire1;
	cwin << tire2;


	a = Point(x - MAX_WIDTH + radius, y - MAX_HEIGHT - radius);
	b = Point(x - MAX_WIDTH + radius * 3.5, y - MAX_HEIGHT - radius);
	tire1 = Circle(a, radius);
	tire2 = Circle(b, radius);
	cwin << tire1;
	cwin << tire2;

	a = Point(x - MAX_WIDTH - MAX_WIDTH / 2 + radius * 1.5, y - MAX_HEIGHT - radius);
	tire1 = Circle(a, radius);
	cwin << tire1;
}
