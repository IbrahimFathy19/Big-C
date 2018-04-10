/*
  CCC Graphics Library
  COPYRIGHT (C) 1994 - 2011 Cay S. Horstmann. All Rights Reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <sstream>

#include "ccc_shap.h"

Point::Point()
{  
   x = 0.0;
   y = 0.0;
}

Point::Point(double x1, double y1)
{  
   x = x1;
   y = y1;
}

double Point::get_x() const
{  
   return x;
}

double Point::get_y() const
{  
   return y;
}

void Point::move(double dx, double dy)
{  
   x += dx;
   y += dy;
}
void Point::set_x(float x1)
{
  x = x1;
}
void Point::set_y(float y1)
{
  y = y1;
}

/*-------------------------------------------------------------------------*/

Circle::Circle()
{  
   radius = 0.0;
}

Circle::Circle(Point p, double r)
{  
   center = p;
   radius = r;
}

Point Circle::get_center() const
{  
   return center;
}

double Circle::get_radius() const
{  
   return radius;
}

void Circle::move(double dx, double dy)
{  
   center.move(dx, dy);
}

/*-------------------------------------------------------------------------*/

Line::Line()
{
}

Line::Line(Point p1, Point p2)
{  
   from = p1;
   to = p2;
}

Point Line::get_start() const
{  
   return from;
}

Point Line::get_end() const
{  
   return to;
}

void Line::move(double dx, double dy)
{  
   from.move(dx, dy);
   to.move(dx, dy);
}

/*-------------------------------------------------------------------------*/

Message::Message()
{}

Message::Message(Point s, const string& m)
{  
   start = s;
   text = m;
}

Message::Message(Point s, double x)
{  
   start = s;
   ostringstream strm;
   strm << x;
   text = strm.str();
}


Point Message::get_start() const
{  
   return start;
}

string Message::get_text() const
{  
   return text;
}

void Message::move(double dx, double dy)
{  
   start.move(dx, dy);
}

