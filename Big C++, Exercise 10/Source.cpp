#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>


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
	std::cout << "Write the letter \"p\" followed by the problem numberto show the solution: \n"
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

}



void p8()
{

}

void p9()
{

}

void p10()
{

}

void p11()
{

}

void p12()
{

}

void p13()
{

}

void p14()
{

}