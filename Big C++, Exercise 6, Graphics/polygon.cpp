#include "polygon.h"
#include <math.h>


polygon::polygon()
{
}

void polygon::add_point(Point p)
{
	corners.push_back(p);
}

void polygon::plot() const
{
	Line temp;
	for (int i = 0, n = corners.size(); i < n; i++)
	{
		temp = Line(corners[i], corners[(i + 1) % n]); // wrap the index To get the 4 points
		cwin << temp;
	}
	
}

double polygon::perimeter() const
{
	double Perimeter = 0, x1, x2, y1, y2;
	int n = corners.size();
	for (int i = 0; i < n; i++)
	{
		x1 = corners[i].get_x();
		x2 = corners[(i + 1) % n].get_x(); // wrap the index
		y1 = corners[i].get_y();
		y2 = corners[(i + 1) % n].get_y();
		Perimeter += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}	
	return Perimeter;
}

double polygon::area() const
{
	double Area_pos = 0, Area_neg = 0, Area;
	int n = corners.size();
	double x, y;
	for (int i = 0; i < n; i++)
	{
		x = corners[i].get_x();
		y = corners[(i + 1) % n].get_y();
		Area_pos += x * y;

		x = corners[(i + 1) % n].get_x();
		y = corners[i].get_y();
		Area_neg -= x * y;
	}
	Area = (Area_pos - Area_neg);
	return 0.5 * Area;
}

void polygon::move(double dx, double dy)
{
	int n = corners.size();
	for (int i = 0; i < n; i++)
		corners[i].move(dx, dy);
}

void polygon::scale(double factor)
{
	for (int i = 0, n = corners.size(); i < n; i++)
	{
		corners[i].set_x(corners[i].get_x() * factor);
		corners[i].set_y(corners[i].get_y() * factor);
	}
}
