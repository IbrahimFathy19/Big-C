//Big C++, Exercise 1
/*The problems is divided into functions, each function indicates the name
of the problem, for example function p1 stands for problem 1*/


#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;


void R16();
void R18();
void P1();
void P2();
void P3();
void P4();
void P5();


int main()
{
	std::string problem_name;
	std::cout << "Write the code of the problem to show the solution of it: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl
		<< "Contents: r16, r18, p1, p2, p3, p4, p5" << std::endl
		<< "******\n";

	do {
		std::cout << "Enter the problem's code: ";
		getline(std::cin, problem_name);
		if (problem_name == ("r16"))
			R16();
		else if (problem_name == ("r18"))
			R18();
		else if (problem_name == ("p1"))
			P1();
		else if (problem_name == ("p2"))
			P2();
		else if (problem_name == ("p3"))
			P3();
		else if (problem_name == ("p4"))
			P4();
		else if (problem_name == ("p5"))
			P5();

		else
			std::cout << "Error, no such problem was found. Try again!\n";

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n\a";

	return 0;

}
void R16()
{
	/* account = $10,000 + .005 * account - $500 for every month */
	double account = 10000;
	int n = 0;
	while (account > 500)
	{
		account = account + .005 * account;
		account = account - 500;
		n++; // number of months
		cout << "account = " << account << endl;
	}
	float n_years = n / 12.0;
	cout << "Number of years = " << n_years << " year" << endl << "End" << endl;
	return;
}
void R18()
{
	double pi = 0; int n = 1;
	double x; double y; double z;
	for (int i = 0; i < 100e5; i++)
	{
		x = 1.0 / n;
		y = 1.0 / (n + 2);
		z = x - y;
		n = n + 4;
		pi += z;
	}
	cout << setprecision(100) << (4 * pi) << endl << "End" << endl;
	return;
}

// Programming exercises 
void P1()
{
	cout << "Hello, my name is Hal! \n";
	cout << "What would you like me to do ?" << endl;
	string string_input;
	cin.ignore();
	getline(cin, string_input);
	cout << "I am sorry, I cannot do that." << endl << "End" << endl;
}
void P2()
{
	string user_name;
	cout << "Hello, my name is Hal!" << endl;
	cout << "What is your name?" << endl;
	cin.ignore();
	getline(cin, user_name);
	cout << "Hello, " << user_name << ". I am glad to meet you!" << endl << "End" << endl;
}
void P3()
{
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	cout << sum << endl << "End" << endl;
}
void P4()
{
	int product = 1;
	double sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		product *= i;
		sum += 1.0 / i;
	}
	cout << "Product = " << product << endl;
	cout << "Sum = " << sum << endl << "End" << endl;
}
void P5()
{
	cout << "__________" << endl << "|  Dave  |" << endl << "|________|" << endl << "End" << endl;
}
