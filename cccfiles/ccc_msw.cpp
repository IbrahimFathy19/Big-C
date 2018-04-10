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
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <tchar.h>

using namespace std;

#include "ccc_msw.h"

const double DEFAULT_XMIN = -10;
const double DEFAULT_YMIN = 10;
const double DEFAULT_XMAX = 10;
const double DEFAULT_YMAX = -10;

GraphicWindow cwin;

extern int ccc_win_main();

/*-------------------------------------------------------------------------*/

long FAR PASCAL ccc_win_proc(HWND hwnd, UINT message, UINT wParam, LONG lParam)
{  
   static int paint_flag = 1;   // tells WinProc to call ccc_win_main()
   PAINTSTRUCT ps; // the display's paint struct
   HDC mainwin_hdc;
  
   switch (message)
   {  
      case WM_PAINT:
         mainwin_hdc = BeginPaint(hwnd, &ps);

         if (paint_flag)
         {  
            paint_flag = false;       // flag must be set first in case
            cwin.open(hwnd, mainwin_hdc);
            ccc_win_main();
         }
         else
            cwin.repaint(ps);

         EndPaint(hwnd, &ps);
         break;

      case WM_DESTROY:
         cwin.close();
         exit(0); 
   }
   return DefWindowProc(hwnd, message, wParam, lParam);
}

/*-------------------------------------------------------------------------*/

int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   LPSTR, int nShowCmd)
{  
   MSG msg;
   WNDCLASS wndclass;

   if (!hPrevInstance)
   {  
      wndclass.style = CS_HREDRAW | CS_VREDRAW;
      wndclass.lpfnWndProc = ccc_win_proc;
      wndclass.cbClsExtra = 0;
      wndclass.cbWndExtra = 0;
      wndclass.hInstance = hInstance;
      wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
      wndclass.hCursor = LoadCursor (NULL, IDC_ARROW);
      wndclass.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH);
      wndclass.lpszMenuName = NULL;
      wndclass.lpszClassName = _T("CCC_WIN");

      RegisterClass (&wndclass);
   }

   TCHAR title[80];
   GetModuleFileName(hInstance, title, sizeof(title) / sizeof(title[0]));

   HWND hwnd = CreateWindow(wndclass.lpszClassName,
      title,
      WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
      CW_USEDEFAULT,
      CW_USEDEFAULT,
      GetSystemMetrics(SM_CYFULLSCREEN) * 3 / 4,
      GetSystemMetrics(SM_CYFULLSCREEN) * 3 / 4,
      NULL,
      NULL,
      hInstance,
      0);

   ShowWindow(hwnd, nShowCmd);
   UpdateWindow(hwnd);

   while (GetMessage(&msg, NULL, 0, 0))
   {  
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   return msg.wParam;
}

/*-------------------------------------------------------------------------*/

GraphicWindow::GraphicWindow()
:  _user_xmin(DEFAULT_XMIN),
   _user_ymin(DEFAULT_YMIN),
   _user_xmax(DEFAULT_XMAX),
   _user_ymax(DEFAULT_YMAX)
{}

void GraphicWindow::open(HWND hwnd, HDC mainwin_hdc)
{  
   HINSTANCE hInstance = (HINSTANCE)
      GetWindowLong(hwnd, GWL_HINSTANCE);
   child_hwnd = CreateWindow(_T("static"),
      NULL,
      WS_CHILD | WS_VISIBLE, /* style */
      0,  /* x position */
      0,  /* y position */
      0,  /* width (x) */
      30, /* height (y) */
      hwnd,
      (HMENU)84,  /* child ID */
      hInstance,
      0);

   edit_hwnd  = CreateWindow(_T("edit"),
      NULL,
      WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL, /* style */
      0,  /* x position */
      0,  /* y position */
      0,  /* width (x) */
      30, /* height (y) */
      hwnd,
      (HMENU)85,  /* child ID */
      hInstance,
      0);

   RECT rect;
   GetClientRect(hwnd, &rect);
   _disp_xmax = rect.right - 1;
   _disp_ymax = rect.bottom - 1;

   _hdc = mainwin_hdc;

   SelectObject(_hdc, GetStockObject(NULL_BRUSH));
   SelectObject(_bitmap_hdc, GetStockObject(NULL_BRUSH));

   SelectObject(_hdc, GetStockObject(BLACK_PEN));
   SelectObject(_bitmap_hdc, GetStockObject(BLACK_PEN));

   SelectObject(_hdc, GetStockObject(SYSTEM_FONT));
   SelectObject(_bitmap_hdc, GetStockObject(SYSTEM_FONT));

   _bitmap_xmax = GetSystemMetrics(SM_CXFULLSCREEN);
   _bitmap_ymax = GetSystemMetrics(SM_CYFULLSCREEN);

   HDC hdc = GetDC(hwnd);
   _bitmap_hdc = CreateCompatibleDC(hdc);
   _hbm = CreateCompatibleBitmap(hdc, _bitmap_xmax, _bitmap_ymax);
   ReleaseDC(hwnd, hdc);
   if (!_hbm)
   {  
      MessageBox(hwnd, _T("Memory problems in Bitmap Creation"),
         _T("CCC Error"), MB_ICONHAND);
         SendMessage(hwnd, WM_DESTROY, 0, 0L);
         return;
   }
   _hbm_saved = (HBITMAP)SelectObject(_bitmap_hdc, _hbm);

   clear();
}

void GraphicWindow::clear()
{  
   COLORREF color = RGB(255, 255, 255);
   HBRUSH brush = CreateSolidBrush(color);
   HBRUSH saved_brush = (HBRUSH)SelectObject(_hdc, brush);
   PatBlt(_hdc, 0, 0, _disp_xmax, _disp_ymax, PATCOPY);
   SelectObject(_hdc, saved_brush);
   saved_brush = (HBRUSH)SelectObject(_bitmap_hdc, brush);
   PatBlt(_bitmap_hdc, 0, 0, _bitmap_xmax, _bitmap_ymax, PATCOPY);
   SelectObject(_bitmap_hdc, saved_brush);
   DeleteObject(brush);
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

#undef Ellipse
   Ellipse(_hdc, disp_x - POINT_RADIUS, disp_y - POINT_RADIUS,
      disp_x + POINT_RADIUS, disp_y + POINT_RADIUS);
   Ellipse(_bitmap_hdc, disp_x - POINT_RADIUS, disp_y - POINT_RADIUS,
      disp_x + POINT_RADIUS, disp_y + POINT_RADIUS);
#define Ellipse CCC_WIN_Ellipse
}

void GraphicWindow::ellipse(double x, double y, double ra, double rb)
{
#undef Ellipse
   Ellipse(_hdc, user_to_disp_x(x - ra), user_to_disp_y(y - rb),
      user_to_disp_x(x + ra),user_to_disp_y(y + rb));
   Ellipse(_bitmap_hdc, user_to_disp_x(x - ra), user_to_disp_y(y - rb),
      user_to_disp_x(x + ra),user_to_disp_y(y + rb));
#define Ellipse CCC_WIN_Ellipse
}

void GraphicWindow::line(double xfrom, double yfrom, double xto,
   double yto)
{
   MoveToEx(_hdc, user_to_disp_x(xfrom), user_to_disp_y(yfrom), 0);
   LineTo(_hdc,user_to_disp_x(xto), user_to_disp_y(yto));

   MoveToEx(_bitmap_hdc, user_to_disp_x(xfrom), user_to_disp_y(yfrom), 0);
   LineTo(_bitmap_hdc,user_to_disp_x(xto), user_to_disp_y(yto));
}

TCHAR* string2PTCHAR(string s)
{
#ifdef _UNICODE
   int targetLength = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, 0);

   if (targetLength == 0) { return NULL; }

   TCHAR* target = new TCHAR[targetLength];
   MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, target, targetLength);
   return target;
#else
   TCHAR* target = new TCHAR[s.length() + 1];
   strcpy_s(target, s.length() + 1, s.c_str());
   return target;
#endif
}

string PTCHAR2string(TCHAR* p)
{
#ifdef _UNICODE
   int targetLength = WideCharToMultiByte(CP_ACP, 0, p, -1, NULL, 0, NULL, FALSE);
   char* target = new char[targetLength];
   WideCharToMultiByte(CP_ACP, 0, p, -1, target, targetLength, NULL, FALSE);
   string result(target);
   delete[] target;
   return result;
#else
   return string(p);
#endif
}

void GraphicWindow::text(string s, double x, double y)
{  
   TCHAR* t = string2PTCHAR(s);
   SetBkMode(_hdc, TRANSPARENT);
   TextOut(_hdc, user_to_disp_x(x), user_to_disp_y(y), t, _tcslen(t));
   SetBkMode(_bitmap_hdc, TRANSPARENT);
   TextOut(_bitmap_hdc, user_to_disp_x(x), user_to_disp_y(y), t, _tcslen(t));
   delete[] t;
}

void GraphicWindow::statusline_prompt(string s)
{  
   const int M_WIDTH = 30;
   TCHAR* t = string2PTCHAR(s);
   HDC child_hdc;

   child_hdc = GetDC(child_hwnd);
   SIZE sz;
   GetTextExtentPoint32(child_hdc, t, s.length(), &sz);
   _mlength = sz.cx;
   GetTextExtentPoint32(child_hdc, _T(" "), 1, &sz);
   _mlength += sz.cx;
   ReleaseDC(child_hwnd, child_hdc);
   MoveWindow (child_hwnd, 1, 0, _mlength, M_WIDTH, true);
   SendMessage (child_hwnd, WM_SETTEXT, 0, (LPARAM) t);

   // move edit window from end of child window to edge of main window
   MoveWindow (edit_hwnd, cwin._mlength+1, 0, cwin._disp_xmax, M_WIDTH, true);
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{  
   point(p.get_x(), p.get_y());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c)
{  
   ellipse(c.get_center().get_x(), c.get_center().get_y(), c.get_radius(), c.get_radius());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Line s)
{  
   line(s.get_start().get_x(), s.get_start().get_y(), s.get_end().get_x(), s.get_end().get_y());
   return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message t)
{  
   text(t.get_text(), t.get_start().get_x(), t.get_start().get_y());
   return *this;
}

string GraphicWindow::get_string(string out_string)
{  
   MSG msg;
   const int BUFFSIZE = 80;

   TCHAR buffer[BUFFSIZE];
   buffer[0] = 0;
   SendMessage (edit_hwnd, WM_SETTEXT,0, (LPARAM) buffer);

   string result;

   statusline_prompt(out_string);   // output prompt

   SetFocus(edit_hwnd);

   HWND phwnd = GetParent(child_hwnd);

   while (GetMessage(&msg, (HWND) NULL, 0, 0))
   {  
      TranslateMessage(&msg);
      DispatchMessage(&msg);

      switch(msg.message)
      {  
         case WM_KEYUP:
            if ((msg.wParam == VK_RETURN) || (msg.wParam == VK_ESCAPE))
            {  
               SendMessage(edit_hwnd, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), (LPARAM) buffer);


               int buflen = _tcslen(buffer);
               if (buflen >= 2 && buffer[buflen - 2] == '\r') buffer[buflen - 2] = 0;
               result = PTCHAR2string(buffer);
               //shrink child windows after use

               MoveWindow (child_hwnd, 0, 0, 0, 0, true);
               MoveWindow (edit_hwnd, 0, 0, 0, 0, true);
               SetFocus(phwnd);
               return result;
            }
            break;
      }
   }
   return result; 
}

Point GraphicWindow::get_mouse(string outstr)
{  
   MSG msg;

   Point p;// = new point;
   int mouse_x, mouse_y;

   statusline_prompt(outstr);
   

   while (GetMessage(&msg, (HWND) NULL, 0, 0))
   {  
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      switch(msg.message)
      {  
         case WM_LBUTTONDOWN:
            mouse_x = LOWORD(msg.lParam);
            mouse_y = HIWORD(msg.lParam);
            p = Point(disp_to_user_x(mouse_x), disp_to_user_y(mouse_y));
            MoveWindow (child_hwnd, 0, 0, 0, 0, true);
            MoveWindow (edit_hwnd, 0, 0, 0, 0, true);
            return p;

         case WM_MOUSEMOVE:
            mouse_x = LOWORD(msg.lParam);
            mouse_y = HIWORD(msg.lParam);
            TCHAR msg[100];
            _stprintf_s(msg, _T("(%f,%f)"), disp_to_user_x(mouse_x), disp_to_user_y(mouse_y)); 
            SendMessage(edit_hwnd, WM_SETTEXT, 0, (LPARAM) msg);
            break;
      }
   }

   return p;
}

void GraphicWindow::close()
{  
   SelectObject(_bitmap_hdc, _hbm_saved);
   DeleteDC(_bitmap_hdc);
   DeleteObject(_hbm);
}

void GraphicWindow::repaint(PAINTSTRUCT& ps)
{  
   BitBlt(ps.hdc, ps.rcPaint.left, ps.rcPaint.top,
      ps.rcPaint.right, ps.rcPaint.bottom, _bitmap_hdc,
      ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
}

int GraphicWindow::get_int(const string& out_string) 
{  
   return atoi(get_string(out_string).c_str()); 
}

double GraphicWindow::get_double(const string& out_string) 
{  
   return atof(get_string(out_string).c_str()); 
}
