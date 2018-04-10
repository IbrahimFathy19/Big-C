#include "Person.h"
#include <iostream>

Person::Person()
{
	popularity = 0;
	best_friend = NULL;
}

Person::Person(const std::string& n)
	:name(n)
{
	popularity = 0;
	best_friend = NULL;
}

void Person::set_best_friend(Person * bf)
{
	best_friend = bf;
	(bf->popularity)++;// You increase the person who is the best_friend to the others
	// Not the one who has that best_friend
}

std::string Person::get_name()
{
	return name;
}

void Person::print_person()
{
	if (this != NULL && best_friend != NULL)
	{
		std::cout << "Name: " << name << "\n"
			<< "Popularity: " << popularity << "\n"
			<< "Best friend: " << best_friend->get_name() << "\n";
	}
}

