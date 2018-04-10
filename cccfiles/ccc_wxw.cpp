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

#include <wx/wx.h>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <csetjmp>
#include <cstdio>
#include <iostream>

#include "ccc_wxw.h"

/*-------------------------------------------------------------------------*/

const double DEFAULT_XMIN = -10;
const double DEFAULT_YMIN = 10;
const double DEFAULT_XMAX = 10;
const double DEFAULT_YMAX = -10;

const int ID_TEXT = 1000;

/*-------------------------------------------------------------------------*/

/**
   A window onto which the graphics output is painted.
*/
class GraphicCanvas : public wxWindow
{
public:
   /**
      Initializes the base class.
      @param parent the parent window
   */
   GraphicCanvas(wxWindow* parent);
   void OnPaint(wxPaintEvent& event);
   void OnSize(wxSizeEvent& event);
   void OnMouseEvent(wxMouseEvent& event);
   /**
      Clears the window.
   */
   void clear();
   /**
      Sets the coordinate system.
      @param x1 the minimum x-value
      @param y1 the minimum y-value
      @param x2 the maximum x-value
      @param y2 the maximum y-value
   */
   void coord(double xmin, double ymin, double xmax, double ymax);
   /**
      Adds a point to the set of shapes that need to be displayed.
      @param s the point to add
   */
   void add(Point s);
   /**
      Adds a circle to the set of shapes that need to be displayed.
      @param s the circle to add
   */
   void add(Circle s);
   /**
      Adds a line to the set of shapes that need to be displayed.
      @param s the line to add
   */
   void add(Line s);
   /**
      Adds a message to the set of shapes that need to be displayed.
      @param s the message to add
   */
   void add(Message s);
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
      Draws a point
      @param dc the device context
      @param s the point to draw
   */
   void draw(wxDC& dc, Point s);
   /**
      Draws a circle
      @param dc the device context
      @param s the circle to draw
   */
   void draw(wxDC& dc, Circle s);
   /**
      Draws a line
      @param dc the device context
      @param s the line to draw
   */
   void draw(wxDC& dc, Line s);
   /**
      Draws a message
      @param dc the device context
      @param s the message to draw
   */
   void draw(wxDC& dc, Message s);

   double _user_xmin; // the user's window's logical window coords
   double _user_xmax;
   double _user_ymin;
   double _user_ymax;
   int _disp_xmax; // the physical window dimension (in pixels)
   int _disp_ymax;
   int _disp_xoff;
   int _disp_yoff;

   vector<Point> points;
   vector<Line> lines;
   vector<Circle> circles;
   vector<Message> messages;

   DECLARE_EVENT_TABLE()
};

/**
   A frame with a window that shows the graphical output.
*/
class GraphicFrame : public wxFrame
{
public:
   /**
      Constructs the window.
   */
   GraphicFrame(const wxString& appName);
   /**
      Runs the ccc_win_main function.
   */
   void run();
   void set_text_focus(bool b);
   void OnEnter(wxCommandEvent& event);

private:
   wxTextCtrl* text;
   GraphicCanvas* window;

   DECLARE_EVENT_TABLE()
};

/**
   An application that generates a simple painting.
*/
class GraphicApp : public wxApp
{
public:
   /**
      Constructs the frame.
   */
   GraphicApp();
   virtual bool OnInit();
private:
   GraphicFrame* frame;
};

DECLARE_APP(GraphicApp)

GraphicWindow cwin;

IMPLEMENT_APP(GraphicApp)

BEGIN_EVENT_TABLE(GraphicCanvas, wxWindow)
   EVT_PAINT(GraphicCanvas::OnPaint)
   EVT_SIZE(GraphicCanvas::OnSize)
   EVT_MOUSE_EVENTS(GraphicCanvas::OnMouseEvent)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(GraphicFrame, wxFrame)
   EVT_TEXT_ENTER(ID_TEXT, GraphicFrame::OnEnter)
END_EVENT_TABLE()

/*-------------------------------------------------------------------------*/

GraphicCanvas::GraphicCanvas(wxWindow* parent)
   : wxWindow(parent, -1)
{
   _user_xmin = DEFAULT_XMIN;
   _user_xmax = DEFAULT_XMAX;
   _user_ymin = DEFAULT_YMIN;
   _user_ymax = DEFAULT_YMAX;
}

void GraphicCanvas::clear()
{
   points.clear();
   lines.clear();
   circles.clear();
   messages.clear();
}

void GraphicCanvas::add(Point s)
{
   points.push_back(s);
}

void GraphicCanvas::add(Circle s)
{
   circles.push_back(s);
}

void GraphicCanvas::add(Line s)
{
   lines.push_back(s);
}

void GraphicCanvas::add(Message s)
{
   messages.push_back(s);
}

void GraphicCanvas::OnSize(wxSizeEvent& event)
{
   wxSize size = GetSize();
   int width = size.GetWidth();
   int height= size.GetHeight();
   int sz = width < height ? width : height;
   _disp_xmax = sz;
   _disp_ymax = sz;
   _disp_xoff = (width - sz) / 2;
   _disp_yoff = (height - sz) / 2;
}

void GraphicCanvas::OnPaint(wxPaintEvent& event)
{
   wxPaintDC dc(this);
   dc.SetBrush(*wxTRANSPARENT_BRUSH);

   for (int i = 0; i < points.size(); i++)
      draw(dc, points[i]);
   for (int i = 0; i < lines.size(); i++)
      draw(dc, lines[i]);
   for (int i = 0; i < circles.size(); i++)
      draw(dc, circles[i]);
   for (int i = 0; i < messages.size(); i++)
      draw(dc, messages[i]);
}

void GraphicCanvas::OnMouseEvent(wxMouseEvent& event)
{
   if (event.ButtonDown())
      cwin.mouse_input(Point(disp_to_user_x(event.GetX()), 
         disp_to_user_y(event.GetY())));
}

int GraphicCanvas::user_to_disp_x(double x) const
{  
   return (int) (_disp_xoff + (x - _user_xmin) * _disp_xmax / (_user_xmax - _user_xmin));
}

int GraphicCanvas::user_to_disp_y(double y) const
{  
   return (int) (_disp_yoff + (y - _user_ymin) * _disp_ymax / (_user_ymax - _user_ymin));
}

double GraphicCanvas::disp_to_user_x(int x) const
{  
   return (double)(x - _disp_xoff) * (_user_xmax - _user_xmin) / _disp_xmax + _user_xmin;
}

double GraphicCanvas::disp_to_user_y(int y) const
{  
   return (double)(y - _disp_yoff) * (_user_ymax - _user_ymin) / _disp_ymax + _user_ymin;
}

void GraphicCanvas::draw(wxDC& dc, Point s)
{
   const int POINT_RADIUS = 3;
   int disp_x = user_to_disp_x(s.get_x());
   int disp_y = user_to_disp_y(s.get_y());
   dc.DrawEllipse(disp_x - POINT_RADIUS, disp_y - POINT_RADIUS, 
      2 * POINT_RADIUS, 2 * POINT_RADIUS);
}

void GraphicCanvas::draw(wxDC& dc, Circle s)
{
   int disp_x1 = user_to_disp_x(s.get_center().get_x() - s.get_radius());
   int disp_y1 = user_to_disp_y(s.get_center().get_y() - s.get_radius());
   int disp_x2 = user_to_disp_x(s.get_center().get_x() + s.get_radius());
   int disp_y2 = user_to_disp_y(s.get_center().get_y() + s.get_radius());

   dc.DrawEllipse(disp_x1, disp_y1, disp_x2 - disp_x1, disp_y2 - disp_y1);
}

void GraphicCanvas::draw(wxDC& dc, Line s)
{
   int disp_x1 = user_to_disp_x(s.get_start().get_x());
   int disp_y1 = user_to_disp_y(s.get_start().get_y());
   int disp_x2 = user_to_disp_x(s.get_end().get_x());
   int disp_y2 = user_to_disp_y(s.get_end().get_y());
   dc.DrawLine(disp_x1, disp_y1, disp_x2, disp_y2);
}

void GraphicCanvas::draw(wxDC& dc, Message s)
{
   int disp_x = user_to_disp_x(s.get_start().get_x());
   int disp_y = user_to_disp_y(s.get_start().get_y());
   string text = s.get_text();
   wxString msg(text.c_str(), wxConvLocal);
   dc.DrawText(msg, disp_x, disp_y);
}

void GraphicCanvas::coord(double xmin, double ymin,
   double xmax, double ymax)
{  
   _user_xmin = xmin;
   _user_xmax = xmax;
   _user_ymin = ymin;
   _user_ymax = ymax;
}

/*-------------------------------------------------------------------------*/

GraphicWindow::GraphicWindow()
{
   canvas = NULL;
   frame = NULL;
   waiting_for_mouse_input = false;
   waiting_for_string_input = false;
}

void GraphicWindow::open(GraphicFrame* f, GraphicCanvas* c)
{
   frame = f;
   canvas = c;
   canvas->clear();
   string_input_count = 0;
   mouse_input_count = 0;
}

void GraphicWindow::coord(double xmin, double ymin,
   double xmax, double ymax)
{  
   canvas->coord(xmin, ymin, xmax, ymax);
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{  
   canvas->add(p);
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c)
{ 
   canvas->add(c);
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Line s)
{  
   canvas->add(s);
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message t)
{  
   canvas->add(t);
   return *this;
}

int GraphicWindow::get_int(const string& out_string) 
{  
   return atoi(get_string(out_string).c_str()); 
}

double GraphicWindow::get_double(const string& out_string) 
{  
   return atof(get_string(out_string).c_str()); 
}

jmp_buf buf;

string GraphicWindow::get_string(string outstr)
{
   string_input_count++;
   if (string_input_count <= string_inputs.size())
      return string_inputs[string_input_count - 1];
   else
   {
      waiting_for_string_input = true;
      frame->SetStatusText(wxString(outstr.c_str(), wxConvLocal));
      frame->set_text_focus(true);
      longjmp(buf, 1);
      return ""; 
   }
}

Point GraphicWindow::get_mouse(string outstr)
{
   mouse_input_count++;
   if (mouse_input_count <= mouse_inputs.size())
      return mouse_inputs[mouse_input_count - 1];
   else 
   {
      waiting_for_mouse_input = true;
      frame->SetStatusText(wxString(outstr.c_str(), wxConvLocal));
      longjmp(buf, 1);
      return Point(); 
   }
}

void GraphicWindow::mouse_input(Point p)
{
   if (waiting_for_mouse_input)
   {
      mouse_inputs.push_back(p);
      frame->SetStatusText(wxT(""));
      waiting_for_mouse_input = false;
      frame->run();
   }
}

void GraphicWindow::string_input(string s)
{
   if (waiting_for_string_input)
   {
      string_inputs.push_back(s);
      frame->SetStatusText(wxT(""));
      frame->set_text_focus(false);
      waiting_for_string_input = false;
      frame->run();
   }
}

/*-------------------------------------------------------------------------*/

extern int ccc_win_main();

GraphicFrame::GraphicFrame(const wxString& appName) 
   : wxFrame(NULL, -1, appName)
{
   window = new GraphicCanvas(this);
   CreateStatusBar();

   text = new wxTextCtrl(this, ID_TEXT, wxT(""), 
      wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

   wxBoxSizer* frame_sizer = new wxBoxSizer(wxVERTICAL);
   frame_sizer->Add(window, 1, wxGROW);
   frame_sizer->Add(text, 0, wxGROW);

   SetAutoLayout(true);
   SetSizer(frame_sizer);
   Layout();

   run();
}

void GraphicFrame::run()
{
   if (setjmp(buf) == 0)
   { 
      cwin.open(this, window);
      ccc_win_main();
   }
   window->Refresh();
}

void GraphicFrame::set_text_focus(bool b)
{
   if (b) text->SetFocus(); else window->SetFocus();
}

void GraphicFrame::OnEnter(wxCommandEvent& event)
{
   string input(text->GetValue().mb_str());
   text->SetValue(wxT(""));
   cwin.string_input(input);   
}

/*-------------------------------------------------------------------------*/

#ifdef __WXMAC__
struct ProcessSerialNumber 
{
   int highLongOfPSN;
   int lowLongOfPSN;
};

extern "C" 
{ 
   void CPSEnableForegroundOperation(ProcessSerialNumber* psn); 
   void GetCurrentProcess(ProcessSerialNumber* psn);
   void SetFrontProcess(ProcessSerialNumber* psn);
}
#endif


GraphicApp::GraphicApp()
{
/* 
http://www.miscdebris.net/blog/2010/03/30/solution-for-my-mac-os-x-gui-program-doesnt-get-focus-if-its-outside-an-application-bundle/
this hack enables to have a GUI on Mac OSX even if the
     * program was called from the command line (and isn't a bundle) */
#ifdef __WXMAC__

   ProcessSerialNumber psn;
   
   GetCurrentProcess( &psn );
   CPSEnableForegroundOperation( &psn );
   SetFrontProcess( &psn );
#endif
}

bool GraphicApp::OnInit()
{
   frame = new GraphicFrame(GetAppName());
   frame->Show(true);
   return true;
}
