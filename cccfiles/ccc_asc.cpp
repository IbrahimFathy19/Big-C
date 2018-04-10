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

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "ccc_asc.h"

GraphicWindow cwin;

GraphicWindow::GraphicWindow()
{  
   const double DEFAULT_XMIN = -10;
   const double DEFAULT_YMIN = 10;
   const double DEFAULT_XMAX = 10;
   const double DEFAULT_YMAX = -10;

   _disp_xoff = 0; 
   _disp_yoff = 0;
   _disp_xmax = XSIZE;
   _disp_ymax = YSIZE;

   clear();
   coord(DEFAULT_XMIN, DEFAULT_YMIN, DEFAULT_XMAX, DEFAULT_YMAX);
}

GraphicWindow::~GraphicWindow()
{  
   flush();
}

void GraphicWindow::flush()
{  
   if (!dirty) return;
   for (int y = 0; y < YSIZE; y++)
      cout << g[y] << "\n";
   dirty = false;
}

void GraphicWindow::coord(double xmin, double ymin,
      double xmax, double ymax)
{  
   _user_xmin = xmin;
   _user_xmax = xmax;
   _user_ymin = ymin;
   _user_ymax = ymax;
}

int GraphicWindow::user_to_disp_x(double x) const
{  
   return (int)((x - _user_xmin) * _disp_xmax / (_user_xmax - _user_xmin));
}

int GraphicWindow::user_to_disp_y(double y) const
{  
   return (int)((y - _user_ymin) * _disp_ymax / (_user_ymax - _user_ymin));
}

double GraphicWindow::user_to_disp_dx(double x) const
{  
   return (x * _disp_xmax) / (_user_xmax - _user_xmin);
}

double GraphicWindow::user_to_disp_dy(double y) const
{  
   return (y * _disp_ymax) / (_user_ymax - _user_ymin);
}

double GraphicWindow::disp_to_user_x(int x) const
{  
   return (x - _disp_xoff) * (_user_xmax - _user_xmin) / _disp_xmax + _user_xmin;
}

double GraphicWindow::disp_to_user_y(int y) const
{  
   return (y - _disp_yoff) * (_user_ymax - _user_ymin) / _disp_ymax + _user_ymin;
}

void GraphicWindow::set(int x, int y)
{  
   if (0 <= x && x <= XSIZE && 0 <= y && y < YSIZE)
      g[y][x] = '*';
}

void GraphicWindow::set(int x, int y, char ch)
{  
   if (0 <= x && x < XMAXSIZE && 0 <= y && y < YSIZE)
      g[y][x] = ch;
}

void GraphicWindow::point(double x, double y)
{  
   int cx = user_to_disp_x(x);
   int cy = user_to_disp_y(y);
   
   set(cx, cy);
   dirty = true;
}

//............................................................................

void GraphicWindow::line(double xfrom, double yfrom, double xto, double yto)
{  
   int x1 = user_to_disp_x(xfrom);
   int x2 = user_to_disp_x(xto);
   int y1 = user_to_disp_y(yfrom);
   int y2 = user_to_disp_y(yto);
   
   int dx = x2 - x1;
   int dy = y2 - y1;
   if (abs(dy) < abs(dx)) // |slope| < 1
   {  
      if (dx < 0) 
      {  
         int temp = x1; x1 = x2; x2 = temp;
         temp = y1; y1 = y2; y2 = temp;
         dx = -dx; dy = -dy;
      }
      double y = y1 + 0.5;
      for (int x = x1; x != x2; x++)
      {  
         set(x, int(y));
         y += double(dy) / double(dx);
      }
   }
   else
   {  
      if (dy < 0) 
      {  
         int temp = x1; x1 = x2; x2 = temp;
         temp = y1; y1 = y2; y2 = temp;
         dx = -dx; dy = -dy;
      }
      double x = x1 + 0.5;
      for (int y = y1; y != y2; y++)
      {  
         set(int(x), y);
         x += double(dx) / double(dy);
      }
   }
   set(x2, y2);

   dirty = true;
}

//............................................................................

void GraphicWindow::clear()
{  
   for (int y = 0; y < YSIZE; y++)
   {  
      for (int x = 0; x < XMAXSIZE; x++)
         g[y][x] = ' ';
      g[y][XMAXSIZE] = '\0';
   }
   dirty = false;
}

//............................................................................

void GraphicWindow::set4(int x, int y, int cx, int cy)
{  
   set(cx + x, cy + y);
   set(cx + x, cy - y);
   set(cx - x, cy + y);
   set(cx - x, cy - y);
}

//............................................................................

void GraphicWindow::ellipse(double center_x, double center_y, double ra, double rb)
{  
   int cx = user_to_disp_x(center_x);
   int cy = user_to_disp_y(center_y);
   double a = fabs(user_to_disp_dx(ra));
   double b = fabs(user_to_disp_dy(rb));
   
   int x = 0;
   int y = (int)(b + 0.5);
   double d1 = b * b - a * a * b + a * a / 4;
   set4(x, y, cx, cy);
   
   while (a * a * (y - 0.5) > b * b * (x + 1))
   {  
      if (d1 < 0)
      {  
         d1 += b * b * (2 * x + 3);
         x++;
      }
      else
      {  
         d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
         x++;
         y--;
      }
      set4(x, y, cx, cy);
   }
   
   double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
   while (y > 0)
   {  
      if (d2 < 0)
      {  
         d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
         x++;
         y--;
      }
      else
      {  
         d2 += a * a * (-2 * y + 3);
         y--;
      }
      set4(x, y, cx, cy);
   }

   dirty = true;
}

void GraphicWindow::text(string t, double x, double y)
{  
   int dx = user_to_disp_x(x);
   int dy = user_to_disp_y(y);
   for (int i = 0; i < t.length(); i++) set(dx + i, dy, t[i]);
   dirty = true;
}

GraphicWindow& GraphicWindow::operator<<(Line s)
{  
   line(s.get_start().get_x(), s.get_start().get_y(),
         s.get_end().get_x(), s.get_end().get_y());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message t)
{
   text(t.get_text(), t.get_start().get_x(), t.get_start().get_y());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c)
{
   ellipse(c.get_center().get_x(), c.get_center().get_y(),
         c.get_radius(), c.get_radius());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{  point (p.get_x(), p.get_y());
   return *this;
}

Point GraphicWindow::get_mouse(string s)
{  
   flush();
   cout << s << " [x y] ";
   string sx;
   string sy;
   cin >> sx >> sy;
   return Point(atof(sx.c_str()), atof(sy.c_str()));
}

double GraphicWindow::get_double(const string& prompt) 
{ 
   return atof(get_string(prompt).c_str()); 
}

int GraphicWindow::get_int(const string& prompt) 
{ 
   return atoi(get_string(prompt).c_str()); 
}

string GraphicWindow::get_string(string s)
{  
   flush();
   cout << s;
   string r;
   getline(cin, r);
   return r;
}

extern int ccc_win_main();

int main()
{
   return ccc_win_main();
}
