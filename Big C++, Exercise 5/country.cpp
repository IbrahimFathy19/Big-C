#include "country.h"
#include <iostream>

Country::Country()
{
	country_area = 0;
	country_population = 0;
}

Country::Country(std::string name, long population, double area)
	:country_name(name)
{
	country_population = population;
	country_area = area;
}

void Country::read_country()
{
	std::cout << "Enter the country name: ";
	std::cin >> country_name;
	std::cout << "Enter the population: ";
	std::cin >> country_population;
	std::cout << "Enter the area: ";
	std::cin >> country_area;
}

double Country::get_area() const
{
	return country_area;
}

long Country::get_population() const
{
	return country_population;
}

void Country::print_country() const
{
	std::cout << "Country: " << country_name
		<< '\n'
		<< "Population: " << country_population
		<< '\n'
		<< "Area: " << country_area
		<< '\n';
}

bool Country::is_larger_than(Country anoter_country) const
{
	if (this->country_area > anoter_country.country_area)
		return true;
	return false;
}

bool Country::more_population_than(Country another_country) const
{
	if (this->country_population > another_country.country_population)
		return true;
	return false;
}
