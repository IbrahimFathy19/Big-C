/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include <cmath>
#define PI 3.141592654


void p19();
void p20();
void p21();
void p22();
void p23();




/**
	Calculates the perimeter of a circle c
	@param c the circle whose perimeter will be calculated
	@return the value of perimeter
*/
double perimeter(const Circle& c);
/**
	Calculates the area of a circle c
	@param c the circle whose area will be calculated
	@return the value of area
*/
double area(const Circle& c);
/**
	Computes the distance between two points
	@param p is the first point
	@param q is the second point
	@return the distance between them
*/
double distance(const Point& p, const Point& q);
/**
	tests if a point p is inside a circle
	@param p the point to be tested if it's inside the circle or not
	@param c the circle in which we make our test
	@return true if p is inside c
*/
bool is_inside(const Point & p, const Circle & c);
/**
	Draws the letter H in a square 1 * 1
	@param p the top left corner of the letter
*/
void display_H(const Point& p);
/**
	Draws the letter E in a square 1 * 1
	@param p the top left corner of the letter
*/
void display_E(const Point& p);
/**
	Draws the letter L in a square 1 * 1
	@param p the top left corner of the letter
*/
void display_L(const Point& p);
/**
	Draws the letter O in a square 1 * 1
	@param p the top left corner of the letter
*/
void display_O(const Point& p);
/**
	Rotates a point for a specific angle
	@param p the point to be rotated
	@param angle the amount of angle the point p will be rotated with (in radian)
*/
void rotate(Point& p, double angle);
/**
	Scales a point with a given scale factor
	@param p the point to be scaled
	@param scale is the scale factor
*/
void scale(Point& p, double scale);




int ccc_win_main()
{
	std::string problem_name;
	do {

		problem_name = cwin.get_string("Enter the problem's code: ");
		if (problem_name == ("p19"))
			p19();
		else if (problem_name == ("p20"))
			p20();
		else if (problem_name == ("p21"))
			p21();
		else if (problem_name == ("p22"))
			p22();
		else if (problem_name == ("p23"))
			p23();


		std::string clear;
		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();


	} while (problem_name != ("Quit"));
	return 0;
}



void p19()
{
	Point center = cwin.get_mouse("Specify a center of the circle by a click");
	double radius = cwin.get_double("Enter the radius");
	Circle c(center, radius);
	cwin << c;
	Message p(Point(-9, 8), "Perimeter: "), a(Point(-9, 6), "Area: ");
	Message perimeter_circle(Point(-9, 7), perimeter(c)),
		area_circle(Point(-9, 5), area(c));
	cwin << p << a << perimeter_circle << area_circle;
}
void p20()
{
	Point one = cwin.get_mouse("Specify the first point by a click");
	cwin << one;
	Point two = cwin.get_mouse("Specify the second point by a click");
	cwin << two;
	Line connect_points(one, two);
	double distane_points = distance(one, two);
	Message d(Point(-9, 8), "Distance between the two points is: "),
		distance(Point(-9, 7), distane_points);
	cwin << d << distance << connect_points;
}
void p21()
{
	Point center = cwin.get_mouse("Specify a center of the circle by a click");
	double radius = cwin.get_double("Enter the radius");
	Circle c(center, radius);
	cwin << c;
	Point p = cwin.get_mouse("Specify the point by a click");
	cwin << p;
	bool check = is_inside(p, c);
	std::string test_result;
	if (check == true)
		test_result = "The point is inside the circle!";
	else
		test_result = "The point is outside the circle!";
	Message m(Point(-9, 8), test_result);
	cwin << m;

}
void p22()
{
	display_H(Point(-4, 8));
	display_E(Point(-2.5, 8));
	display_L(Point(-1, 8));
	display_L(Point(0.5, 8));
	display_O(Point(2, 8));

	display_H(Point(-3, -4));
	display_O(Point(-1.5, -4));
	display_L(Point(0, -4));
	display_E(Point(1.5, -4));

}
void p23()
{
	Point p(5, 5);
	cwin << p;
	for (int i = 0; i < 5; i++)
	{
		rotate(p, 10 * PI / 180);
		cwin << p;
	}
	for (int i = 0; i < 5; i++)
	{
		scale(p, 0.95);
		cwin << p;
	}
	Point b(-5, -5);
	for (int i = 0; i < 5; i++)
	{
		rotate(b, 10 * PI / 180);
		cwin << b;
	}
	for (int i = 0; i < 5; i++)
	{
		scale(b, 0.95);
		cwin << b;
	}
}





double perimeter(const Circle & c)
{
	double perimeter = 2 * PI * c.get_radius();
	return perimeter;
}
double area(const Circle & c)
{
	double area = PI * c.get_radius() * c.get_radius();
	return area;
}
double distance(const Point& p, const Point& q)
{
	double x1, x2, y1, y2;
	x1 = p.get_x(); x2 = q.get_x();
	y1 = p.get_y(); y2 = q.get_y();
	double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); //d stands for distance
	return d;
}
bool is_inside(const Point& p, const Circle& c)
{
	double d = distance(p, c.get_center());
	if (d > c.get_radius())//the point is out
		return false;
	else////the point is in
		return true;
}
void display_H(const Point & p)
{
	Point down_left_corner(p.get_x(), p.get_y() - 1);
	Line vertical(p, down_left_corner);
	cwin << vertical;
	vertical.move(1, 0);
	cwin << vertical;
	Point middle_left(p.get_x(), p.get_y() - 0.5);
	Point middle_right(p.get_x() + 1, p.get_y() - 0.5);
	Line horizontal(middle_left, middle_right);
	cwin << horizontal;
}
void display_E(const Point & p)
{
	Point down_left_corner(p.get_x(), p.get_y() - 1);
	Line vertical(p, down_left_corner);
	cwin << vertical;
	Point middle_left(p.get_x(), p.get_y() - 0.5);
	Point middle_right(p.get_x() + 1, p.get_y() - 0.5);
	Line horizontal(middle_left, middle_right);
	cwin << horizontal;
	horizontal.move(0, -0.5);
	cwin << horizontal;
	horizontal.move(0, 1);
	cwin << horizontal;
}
void display_L(const Point & p)
{
	Point down_left_corner(p.get_x(), p.get_y() - 1);
	Line vertical(p, down_left_corner);
	cwin << vertical;
	Point down_rigth_corner(p.get_x() + 1, p.get_y() - 1);
	Line horizontal(down_left_corner, down_rigth_corner);
	cwin << horizontal;
}
void display_O(const Point & p)
{
	Point center(p.get_x() + 0.5, p.get_y() - 0.5);
	Circle c(center, 0.5);
	cwin << c;
}
void rotate(Point & p, double angle)
{
	double px = p.get_x(), py = p.get_y();
	double qx = px * cos(angle) + py * sin(angle);
	double qy = -px * sin(angle) + py * cos(angle);
	p.set_x(qx);
	p.set_y(qy);
}
void scale(Point & p, double scale)
{
	double qx = scale * p.get_x();
	double qy = scale * p.get_y();
	p.set_x(qx);
	p.set_y(qy);
}