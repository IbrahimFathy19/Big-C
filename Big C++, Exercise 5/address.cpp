#include "address.h"
#include <iostream>

address::address()
{
	house_number = 0, apartment_number = 0, postal_code = 0;
}

address::address(int apart_num)
{
	house_number = 0, apartment_number = apart_num, postal_code = 0;
}
void address::print() const
{
	std::cout << street << '\n' << city << ", " << state << " ," << postal_code << '\n';
}
bool address::comes_before(address b) const
{
	if (this->postal_code < b.postal_code)
		return true; //means that this comes before b
	else
		return false; //means that b comes before this
}