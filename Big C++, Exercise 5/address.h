#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class address
{
public:
	/**
		Constructs the integer data to zero
	*/
	address();


	/**
	Constructs the apartment number to apart_num and the other intgers to zero
	@param apart_num is the number of the apartment of the implicit parameter
	*/
	address(int apart_num);


	/**
		prints the address with the street on one line and the city, state, 
		and postal code on the next line
	*/
	void print() const;
	

	/**
		tests whether one address comes before another when the addresses 
		are compared by postal code.
		@param b is the address to be tested with the implicit address
		@return true if the implicit object comes before b
	*/
	bool comes_before(address b) const;

private:
	int house_number, apartment_number, postal_code;
	std::string street, city, state;
};

#endif