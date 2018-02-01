#include "car.h"

Car::Car()
{
	owner = NULL;
	driver = NULL;
}

Car::Car(const std::string & m, Person2 * o, Person2 * d)
	:model(m)
{
	owner = o;
	driver = d;
}
