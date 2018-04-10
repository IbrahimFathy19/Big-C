#include "triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(const Point & a, const Point & b, const Point & c)
	:Shape(a), corner_one(b), corner_two(c)
{
}

double Triangle::area() const
{
	Point corner_three = Shape::get_corner();
	double area;
	double a = sqrt(pow(abs(corner_one.get_x() - corner_two.get_x()), 2)
		+ pow(abs(corner_one.get_y() - corner_two.get_y()), 2)); /* get the length of the line 
			between the two corners one and two*/
	double b = sqrt(pow(abs(corner_one.get_x() - corner_three.get_x()), 2)
		+ pow(abs(corner_one.get_y() - corner_three.get_y()), 2));/* get the length of the line 
			between the two corners one and three
			Now get the angle between them by finding the slope of each one
			then find their indication angles then subtract them to finally get the angle 
			between the two lines*/
	double slope_a = (corner_one.get_y() - corner_two.get_y()) /
		(corner_one.get_x() - corner_two.get_x());
	double slope_b = (corner_one.get_y() - corner_three.get_y()) /
		(corner_one.get_x() - corner_three.get_x());
	double angle_a = atan(slope_a);//in radian
	double angle_b = atan(slope_b);//in radian
	double angle = angle_a - angle_b;//the angle between the two lines a and b
	area = abs(a * b * sin(angle) / 2);
	return area;
}

void Triangle::plot() const
{
	Point corner_three = Shape::get_corner();
	Line first(corner_one, corner_two);
	Line second(corner_two, corner_three);
	Line third(corner_three, corner_one);
	cwin << first << second << third;
}

Shape * Triangle::make_shape(const Point & pos)
{
	Point first_corner(pos.get_x(), pos.get_y() + 1);
	Point second_corner(pos.get_x() - 1, pos.get_y() - 1);
	Point third_corner(pos.get_x() + 1, pos.get_y() - 1);
	Shape* s = new Triangle(first_corner, second_corner, third_corner);
	return s;
}
