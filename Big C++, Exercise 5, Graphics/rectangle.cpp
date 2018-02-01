#include "rectangle.h"

rectangle::rectangle()
{
}
rectangle::rectangle(const Point& a, const Point& b)
	:left_corner(a),right_corner(b)
{
}
void rectangle::plot() const
{
	double length = get_length();
	double width = get_width();

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

void rectangle::move(double dx, double dy)
{
	left_corner.move(dx, dy);
	right_corner.move(dx, dy);
}

double rectangle::get_length() const
{
	double length = left_corner.get_y() - right_corner.get_y();
	return length;
}

double rectangle::get_width() const
{
	double width = right_corner.get_x() - left_corner.get_x();
	return width;
}

double rectangle::get_area() const
{
	double area = get_length() * get_width();
	return area;
}

double rectangle::get_perimeter() const
{
	double perimeter = 2 * (get_length() + get_width());
	return perimeter;
}
