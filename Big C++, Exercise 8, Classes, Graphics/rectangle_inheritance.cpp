#include "rectangle_inheritance.h"

Rectangle_inheritance::Rectangle_inheritance()
{
}

Rectangle_inheritance::Rectangle_inheritance(const Point & corner_lu, const Point & corner_rd)
	:Shape(corner_lu), corner_two(corner_rd)
{
}

double Rectangle_inheritance::area() const
{

	return get_width() * get_length();
}

void Rectangle_inheritance::plot() const
{
	double length = get_length();
	double width = get_width();

	Point left_corner(Shape::get_corner());

	Line top_horizontal(left_corner,
		Point(left_corner.get_x() + width, left_corner.get_y()));
	cwin << top_horizontal;

	top_horizontal.move(0, -length);
	cwin << top_horizontal;

	Line left_vertical(left_corner,
		Point(left_corner.get_x(), left_corner.get_y() - length));
	cwin << left_vertical;

	left_vertical.move(width, 0);
	cwin << left_vertical;
}

Shape * Rectangle_inheritance::make_shape(const Point & pos)
{
	Point left_corner(pos.get_x() - 1.5, pos.get_y() + 0.5);
	Point right_corner(pos.get_x() + 1.5, pos.get_y() - 0.5);
	Shape* s = new Rectangle_inheritance(left_corner, right_corner);
	return s;
}

double Rectangle_inheritance::get_length() const
{
	double length = Shape::get_corner().get_y() - corner_two.get_y();
	return length;
}

double Rectangle_inheritance::get_width() const
{
	double width = corner_two.get_x() - Shape::get_corner().get_x();
	return width;
}
