#include "street.h"

Street::Street()
{
	number_houses = 0;
}

Street::Street(House f_h, House l_h, int n)
	:first_house(f_h), last_house(l_h)
{
	number_houses = n;
}

void Street::plot() const
{
	Point f = first_house.get_location();
	for (int i = first_house.get_houseNumber();
		i < last_house.get_houseNumber(); i++)
	{
		House h(i, f);
		
			f.move(1.5, 0);
		
		h.plot();
	}
}
