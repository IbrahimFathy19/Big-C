#include "Cross.h"

Cross::Cross()
{
}

Cross::Cross(Point p, Point c)
	:right_down_corner(p), left_up_corner(c)
{
}

Cross::Cross(Point intersect, double height, double width)
	:right_down_corner(intersect.get_x() + width / 2.0,
		intersect.get_y() - height / 2.0), 
	left_up_corner(intersect.get_x() - width / 2.0,
		intersect.get_y() + height / 2.0)
{
}

void Cross::plot() const
{
	Line temp(right_down_corner, left_up_corner);
	cwin << temp;
	Point right_up_corner(right_down_corner.get_x(), left_up_corner.get_y());
	Point left_down_corner(left_up_corner.get_x(), right_down_corner.get_y());
	temp = Line(right_up_corner, left_down_corner);
	cwin << temp;
}
