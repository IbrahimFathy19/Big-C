#ifndef CAR_H
#define CAR_H

class Car
{
public:
	/**
		constructs the car fuel with 0 and fuel efficiency with 0
	*/
	Car();

	/**
		constructs the car fuel with 0 and fuel efficiency with new_fuel_efficiency
		@param is the quantity of the fuel effieciency of this car
	*/
	Car(double new_fuel_efficiency);

	/**
		Simulates driving the car for a certain distance, reducing the fuel level 
		in the gas tank, this function modifies the data field
		@param distance is the distance that the car will drive, and the fuel reduces
		with respect to it.
	*/
	void drive(double distance);

	/**
		Adds some fuel to the current amount of fuel in the car
		@param new_fuel is the extra amount of fuel to be added
	*/
	void add_gas(double new_fuel);

	/**
		Gets the current amount of fuel available in the car
		@return the fuel amount available in the car
	*/
	double get_gas() const;

private:
	double fuel_efficiency; //measured in liters / km
	double amount_fuel;//measured in liters
};

#endif