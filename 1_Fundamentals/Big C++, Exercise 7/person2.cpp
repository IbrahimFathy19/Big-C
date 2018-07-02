#include "person2.h"

Person2::Person2()
{
	age = 0;
}

Person2::Person2(const std::string& n, int a)
	:name(n)
{
	age = a;
}

void Person2::update_age(int a)
{
	age += a;
}
