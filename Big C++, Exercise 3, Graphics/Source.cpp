/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include <ctime>
#include <cmath>
#define ALPHA 60
#define PI 3.14159265


void p23();
void p24();
void p25();
void p26();
void p27();
void p28();
void p30();


int ccc_win_main()
{
	std::string problem_name;
	do {
		problem_name = cwin.get_string("Enter the problem's code: ");
		
		if (problem_name == "p23")
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
		else if (problem_name == "p30")
			p30();

		std::string clear;
		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();


	} while (problem_name != ("Quit"));
	return 0;
}

void p23()
{
	Point origin(0, 0);
	cwin << origin;
	Point corner_one(-1, -1);
	Point corner_two(1, -1);
	Line horizontal(corner_one, corner_two);
	cwin << horizontal;
	horizontal.move(0, 2);
	cwin << horizontal;
	corner_one.move(2, 2);
	Line vertical(corner_one, corner_two);
	cwin << vertical;
	vertical.move(-2, 0);
	cwin << vertical;
	Circle unit(origin, 1);
	cwin << unit;
	srand(static_cast <unsigned> (time(0)));
	double x = -100 + rand() % (100 - -100 + 1);
	x *= 0.01;
	double y = -100 + rand() % (100 - -100 + 1);
	y *= 0.01;
	Point dart(x, y);
	int miss = 0, hit = 0;
	long dart_count = 0;
	for (long i = 0; i < 100000000; i++)
	{
		x = -100 + rand() % (100 - -100 + 1);
		x *= 0.01;
		y = -100 + rand() % (100 - -100 + 1);
		y *= 0.01;
		dart_count++;
		if ((x * x + y * y) <= 1) //Circle equation :D
			hit++;
		else
			miss++;
		//cwin << dart;
	}
	double pi = ((hit * 1.0) / dart_count) * 4;
	Message m(Point(-9, 9), pi);
	cwin << m;
}

void p24()
{
	Point corner_one(0, 0);
	Point corner_two(1, 0);
	Line horizontal(corner_one, corner_two);
	cwin << horizontal;
	horizontal.move(0, 1);
	cwin << horizontal;
	corner_one.move(1, 1);
	Line vertical(corner_one, corner_two);
	cwin << vertical;
	vertical.move(-1, 0);
	cwin << vertical;
	std::string s;
	Point msg_location(-5, 5);
	Point click = cwin.get_mouse("Click with your mouse on the saquare!");
	if (click.get_x() < 1 && click.get_x() > 0 && click.get_y() < 1 && click.get_y() > 0)
		s = "Congratulations!";
	else
		s = "You missed up!";
	Message msg(msg_location, s);
	cwin << msg;
}

void p25()
{

	Point center_1 = cwin.get_mouse("Click with your mouse to set the center of the "
		"first circle");
	double r1 = cwin.get_double("Enter the radius of the first circle");
	if (r1 < 0)
		return;
	Point center_2 = cwin.get_mouse("Click with your mouse to set the center of the "
		"seccond circle");
	double r2 = cwin.get_double("Enter the radius of the second circle");
	if (r2 < 0)
		return;
	Circle first(center_1, r1);
	Circle second(center_2, r2);
	cwin << first << second;
	Point msg_location(-9, 9);
	std::string s;
	double x1 = center_1.get_x(), y1 = center_1.get_y(),
		x2 = center_2.get_x(), y2 = center_2.get_y();

	//	if two circles are intersecting(R0-R1)^2 <= (x0-x1)^2+(y0-y1)^2 <= (R0+R1)^2
	if (pow((r1 - r2), 2) <= pow((x1 - x2), 2) + pow((y1 - y2), 2) &&
		pow((x1 - x2), 2) + pow((y1 - y2), 2) <= pow((r1 + r2), 2))
		s = "The two circles intersect";
	else
		s = "The two circles does not intersect";
	Message msg(msg_location, s);
	cwin << msg;

}

void p26()
{
	Line horizontal(Point(8, 8), Point(9, 8));
	int i, j;
	for (i = 0; i <= 10; i++)//horizontal rows in the whole grid
	{
		for (j = 0; j <= 20; j++)//horizontal rows in each column
		{
			cwin << horizontal;
			horizontal.move(0, -1);
		}
		horizontal.move(-1.5, 21);
	}
	Line vertical(Point(8, 8), Point(8, 9));
	for (i = 0; i <= 10; i++)//horizontal rows in the whole grid
	{
		for (j = 0; j <= 10; j++)//horizontal rows in each column
		{
			cwin << vertical;
			vertical.move(0, -2);
		}
		vertical.move(-1.5, 22);
	}
	Point drunkard(1.8, -2.5);
	cwin << drunkard;
	srand(static_cast<unsigned> (time(0)));
	bool north = false, south = false, west = false, east = false;
	double x;
	double distance = 0;
	for (int i = 0; i < 100; i++)
	{
		x = 0 + rand() % (100 - 0 + 1);
		//north = false, south = false, west = false, east = false;

		if (x <= 25)
		{
			north = true;
			drunkard.move(0, 2);
			distance++;
			if (south == true)//the previous diection was south 
			{
				distance--;
				south = false;
			}
		}
		else if (x <= 50)
		{
			south = true;
			drunkard.move(0, -2);
			distance++;
			if (north == true)
			{
				distance--;
				north = false;
			}
		}
		else if (x <= 75)
		{
			west = true;
			drunkard.move(-1.5, 0);
			distance++;
			if (east == true)
			{
				distance--;
				east = false;
			}
		}
		else if (x <= 100)
		{
			east = true;
			drunkard.move(1.5, 0);
			distance++;
			if (west == true)
			{
				distance--;
				west = false;
			}
		}
		cwin << drunkard;
	}
	Message msg(Point(-9, 9), distance);
	cwin << msg;
}

void p27()
{

	//Source of laws: https://goo.gl/wGjjxC
	const double gravity = 9.8;
	double s = 0;//for initial distance
	double V0 = 100;//for initial velocity
	double Vx = 0
		, Vy = 0;
	double x = 0,
		y = 0;
	double delta_t = 0.01;
	Point position;

	while (y >= 0)//condition for the cannonball while 
				  //it didn't hit the ground yet
	{
		Vx = V0 * cos(ALPHA * PI / 180.0);
		Vy = V0 * sin(ALPHA * PI / 180.0) - gravity * delta_t;
		x = V0 * delta_t * cos(ALPHA * PI / 180.0);

		y = V0 * delta_t * sin(ALPHA * PI / 180.0) - 0.5 * gravity
			* delta_t * delta_t;
#if 0
		std::cout << "x: " << x << "\n";
		std::cout << "y: " << y << "\n";
#endif
		s = sqrt(x * x + y * y); //update distance 
		delta_t += 0.01;
		x = (x - 10) * 0.04;
		position.set_x(x);
		y = (y * .02);
		position.set_y(y);
		cwin << position;
		Circle c(position, .5);
		cwin << c;
		c.move(.05, .05);
		cwin << c;
	}
}

void p28()
{
	Point corner_one(-1, -10);
	Point corner_two(1, -10);
	Line horizontal(corner_one, corner_two);
	cwin << horizontal;
	horizontal.move(0, 2);
	cwin << horizontal;
	corner_one.move(2, 2);
	Line vertical(corner_one, corner_two);
	cwin << vertical;
	vertical.move(-2, 0);
	cwin << vertical;
	Message msg(Point(-1, -7), "Stop");
	cwin << msg;

	int point_count = 0;
	double sum_x = 0, sum_y = 0, sum_x_squared = 0, x_average, y_average, m
		, sum_xy = 0, x = 0, y = 0;

	Point click(0, 0);

	while (true)
	{
		click = cwin.get_mouse("Click to specify a point");
		if (click.get_x() < 1 && click.get_x() > -1 &&
			click.get_y() < -8 && click.get_y() > -10)
			break;
		point_count++;
		x = click.get_x();
		y = click.get_y();
		sum_y = sum_y + y;
		sum_x = sum_x + x;
		sum_x_squared = sum_x_squared + x * x;
		sum_xy = sum_xy + x * y;
		cwin << click;
	}
	x_average = sum_x / point_count;
	y_average = sum_y / point_count;
	m = (sum_xy - point_count * x_average * y_average) / (sum_x_squared - point_count
		* x_average * x_average);
	//Draw the line, get y when x = -10 and when x = 10
	y = y_average + m * (-10 - x_average);
	Point line_end(-10, y);
	y = y_average + m * (10 - x_average);
	Point line_start(10, y);
	Line regression_line(line_end, line_start);
	cwin << regression_line;

}

void p30()
{
	double r, x, y;
	Point p;
	for (double theta = 0; theta <= 2 * PI; theta = theta + (2 * PI - 0) / (100 - 1))
		//(b - a)/c + 1 for the symmetric loop
	{
		r = cos(2 * theta);
		x = r * cos(theta);
		y = r * sin(theta);
		p.set_x(x);
		p.set_y(y);
		cwin << p;
	}
}