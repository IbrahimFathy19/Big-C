#include "person.h"

Person::Person()
{
}

Person::Person(const std::string & person_name, int month, int day, int year)
	:name(person_name)
{
	birthdate.resize(3);
	birthdate[0] = month;
	birthdate[1] = day;
	birthdate[2] = year;
}

void Person::print() const
{
	int n = birthdate.size();
	std::cout << "Name: " << name << "\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << birthdate[i];
		if (i != n - 1)
			std::cout << "/";
	}
	std::cout << "\n";
}
