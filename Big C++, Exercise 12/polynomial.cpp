#include "polynomial.h"

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(Term t)
{
	poly.push_back(t);
}

void Polynomial::add(Polynomial p)
{
	bool equal_power;
	std::list<Term>::iterator i, j;
	for (i = p.poly.begin(); i != p.poly.end(); i++)
	{
		equal_power = false;
		for (j = this->poly.begin(); j != this->poly.end(); j++)
		{
			if ((*i).get_power() == (*j).get_power())
			{
				Term new_term = Term((*i).get_coeff() + (*j).get_coeff(), (*i).get_power());
				*j = Term(new_term);
				equal_power = true;
			}
		}
		if (equal_power == false)
			poly.push_back(*i);
	}
}

Polynomial Polynomial::multiply(Polynomial p)
{
	Polynomial result;
	std::list<Term>::iterator i, j;
	for (i = p.poly.begin(); i != p.poly.end(); i++)
	{
		for (j = this->poly.begin(); j != this->poly.end(); j++)
		{
			Term new_term = Term((*i).get_coeff() * (*j).get_coeff(), (*i).get_power() + (*j).get_power());
			result.poly.push_back(new_term);
		}
	}
	return result;
}

void Polynomial::print_polynomial()
{
	std::list<Term>::iterator i;
	for (i = poly.begin(); i != poly.end(); i++)
		(*i).print_term();

	std::cout << "\n";
}
