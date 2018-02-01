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

#include "ccc_shap.h"

#if defined(_MSC_VER)
   #define CCC_MSW
#endif
#if defined(_WINDOWS_) || defined (_Windows) || defined(WINVER) || defined(__WIN32__)
   #define CCC_MSW
#endif
#if defined(__GNUC__) && !defined(CCC_MSW)
   #define CCC_X11
#endif

#if defined(CCC_ASC)
#include "ccc_asc.h"
#elif defined(CCC_WXW)
#include "ccc_wxw.h"
#elif defined(CCC_X11)
#include "ccc_x11.h"
#elif defined(CCC_MSW)
#include "ccc_msw.h"
#else
#include "ccc_asc.h"
#endif
