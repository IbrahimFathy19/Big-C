#include "term.h"

Term::Term()
{
	power = coeff = 0;
}

Term::Term(double c, double p)
{
	coeff = c;
	power = p;
}

double Term::get_coeff() const
{
	return coeff;
}

double Term::get_power() const
{
	return power;
}

void Term::print_term() const
{
	if (coeff < 0)
	{
		if (coeff != -1)
			std::cout << coeff;
		else
			std::cout << "-";
	}
	else if (coeff > 0 && coeff != 1)
		std::cout << "+" << coeff;

	if (power == 1)
		std::cout << "x";

	else if (power != 0 && power != 1)
		std::cout << "x^" << power;
}
