/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "point.h"

/**
	Calculates the number of permutations of a string of length n
	@param n the length of a string
	@return the number of permutations
*/
long long number_permutations(int n);

/**
	Reverse a given string
	@param to_reverse input string and output of the function
*/
void reverse(std::string& to_reverse);

/**
	Reverse a given sub-string
	@param to_reverse input string and output of the function
*/
void reverse_substring(std::string & to_reverse);

/**
	Reverse a given string
	@param to_reverse input string and output of the function
*/
void reverse_with_helper_function(std::string & to_reverse);

/**
	Tests whether a string part is contained in a string all
	@param all string in which we search for part
	@param part string that we search for
	@return true if string part is contained in the string all
*/
bool find(const std::string & all, const std::string & part);

/**
	Returns the starting position of the first substring of the string all that matches part.
	@param all string in which we search for part
	@param part string that we search for
	@return the starting position of the first substring of the string all that matches part.
	-1 if it is not found
*/
int index_of(const std::string & all, const std::string & part);

/**
	Helper function for the index_of() function, used to keep watching the index
*/
int find_index_of(const std::string & all, const std::string & part, int index);

/**
	claculates the maximum value of an array (vetor)
	@param values Values to find the maximum of it
	@return maximum value
*/
int maximum(const std::vector<int>& values);

/**
	claculates the maximum value of an array (vetor)
	@param values Values to find the maximum of it
	@param end index of the last element in the array
	@return maximum value
*/
int maximum_subVector(const std::vector<int>& values, size_t end);

/**
	Calculates the sum of the given array in a recursive way
	It works like that: add a[0] + a[size - 1], size - 1 will be 1, 2, 3, ..., etc
	@param a Integer Array to calculate its sum
	@param size Number of Elements used in this array
*/
int sum_array(int a[], int size);

/**
	Calculates the area of a polygon with sides >= 3 by passing the coordinates of its corners
	@param corners array of the points on the corners of the polygon
	@return area of the polygon
*/
double calc_polygon_area(std::vector<Point>& corners);

/**
	Calculates the area of a triangle by passing the coordinates of its corners
	@param corners array of the points on the corners of the tringle
	@return area of the tringle
*/
double calc_triangle_area(const std::vector<Point>& corners);

/**
	Generates all possible substrings of a string s
	the substrings of the string
	"rum" are the seven strings
	"r", "ru", "rum", "u", "um", "m", ""
	@param s the string to get its substring
	@return array of substrings
*/
std::vector<std::string> generate_substrings(const std::string& s);

/**
	Generates all possible subsets of a string s
	the subsets of characters of the string "rum" are the eight strings
	"rum", "ru", "rm", "r", "um", "u", "m", ""
	@param s the string to get its subsets
	@return array of subsets
*/
std::vector<std::string> generate_subsets(const std::string & s);

/**
	Generates the permutations of a string using the iterative method
	@param s string to get its permutations
	@return vector of strings, each string represents one permutation
*/
std::vector<std::string> generate_permutations(const std::string & s);
void reverse(std::vector<int>& a, int i, int j);
bool next_permutation(std::vector<int>& a);


/**
	Checks if a given string is palindrome or not
	@param s string to be checked
	@return true if the string is palindrome
*/
bool is_palindrome(const std::string & s);

/**
	returns a string free of non-letter characters. and make its letters lowercase
	@param s input string
	@return the pure letters strings
*/
std::string lower_case_alpha_string(const std::string s);

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

void p1()
{
	int n;
	std::cout << "Enter number n: ";
	std::cin >> n;

	std::cout << "A string consists of " << n << " characters has " << number_permutations(n) << " permutations\n";
}

long long number_permutations(int n)
{
	if (n <= 0)
		return 1;
	return number_permutations(n - 1) * n;
}

void p2()
{
	std::string input;
	std::cout << "Enter a string to reverse it: ";
	std::cin.ignore();
	getline(std::cin, input);

	reverse(input);
	std::cout << "Reversed string is: " << input << "\n";
}

void reverse(std::string& to_reverse)
{
	if (to_reverse.length() <= 1)
		return;

	char first = to_reverse[0];
	to_reverse = to_reverse.substr(1);
	reverse(to_reverse);
	to_reverse = to_reverse + first;
}

void p3()
{
	std::string input;
	std::cout << "Enter a string to reverse it: ";
	std::cin.ignore();
	getline(std::cin, input);

	reverse_with_helper_function(input);
	std::cout << "Reversed string is: " << input << "\n";
}

void reverse_substring(std::string & to_reverse)
{
	if (to_reverse.length() <= 1)
		return;

	char first = to_reverse[0];
	to_reverse = to_reverse.substr(1);
	reverse_substring(to_reverse);
	to_reverse = to_reverse + first;
}

void reverse_with_helper_function(std::string & to_reverse)
{
	reverse_substring(to_reverse);
}

void p4()
{
	std::string input;
	std::cout << "Enter a string to reverse it: ";
	std::cin.ignore();
	getline(std::cin, input);

	char temp; int last;
	for (size_t i = 0, length = input.length(); i < length / 2; i++)
	{
		last = length - i - 1;
		temp = input[i];
		input[i] = input[last];
		input[last] = temp;
	}

	std::cout << "Reversed string is: " << input << "\n";
}

void p5()
{
	std::string input;
	std::string word;
	std::cin.ignore();

	std::cout << "Enter a string to find a word in it: ";
	getline(std::cin, input);
	std::cout << "Enter a word to find in this string: ";
	getline(std::cin, word);

	find(input, word) ? std::cout << word << " was found\n" : std::cout << word << " was not found\n";
}

bool find(const std::string& all, const std::string& part)
{
	if (all.substr(0, part.length()) == part)
		return true;

	if (all.length() == 1)
		return false;

	return find(all.substr(1), part);
}

void p6()
{
	std::string input;
	std::string word;
	std::cin.ignore();

	std::cout << "Enter a string to find a word in it: ";
	getline(std::cin, input);
	std::cout << "Enter a word to find in this string: ";
	getline(std::cin, word);

	std::cout << index_of(input, word) << " is the starting position of the first substring of the string " <<input<<
		" that matches " << word << "\n";
}

int index_of(const std::string& all, const std::string& part)
{
	return find_index_of(all, part, 0);
}

int find_index_of(const std::string& all, const std::string& part, int index)
{
	if (all.substr(0, part.length()) == part)
		return index;

	if (all.length() == 1)//not found
			return -1;

	index++;
	return find_index_of(all.substr(1), part, index);
}

void p7()
{
	std::vector<int> random(10);
	for (size_t i = 0, length = random.size(); i < length; i++)
	{
		random[i] = rand();
		std::cout << random[i] <<"\n";
	}
	std::cout << "Maximum value is: " << maximum(random) << "\n";
}

int maximum(const std::vector<int>& values)
{
	return maximum_subVector(values, values.size());

}

int maximum_subVector(const std::vector<int>& values, size_t end)
{
	if (end == 2)
	{
		if (values[0] > values[1])
			return values[0];
		else
			return values[1];
	}

	int maximi = maximum_subVector(values, end - 1);
	
	if (maximi > values[end - 1])
		return maximi;
	else
		return values[end - 1];
}

void p8()
{
	int random[5];
	for (size_t i = 0, length = 5; i < length; i++)
	{
		random[i] = 1 + rand() % 5;
		std::cout << random[i] << "\n";
	}
	std::cout << "Sum is: " << sum_array(random, 5) << "\n";
}

int sum_array(int a[], int size)
{
	if (size == 1)
		return a[0];

	return sum_array(a, size - 1) + a[size - 1];
}

void p9()
{
	int n_sides;
	std::cout << "Data are read from the file: p9_input.txt\n";
	std::fstream input_file("p9_input.txt");
	if (input_file.fail())
	{
		std::cout << "Error Opening data file\n";
		exit(0);
	}

	input_file >> n_sides;
	std::cout << "Number of polygon sides: " << n_sides << "\n"
		<< "Points of the polygon are: " << "\n";

	double x, y;
	std::vector<Point> corners(n_sides);
	for (size_t i = 0, length = corners.size(); i < length; i++)
	{
		input_file >> x >> y;
		corners[i] = Point(x, y);
		std::cout << "(" << x << ", " << y << ")\n";
	}
	std::cout << "Area of the Polygon: " << calc_polygon_area(corners) << "\n";
}

double calc_polygon_area(std::vector<Point>& corners)
{
	int n = corners.size();

	std::vector<Point> triangle_points(3);
	triangle_points[0] = corners[n - 1];
	triangle_points[1] = corners[n - 2];
	triangle_points[2] = corners[0];

	if (n == 3)
		return calc_triangle_area(triangle_points);

	if (n > 3)
	{
		corners.pop_back();
		double area = calc_polygon_area(corners) + calc_triangle_area(triangle_points);
		return area;
	}
	else
		return -1;
}

double calc_triangle_area(const std::vector<Point>& corners)
{
	// three Points found in corners[0], corners[1], corners[2]

	if (corners.size() == 3) 
	{		
		double x1 = corners[0].get_x(),
			y1 = corners[0].get_y(),
			x2 = corners[1].get_x(),
			y2 = corners[1].get_y(),
			x3 = corners[2].get_x(),
			y3 = corners[2].get_y();

		return abs((x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2.0);
	}
	return -1;
}

void p10()
{
	std::string s;
	std::cout << "Enter a string to generate all its substrings: ";
	std::cin >> s;
	std::vector<std::string> result = generate_substrings(s);
	for (size_t i = 0, length = result.size(); i < length; i++)
		std::cout << "\"" << result[i] <<"\""<< ", ";
	std::cout << "\n";
}

std::vector<std::string> generate_substrings(const std::string& s)
{
	std::vector<std::string> result;
	if (s.length() == 0)
	{
		result.push_back("");
		return result;
	}

	char first_char = s[0];
	std::string new_string = s.substr(1);
	for (size_t i = 0, length = s.length(); i < length; i++)
		result.push_back(first_char + new_string.substr(0, i));

	std::vector<std::string> shorter_result = generate_substrings(new_string);
	for (int j = 0, n = shorter_result.size(); j < n; j++)
		result.push_back(shorter_result[j]);

	return result;
}

void p11()
{
	std::string s;
	std::cout << "Enter a string to generate all its subsets: ";
	std::cin >> s;
	std::vector<std::string> result = generate_subsets(s);
	for (size_t i = 0, length = result.size(); i < length; i++)
		std::cout << "\"" << result[i] << "\"" << ", ";
	std::cout << "\n";
}

std::vector<std::string> generate_subsets(const std::string& s)
{
	std::vector<std::string> result;
	if (s.length() == 0)
	{
		result.push_back("");
		return result;
	}

	char first_char = s[0];
	std::string c;
	c.push_back(first_char);
	result.push_back(c);
	
	std::string new_string = s.substr(1); // remove the first character
	for (size_t j = 0, n = new_string.length(); j < n; j++)
	{
		for (size_t i = 0, length = new_string.length(); i < length; i++)
			result.push_back(first_char + new_string.substr(0, i + 1));
		new_string = new_string.substr(1);
	}

	std::vector<std::string> shorter_result = generate_substrings(s.substr(1));
	for (int j = 0, n = shorter_result.size(); j < n; j++)
		result.push_back(shorter_result[j]);

	return result;
}

void p12()
{
	std::string s;
	std::cout << "Enter a string to get its permutations: ";
	std::cin >> s;

	std::vector<std::string> result = generate_permutations(s);
	for (size_t i = 0, length = result.size(); i < length; i++)
		std::cout << result[i] << "\n";
}

std::vector<std::string> generate_permutations(const std::string& s)
{
	int n = s.length();
	std::vector<int> a(n);
	for (int i = 0; i < a.size(); i++)
		a[i] = i;

	std::vector<std::string> result;
	result.push_back(s); //push the original string

	std::string modifiable_s = s;
	while (next_permutation(a))
	{
		for (int i = 0; i < a.size(); i++)
			modifiable_s[i] = s[a[i]];
		result.push_back(modifiable_s);
	}
	return result;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void reverse(std::vector<int>& a, int i, int j)
{
	while (i < j)
	{
		swap(a[i], a[j]); i++; j--;
	}
}

bool next_permutation(std::vector<int>& a)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		if (a[i - 1] < a[i])
		{
			int j = a.size() - 1;
			while (a[i - 1] > a[j]) j--;
			swap(a[i - 1], a[j]);
			reverse(a, i, a.size() - 1);
			return true;
		}
	}
	return false;
}

void p13()
{
	std::string s;
	std::cout << "Enter a string to check if it's palindrome or not: ";
	std::cin >> s;

	s = lower_case_alpha_string(s);
	if (is_palindrome(s))
		std::cout << "It's palindrome\n";
	else
		std::cout << "It's not palindrome\n";
}

bool is_palindrome(const std::string& s)
{
	int n = s.length();

	if (n <= 1)
		return true;
	
	char first = s[0]; 
	char last = s[n - 1];

	if (first == last)
	{
		std::string shorter = s.substr(1, n - 2);
		return is_palindrome(shorter);
	}

	else
		return false;
}

std::string lower_case_alpha_string(const std::string s)
{
	std::string new_s = s;
	for (size_t i = 0, j = 0, length = s.length(); i < length; i++)
	{
		if (!isalpha(new_s[j]))
			new_s = new_s.substr(0, j) + new_s.substr(j + 1);
		else
			j++;

		new_s[j] = tolower(new_s[j]);
	}
	return new_s;
}


void p14()
{
	int n;
	std::cout << "How many disks? ";
	std::cin >> n;

	std::vector<int> disks(n),
		peg1, peg2, peg3;

	for (int i = 0; i < n; i++)
		disks[i] = i + 1; // the top disk is indexed by 1, the last disk is indexed by n

	/*while (!test_hanoi(peg3))
	{
		hanoi();
	}*/
}

bool test_hanoi(const std::vector<int>& last_peg)
{
	for (size_t i = 0, n = last_peg.size(); i < n; i++)
		if (last_peg[i] != i + 1)
			return false;

	return true;
}

void hanoi(const std::vector<int>& disks, std::vector<int> peg1, std::vector<int> peg2, 
	std::vector<int> peg3, int from, int to, int n)
{
/*	int top_peg1 = (peg1.empty) ? -1 : peg1[peg1.size() - 1];
	int top_peg2 = (peg2.empty) ? -1 : peg2[peg2.size() - 1];
	int top_peg3 = (peg3.empty) ? -1 : peg3[peg3.size() - 1];
	*/
}
