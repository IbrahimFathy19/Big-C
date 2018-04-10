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

#ifndef CCC_WXW_H
#define CCC_WXW_H

#include <vector>

using namespace std;

#include "ccc_shap.h"

class GraphicCanvas;

class GraphicFrame;

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
      Clears this window.
   */
   void clear();

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
      @param s the line to display
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
   string get_string(string out_string);
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
   Point get_mouse(string out_string);
   /**
      Opens the window.
      @param frame the application frame
      @param canvas the canvas to draw on
   */
   void open(GraphicFrame* frame, GraphicCanvas* canvas);
   /**
      Process mouse input.
      @param p the mouse click point 
   */
   void mouse_input(Point p);
   /**
      Process mouse input.
      @param p the string that the user entered.
   */
   void string_input(string p);
private:
   GraphicFrame* frame;
   GraphicCanvas* canvas;
   vector<Point> mouse_inputs;
   int mouse_input_count;
   bool waiting_for_mouse_input;
   vector<string> string_inputs;
   int string_input_count;
   bool waiting_for_string_input;
};

extern GraphicWindow cwin;

#endif
