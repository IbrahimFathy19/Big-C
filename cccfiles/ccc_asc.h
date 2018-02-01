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

#ifndef CCC_ASC_H
#define CCC_ASC_H

#include "ccc_shap.h"

class GraphicWindow
{
public:
   /**
      Default constructor. Constructs a window with the standard 
      coordinate system with corners (-10, -10) and (10, 10).
   */
   GraphicWindow();
   /**
      The destructor flushes any accumulated output.
   */
   ~GraphicWindow();

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
   GraphicWindow& operator<<(Line s);
   /**
      Displays a message on this window.
      @param t the message to display
      @return a reference to this window
   */
   GraphicWindow& operator<<(Message t);

   /**
      Prompts the user for a string.
      @param s the prompt text
      @return the string that the user entered.
   */
   string get_string(string prompt);
   /**
      Prompts the user for a floating-point value.
      @param s the prompt text
      @return the number that the user entered
   */
   double get_double(const string& prompt); 
   /**
      Prompts the user for an integer.
      @param s the prompt text
      @return the number that the user entered
   */
   int get_int(const string& prompt); 
   /**
      Prompts the user to click on a point.
      @param s the prompt text
      @return the point on which the user clicked.
   */
   Point get_mouse(string prompt);

   /**
      Sets the coordinate system of this window.
      @param x1 the minimum x-value
      @param y1 the minimum y-value
      @param x2 the maximum x-value
      @param y2 the maximum y-value
   */
   void coord(double xmin, double ymin, double xmax, double ymax);
   /**
      Clears this window.
   */
   void clear();
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
   double user_to_disp_dx(double x) const;
   /**
      Scales an y-distance from user to display coordinates.
      @param dx a difference between coordinate positions in user coordinates
      @return the scaled coordinate
   */
   double user_to_disp_dy(double y) const;
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
   void text(string t, double x, double y);

   /**
      Sets a * character in the grid.
      @param x the display x-coordinate
      @param y the display y-coordinate
   */
   void set(int x, int y);
   /**
      Sets a character in the grid.
      @param x the display x-coordinate
      @param y the display y-coordinate
      @param ch the character to set
   */
   void set(int x, int y, char ch);
   /**
      Sets four * characters in the grid that are spaced 
      around a common center, with offsets applied in positive
      and negative directions. This is a helper function for
      drawing an ellipse.
      @param x the x-offset
      @param y the y-offset
      @param x the display x-coordinate of the center
      @param y the display y-coordinate of the center
   */
   void set4(int x, int y, int cx, int cy);

   /**
      Flushes display if it has changed since the last flush.
   */
   void flush();
   
   double _user_xmin;
   double _user_xmax;
   double _user_ymin;
   double _user_ymax;

   int _disp_xmax;
   int _disp_ymax;
   int _disp_xoff;
   int _disp_yoff;

   enum { XSIZE = 60, YSIZE = 24, XMAXSIZE = 79 };
   /* 
      graphics clipped at 60 (because 60 * 24 is a square region), 
      text clipped at 79
   */

   char g[YSIZE][XMAXSIZE+1];
   bool dirty;
};

extern GraphicWindow cwin;

#endif
