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

#ifndef CCC_X11_H
#define CCC_X11_H

#define Time X11_TIME    // so that Time class doesn't conflict with #typedef
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/Xos.h>
#undef Time

using namespace std;

#include "ccc_shap.h"

/**
   A conduit to a display window.
*/
class GraphicWindow
{
public:
   /**
      Default constructor. Constructs a window with the standard 
      coordinate system with corners (-10, -10) and (10, 10).
   */
   GraphicWindow();
   /**
      Sets the coordinate system of this window.
      @param x1 the minimum x-value
      @param y1 the minimum y-value
      @param x2 the maximum x-value
      @param y2 the maximum y-value
   */
   void coord(double xmin, double ymin, double xmax, double ymax);
   /**
      Recycles resources used by this window.
   */
   void close();
   /**
      Clears this window.
   */
   void clear();
   /**
      Puts the image of the pixmap onto the display screen.
   */
   void repaint();
   /**
      Displays a point on this window.
      @param p the point to display (as a small circle)
      @return a reference to this window
   */
   GraphicWindow& operator<<(Point p);
   /**
      Displays a circle on this window.
      @param c the circle to display
      @return a reference to this window
   */
   GraphicWindow& operator<<(Circle c);
   /**
      Displays a line on this window.
      @param l the line to display
      @return a reference to this window
   */
   GraphicWindow& operator<<(Line l);
   /**
      Displays a message on this window.
      @param m the message to display
      @return a reference to this window
   */
   GraphicWindow& operator<<(Message m);
   /**
      Prompts the user for a string.
      @param s the prompt text
      @return the string that the user entered.
   */
   string get_string(string s);
   /**
      Prompts the user for an integer.
      @param s the prompt text
      @return the number that the user entered
   */
   int get_int(const string& out_string);
   /**
      Prompts the user for a floating-point value.
      @param s the prompt text
      @return the number that the user entered
   */
   double get_double(const string& out_string);
   /**
      Prompts the user to click on a point.
      @param s the prompt text
      @return the point on which the user clicked.
   */
   Point get_mouse(string outstr);
   /** 
      Open the window and attach it to X window
      @param d the display
      @param w the window
   */
   void open(Display* d, Window w);
private:
   /**
      Scales an x-coordinate from user to display coordinates.
      @param x a coordinate position in user coordinates
      @return the scaled coordinate
   */
   int user_to_disp_x(double x) const;
   /**
      Scales a y-coordinate from user to display coordinates.
      @param y a coordinate position in user coordinates
      @return the scaled coordinate
   */
   int user_to_disp_y(double y) const;
   /**
      Scales an x-distance from user to display coordinates.
      @param dx a difference between coordinate positions in user coordinates
      @return the scaled coordinate
   */
   int user_to_disp_dx(double x) const;
   /**
      Scales an y-distance from user to display coordinates.
      @param dx a difference between coordinate positions in user coordinates
      @return the scaled coordinate
   */
   int user_to_disp_dy(double y) const;
   /**
      Scales an x-coordinate from display to user coordinates.
      @param x a coordinate position in display coordinates
      @return the scaled coordinate
   */
   double disp_to_user_x(int x) const;
   /**
      Scales an y-coordinate from display to user coordinates.
      @param y a coordinate position in display coordinates
      @return the scaled coordinate
   */
   double disp_to_user_y(int y) const;
   /**
      Displays a prompt on the status line.
      @param s the prompt
   */
   void statusline_prompt(string s);
   /**
      Plots a point.
      @param x the x-coordinate of the point
      @param y the y-coordinate of the point
   */
   void point(double x, double y);
   /**
      Plots a line.
      @param xfrom the x-coordinate of the starting point
      @param yfrom the y-coordinate of the starting point
      @param xto the x-coordinate of the ending point
      @param yto the y-coordinate of the ending point
   */
   void line(double xfrom, double yfrom, double xto, double yto);
   /**
      Plots a line.
      @param x the x-coordinate of the center point
      @param y the y-coordinate of the center point
      @param rx the radius in x-direction
      @param ry the radius in y-direction
   */
   void ellipse(double x, double y, double ra, double rb);
   /**
      Plots text.
      @param t the text string
      @param x the x-coordinate of the top left corner point
      @param y the y-coordinate of the top left corner point
   */
   void text(const char t[], double x, double y);
   /**
      Echoes user input.
      @param instr the user input
      @param str_x the x-coordinate of the string start
      @param curr_x the x-coordinate of the cursor
   */
   int put_string(const char instr[], int str_x, int curr_x);

   string _display_string; // string displayed to user at top
   double _user_xmin; // the user's window's logical window coords
   double _user_ymin; // min is upper left   
   double _user_xmax; // max lower right 
   double _user_ymax; 
   int _disp_xmax; // the physical window dimension (in pixels)
   int _disp_ymax;

   XFontStruct* _fontinfo_ptr; // points to font info for all fonts used
   Pixmap _ppm;

   Window win; 
   Display* display;
   int screen_num;
   GC xgc;
};

extern GraphicWindow cwin;

#endif
