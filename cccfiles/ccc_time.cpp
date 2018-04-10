#include <ctime>
#include <cassert>

using namespace std;

#include "ccc_time.h"

#if defined(_MSC_VER) || defined(_WINDOWS_) || defined (_Windows) || defined(WINVER) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
   #define CCC_MSW
#endif


/**
   Computes the correct remainder for negative dividend
   @param a - an integer
   @param n - an integer > 0
   @return the mathematically correct remainder r such that
   a - r is divisible by n and 0 <= r and r < n
*/
int remainder(int a, int n)
{  
   if (a >= 0)
      return a % n;
   else
      return n - 1 - (-a - 1) % n;
}

Time::Time(int hour, int min, int sec)
{  
   assert(0 <= hour);
   assert(hour < 24);
   assert(0 <= min);
   assert(min < 60);
   assert(0 <= sec);
   assert(sec < 60);

   time_in_secs = 60L * 60 * hour + 60 * min + sec;
}

Time::Time()
{  
   time_t now = time(0);
#ifdef CCC_MSW
   struct tm t;
   localtime_s(&t, &now); 
#else   
   struct tm& t = *localtime(&now);
#endif
   time_in_secs = 60L * 60 * t.tm_hour + 60 * t.tm_min + t.tm_sec;
}

int Time::get_hours() const
{  
   return time_in_secs / (60 * 60);
}

int Time::get_minutes() const
{  
   return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const
{  
   return time_in_secs % 60;
}

int Time::seconds_from(Time t) const
{  
   return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s)
{  
   const int SECONDS_PER_DAY = 60 * 60 * 24;
   time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}
