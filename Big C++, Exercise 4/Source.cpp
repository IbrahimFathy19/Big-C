/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "ccc_empl.h"
#include <sstream>

#define PI 3.14159




//Functions declarations

void p1();
void p2();
void p3();
void p4();
void p5();
void p7();
void p8();
void p9();
void p10();
void p11();
void p12();
void p13();
void p15();






/****************************************************************/





/**
	Computes the value of an investment with compound interest.
	@param initial_balance the initial value of the investment
	@param p the interest rate per period in percent
	@param n the number of periods the investment is held
	@return the balance after n periods
*/
double future_value(double p, double initial_balance, int n);

/**
	Swaps the two variables a and b if a is greater than b and otherwise
	leaves a and b unchanged
	@param a is the controller vairable as if it was greater than b the function
	swaps them and it's called by reference
	@param b is the second vairable and it's called by reference
*/
void sort2(int& a, int& b);

/**
	Rearrange the three integers using the procedure sort2()
	@param a is the first variable to be compared and it's called by reference
	@param b is the second vairable and it's called by reference
	@param c is the third variable to be compared
*/
void sort3(int& a, int& b, int& c);

/**
	Turns a digit into its English name.
	@param n an integer between 1 and 9
	@return the name of n ("one" . . . "nine")
*/
std::string digit_name(int n);

/**
	Turns a number between 10 and 19 into its English name.
	@param n an integer between 10 and 19
	@return the name of n ("ten" . . . "nineteen")
*/
std::string teen_name(int n);

/**
	Gives the English name of a multiple of 10.
	@param n an integer between 2 and 9
	@return the name of 10 * n ("twenty" . . . "ninety")
*/
std::string tens_name(int n);

/**
	Turns a number into its English name.
	@param n a positive integer < 10,000,000
	@return the name of n (e.g. "two hundred seventy four")
*/
std::string int_name(int n);

/**
	Calculates the volume of a sphere of radius r
	@param r is the radius of the sphere
	@return the volume of that sphere
*/
double sphere_volume(double r);

/**
	Calculates the surface area of a sphere of radius r
	@param r is the radius of the sphere
	@return the surface area of that sphere
*/
double sphere_surface(double r);

/**
	Calculates the vloume of a cylinder
	@param r is the radius of the cylinder
	@param h is the height of the cylinder
	@return the volume of that cylinder
*/
double cylinder_volume(double r, double h);

/**
	Calculates the surface area of a cylinder
	@param r is the radius of the cylinder
	@param h is the height of the cylinder
	@return the surface area of that cylinder
*/
double cylinder_surface(double r, double h);

/**
	Calculates the volume of a cone
	@param r is the radius of the cone
	@param h is the height of the cone
	@return the volume of that cone
*/
double cone_volume(double r, double h);

/**
	Calculates the surface area of a cone
	@param r is the radius of the cone
	@param h is the height of the cone
	@return the surface area of that cone
*/
double cone_surface(double r, double h);

/**
	Displays the prompt string, followed by a space, reads a floating-point number
	in, and returns it.
	@param prompt is the string that will be displayed to the user
	@return the double value
*/
double get_double(const std::string& prompt);

/**
	Check whether a year is a leap year or not
	@param year is the year to be tested
	@return true if the year is leap
*/
bool leap_year(int year);

/**
	Asks for the problem name (e.g. p5) and then print the solution of that problem
*/
void print_solution();

/**
	converts a date into a Julian day number.
	@param year is the year in the date that will be converted
	@param month is the month in the date that will be converted
	@param day is the day in the date that will be converted
	@return the julian day number
*/
long julian(int year, int month, int day);

/**
	performs the opposite conversion, from Julian day numbers to dates.
	@param jul is the julian day to be converted
	@param year is the year corresponding to that julian day
	@param month is the month corresponding to that julian day
	@param day is the day corresponding to that julian day
*/
void jul_to_date(long jul, int& year, int& month, int& day);

/**
	Translates one digit, using the strings specified for the one, five, and
	ten values.
	@param n is the integer to be translated
	@param one is the least character value (e.g. for ones it's I)
	@param five is the middle character value (e.g. for ones it's V)
	@param ten is the most character value (e.g. for ones it's X)
	@return the translation of n
*/
std::string roman_digit(int n, std::string one, std::string five,
	std::string ten);

/**
	Yields the numeric value of each of the letters
	@param the Roman letter to be converted
	@return the numeric value of this letter
*/
int convert_roman_letter(char letter);

Employee read_employee();
/**
	Encodes a five-digit zip code into bar code and print the result
	@parma zip_code is a string contains the zip code to be encoded
*/





/****************************************************************/



//Functions defintions


int main()
{
	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;
	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p19, p20, p21, p22, p23" << std::endl
		<< "******\n";
	print_solution();

	return 0;
}
void print_solution()
{
	std::string problem_name;
	do {
		std::cout << "Enter the problem's code: ";
		std::cin >> problem_name;
		if (problem_name == ("p1"))
			p1();
		else if (problem_name == ("p2"))
			p2();
		else if (problem_name == ("p3"))
			p3();
		else if (problem_name == ("p4"))
			p4();
		else if (problem_name == ("p5"))
			p5();
		else if (problem_name == ("p7"))
			p7();
		else if (problem_name == ("p8"))
			p8();
		else if (problem_name == ("p9"))
			p9();
		else if (problem_name == ("p10"))
			p10();
		else if (problem_name == ("p11"))
			p11();
		else if (problem_name == ("p12"))
			p12();
		else if (problem_name == ("p13"))
			p13();
		else if (problem_name == ("p15"))
			p15();
		else if (problem_name == ("p19") || problem_name == ("p20")
			|| problem_name == ("p21") || problem_name == ("p22")
			|| problem_name == ("p23"))
			std::cout << "Graphical, In a separate file\n";


	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n";
}





/****************************************************************/






void p1()
{
	double rate, balance;
	int years;
	std::cout << "Please enter the interest rate in percent: ";
	std::cin >> rate;
	std::cout << "Please enter the initial balance: ";
	std::cin >> balance;
	std::cout << "Please enter the number of years: ";
	std::cin >> years;
	double new_balance = future_value(rate, balance, years);
	std::cout << "The balance after " << years << " years is: "
		<< new_balance << '\n';
}
void p2()
{
	int num1, num2;
	std::cout << "Enter a number: ";
	std::cin >> num1;
	std::cout << "Enter another number: ";
	std::cin >> num2;
	sort2(num1, num2);
	std::cout << "The sort from smallest to largest is: " << num1 << ", "
		<< num2 << "\n";
}
void p3()
{
	int num1, num2, num3;
	std::cout << "Enter a number: ";
	std::cin >> num1;
	std::cout << "Enter another number: ";
	std::cin >> num2;
	std::cout << "Enter another number: ";
	std::cin >> num3;
	sort3(num1, num2, num3);
	std::cout << "The sort from smallest to largest is: " << num1 << ", "
		<< num2 << ", " << num3 << "\n";
}
void p4()
{
	int n;
	std::cout << "Please enter a positive integer: ";
	std::cin >> n;
	std::cout << int_name(n) << '\n';
}
void p5()
{
	int n;
	std::cout << "Please enter a positive integer: ";
	std::cin >> n;
	std::cout << int_name(n) << '\n';
}
//p6 done, edited int_name funtion
void p7()
{
	double r, h;
	std::cout << "Enter the radius: ";
	std::cin >> r;
	std::cout << "Enter the height: ";
	std::cin >> h;
	std::cout << "The volume of a sphere with radius " << r << " is: "
		<< sphere_volume(r) << '\n'
		<< "The surface area of a sphere with radius " << r << " is: "
		<< sphere_surface(r) << '\n'
		<< "The volume of a cylinder with radius " << r << " and height " << h << " is: "
		<< cylinder_volume(r, h) << '\n'
		<< "The surface area of a cylinder with radius " << r << " and height " << h
		<< " is: "
		<< cylinder_surface(r, h) << '\n'
		<< "The volume of a cone with radius " << r << " and height " << h
		<< " is: "
		<< cone_volume(r, h) << '\n'
		<< "The surface area of a cone with radius " << r << " and height " << h
		<< " is: "
		<< cone_surface(r, h) << '\n';

}
void p8()
{
	double x = get_double("Please enter your salary:");
	std::cout << x << '\n';
}
void p9()
{
	int year;
	std::cout << "Enter the year to check whether it's a leap year or not: ";
	std::cin >> year;
	bool leap = leap_year(year);
	if (leap == true)
		std::cout << year << " is a leap year\n";
	else
		std::cout << year << " is not a leap year\n";
}
void p10()
{
	std::cout << "Enter a date in the past:\n";
	std::cout << "year: ";
	int year;
	std::cin >> year;
	std::cout << "month: ";
	int month;
	std::cin >> month;
	std::cout << "day: ";
	int day;
	std::cin >> day;
	long jul = julian(year, month, day);

	time_t t = time(0);  // current time: http://cplusplus.com/reference/clibrary/ctime/time/
	struct tm * now = localtime(&t);  // http://cplusplus.com/reference/clibrary/ctime/localtime/

									  // struct tm: http://cplusplus.com/reference/clibrary/ctime/tm/
	int current_day = now->tm_mday;
	int current_month = now->tm_mon + 1;
	int current_year = now->tm_year + 1900;

	long current_jul = julian(current_year, current_month, current_day);
	long days = current_jul - jul;
	std::cout << "The days number since that date is: " << days << " day\n";

}
void p11()
{
	std::cout << "Enter a date:\n";
	std::cout << "year: ";
	int year;
	std::cin >> year;
	std::cout << "month: ";
	int month;
	std::cin >> month;
	std::cout << "day: ";
	int day;
	std::cin >> day;
	long jul = julian(year, month, day);
	std::cout << "Enter a number n: ";
	long n;
	std::cin >> n;
	int n_year, n_month, n_day;//n stands for new
	jul_to_date(jul - n, n_year, n_month, n_day);
	std::cout << n_day << " / " << n_month << " / " << n_year << " is " <<
		n << " days away from " << day << " / " << month << " / " << year << "\n";
}
void p12()
{
	int input;
	std::cout << "Enter a number: ";
	std::cin >> input;
	int thousands = input / 1000;
	input = input - thousands * 1000;
	int hundreds = input / 100;
	input = input - hundreds * 100;
	int tens = input / 10;
	input = input - tens * 10;
	int ones = input;

	for (int i = 0; i < thousands; i++)
		std::cout << "M";

	std::string ones_digit = roman_digit(ones, "I", "V", "X");
	std::string tens_digit = roman_digit(tens, "X", "L", "C");
	std::string hundreds_digit = roman_digit(ones, "C", "D", "M");

	std::cout << hundreds_digit << tens_digit << ones_digit << '\n';
}
void p13()
{
	std::cout << "Enter a Roman Number: ";
	std::string roman_number;
	std::cin >> roman_number;
	unsigned int decimal_number = 0;
	int first;
	int second;
	int n = roman_number.length();
	for (int i = 0; i < n; i += 2)
	{
		first = convert_roman_letter(roman_number[i]);
		second = convert_roman_letter(roman_number[i + 1]);
		if (first < second)
			first *= -1;
		decimal_number = decimal_number + first + second;
	}
	std::cout << decimal_number << '\n';
}
void p15()
{
	read_employee();
}




/****************************************************************/













double future_value(double p, double initial_balance, int n)
{
	double b = initial_balance * pow(1 + p / 100, n);
	return b;
}
void sort2(int& a, int& b)
{
	int temp;
	if (a > b)
	{
		temp = b;
		b = a;
		a = temp;
	}
}
void sort3(int& a, int& b, int& c)
{
	sort2(a, b);
	sort2(b, c);
	sort2(a, b);
}
std::string digit_name(int n)
{
	if (n == 1) return "one";
	if (n == 2) return "two";
	if (n == 3) return "three";
	if (n == 4) return "four";
	if (n == 5) return "five";
	if (n == 6) return "six";
	if (n == 7) return "seven";
	if (n == 8) return "eight";
	if (n == 9) return "nine";
	return "";
}
std::string teen_name(int n)
{
	if (n == 10) return "ten";
	if (n == 11) return "eleven";
	if (n == 12) return "twelve";
	if (n == 13) return "thirteen";
	if (n == 14) return "fourteen";
	if (n == 15) return "fifteen";
	if (n == 16) return "sixteen";
	if (n == 17) return "seventeen";
	if (n == 18) return "eighteen";
	if (n == 19) return "nineteen";
	return "";
}
std::string tens_name(int n)
{
	if (n == 2) return "twenty";
	if (n == 3) return "thirty";
	if (n == 4) return "forty";
	if (n == 5) return "fifty";
	if (n == 6) return "sixty";
	if (n == 7) return "seventy";
	if (n == 8) return "eighty";
	if (n == 9) return "ninety";
	return "";
}
std::string int_name(int n)
{
	int c = n; // The part that still needs to be converted 
	std::string r; // The return value
	if (c < 0)
	{
		r = "Negative- ";
		c = c * -1;
	}
	if (c >= 1000000)
	{
		r = r + digit_name(c / 1000000) + " million ";
		c = c % 1000000;
	}
	if (c >= 1000)
	{
		r = r + int_name(c / 1000) + "thousand ";
		c = c % 1000;
	}

	if (c >= 100)
	{
		r = r + digit_name(c / 100) + " hundred ";
		c = c % 100;
	}

	if (c >= 20)
	{
		r = r + tens_name(c / 10) + " ";
		c = c % 10;
	}

	if (c >= 10)
	{
		r = r + teen_name(c) + " ";
		c = 0;
	}

	if (c > 0)
		r = r + digit_name(c) + " ";
	if (n == 0)//test unchanged variable! :D
		r = "zero";
	return r;
}
double sphere_volume(double r)
{
	double volume = (4 / 3.0) * PI * pow(r, 3);
	return volume;
}
double sphere_surface(double r)
{
	double area = 4 * PI * r * r;
	return area;
}
double cylinder_volume(double r, double h)
{
	double volume = PI * r * r * h;
	return volume;
}
double cylinder_surface(double r, double h)
{
	double area = 2 * PI * r * h + 2 * PI * r * r;
	return area;
}
double cone_volume(double r, double h)
{
	double volume = PI * r * r * h / 3.0;
	return volume;
}
double cone_surface(double r, double h)
{
	double area = PI * r * (r + sqrt(h * h + r * r));
	return area;
}
double get_double(const std::string& prompt)
{
	double value;
	std::cout << prompt << "\n";
	std::cin >> value;
	if (std::cin.fail())
		exit(1);
	return value;
}
bool leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
long julian(int year, int month, int day)
{
	int jy = year, jm = month, jd = day;
	long jul;

	if (jy < 0)
		jy++;
	if (jm > 2)
		jm++;
	else
	{
		jm += 13;
		jy--;
	}
	jul = floor(365.25 * jy) + floor(30.6001 * jm) + jd
		+ 1720995.0;
	if (!(year <= 1582 && month <= 10 && day < 15))
	{
		int ja = 0.01 * jy;
		jul = jul + 2 - ja + 0.25 * ja;
	}
	return jul;
}
void jul_to_date(long jul, int& year, int& month, int& day)
{
	long julian = jul;//don't modigy the input parameters
	if (julian >= 2299161)
	{
		long jalpha = ((jul - 1867216) - 0.25) / 36524.25;
		julian = julian + 1 + jalpha - (int)(0.25 * jalpha);
	}
	long jb = julian + 1524;
	long jc = 6680.0 + (jb - 2439870 - 122.1) / 365.25;
	long jd = 365 * jc + (0.25 * jc);
	int je = (jb - jd) / 30.6001;

	day = jb - jd - (long)(30.6001 * je);
	month = je - 1;
	year = (int)(jc - 4715);

	if (month > 12)
		month -= 12;
	else if (month > 2)
		year--;
	if (year < 0)
		year--;
}
std::string roman_digit(int n, std::string one, std::string five,
	std::string ten)
{
	std::string represent;
	int i;
	if (n <= 3)
	{
		for (i = 0; i < n; i++)
			represent = represent + one;
	}
	else if (n == 9)
		represent = one + ten;
	else if (n == 4)
		represent = one + five;
	else
	{
		represent = five;
		for (i = 0; i < (n - 5); i++)
			represent = represent + one;
	}
	return represent;
}
int convert_roman_letter(char letter)
{
	if (letter == 'M')
		return 1000;
	else if (letter == 'D')
		return 500;
	else if (letter == 'C')
		return 100;
	else if (letter == 'L')
		return 50;
	else if (letter == 'X')
		return 10;
	else if (letter == 'V')
		return 5;
	else if (letter == 'I')
		return 1;
	return 0;
}
Employee read_employee()
{
	//The peoblem is mixing between getline and cin
	std::cin.ignore();
	std::cout << "Please enter the name: ";
	std::string name;
	getline(std::cin, name);
	std::cout << "Please enter the salary: ";
	double salary;
	std::cin >> salary;
	Employee r(name, salary);
	return r;
}
