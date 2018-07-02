/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include "ccc_time.h"
#include <string>
#include <sstream>
#include <cmath>


#define PI 3.14159265359

string int_to_string(int n);

void p22();
void p23();
void p24();
void p25();
void p26();
void p27();
void p28();
void p31();


int ccc_win_main()
{
	std::string problem_name;
	do {
		problem_name = cwin.get_string("Enter the problem's code: ");

		if (problem_name == "p22")
			p22();
		else if (problem_name == "p23")
			p23();
		else if (problem_name == "p24")
			p24();
		else if (problem_name == "p25")
			p25();
		else if (problem_name == "p26")
			p26();
		else if (problem_name == "p27")
			p27();
		else if (problem_name == "p28")
			p28();
		else if (problem_name == "p31")
			p31();

		std::string clear;
		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();


	} while (problem_name != ("Quit"));
	return 0;
}

void p22()
{
	Point origin(0, 0);
	Circle big_circle(origin, 5);
	Point origin_left(-2, 2);
	Circle left_cicle(origin_left, .5);
	Point origin_right(2, 2);
	Circle right_cicle(origin_right, .5);
	Point satrt_line(-2.5, -1.5), end_line(2.5, -1.5);
	Line mouth(satrt_line, end_line);
	cwin << big_circle << left_cicle << right_cicle << mouth;
}

void p23()
{
	Point vertical_start(-9, 5);
	Point vertical_end(-9, -5);
	Point horizontal_start(-9, 0);
	Point horizontal_end(-6, 0);
	Line vertical(vertical_start, vertical_end);
	Line horizontal(horizontal_start, horizontal_end);
	// H
	cwin << vertical << horizontal;
	vertical.move(3, 0);
	cwin << vertical;
	horizontal.move(4, 5);
	cwin << vertical << horizontal;
	// next
	vertical.move(1, 0);
	cwin << vertical;
	// E
	horizontal.move(0, -5);
	cwin << horizontal;
	horizontal.move(0, -5);
	cwin << horizontal;
	// next
	vertical.move(4, 0);
	cwin << vertical;
	// L
	horizontal.move(4, 0);
	cwin << horizontal;
	// next
	vertical.move(4, 0);
	cwin << vertical;
	// L
	horizontal.move(4, 0);
	cwin << horizontal;
	Point origin(12, 0);
	Circle o(origin, 5);
	cwin << o;
}

void p24()
{
	// we first multiply all span in 2
	Point golden_gate_top(2, 8.4);
	Point golden_gate_down(2, 0);
	Line golden_gate(golden_gate_top, golden_gate_down);
	Point brooklyn_top(4, 3.19);
	Point brooklyn_down(4, 0);
	Line brooklyn(brooklyn_top, brooklyn_down);
	Point delaware_memorial_top(6, 4.3);
	Point delaware_memorial_down(6, 0);
	Line delaware_memorial(delaware_memorial_top, delaware_memorial_down);
	Point mackinaw_top(8, 7.6);
	Point mackinaw_down(8, 0);
	Line mackinaw(mackinaw_top, mackinaw_down);
	Point origin(0, 0);
	Point x_end(10, 0);
	Point y_end(0, 10);
	Line x(origin, x_end);
	Line y(origin, y_end);
	cwin << golden_gate << brooklyn << delaware_memorial << mackinaw << x << y;
	Message gloden_gate_msg(Point(0, -.5), "Golden Gate");
	Message brooklyn_msg(Point(3, -1.5), "Brooklyn");
	Message delaware_memorial_msg(Point(3.5, -.5), "Delaware Memorial");
	Message mackinaw_msg(Point(7, -1.5), "Mackinaw");
	Message name_msg(Point(8.5, 1), "Name");
	Message longest_span(Point(-4, 10), "Longest Span ft");
	Message golden_gate_value(Point(1.3, 9.4), "4,200");
	Message brooklyn_value(Point(3.3, 4.19), "1,595");
	Message delware_memorial_value(Point(5.3, 5.3), "2,150");
	Message machinaw_value(Point(7.3, 8.6), "3,800");
	cwin << gloden_gate_msg
		<< delaware_memorial_msg
		<< brooklyn_msg
		<< mackinaw_msg
		<< name_msg
		<< longest_span
		<< golden_gate_value
		<< brooklyn_value
		<< delware_memorial_value
		<< machinaw_value;
}

void p25()
{
	Point p1 = cwin.get_mouse("Please click on the first point");
	Point p2 = cwin.get_mouse("Please click on the second point");
	Point p3 = cwin.get_mouse("Please click on the third point");

	Line l1(p1, p2);
	Line l2(p2, p3);
	Line l3(p3, p1);
	cwin << l1 << l2 << l3;
}

void p26()
{
	Point origin_middle(0, 2);
	Circle middle(origin_middle, 2);
	cwin << middle;
	middle.move(2.5, 0); // upper right
	cwin << middle;
	middle.move(-5, 0); // upper left
	cwin << middle;
	middle.move(1.5, -2.5); // down left
	cwin << middle;
	middle.move(2.5, 0); // down right
	cwin << middle;
}

void p27()
{
	Point origin(0, 0);
	int radius = 4;

	Circle data(origin, radius);
	double area = radius * radius * PI;

	double first = cwin.get_double("Enter the first data value");
	double second = cwin.get_double("Enter the second data value");
	double third = cwin.get_double("Enter the third data value");
	double fourth = cwin.get_double("Enter the fourth data value");
	double all = first + second + third + fourth;
	// IN ratios
	first = first / all;
	second = second / all;
	third = third / all;
	fourth = fourth / all;
	// In areas 
	first = first * area;
	second = second * area;
	third = third * area;
	fourth = fourth * area;

	Point preimer_point(0, radius);
	Line preimer_line(origin, preimer_point);

	cwin << data;

	double theta = (360.0 * first) / area;/* the angle between
	axis and the line of the sub-area ****in degrees****/
	double x = radius * sin((theta * PI) / 180.0);
	double y = radius * cos((theta * PI) / 180.0);
	Point second_point(x, y);
	Line second_line(origin, second_point);
	Message m(second_point, "First Segment");

	cwin << preimer_line
		<< second_line
		<< m;



	theta = (360.0 * second) / area + theta;
	x = radius * sin((theta * PI) / 180.0);
	y = radius * cos((theta * PI) / 180.0);
	second_point = Point(x, y);
	second_line = Line(origin, second_point);
	m = Message(second_point, "Second Segment");

	cwin << preimer_line
		<< second_line
		<< m;


	theta = (360.0 * third) / area + theta;
	x = radius * sin((theta * PI) / 180.0);
	y = radius * cos((theta * PI) / 180.0);
	second_point = Point(x, y);
	second_line = Line(origin, second_point);
	m = Message(second_point, "Third Segment");

	cwin << preimer_line
		<< second_line
		<< m;


	theta = (360.0 * fourth) / area + theta;
	x = radius * sin((theta * PI) / 180.0);
	y = radius * cos((theta * PI) / 180.0);
	second_point = Point(x, y);
	second_line = Line(origin, second_point);
	m = Message(second_point, "Fourth Segment");

	cwin << preimer_line
		<< second_line
		<< m;
}

void p28()
{
	double x;
	double y;
	Point origin(0, 0);
	double radius = 4;
	Circle watch(origin, radius);
	Time current_time = Time();


	//Show the numbers and dashes
	int numbers[12];
	int number_angle[12];
	Line dash;
	Point first;
	Point end;
	for (int i = 0; i < 12; i++)
	{
		numbers[i] = i + 1;
		number_angle[i] = ((numbers[i] * 360) / 12) + 90;
		x = 5 * cos((number_angle[i] * PI) / 180.0);
		y = 5 * sin((number_angle[i] * PI) / 180.0);
		Point number(-x, y);
		x = (x / 5.0) * 4;
		y = (y / 5.0) * 4;
		first = Point(-x, y);
		x = (x / 4.0) * 3.7;//where .3 is the length of the dash
		y = (y / 4.0) * 3.7;
		end = Point(-x, y);
		dash = Line(first, end);
		cwin << dash;
		Message num(number, int_to_string(numbers[i]));
		cwin << num;

	}
	int seconds = current_time.get_seconds();
	int minutes = current_time.get_minutes();
	int hours = current_time.get_hours();
	double seconds_angle = ((seconds * 360) / 60) + 90;
	x = 3.5 * cos((seconds_angle*PI) / 180.0);
	y = 3.5 * sin((seconds_angle*PI) / 180.0);
	Point end_line(-x, y);
	Line minute(origin, end_line);
	double minutes_angle = ((minutes * 360) / 60) + 90;//We increase 90 degrees to make the start angle at point (0,radius)
	x = 2.8 * cos((minutes_angle*PI) / 180.0);
	y = 2.8 * sin((minutes_angle*PI) / 180.0);
	end_line = Point(-x, y);
	Line second(origin, end_line);
	double hours_angle = (((hours * 60 + minutes) * 360) / (60 * 12)) + 90; //We deal with minutes here
	x = 2 * cos((hours_angle*PI) / 180.0);
	y = 2 * sin((hours_angle*PI) / 180.0);
	end_line = Point(-x, y);
	Line hour(origin, end_line);

	cwin << watch;
	cwin << hour;
	cwin << minute;
	cwin << second;



}
//Converting Integers To strings
string int_to_string(int n)
{
	ostringstream outstr;
	outstr << n;
	return outstr.str();
}

void p31()
{
	Point right_corner_down(2, 0);
	Point right_corner_up(2, 4);
	Line right(right_corner_down, right_corner_up);
	cwin << right;
	right.move(-4, 0);
	cwin << right; //left line
	Point left_corner_down = right.get_start();
	Line down(left_corner_down, right_corner_down);
	cwin << down;
	down.move(0, 4);
	cwin << down;
	Point head_triangle(0, 6);
	Line first_arm_triangle(right_corner_up,head_triangle);
	cwin << first_arm_triangle;
	Line second_arm_triangle(right.get_end(), head_triangle);
	cwin << second_arm_triangle;
	Point door_left_corner_down(-1, 0);
	Point door_left_corner_up(-1, 3);
	Line left_door(door_left_corner_down, door_left_corner_up);
	cwin << left_door;
	left_door.move(1, 0);
	cwin << left_door;
	Point door_right_corner_up = left_door.get_end();
	Line up_door(door_left_corner_up, door_right_corner_up);
	cwin << up_door;
}