/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include "rectangle.h"
#include "car.h"
#include "truck.h"
#include <vector>	
#include "vehicle.h"
#include "square.h"
#include "rectangle_inheritance.h"
#include "triangle.h"
#include "circleshape.h"
void p10();
void p11();
void p12();
void plot_menu();

int ccc_win_main()
{
	std::string problem_name;
	do {

		problem_name = cwin.get_string("Enter the problem's code: ");
		if (problem_name == ("p10"))
			p10();
		else if (problem_name == ("p11"))
			p11();
		else if (problem_name == ("p12"))
			p12();


		std::string clear;
		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();


	} while (problem_name != ("Quit"));
	return 0;
	return 0;
}

void p10()
{
	Point a(-5, 0),
		b(10, 0),
		c(10, 6),
		d(30, 0);

	std::vector<Vehicle*> mix(4);
	mix[0] = new Car(a);
	mix[1] = new Truck(b);
	mix[2] = new Car(c);
	mix[3] = new Truck(d);
	for (int i = 0, n = mix.size(); i < n; i++)
	{
		mix[i]->draw();
		delete mix[i];
	}
}

void p11()
{
	std::vector<Shape*> shapes(5);
	shapes[0] = new Square(Point(-9,3), Point(-6,0));
	shapes[1] = new Rectangle_inheritance(Point(-5,4), Point(-1,-6));
	shapes[2] = new Triangle(Point(0,0), Point(3,0), Point(2,7));
	shapes[3] = new Square(Point(4,4), Point(8,0));
	shapes[4] = new Triangle(Point(0,-4), Point(0,-9), Point(5,-6));

	for (int i = 0, n = shapes.size(); i < n; i++)
	{
		shapes[i]->plot();
		delete shapes[i];
	}
}

void p12()
{
	plot_menu();
	const int x_border_left = -9,
		square_length = 3,
		y_border = 8;

	Point mouse_click;
	double mouse_x, mouse_y;
	while (true)
	{
		mouse_click = cwin.get_mouse("Choose what you want to draw from the menu!");
		mouse_x = mouse_click.get_x();
		mouse_y = mouse_click.get_y();

		if (mouse_x >= x_border_left &&
			mouse_x <= x_border_left + square_length) //-9 and -6 are the x borders 
			// of the menu
		{
			if (mouse_y <= y_border && mouse_y >= y_border - square_length)//rectangle
			{
				Point mouse_click_corner = cwin.get_mouse("click to draw the rectangle");
				Rectangle_inheritance s;
				Shape *x = s.make_shape(mouse_click_corner);
				x->plot();
				delete x;
			}
			else if (mouse_y <= y_border - square_length &&
				mouse_y >= y_border - square_length * 2)//square
			{
				Point mouse_click_corner = cwin.get_mouse("click to draw the square");
				Square s;
				Shape *x = s.make_shape(mouse_click_corner);
				x->plot();
				delete x;
			}
			else if (mouse_y <= y_border - square_length * 2 &&
				mouse_y >= y_border - square_length * 3)//triangle
			{
				Point mouse_click_corner = cwin.get_mouse("click to draw the triangle");
				Triangle s;
				Shape *x = s.make_shape(mouse_click_corner);
				x->plot();
				delete x;
			}
			else if (mouse_y <= y_border - square_length * 3 &&
				mouse_y >= y_border - square_length * 4)
			{
				Point mouse_click_corner = cwin.get_mouse("click to draw the circle");
				CircleShape s;
				Shape *x = s.make_shape(mouse_click_corner);
				x->plot();
				delete x;
			}
			else if (mouse_y <= y_border - square_length * 4 &&
				mouse_y >= y_border - square_length * 5)//quit
				break;
		}
	}
}

void plot_menu()
{
	const int square_length = 3,
		square_num = 5;
	// 3 for length of the square
	for (int i = 0; i < square_num; i++)
	{
		Point menu_up_left(-9, 8 - i * square_length),
			menu_down_right(-9 + square_length, 8 - (i + 1) * square_length);
		Square s(menu_up_left, menu_down_right);
		s.plot();
		s.move(0, 3);
	}
	Rectangle_inheritance rectangle_sample(Point(-9 + 0.5, 8 - 1), Point(-9 + 2.5, 8 - 2));
	rectangle_sample.plot();

	Square square_sample(Point(-9 + 0.5, 8 - square_length - .5), Point(-9 + 2.5, 8 -
		square_length -2.5));
	square_sample.plot();

	Triangle triangle_sample(Point(-9 + 1.5, 8 - square_length * 2 - 0.5),
		Point(-9 + 0.5, 8 - square_length * 2 - 2.5),
		Point(-9 + 2.5, 8 - square_length * 2 - 2.5));
	triangle_sample.plot();

	CircleShape cricle_sample(Point( - 9 + 1.5, 8 - square_length * 3 - 1.5), 1);
	cricle_sample.plot();

	Message message_quit(Point(-9 + 1, 8 - square_length * 4 - 1), "Quit");
	cwin << message_quit;
}

