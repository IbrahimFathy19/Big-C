#include "square.h"

Square::Square()
{
}

Square::Square(const Point & corner_lu, const Point & corner_rd)
	:Shape(corner_lu), corner_two(corner_rd)
{
}

double Square::area() const
{
	if (is_square())
		return get_length() * 2.0;
	else
	{
		Message m(Point(-8, 8), "Not a square, try different points!");
		cwin << m;
	}
}

void Square::plot() const
{
	if (is_square())
	{
		double length = get_length();
		double width = get_length();

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
	else
	{
		Message m(Point(-8, 8), "Not a square, try different points!");
		cwin << m;
	}
}

bool Square::is_square() const
{
	double length = get_length();
	double width = corner_two.get_x() - Shape::get_corner().get_x();
	if (length == width)
		return true;
	return false;
}

void Square::move(double dx, double dy)
{
	Point left_corner(Shape::get_corner());
	Point right_corner(corner_two);
	left_corner.move(dx, dy);
	right_corner.move(dx, dy);
}
Shape * Square::make_shape(const Point & pos)
{
	Point left_corner(pos.get_x() - 1, pos.get_y() + 1);
	Point right_corner(pos.get_x() + 1, pos.get_y() - 1);
	Shape* s = new Square(left_corner, right_corner);
	return s;
}
double Square::get_length() const
{
	double length = Shape::get_corner().get_y() - corner_two.get_y();
	return length;
}