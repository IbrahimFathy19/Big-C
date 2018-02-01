#include "circleshape.h"

CircleShape::CircleShape()
{
	radius = 0;
}

CircleShape::CircleShape(const Point & center, double r)
	:Shape(center)
{
	radius = r;
}

double CircleShape::area() const
{
	double a = PI * radius * radius;
	return a;
}

void CircleShape::plot() const
{
	Point center = get_corner();
	Circle c(center, radius);
	cwin << c;
}

Shape * CircleShape::make_shape(const Point & pos)
{
	Shape* s = new CircleShape(pos, 1);
	return s;
}
