/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include "rectangle.h"
#include "triangle.h"
#include "house.h"
#include "street.h"
#include "cannonball.h"
#define PI 3.14159265

int ccc_win_main()
{
	//Test problem 19 exercise 5
#if 1 
	Cannonball x;
	x.shoot(65,15);



#endif
	//Test problem 18 exercise 5
#if 0
	Point first_house_loc = cwin.get_mouse("click at the top right point of the first house");
	Point second_house_loc = cwin.get_mouse("click at the top right point of the second house");
	int n1 = cwin.get_int("Enter the house number of the first house");
	int n2 = cwin.get_int("Enter the house number of the second house");
	int n = cwin.get_int("Enter the number of houses in the street");
	House first(n1, first_house_loc);
	House last(n2, second_house_loc);
	Street s(first, last, n);
	s.plot();
#endif
	//Test problem 17 exercise 5
#if 0 
	Triangle t(Point(0, 0), Point(1, 2), Point(0, 2));
	Message m(Point(-9, 9), t.get_area());
	cwin  << m;
#endif
	//Test problem 16 exercise 5
#if 0
	Triangle t(Point(-10, -10), Point(-9, -10), Point(-9.5, -9));
	for (int i = 0; i < 20; i++)
	{
		t.plot();
		t.move(1, 0);
		t.plot();
		t.move(0, 1);
	}

#endif
	//Test problem 14 exercise 5
#if 0
	rectangle s(Point(-10, -9), Point(-9, -10));
	for (int i = 0; i < 20; i++)
	{
		s.plot();
		s.move(1, 0);
		s.plot();
		s.move(0, 1);
	}
#endif
	return 0;
}

