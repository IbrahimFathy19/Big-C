#include "person.h"

Person::Person()
{
	age = 0;
}
Person::Person(std::string pname, int page)
	:name(pname)
{
	age = page;
}
std::string Person::get_name() const
{
	return this->name;
}
int Person::get_age() const
{
	return this->age;
}