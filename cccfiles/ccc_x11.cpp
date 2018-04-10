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

/*

NOTE TO STUDENTS: Do not attempt to study the contents of this file. You
can, and should, use the services provided in this file without knowing
the highly technical details of the implementation.

*/

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "ccc_x11.h"

/* CONSTANTS ****************************************************************/

const double DEFAULT_XMIN = -10;
const double DEFAULT_YMIN = 10;
const double DEFAULT_XMAX = 10;
const double DEFAULT_YMAX = -10;

static int DEF_WIDTH = 480;
static int DEF_HEIGHT = 480;

// The following is an alias for an X11 font. 
// Make sure this is available on your system.  Substitute as necessary.
// Run xfontsel to get a font string.
#define SYS_FONT_NAME  "-adobe-courier-bold-r-normal-*-*-120-*-*-*-*-*-*"

/* Our program wrapper. */
extern int ccc_win_main();

GraphicWindow cwin;

/**************************************************************************/

GraphicWindow::GraphicWindow()
:  _user_xmin(DEFAULT_XMIN), _user_ymin(DEFAULT_YMIN), 
   _user_xmax(DEFAULT_XMAX), _user_ymax(DEFAULT_YMAX),
   _disp_xmax(DEF_WIDTH), _disp_ymax(DEF_HEIGHT)
{
}

void GraphicWindow::open(Display* d, Window w)
{  
   display = d;
   win = w;
   screen_num = DefaultScreen(display);

   XGCValues xgc_values;  // ignored
   xgc = XCreateGC(display, win, 0, &xgc_values);

   //   specify black foreground since default window background is
   //   white and default foreground is undefined.
   XSetForeground(display, xgc, BlackPixel(display, screen_num));

   // set line attributes.  This class only uses rounded styles.
   XSetLineAttributes(display, xgc, 2 /* pen thickness */, LineSolid,
         CapRound, JoinRound);

   // set up the font - uses only 14pt bold Courier
   _fontinfo_ptr = XLoadQueryFont(display, SYS_FONT_NAME);
   if (_fontinfo_ptr == NULL)
   {   cerr << "Unable to initialize font: " << SYS_FONT_NAME << endl;
      exit(1);
    }
   XSetFont(display, xgc, _fontinfo_ptr->fid);

   // sets the rop mode, using Copy for the user prompts
   XSetFunction(display, xgc, GXcopy /*0x3 COPY*/);

   _ppm = XCreatePixmap(display, win, DEF_WIDTH, DEF_HEIGHT, 
      DefaultDepth(display, screen_num));

   clear();
}

void GraphicWindow::close()
{
   XFreePixmap(display, _ppm);
   XFreeFont(display, _fontinfo_ptr);
}

void GraphicWindow::repaint()
{  
   XCopyArea(display, _ppm, win, xgc, 0, 0, DEF_WIDTH, DEF_HEIGHT, 0, 0);
}

void GraphicWindow::clear()
{
   XClearWindow(display, win);

   XGCValues vals;
   XGetGCValues(display, xgc, GCForeground, &vals);
   unsigned long color = WhitePixel(display, screen_num);
   unsigned long fg = vals.foreground;
   XSetForeground(display, xgc, color);
   XFillRectangle(display, _ppm, xgc, 0, 0, DEF_WIDTH + 1, DEF_HEIGHT + 1);
   XSetForeground(display, xgc, fg);
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
   return (int) ((x - _user_xmin) * _disp_xmax / (_user_xmax - _user_xmin));
}

int GraphicWindow::user_to_disp_y(double y) const
{  
   return (int) ((y - _user_ymin) * _disp_ymax / (_user_ymax - _user_ymin)); 
}

int GraphicWindow::user_to_disp_dx(double x) const
{  
   return (int) (x * _disp_xmax / (_user_xmax - _user_xmin));
}

int GraphicWindow::user_to_disp_dy(double y) const
{  
   return (int) (y * _disp_ymax / (_user_ymax - _user_ymin));
}

double GraphicWindow::disp_to_user_x(int x) const
{  
   return (double)x * (_user_xmax - _user_xmin) / _disp_xmax + _user_xmin;
}

double GraphicWindow::disp_to_user_y(int y) const
{  
   return (double)y * (_user_ymax - _user_ymin) / _disp_ymax + _user_ymin;
}

void GraphicWindow::point(double x, double y)
{  
   const int POINT_RADIUS = 3;
   int disp_x = user_to_disp_x(x);
   int disp_y = user_to_disp_y(y);

   XSetForeground(display, xgc, BlackPixel(display, screen_num));
   XDrawArc(display, win, xgc, disp_x - POINT_RADIUS, disp_y - POINT_RADIUS,
      2 * POINT_RADIUS, 2 * POINT_RADIUS, 0 , 360 * 64);
   XDrawArc(display, _ppm, xgc, disp_x - POINT_RADIUS,
      disp_y - POINT_RADIUS, 2 * POINT_RADIUS, 2 * POINT_RADIUS, 0 , 360 * 64);
}

void GraphicWindow::ellipse(double x, double y, double ra, double rb)
{  
   int disp_x = user_to_disp_x(x);
   int disp_y = user_to_disp_y(y);
   int disp_rx = abs(user_to_disp_dx(ra));
   int disp_ry = abs(user_to_disp_dy(rb));

   XSetForeground(display, xgc, BlackPixel(display, screen_num));
   XDrawArc(display, win, 
      xgc,               // the drawable
      disp_x - disp_rx,  // the x coord of upperleft corner of bounding rect
      disp_y - disp_ry,  // the y coord of upperleft corner of bounding rect
      disp_rx * 2,       // the major axis length
      disp_ry * 2,       // the minor axis length
      0,                 // offset from 3 o'clock  
      360 * 64);         // complete circle (360 degrees * 64 clicks per degree)
   XDrawArc(display, _ppm, xgc, disp_x - disp_rx, 
   disp_y - disp_ry, disp_rx * 2, disp_ry * 2, 0, 360 * 64);
}

void GraphicWindow::line(double xfrom, double yfrom, double xto,
   double yto) 
{  
   XSetForeground(display, xgc, BlackPixel(display, screen_num));
   XDrawLine(display, win, xgc, user_to_disp_x(xfrom), user_to_disp_y(yfrom),
      user_to_disp_x(xto), user_to_disp_y(yto));
   XDrawLine(display, _ppm, xgc, user_to_disp_x(xfrom),
      user_to_disp_y(yfrom), user_to_disp_x(xto), user_to_disp_y(yto));
}

void GraphicWindow::text(const char t[], double x, double y)
{  
   int direction, ascent, descent;
   XCharStruct overall;
   XTextExtents(_fontinfo_ptr, t, strlen(t), &direction, &ascent, &descent, &overall);

   int disp_x = user_to_disp_x(x);
   int disp_y = user_to_disp_y(y) + ascent;

   XSetForeground(display, xgc, BlackPixel(display, screen_num));
   XDrawString(display, win, xgc, disp_x, disp_y, t, strlen(t));
   XDrawString(display, _ppm, xgc, disp_x, disp_y, 
      t, strlen(t));
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{  
   point(p.get_x(), p.get_y());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c)
{  
   ellipse (c.get_center().get_x(), 
      c.get_center().get_y(),
      c.get_radius(),
      c.get_radius());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message m)
{  
   _display_string = m.get_text();
   text(_display_string.c_str(), m.get_start().get_x(), m.get_start().get_y());

   return *this;
}

GraphicWindow& GraphicWindow::operator<< (Line l)
{  
   line(l.get_start().get_x(), l.get_start().get_y(), 
       l.get_end().get_x(), l.get_end().get_y());
   return *this;
}


void GraphicWindow::statusline_prompt(string s)
{  
   int direction, ascent, descent;
   XCharStruct overall;
   const char* t = s.c_str();
   XTextExtents(_fontinfo_ptr, t, strlen(t), 
      &direction, &ascent, &descent, &overall);
  
   XSetBackground(display, xgc, WhitePixel(display, screen_num));

   XClearArea(display, win, 
                0,
                0, /*clear from top*/
                0 /*clear to right edge of screen*/, 
                ascent + descent, 
                0 /* generate exposure events */);

   XDrawImageString(display, win, xgc, 0, ascent, t, strlen(t));
   XDrawImageString(display, _ppm, xgc, 0, ascent, t, strlen(t)); 
}

Point GraphicWindow::get_mouse(string outstr)
{  
   XEvent report;
   Point p;
   int x, y;

   cwin.statusline_prompt(outstr);   

   // Event Loop
   while (true)
   {
      XNextEvent(display, &report);
      switch(report.type)
      {
         case Expose:
             cwin.repaint();
             break;

         case ButtonPress:
            if (report.xbutton.button == Button1)
            {
               x = report.xbutton.x;
               y = report.xbutton.y;
               p = Point(cwin.disp_to_user_x(x), cwin.disp_to_user_y(y));
               cwin.statusline_prompt(outstr);
               return p;               
            }
       }
   }

   return p; // to keep compiler happy, will never get here!
}
                

/***************************************************************************/

int GraphicWindow::put_string(const char instr[], int str_x, int curr_x)
{  
   int direction, ascent, descent;
   XCharStruct overall;
   XTextExtents(_fontinfo_ptr, instr, strlen(instr), &direction, &ascent, &descent, &overall);

   XClearArea(display, win, 
      str_x - 1,
      0, /*clear from top*/
      curr_x + 1, /*clear to right edge of screen*/ 
      ascent + descent + 1, 
      0 /* generate exposure events */);

   XSetForeground(display, xgc, BlackPixel(display, screen_num));
   XDrawImageString(display, win, xgc, str_x, ascent, instr, strlen(instr));
   curr_x = str_x + overall.width;
   /* redraw cursor */
   XDrawLine(display, win, xgc, curr_x, 0, curr_x, ascent + descent);
   return curr_x;
}

/***************************************************************************/

string GraphicWindow::get_string(string outstr)
{  
   XEvent report;
   string instring;
   char instr[50];
   char buffer[3];
   int   buffsize = 3;
   KeySym keysym;
   XComposeStatus compose;
   int count, length;

   int str_x;        // initial x position, at the end of the prompt string
   int str_y;        // initial yposition
   int curr_x;       // current x position (measured from str_x)

   int direction;    // draw chars l->r
   int ascent;       // above font's baseline
   int descent;      // below font's baseline
   XCharStruct overall;

   _display_string=outstr;

   statusline_prompt(outstr);

   XTextExtents(_fontinfo_ptr, _display_string.c_str(), 
      _display_string.length(), &direction, &ascent, &descent, &overall);

   str_x = overall.width; 
   curr_x = overall.width;
   str_y = ascent;   // set initial cursor position 

   instr[0] = '\0';
   curr_x = put_string(instr, str_x, curr_x);

   //Event loop
   while(1)
   {
      XNextEvent(display, &report);
      switch (report.type)
      {
         case Expose:
             cwin.repaint();
             break;

         case KeyPress:
            /* get characters until carriage return */
            count = XLookupString(&(report.xkey), buffer, 
               buffsize, &keysym, &compose);
            /* got a carriage return */
            if ((keysym == XK_Return) || (keysym == XK_KP_Enter)
                || (keysym == XK_Linefeed))
            {
                 XClearArea(display, win, 
                            0,
                            0, /*clear from top*/
                            0, /*clear to right edge of screen*/ 
                            ascent + descent + 1, 
                            0 /* generate expoure events */);

                 instring = instr;
                 return instring;
            }

            /* eat white space */
            else if (((keysym >= XK_KP_Space) && (keysym <= XK_KP_9))
                     || ((keysym >= XK_space) && (keysym <= XK_asciitilde)))
            {
               if ((strlen(instr) + strlen(buffer)) >= 50)
                  XBell(display, 100);
               else
               {
                  buffer[1] = '\0';
                  strcat (instr, buffer);
               }
            }

            /* got a delete key */
            else if ((keysym == XK_BackSpace) || (keysym == XK_Delete))
            {
                if ((length = strlen(instr)) > 0)
                {  
                   // resize the string 
                   instr[length-1] = '\0';
                }
                else 
                    XBell(display, 100);
            }            

            /* display the new string, and reposition cursor */     
            curr_x = put_string(instr, str_x, curr_x);
      }
   }
   return instring; // never get here but it keeps compiler happy :)!
}

int GraphicWindow::get_int(const string& out_string) 
{     
   return atoi(get_string(out_string).c_str()); 
}

double GraphicWindow::get_double(const string& out_string) 
{  
   return atof(get_string(out_string).c_str()); 
}

#define BITMAPDEPTH 1
#define TOO_SMALL 0
#define BIG_ENOUGH 1

/***************************************************************************/

int main(int argc, char** argv)
{  
   // The usual X overhead...
   unsigned int width, height;   // window size
   unsigned int border_width = 4;

   char* window_name = argv[0];
   char* icon_name = (char*) "GCT";

   Pixmap icon_pixmap;
   XSizeHints* size_hints;
   XWMHints* wm_hints;
   XClassHint* class_hints;
   XTextProperty windowName;
   XTextProperty iconName;
   XEvent report;
   int window_size_ok = 1;
   char* display_name = 0;
   char* progname = argv[0];
   Window win; 
   Display* display;
   int screen_num;

   // check allocation of hints
   if (!(size_hints = XAllocSizeHints())
      || !(wm_hints = XAllocWMHints())
      || !(class_hints = XAllocClassHint()))
   {  
      cerr << progname << " error: failure allocating memory" << endl;
      exit(-1);
   }

   progname = argv[0];

   // connect to X server
   display = XOpenDisplay(display_name);
   if (display == NULL)
   {  
      cerr << progname << " error: can't connect to server " <<
         XDisplayName(display_name) << endl;
      exit(-1);
   }

   // get screen size from display structure macro
   screen_num = DefaultScreen(display);

   win = XCreateSimpleWindow(display, RootWindow(display, screen_num),
      0, 0, DEF_WIDTH, DEF_HEIGHT, border_width, BlackPixel(display,
      screen_num), WhitePixel(display, screen_num));

   if (XStringListToTextProperty(&window_name, 1, &windowName) == 0)
   {  
      cerr << progname
         << " error: structure allocation for windowName failed."
         << endl;
      exit(-1);
   }

   if (XStringListToTextProperty(&icon_name, 1, &iconName) == 0) 
   {  
      cerr << progname
         << " error: structure allocation for iconName failed."
         << endl;
      exit(-1);
   }

   size_hints->flags = PPosition | PSize | PMinSize;
   size_hints->min_width = DEF_WIDTH;
   size_hints->min_height = DEF_HEIGHT;

   wm_hints->initial_state = NormalState;
   wm_hints->input = True;
   wm_hints->icon_pixmap = icon_pixmap;
   wm_hints->flags = StateHint | IconPixmapHint | InputHint;

   class_hints->res_name = progname;
   class_hints->res_class = (char*) "chigcx";

   XSetWMProperties(display, win, &windowName, &iconName, argv, argc,
      size_hints, wm_hints, class_hints);

   // Select desired event types
   XSelectInput(display, win, ExposureMask | KeyPressMask
      | ButtonPressMask);

   // Highly intuitive way to state that we can process "delete window"
   Atom delete_atom = XInternAtom(display, "WM_DELETE_WINDOW", false);
   XSetWMProtocols(display, win, &delete_atom, 1);

   XMapWindow(display, win);

   cwin.open(display, win);

   // Event loop
   int draw_flag = 1;
   while (true)
   {  
      XNextEvent(display, &report);
      switch ((int)report.type)
      {  
         case Expose:
            if (report.xexpose.count == 0)
            {  
               if (window_size_ok)
               {  
                  if (draw_flag)
                  {  
                     ccc_win_main();
                     draw_flag = 0;
                  }
                  else
                     cwin.repaint();
               }
            }
            break;

         case ConfigureNotify:
            /* 
               window has been resized, change width and
               height to send to draw_text and draw_graphics
               in next Expose 
            */
            width = report.xconfigure.width;
            height = report.xconfigure.height;
            window_size_ok = (width >= size_hints->min_width)
               && (height >= size_hints->min_height);
            break;

         case ClientMessage:
            if (report.xclient.data.l[0] == delete_atom)
            {
               cwin.close();
               exit(0);
            }
            break;
         case ButtonPress:
         case KeyPress:
         default:
            break;
      }
   }
   return 0;
}
