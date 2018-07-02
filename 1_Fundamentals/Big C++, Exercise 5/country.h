#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country
{
public:
	/**
		Constructs the Country with area 0 and population 0
	*/
	Country();

	/**
		Constructs the Country with a name and population and area
		@param name is the name of this country
		@param population is the people count in this country
		@param area is the area of this country
	*/
	Country(std::string name, long population, double area);
	
	/**
		Reads a country and modifies the data field by the stream std::cin
	*/
	void read_country();
	
	/**
		Gets the area of this country
		@return the area of the country
	*/
	double get_area() const;
	
	/**
		Gets the count of people in this country
		@return the population of this country
	*/
	long get_population() const;
	
	/**
		Prints the country data field: name, area, population with
		the stream std::cout
	*/
	void print_country() const;
	
	/**
		Tests areas of two countries (implicit and explicit)
		@param another_country is the country to be tested
		@return true if the implict country ("this") is larger than
		the another_country
	*/
	bool is_larger_than(Country anoter_country) const;
	
	/**
		Tests the population of two countries (implicit and explicit)
		@param another_country is the country to be tested
		@return true if the implict country ("this") has more population than
		the another_country
	*/
	bool more_population_than(Country another_country) const;

private:

	std::string country_name;
	long country_population;
	double country_area;//in km

};



#endif