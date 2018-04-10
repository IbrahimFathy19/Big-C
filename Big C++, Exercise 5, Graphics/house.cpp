#include "house.h"

House::House()
	:location(0, 0)
{
	house_number = 0;
}

House::House(int h_n, const Point & loc)
	:location(loc)
{
	house_number = h_n;
}

void House::plot() const
{
	int x = location.get_x();
	int y = location.get_y();
	Triangle t(Point(x - 0.5, y), Point(x, y - 0.5), Point(x - 1, y - 0.5));
	rectangle r(Point(x - 1, y - 0.5), Point(x, y - 1.5));
	t.plot();
	r.plot();
}

int House::get_houseNumber() const
{
	return house_number;
}

Point House::get_location() const
{
	return location;
}
