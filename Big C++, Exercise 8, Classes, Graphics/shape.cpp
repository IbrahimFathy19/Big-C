#include "shape.h"

Shape::Shape()
{
}

Shape::Shape(const Point & a)
	:corner(a)
{
}

double Shape::area() const
{
	return 0.0;
}

void Shape::plot() const
{
}

Shape* Shape::make_shape(const Point & pos)
{
	return nullptr;
}

Point Shape::get_corner() const
{
	return corner;
}
