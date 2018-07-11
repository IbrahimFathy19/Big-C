#include "complex.h"

Complex operator*(const Complex& c1, const Complex& c2)
{
	return Complex((c1.get_real() * c2.get_real()) - c1.get_img() * c2.get_img()
		, (c1.get_img() * c2.get_real()) + (c1.get_real() * c2.get_img()));
}

Complex operator/(const Complex& c1, const Complex& c2)
{
	Complex conjugate = Complex(c2.get_real(), -c2.get_img());

	Complex numerator = c1 * conjugate;
	Complex denominator = c2 * conjugate; // now the imaginary part is gone
	
	return Complex(numerator.get_real() / denominator.get_real(), 
		numerator.get_img() / denominator.get_real());
}

std::ostream & operator<<(std::ostream & out, const Complex & c)
{
	if (c.get_real() == 0)
	{
		if (c.get_img() > 0 && c.get_img() != 1)
			out << "+ " << c.get_img() << "i";
		else if (c.get_img() == 1)
			out << "+i";
		else if (c.get_img() == 0)
			out << "0";
		else if (c.get_img() == -1)
			out << "-i";
		else if (c.get_img() < 0)
			out << "- " << -c.get_img() << "i";
	}
	else
	{
		out << c.get_real();

		if (c.get_img() > 0 && c.get_img() != 1)
			out << " + " << c.get_img() << "i";
		
		else if (c.get_img() == 1)
			out << " + i";
		
		else if (c.get_img() == -1)
			out << " - i";
		
		else if (c.get_img() < 0)
			out << " - " << -c.get_img() << "i";
	}
	return out;
}

std::istream & operator>>(std::istream & in, Complex & c)
{
	std::string img_str;
	double real, img;
	in >> real >> img_str;

	//extract the value of the img part
	std::stringstream str_stream(img_str);
	str_stream >> img;

	c = Complex(real, img);
	return in;
}
