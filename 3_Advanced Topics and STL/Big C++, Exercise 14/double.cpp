#include "double.h"

Double::Double()
{
	value = 0;
}

Double::Double(double v, const std::string & k)
	:key(k)
{
	value = v;
}
