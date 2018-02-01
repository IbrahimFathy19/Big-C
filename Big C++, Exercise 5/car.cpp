#include "car.h"

Car::Car()
{
	fuel_efficiency = 0, amount_fuel = 0;
}
Car::Car(double new_fuel_efficiency)
{
	fuel_efficiency = new_fuel_efficiency;
	amount_fuel = 0;
}
void Car::drive(double distance)
{
	amount_fuel = amount_fuel - (distance / fuel_efficiency * 1.0);
}
void Car::add_gas(double new_feul)
{
	amount_fuel = amount_fuel + new_feul;
}
double Car::get_gas() const
{
	return amount_fuel;
}