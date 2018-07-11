#include "polynomial.h"

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const std::vector<double>& coeff)
	:coefficents(coeff)
{
}

std::vector<double> Polynomial::get_coeff() const
{
	return coefficents;
}

Polynomial operator+(const Polynomial & p1, const Polynomial & p2)
{
	std::vector<double> coeff_p1 = p1.get_coeff(),
		coeff_p2 = p2.get_coeff();

	size_t size_p1 = coeff_p1.size(),
		size_p2 = coeff_p2.size();
	
	int i1 = 0;
	// Next element to consider in the first polynomial 
	int i2 = 0;
	// Next element to consider in the second polynomial 
	int j = 0; // Next open position in coeff 

	std::vector<double> coeff(std::max(size_p1, size_p2));
	while (i1 < size_p1 && i2 < size_p2)
	{
		coeff[j] = coeff_p1[i1] + coeff_p2[i2];
		i2++;
		i1++;
		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first polynomial
	while (i1 < size_p1)
	{
		coeff[j] = coeff_p1[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second polynomial
	while (i2 < size_p2)
	{
		coeff[j] = coeff_p2[i2];
		i2++;
		j++;
	}
	return Polynomial(coeff);
}


Polynomial operator-(const Polynomial & p1, const Polynomial & p2)
{
	std::vector<double> coeff_p1 = p1.get_coeff(),
		coeff_p2 = p2.get_coeff();

	size_t size_p1 = coeff_p1.size(),
		size_p2 = coeff_p2.size();

	int i1 = 0;
	// Next element to consider in the first polynomial 
	int i2 = 0;
	// Next element to consider in the second polynomial 
	int j = 0; // Next open position in coeff 

	std::vector<double> coeff(std::max(size_p1, size_p2));
	while (i1 < size_p1 && i2 < size_p2)
	{
		coeff[j] = coeff_p1[i1] - coeff_p2[i2];
		i2++;
		i1++;
		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first polynomial
	while (i1 < size_p1)
	{
		coeff[j] = coeff_p1[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second polynomial
	while (i2 < size_p2)
	{
		coeff[j] = coeff_p2[i2];
		i2++;
		j++;
	}
	return Polynomial(coeff);
}

Polynomial operator*(const Polynomial & p1, const Polynomial & p2)
{
	std::vector<double> coeff_p1 = p1.get_coeff(),
		coeff_p2 = p2.get_coeff();

	size_t size_p1 = coeff_p1.size(),
		size_p2 = coeff_p2.size();

	int i1 = 0;
	// Next element to consider in the first polynomial 
	int i2 = 0;
	// Next element to consider in the second polynomial 
	int j = 0; // Next open position in coeff 

	std::vector<double> coeff(std::max(size_p1, size_p2));
	while (i1 < size_p1 && i2 < size_p2)
	{
		coeff[j] = coeff_p1[i1] * coeff_p2[i2];
		i2++;
		i1++;
		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first polynomial
	while (i1 < size_p1)
	{
		coeff[j] = coeff_p1[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second polynomial
	while (i2 < size_p2)
	{
		coeff[j] = coeff_p2[i2];
		i2++;
		j++;
	}
	return Polynomial(coeff);
}

std::ostream & operator<<(std::ostream & out, const Polynomial & p)
{
	std::vector<double> coeff = p.get_coeff();
	for (size_t i = 0, n = coeff.size(); i < n; i++)
	{
		out << p.get_coeff()[i] << "x^" << n - i - 1<<" + ";
	}
	return out;
}
