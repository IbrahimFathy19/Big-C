/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>


void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void roman_conversion(int number, std::string less,
	std::string half, std::string more);
void p7();
void p8();
void p9();
void p10();
double get_double();
int get_int();
void p11();
void p12();
void p13();
void p14();
void p15();
void p16();
void p18();
void p20();
void p21();
void p22();



int main()
{
	std::string problem_name;
	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;
	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23" << std::endl
		<< "p24, p25, p26, p27, p28, p29, p30" << std::endl
		<< "******\n";


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
		else if (problem_name == ("p15"))
			p15();
		else if (problem_name == ("p16"))
			p16();
		else if (problem_name == ("p17"))
			std::cout << "In a separate file (Redirectoin Input Folder)!\n";
		else if (problem_name == ("p18"))
			p18();
		else if (problem_name == ("p19"))
			std::cout << "In a separate file (Redirectoin Input Folder)!\n";
		else if (problem_name == ("p20"))
			p20();
		else if (problem_name == ("p21"))
			p21();
		else if (problem_name == ("p22"))
			p22();
		else if (problem_name == ("p23") || problem_name == ("p24")
			|| problem_name == ("p25") || problem_name == ("p26")
			|| problem_name == ("p27") || problem_name == ("p28")
			|| problem_name == ("p29") || problem_name == ("p30"))
			std::cout << "Graphical!, In a separate file!\n";

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n\a";
	return 0;
}
void p1()
{
	double a, b, c;
	std::cout << "This program prints all of the solutions of a quadratic equation: \n"
		<< "ax^2 + bx + c = 0 \n"
		<< "Enter a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	std::cout << "c: ";
	std::cin >> c;
	double under_root = b * b - 4 * a * c;
	if (under_root < 0)
		std::cout << "NO Real Solutions\n";
	else
	{
		double x1 = (-b + sqrt(under_root)) / (2 * a);
		double x2 = (-b - sqrt(under_root)) / (2 * a);
		std::cout << "First Solution x1: " << x1 << std::endl;
		std::cout << "Second Solution x2: " << x2 << std::endl;
	}
}
void p2()
{
	std::string card_notaion;
	std::cout << "Enter the card notation: ";
	std::cin >> card_notaion;
	std::string first = card_notaion.substr(0, card_notaion.length() - 1);
	std::string last = card_notaion.substr(card_notaion.length() - 1, 2);
	//Check the first char
	if (first == "A")
		first = "Ace";
	else if (first == "J")
		first = "Jack";
	else if (first == "Q")
		first = "Queen";
	else if (first == "K")
		first = "King";
	//Check the second char
	if (last == "C")
		last = "Clubs";
	else if (last == "D")
		last = "Daimonds";
	else if (last == "H")
		last = "Hearts";
	else if (last == "S")
		last = "Spades";
	std::cout << first << " of " << last << std::endl;
}
void p3()
{
	double first, second, third;
	std::cout << "Enter three numbers: ";
	std::cin >> first >> second >> third;
	double max = first;
	if (max < second)
		max = second;
	if (max < third)
		max = third;
	std::cout << "The largest number is: " << max << std::endl;
}
void p4()
{
	std::string letter_grade;
	std::cout << "Enter a letter grade: ";
	std::cin >> letter_grade;
	std::string letter = letter_grade.substr(0, 1);
	std::string sign = letter_grade.substr(1, 2);
	double grade;
	if (letter == "A")
		grade = 4;
	else if (letter == "B")
		grade = 3;
	else if (letter == "C")
		grade = 2;
	else if (letter == "D")
		grade = 1;
	else if (letter == "F")
		grade = 0;
	if (sign == "+" && letter != "A" && letter != "F")
		grade = grade + 0.3;
	else if (sign == "-" && letter != "F")
		grade = grade - 0.3;
	std::cout << "The numeric value is " << grade << std::endl;
}
void p5()
{
	double grade;
	std::cout << "Enter the grade in numeric value: ";
	std::cin >> grade;
	double min_grade = 0.15; // 3 - 2.85
	std::string letter_grade;
	std::string sign = "";//Empty string by default
						  //Specigy the letter: 
	if (grade >= (4 - 0.5))
		letter_grade = "A";
	else if (grade < (3 + 0.5) && grade >= (3 - 0.5))
		letter_grade = "B";
	else if (grade < (2 + 0.5) && grade >= (2 - 0.5))
		letter_grade = "C";
	else if (grade < (1 + 0.5) && grade >= (1 - 0.5))
		letter_grade = "D";
	else
		letter_grade = "F";

	//Specify the sign:
	int integer_grade = static_cast<int> (grade);//get red of the fractional part

	if (grade >= (integer_grade + 1 - 0.5) && grade < (integer_grade + 1 - min_grade)
		&& letter_grade != "F")
		sign = "-";
	/*we add 1 to the integer grade because the comparison is based on the most near
	intger to "grade"
	so if the grade was 2.7 and we didn't add 1, the integer grade would be 2
	and the statement condition would be (if 1.5 <= 2.7 < 1.85)
	this is what we don't want it to be.
	we need the condition to be as follows (if 2.5 <= 2.7 < 2.85)
	assign the sign variable to be negative.*/
	else if (grade < (integer_grade + 0.5) && grade >(integer_grade + min_grade)
		&& letter_grade != "F")
		sign = "+";
	std::cout << letter_grade << sign << std::endl;
}
//Roman Numerals Converter
void p6()
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

	std::cout << "The Romana Representation of the number is: ";
	for (int i = 0; i < thousands; i++)
		std::cout << "M";

	roman_conversion(hundreds, "C", "D", "M");
	roman_conversion(tens, "X", "L", "C");
	roman_conversion(ones, "I", "V", "X");
	std::cout << std::endl;
}
void roman_conversion(int number, std::string less, std::string half, std::string more)
{
	int i;
	if (number <= 3)
	{
		for (i = 0; i < number; i++)
			std::cout << less;
	}
	else if (number == 9)
		std::cout << less << more;
	else if (number == 4)
		std::cout << less << half;
	else
	{
		std::cout << half;
		for (i = 0; i < (number - 5); i++)
			std::cout << less;
	}
}
void p7()
{
	std::string first_input;
	std::string second_input;
	std::string third_input;
	std::cout << "Enter three strings: ";
	std::cin >> first_input >> second_input >> third_input;
	std::string first;
	std::string second;
	std::string third;
	if (first_input < second_input && first_input < third_input)
	{
		first = first_input;

		second = second_input;
		third = third_input;
		if (second_input > third_input)
		{
			third = second_input;
			second = third_input;
		}
	}
	else if (second_input < first_input && second_input < third_input)
	{
		first = second_input;

		second = first_input;
		third = third_input;
		if (first_input > third_input)
		{
			second = third_input;
			third = first_input;
		}
	}
	else
	{
		first = third_input;
		second = first_input;
		third = second_input;
		if (first_input > second_input)
		{
			second = second_input;
			third = first_input;
		}
	}
	std::cout << first << "\n" << second << "\n" << third << "\n";
}
void p8()
{
	double num1, num2;
	std::cout << "Enter two floating-point numbers: ";
	std::cin >> num1 >> num2;
	if (abs(num1 - num2) > 0.01)
		std::cout << "They are different.\n";
	else
		std::cout << "They are the same up to two decimal places.\n";
}
void p9()
{
	std::string name;
	double salary;
	double totalSalary;
	double hours;
	std::cout << "Enter the employee's name: ";
	std::cin >> name;
	std::cout << "Salary per hour: ";
	salary = get_double();
	std::cout << "How many hours the employee worked in the past week: ";
	hours = get_double();

	if (hours > 40)
		totalSalary = 40 * salary + (hours - 40) * salary * 1.5;
	else
		totalSalary = hours * salary;

	std::cout << "The employee: " << name << " has $" << totalSalary << "\n";
}
void p10()
{
begin:
	std::cin.clear();
	std::cin.ignore();   //clear the buffer
	std::string convert_from;
	std::string convert_to;
	double value;
	std::cout << "Convert from? ";
	getline(std::cin, convert_from);
	std::cout << "Convert to? ";
	getline(std::cin, convert_to);
	std::cout << "Value? ";
	value = get_double();

	double result;

	//fluid calculation
	if ((convert_from == ("fl. oz") || convert_from == ("gal")) &&
		(convert_to == ("ml") || convert_to == ("l")))
	{
		if (convert_from == ("fl. oz") && convert_to == ("ml"))
			result = value * 29.586; //29.586 ml in 1 fluid oz.

		else if (convert_from == ("fl. oz") && convert_to == ("l"))
			result = (value * 29.586) / 1000.0;

		else if (convert_from == ("gal") && convert_to == ("ml"))
			result = value * 3.785 * 1000.0; //3.785 l in 1 gallon

		else if (convert_from == ("gal") && convert_to == ("l"))
			result = value * 3.785;
	}
	//mass calculation
	else if ((convert_from == ("oz") || convert_from == ("lb")) &&
		(convert_to == ("g") || convert_to == ("kg")))
	{
		if (convert_from == ("oz") && convert_to == ("g"))
			result = value * 28.3495; //28.3495 grams in 1 oz.

		else if (convert_from == ("oz") && convert_to == ("kg"))
			result = (value * 28.3495) / 1000.0;

		else if (convert_from == ("lb") && convert_to == ("g"))
			result = value * 453.6; //453.6 g in 1 pound

		else if (convert_from == ("lb") && convert_to == ("kg"))
			result = (value * 453.6) / 1000.0;
	}
	//distance calculation
	else if ((convert_from == ("in") || convert_from == ("ft") || convert_from == ("mi")) &&
		(convert_to == ("mm") || convert_to == ("cm") || convert_to == ("m")
			|| convert_to == ("km")))
	{
		if (convert_from == ("in") && convert_to == ("mm"))
			result = (value * 2.54) * 10.0; //2.45 cm in 1 inch

		else if (convert_from == ("in") && convert_to == ("cm"))
			result = value * 2.54;

		else if (convert_from == ("in") && convert_to == ("m"))
			result = (value * 2.54) / 100.0;

		else if (convert_from == ("in") && convert_to == ("km"))
			result = (value * 2.54) / 100000.0;


		else if (convert_from == ("ft") && convert_to == ("mm"))
			result = value * 30.5 * 10.0; //30.5 cm in 1 foot

		else if (convert_from == ("ft") && convert_to == ("cm"))
			result = value * 30.5;

		else if (convert_from == ("ft") && convert_to == ("m"))
			result = (value * 30.5) / 100.0;

		else if (convert_from == ("ft") && convert_to == ("km"))
			result = (value * 30.5) / 100000.0;


		else if (convert_from == ("mi") && convert_to == ("mm"))
			result = (value * 1.609) * 1000000.0; //1.609 km in 1 mile

		else if (convert_from == ("mi") && convert_to == ("cm"))
			result = (value * 1.609) * 100000.0;

		else if (convert_from == ("mi") && convert_to == ("m"))
			result = (value * 1.609) * 1000.0;

		else if (convert_from == ("mi") && convert_to == ("km"))
			result = value * 1.609;
	}
	else
	{
		std::cout << "Rejected: incompatible conversion\nTry again\n";
		goto begin;
	}
	std::cout << value << " " << convert_from << " = " << result << " " << convert_to << "\n";
}
/**
	This function uses the stream cin to get a double number from the user with confirmation that
	the input is really a number
	@return the function return a number of type double which is the correct input
	to the stream cin
*/
double get_double()
{
	double input;
	std::cin >> input;
	while (std::cin.fail())
	{	/*The cin.clear() clears the error flag on cin (so that future I/O operations
		will work correctly), and then cin.ignore(10000, '\n') skips to the next newline
		(to ignore anything else on the same line as the non-number
		so that it does not cause another parse failure).
		It will only skip up to 10000 characters, so the code is assuming
		the user will not input in a very long, invalid line.*/

		std::cout << "Not a number!\nRetry: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> input;
	}
	return input;
}
/**
	This function uses the stream cin to get a number of type integer from the user
	with confirmation that.
	the input is really a number
	@return the function return a number of type int which is the correct input
	to the stream cin.
*/
int get_int()
{
	int input;
	std::cin >> input;
	while (std::cin.fail())
	{
		/*The cin.clear() clears the error flag on cin (so that future I/O operations
		will work correctly), and then cin.ignore(10000, '\n') skips to the next newline
		(to ignore anything else on the same line as the non-number
		so that it does not cause another parse failure).
		It will only skip up to 10000 characters, so the code is assuming
		the user will not put in a very long, invalid line.*/

		std::cout << "Not a number!\nRetry: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> input;
	}
	return input;
}
void p11()
{
	const double SINGLE_LEVEL1 = 21450.00;
	const double SINGLE_LEVEL2 = 51900.00;

	const double SINGLE_TAX1 = 3217.50;
	const double SINGLE_TAX2 = 11743.50;

	const double MARRIED_LEVEL1 = 35800.00;
	const double MARRIED_LEVEL2 = 86500.00;

	const double MARRIED_TAX1 = 5370.00;
	const double MARRIED_TAX2 = 19566.00;

	const double RATE1 = 0.15;
	const double RATE2 = 0.28;
	const double RATE3 = 0.31;

	double cutoff15, cutoff28, cutoff31;

	double income;
	std::cout << "Please enter your income: ";
	std::cin >> income;

	std::cout << "Please enter s for single, m for married: ";
	std::string marital_status;
	std::cin >> marital_status;

	if (marital_status == "s")
	{
		cutoff15 = RATE1 * income;
		cutoff28 = RATE2 * income + SINGLE_TAX1;
		//	cutoff31 = RATE3 * income + SINGLE_TAX2;
	}
	else if (marital_status == "m")
	{
		cutoff15 = RATE1 * income;
		cutoff28 = RATE2 * income + MARRIED_TAX1;
		cutoff31 = RATE3 * income + MARRIED_TAX2;
	}
} ///////////////
void p12()
{
	unsigned short year;
	std::cout << "Enter the year to check whether it's a leap year or not: ";
	std::cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		std::cout << "Leap year\n";
		return;
	}
	std::cout << "Not a leap year\n";
}
void p13()
{
	int month;
	std::cout << "Enter the number of the month: ";
	std::cin >> month;

	const short num1 = 31;//months with 31 days
	const short num2 = 30;//months with 30 days

	std::cout << "Number of days in this month is: ";

	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		std::cout << num1 << " days";
	else if (month == 2) //for February
		std::cout << "28 or 29 days";
	else
		std::cout << num2 << " days";
	std::cout << "\n";
}
void p14()
{
	const double delta_t = 0.01, gravity = 9.8;
	int counter = 0, seconds = 0;
	double s = 0;//for initial distance
	double v = 100;//for initial velocity
	while (s >= 0)//condition for the cannonball while 
				  //it didn't hit the ground yet
	{
		s = s + v * delta_t; //update distance 
		v = v - gravity * delta_t; //update velocity
		counter++;
		if (counter == 1.0 / delta_t)
		{
			seconds++;
			counter = 0;
			std::cout << "Seconds: " << seconds << " sec\n"
				<< "Distance: " << s << "\nVelocity: " << v << "\n"
				<< "***\n";
		}
	}
}
void p15()
{
	double exchange_rate;
	std::cout << "Please type in today's exchange rate between U.S.dollars and Japanese yen: ";
	std::cin >> exchange_rate;
	std::cout << "Then: 1$ = " << exchange_rate << " Yen\n";

	bool test = true;
	double dollar;

	while (test == true)
	{
		std::cout << "Enter U.S. dollar value, 0 or negative to finish: ";
		std::cin >> dollar;
		if (dollar <= 0)
			test = false;
		else
		{
			std::cout << dollar << "$ = " << dollar * exchange_rate << " Yen\n";
		}
	}

}
void p16()
{
	p15();

}

//Fibonacci numbers
void p18()
{
	int term;
	std::cout << "Enter the term number of Fibonacci series to compute: ";
	std::cin >> term;
	long long fold1 = 1, fold2 = 1, fnew = 1;
	for (int i = 0; i < term - 2; i++)
	{
		fnew = fold1 + fold2;
		fold1 = fold2;
		fold2 = fnew;
	}
	if (term == 0)
		fnew = 0;
	std::cout << "f" << term << " = " << fnew << "\n";
}
void p20()
{
	int input;
	std::cout << "Enter a number: ";
	std::cin >> input;
	for (int i = 1; i <= input; i++)
	{
		if (input % i == 0)
			std::cout << i << "\n";
	}
}
//Prime Numbers calculator.
void p21()
{
	int input;
	std::cout << "Enter a number: ";
	std::cin >> input;
	bool prime;
	for (int isPrime = 2; isPrime <= input; isPrime++)
	{
		prime = true;
		for (int i = 2; i < isPrime; i++)
		{
			if (isPrime % i == 0)
			{
				//not prime
				prime = false;
				break;
			}
			else
				prime = true;
		}
		if (prime == true)
			std::cout << isPrime << "\n";
	}
}
void p22()
{
	srand(time(0));
	int size_pile = 10 + rand() % (100 - 10 + 1);//formula to produce a random number 
												 //between 10 and 100
	int computer_intelgence = 0 + rand() % (1 - 0 + 1);
	std::cout << "Computer's intelgence: ";
	///////////////////*/*/
	computer_intelgence = 0;
	///////////////////*/*/	
	if (computer_intelgence == 0)
		std::cout << "Stubid\n";
	else if (computer_intelgence == 1)
		std::cout << "Smart\n";

	int first_move = 0 + rand() % (1 - 0 + 1);

	if (first_move == 0)
		std::cout << "Computer has ";
	else if (first_move == 1)
		std::cout << "You have ";
	std::cout << "the first move\n*******\n";
	int x, r;
	bool win; // true for human, false for Computer
	while (size_pile > 0)
	{
		std::cout << "The current size of pile is: " << size_pile << '\n';
		if (first_move == 0)
		{
			if (size_pile > 1)
				r = 1 + rand() % ((size_pile / 2) - 1 + 1);
			else if (size_pile <= 1)
				r = 1;

			size_pile = size_pile - r;
			std::cout << "The computer took: " << r << "\n*******\n";
			if (size_pile == 0)
			{
				win = true;
				break;
			}
			//*****
			//The player's move:

			std::cout << "The current size of pile is: " << size_pile << '\n'
				<< "Enter a number between 1 and " << size_pile / 2 << ":\n";
			std::cin >> x;
			size_pile = size_pile - x;
			if (size_pile == 0)
			{
				win = false;
				break;
			}

		}
		else
		{

			std::cout << "Enter a number between 1 and " << size_pile / 2 << ":\n";
			std::cin >> x;
			size_pile = size_pile - x;
			if (size_pile == 0)
			{
				win = false;
				break;
			}
			//******
			//Computer's move
			if (size_pile > 1)
				r = 1 + rand() % ((size_pile / 2) - 1 + 1);
			else if (size_pile <= 1)
				r = 1;
			size_pile = size_pile - r;
			std::cout << "The computer took: " << r << "\n*******\n";
			if (size_pile == 0)
			{
				win = true;
				break;
			}
		}
	}
	if (win == true)
		std::cout << "Congrats, You win!\n";
	else
		std::cout << "Sorry, The Computer is smarter than you :(\n";
}

