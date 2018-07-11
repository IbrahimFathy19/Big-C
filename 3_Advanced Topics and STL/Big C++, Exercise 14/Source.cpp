/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "ccc_time.h"
#include "fraction.h"
#include "list.h"
#include "money.h"
#include "complex.h"
#include "BigInterger.h"
#include <sstream>
#include "polynomial.h"
#include "set.h"
#include "matrix1.h"
#include "associative_array.h"

void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();
void p8();
void p9();
void p10();
void p11();
void p12();
void p13();
void p14();

int main()
{
	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;

	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14" << std::endl
		<< "******\n";

	std::string problem_name;
	do
	{
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
		else if (problem_name == ("p6"))
			p6();
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
		else if (problem_name == ("p14"))
			p14();

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n";
}

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

void p1()
{
	// they are all implemented
}

void p2()
{
	Fraction f(1, 0);
	if(f)
		std::cout << f << "\n";
}

void p3()
{
	// done, check the fraction class
	Fraction f; // inlined function
	Fraction f1(0); // inlined function
	if (f == f1) // inlined operator
		std::cout << f << " is equal to " << f1 << "\n";
}

void p4()
{
	List l;
	l.push_back(4);
	l.push_back(5);
	Iterator i;

	// the iterator is incremented by the prefix operator ++
	for (i = l.begin(); !i.equals(l.end()); ++i) 
		std::cout << i.get()  <<"  ";
	std::cout << "\n";
}

void p5()
{
	Money m1(5,80), m2(80, 80);
	if (m1 > m2)
		std::cout << m1 << " is greater than " << m2 <<"\n";
	else if (m1 == m2)
		std::cout << m1 << " is equal to " << m2 << "\n";
	else 
		std::cout << m1 << " is smaller than " << m2 << "\n";

	std::cout << m1 + m2 << "\n";
	std::cout << m2 - m1 << "\n";
	m1 += m2;
	std::cout << m1 << "\n";

	//We should not add * and / operators because there is no meaning of multiplying money!

	std::cout << 50 % m1 << "\n";
}

void p6()
{
	Complex c(3, 2);
	Complex c2(4, -3);

	std::cout << "c1: " << c << "\n" << "c2: " << c2 <<"\n";

	//test arithmetic operators
	std::cout << "c1 + c2 = " << c + c2 << "\n"
		<< "c1 - c2 = " << c - c2 << "\n"
		<< "c1 * c2 = " << c * c2 << "\n"
		<< "c1 / c2 = " << c / c2 << "\n";

		c += c2;
		std::cout << "c1 += c2 = " << c << "\n"
			<< "c1: " << c << "\n" << "c2: " << c2 << "\n";
		c -= c2;
		std::cout << "c1 -= c2 = " << c << "\n"
			<< "c1: " << c << "\n" << "c2: " << c2 << "\n";
		c *= c2;
		std::cout << "c1 *= c2 = " << c << "\n"
			<< "c1: " << c << "\n" << "c2: " << c2 << "\n";
		c /= c2;
		std::cout << "c1 /= c2 = " << c << "\n"
			<< "c1: " << c << "\n" << "c2: " << c2 << "\n";
		
		
}

void p7()
{
	BigInteger a("20052"),
		b("30310");

	std::cout <<  a-  b <<"\n";
	rand_seed();
	while (true)
	{
		int n = rand() % 1000000 + 1;
		int n2 = rand() % 1000000 + 1;

		std::string add_result1 = std::to_string(n + n2);
		std::string sub_result1 = std::to_string(n - n2);

		std::string n_str = std::to_string(n),
			n2_str = std::to_string(n2);

		BigInteger a(n_str),
			b(n2_str);

		std::ostringstream str_stream;
		str_stream << a + b;

		std::string add_result2 = str_stream.str();

		str_stream.clear();
		str_stream.str(std::string());
		str_stream << a - b;
		std::string sub_result2 = str_stream.str();

		std::cout << n << std::setw(10) << n2 << std::setw(15) << add_result1 << std::setw(15)
			<< add_result2 << std::setw(20) << "\n";
		std::cout << n << std::setw(10) << n2 << std::setw(15) << sub_result1 << std::setw(15)
			<< sub_result2 << std::setw(20) << "\n";

		if (add_result1 != add_result2 || sub_result1 != sub_result2)
		{
			std::cout << "Wrong answer\n";
			break;
		}
		else
			std::cout << "OK\n";
	}
}

void p8()
{
	static const double arr[] = { 6,2,7,9 };
	vector<double> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	Polynomial p1(vec);

	static const double arr2[] = { 1,5,2,3 };
	vector<double> vec2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

	Polynomial p2(vec2);
	std::cout << p1 + p2;

}

void p9()
{
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);

	Set s2;
	s2.add(2);
	s2.add(3);
	s2.add(4);
	

	std::cout << s <<" & " << s2 << "\n";
	std::cout << (s & s2) << "\n";

	std::cout << s << " | " << s2 << "\n";
	std::cout << (s | s2) << "\n";

	Set s3;
	s3.add(2);
	s3.add(3);
	s3.add(9);
	std::cout << ~s3 << "\n";

}

void p10()
{
	//included in p9
}

void p11()
{
	//Build class Vector that contains std::vector<double> as data field
}

void p12()
{
	Matrix m1;
	Matrix m2;

	const size_t COLUMNS = 3,
		ROWS = 3;

	rand_seed();
	for (size_t i = 0; i < ROWS; i++)
		for (size_t j = 0; j < COLUMNS; j++)
		{
			int n = rand() % 15 + 1;
			n = rand() % 15 + 1;
			m1(i, j) = n;
			m2(i, j) = n;
		}

	std::cout << "m1\n" << m1 << "\n";
	std::cout << "-m1\n" << -m1;


	-m1; // return m1 as it were
	std::cout << "m1\n" << m1 << "m2\n" << m2
		<<"m1 - m2 = \n" << m1 - m2;

	static const double arr[] = { 6,7,9 };
	vector<double> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "m1 * {6, 7, 9} Column = \n" << m1 * vec;
}

void p13()
{
	//included in p12
}

void p14()
{
	AssociativeArray prices;
	prices["Toaster Oven"] = 19.95;
	prices["Car Vacuum"] = 24.95;
	prices["MS Car"] = 30000;

	std::cout << prices["Toaster Oven"] << "\n";
	std::cout << prices["Car Vacuum"] << "\n";
	std::cout << prices[2] << "\n";

	std::cout << "Toaster Oven and, Car Vacuum costs: "
		<< prices["Toaster Oven"] + prices["Car Vacuum"] << "\n";
}