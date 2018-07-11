#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction 
{
public:
   /**
      Constructs a fraction with numerator 0 and denominator 1.
   */
   Fraction();

   /**
      Constructs a fraction with numerator t and denominator 1.
      @param t the numerator for the fraction
   */
   Fraction(int t);

   /**
      Constructs a fraction with given numerator and denominator.
      @param t the initial numerator
      @param b the initial denominator
   */
   Fraction(int t, int b);

   /**
      Returns the numerator. 
      @return the numerator value
   */
   int numerator() const;

   /**
      Returns the denominator.
      @return the denominator value
   */
   int denominator() const;

   /**
      Updates a fraction by adding in another fraction value.
      @param right  the fraction to be added
      @ return the updated fraction value
   */
   Fraction& operator+=(const Fraction& right);
	/**
		Updates a fraction by subtracting from another fraction value.
		@param right  the fraction to be subtracted
		@ return the updated fraction value
	*/
	Fraction& operator-=(const Fraction& right);
	/**
		Updates a fraction by multiplying by another fraction value.
		@param right  the fraction to be multiplyied
		@ return the updated fraction value
	*/
	Fraction& operator*=(const Fraction& right);
	/**
		Updates a fraction by dividing over another fraction value.
		@param right  the fraction to be divided
		@ return the updated fraction value
	*/
	Fraction& operator/=(const Fraction& right);

   /**
     Increment fraction by 1.
   */
   Fraction& operator++(); // Prefix form
   Fraction operator++(int unused); // Postfix form

   /**
      Compare one fraction value to another.
      Result is negative if less than right, zero if equal, and 
      positive if greater than right.
      @param right the fraction to be compared against 
   */
   int compare(const Fraction& right) const;
	/**
		Conversion operator to change values of type fraction into floating-point number.
	*/
	operator double() const;
	/**
		Conversion operator to be able to check validity of data of type fraction
		That's, it can be used like this
		Fraction f;
		if(f)
			std::cout << f << "\n";
	*/
	operator bool() const;
private:
   /**
      Place the fraction in least common denominator form.
   */
   void normalize();
   /**
      Compute the greatest common denominator of two integer values.
      @param n the first integer
      @param m the second integer
   */
   int gcd(int n, int m);
   int top;
   int bottom;
};

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& value);

bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);

ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& r);



// inline functions definitions

inline Fraction::Fraction() : top(0), bottom(1) { }

inline Fraction::Fraction(int t) : top(t), bottom(1) { }

inline int Fraction::numerator() const
{
	return top;
}

inline int Fraction::denominator() const
{
	return bottom;
}

inline Fraction operator-(const Fraction& value)
{
	Fraction result(-value.numerator(), value.denominator());
	return result;
}

inline bool operator<(const Fraction& left, const Fraction& right)
{
	return left.compare(right) < 0;
}

inline bool operator<=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) <= 0;
}

inline bool operator==(const Fraction& left, const Fraction& right)
{
	return left.compare(right) == 0;
}

inline bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) != 0;
}

inline bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) >= 0;
}

inline bool operator>(const Fraction& left, const Fraction& right)
{
	return left.compare(right) > 0;
}

inline Fraction& Fraction::operator++()
{
	top += bottom;
	return *this;
}

inline Fraction::operator double() const
{
	return static_cast<double>(top) / bottom;
}

inline Fraction::operator bool() const
{
	if (bottom == 0)
		return false;
	return true;
}

#endif
