#ifndef SODACAN_H
#define SODECAN_H

class SodaCan
{
public:
	/**
		Constructs the radius and the vloume of the can with zero
	*/
	SodaCan();

	/**
		Constructs the radius and the vloume of the can with the given value
		@param new_height is the height of "this" can.
		@param new_radius is the radius of "this" can.
	*/
	SodaCan(double new_height, double new_radius);

	/**
		Gets the surface area of the implicit can "this"
		@return the area of the surface of the can
	*/
	double get_surface_area() const;

	/**
	Gets the volume of the implicit can "this"
	@return the volume of the surface of the can
	*/
	double get_volume() const;
private:
	double height, radius;
};



#endif