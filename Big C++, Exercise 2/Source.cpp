//Big C++, Exercise 2
/*The problems is divided into functions, each function indicates the name
of the problem, for example function p1 stands for problem 1*/



#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include "ccc_time.h"
#include "ccc_empl.h"

using namespace std;

const double PI = 3.141592653589793238463;

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
void p15();
void p16();
void p17();
void p18();
void p19();
void p20();
void p21();
void p29();
void p30();

int main()
{
	std::cout << "Write the letter \"p\" followed by the problem numberto show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;
	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23" << std::endl
		<< "p24, p25, p26, p27, p28, p29, p30" << std::endl
		<< "******\n";
	string string_input;
	do {
		std::cout << "Enter the problem's code: ";
		std::cin >> string_input;
		if (string_input == ("p1"))
			p1();
		else if (string_input == ("p2"))
			p2();
		else if (string_input == ("p3"))
			p3();
		else if (string_input == ("p4"))
			p4();
		else if (string_input == ("p5"))
			p5();
		else if (string_input == ("p6"))
			p6();
		else if (string_input == ("p7"))
			p7();
		else if (string_input == ("p8"))
			p8();
		else if (string_input == ("p9"))
			p9();
		else if (string_input == ("p10"))
			p10();
		else if (string_input == ("p11"))
			p11();
		else if (string_input == ("p12"))
			p12();
		else if (string_input == ("p13"))
			p13();
		else if (string_input == ("p14"))
			p14();
		else if (string_input == ("p15"))
			p15();
		else if (string_input == ("p16"))
			p16();
		else if (string_input == ("p17"))
			p17();
		else if (string_input == ("p18"))
			p18();
		else if (string_input == ("p19"))
			p19();
		else if (string_input == ("p20"))
			p20();
		else if (string_input == ("p21"))
			p21();
		else if (string_input == ("p22") ||
			string_input == ("p23") || string_input == ("p24")
			|| string_input == ("p25") || string_input == ("p26")
			|| string_input == ("p27") || string_input == ("p28"))
			std::cout << "Graphical!, In a separate file!\n";
		else if (string_input == ("p29"))
			p29();
		else if (string_input == ("p30"))
			p30();
	} while (string_input != ("Quit"));
	cout << "Thanks" << endl;
	return 0;
}

void p1()
{
	cout << " as integers " << endl;
	unsigned long long num;
	for (int i = 0; i < 12; i++)
	{
		num = static_cast<long long>(pow(10, i));
		cout << num << endl;
	}
	cout << " ************** " << endl;
	cout << " as floating-point numbers" << endl;
	double num2;
	for (int i = 0; i < 12; i++)
	{
		num2 = pow(10, i);
		cout << num2 << endl;
	}
}
void p2()
{
	for (int i = 1; i <= 5; i++)
	{
		cout << i << " ^ 2 = " << i * i << endl
			<< i << " ^ 3 = " << pow(i, 3) << endl
			<< i << " ^ 4 = " << pow(i, 4) << endl
			<< "-------------" << endl;
	}
}
void p3()
{
	cout << "Enter two integers: " << endl;
	int in1, in2;    //in stands for input
	cin >> in1 >> in2;
	// the sum
	cout << "Sum = " << in1 + in2 << endl;
	// the difference
	cout << "Difference = " << in1 - in2 << endl;
	// the product 
	cout << "Product = " << in1 * in2 << endl;
	// the average 
	cout << "Average = " << (in1 + in2) / 2.0 << endl;
	// the distance
	cout << "Distance = " << abs(in1 - in2) << endl;
	// the maximum 
	/**	int max = in1;
	if (in1 < in2)
	max = in2;
	cout << "max = " << max << endl;
	*/ // or
	cout << "max = " << max(in1, in2) << endl
		<< "min = " << min(in1, in2) << endl;
}
void p4()
{
	cout << "Enter the distance (in meters) you want to convert" << endl;
	double distance_meter;
	cin >> distance_meter;

	const double mile_in_km = 0.621371;
	const short feet_in_mile = 5280;
	const short inch_in_foot = 12;
	const double feet_in_meter = 3.28084;
	const double inch_in_meter = 38.3701;

	// convert to miles
	cout << "Distance= " << (distance_meter / 1000.0) * mile_in_km << " mile" << endl;
	// convert to feet
	cout << "Distance= " << distance_meter * feet_in_meter << " foot" << endl;
	// convert to inches
	cout << "Distance= " << distance_meter * inch_in_meter << " inch" << endl;

	// To convert to mile, foot, inch
	double convert = (distance_meter / 1000.0) * mile_in_km;
	int miles = static_cast<int>(convert);
	double fraction = (convert - miles);
	convert = fraction * feet_in_mile;
	int feet = static_cast<int>(convert);
	fraction = convert - feet;
	convert = fraction * inch_in_foot;
	int inches = static_cast<int>(convert);
	cout << "Distance= " << miles << " mile & " << feet << " foot & " << inches << " inch" << endl;
}
void p5()
{
	cout << "Enter radius R: " << endl;
	double radius;
	cin >> radius;
	cout << "Area of a circle with radius " << radius << " = " << radius * radius*PI << endl
		<< "Circumference of a circle with radius " << radius << " = " << 2 * radius*PI << endl
		<< "Volume of a sphere with radius " << radius << " = " << (4.0 / 3.0)*PI*pow(radius, 3) << endl
		<< "Surface area of a sphere with radius " << radius << " = " << 4 * PI*radius*radius << endl;
}
void p6()
{
	cout << "Enter the lengths of the sides of a rectangle" << endl;
	double length, width;
	cout << "length = ";
	cin >> length;
	cout << "width = ";
	cin >> width;
	cout << "Area = " << length * width << endl
		<< "Perimeter = " << 2 * (length + width) << endl
		<< "Length of the diagonal = " << sqrt(length * length + width * width) << endl;
}
void p7()
{
	cout << "Enter the lengths of two sides of a triangle: " << endl;
	double side1, side2;
	cout << "length of side one = ";
	cin >> side1;
	cout << "length of side two = ";
	cin >> side2;

	cout << "Enter the angle between the two sides (in degrees): " << endl;
	double angle1; // between side1, side2
	cout << "angle = ";
	cin >> angle1;

	double side3 = abs(sqrt(side1*side1 + side2 * side2 - 2 * side1*side2*cos(angle1*PI / 180.0)));
	//note :Value representing an angle expressed in radians in cos function
	cout << "length of third side = " << side3 << endl;
	double angle2; // between side2, side3
	angle2 = acos((pow(side3, 2) + pow(side2, 2) - pow(side1, 2)) / (2 * side2*side3))*180.0 / PI;
	double angle3 = 180 - (angle1 + angle2);
	cout << "Angle between " << side2 << " and " << side3 << " = " << angle2 << endl;
	cout << "Angle between " << side1 << " and " << side3 << " = " << angle3 << endl;
}
void p8()
{
	cout << "Enter the length of side c of a triangle: " << endl;
	double c;
	cout << "length of side c = ";
	cin >> c;
	cout << "two angles adjacent to that side (in degrees): " << endl;
	double A, B;
	cout << "angle A = ";
	cin >> A;
	cout << "angle B = ";
	cin >> B;

	double C = 180 - (A + B);
	double a, b;
	a = (c*sin(A* PI / 180.0)) / sin(C * PI / 180.0);
	b = (c*sin(B* PI / 180.0)) / sin(C * PI / 180.0);
	cout << "length of side a = " << a << endl
		<< "length of side b = " << b << endl;
}
void p9()
{
	double amount_due, amount_recieved; // in dollars
	cout << "Enter the amount due = ";
	cin >> amount_due;
	cout << "Enter the amount recieved = ";
	cin >> amount_recieved;

	int diffrence_in_pennies = static_cast<int>((amount_recieved - amount_due) * 100);
	short dollars = diffrence_in_pennies / 100;
	diffrence_in_pennies = diffrence_in_pennies - (dollars * 100);
	short quarters = diffrence_in_pennies / 25;
	diffrence_in_pennies = diffrence_in_pennies - (quarters * 25);
	short dimes = diffrence_in_pennies / 10;
	diffrence_in_pennies = diffrence_in_pennies - (dimes * 10);
	short nickels = diffrence_in_pennies / 5;
	diffrence_in_pennies = diffrence_in_pennies - (nickels * 5);
	short pennies = diffrence_in_pennies;
	cout << "change = " << dollars << " dollar, " << quarters << " quarters, " << dimes
		<< " dimes, " << nickels << " nickels, " << pennies << " pennies" << endl;
}
void p10()
{
	double gallon_in_tank;
	double fuel_efficiency;
	double gallon_price;
	cout << "Number of gallons of gas in the tank = ";
	cin >> gallon_in_tank;
	cout << "Fuel efficiency in miles per gallon (in percentage %) = ";
	cin >> fuel_efficiency;
	cout << "Price of gas per gallon = ";
	cin >> gallon_price;

	double miles = gallon_in_tank * (fuel_efficiency / 100.0);
	double price_100_mile = (100 / (fuel_efficiency / 100.0))*gallon_price;  // gives the number of gallons
	cout << "The car can go a distance: " << miles <<
		" miles " << endl << "The cost per 100 miles : " << price_100_mile << "$" << endl;
}
void p11()
{
	char drive_letter;
	string path;
	string file_name;
	string extension;
	cout << "Enter the drive letter : ";
	cin >> drive_letter;
	cout << "Enter the path in form of (\\Windows\\System) : ";
	cin >> path;
	cout << "Enter the file name : ";
	cin >> file_name;
	cout << "Enter the extension : ";
	cin >> extension;
	cout << "The complete file name : " << drive_letter << ":" << path << "\\" << file_name
		<< "." << extension << endl;
}
void p12()
{
	int input;
	cout << "Please enter an integer >= 1000: ";
	cin >> input;
	int thousand = input / 1000;
	if (input != thousand * 1000)
		cout << thousand << "," << input - (thousand * 1000) << endl;
	else
		cout << thousand << ",000" << endl;
}
void p13()
{
	string input;
	cout << "Please enter an integer between 1,000 and 999,999: ";
	cin >> input;
	int n = input.length();
	string input_before_comma = input.substr(0, n - 4);
	string input_after_comma = input.substr(n - 3);
	cout << input_before_comma << input_after_comma << endl;
}
void p14()
{
	string comb_shaped = "+--+--+--+\n|  |  |  |";
	string bottom_line = "+--+--+--+";

	for (int i = 0; i < 3; i++)
	{
		cout << comb_shaped << endl;
	}
	cout << bottom_line << endl;
}
void p15()
{
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	string input_string = to_string(input); // convert the input to string
	int n = input_string.length();

	for (int i = 0; i < n; i++)
	{
		cout << input_string.substr(i, 1) << " ";
	}
	cout << endl;
}
void p16()
{
	int first_time, second_time;
	cout << "Please enter the first time(in military form,ex (1345)): ";
	cin >> first_time;
	cout << "Please enter the second time: ";
	cin >> second_time;
	int diff_in_minutes = abs(first_time - second_time);
	int hours = diff_in_minutes / 100;
	diff_in_minutes = diff_in_minutes - hours * 100;
	cout << hours << " hours " << diff_in_minutes << " minutes" << endl;
}
void p17()
{
	double total = 0;
	//	cout << "total = " << total << "\n";

	cout << "Please enter a number: ";
	double x1;
	cin >> x1;

	total = total + x1;
	//	cout << "total = " << total << "\n";
	cout << "Please enter a number: ";
	double x2;
	cin >> x2;
	total = total + x2;
	//	cout << "total = " << total << "\n";
	total = total / 2.0;
	//	cout << "total = " << total << "\n";
	cout << "The average is " << total << "\n";
}
void p18()
{
	const string letter_H = "*   *\n*   *\n*****\n*   *\n*   *\n";
	const string letter_E = "*****\n*    \n*****\n*    \n*****\n";
	const string letter_L = "*    \n*    \n*    \n*    \n*****\n";
	const string letter_I = "*****\n  *  \n  *  \n  *  \n*****\n";
	const string letter_O = "  *  \n * * \n*   *\n * * \n  *  \n";
	cout << "Letter H: \n" << "----------\n" << letter_H;
	cout << "Letter E: \n" << "----------\n" << letter_E;
	cout << "Letter L: \n" << "----------\n" << letter_L;
	cout << "Letter I: \n" << "----------\n" << letter_I;
	cout << "Letter O: \n" << "----------\n" << letter_O;
}
void p19()
{
	int month;
	string month_list = "January   February  March     April     May       "
		"June      July      August    September October   November  December  ";
	cout << "Enter an integer <= 12: ";
	cin >> month;
	month -= 1;
	cout << "Month " << month + 1 << " is " << month_list.substr(month * 10, 10) << endl;
}
void p20()
{
	int hours, minutes;
	cout << "Enter the due date of the next assignment:" << endl;
	cout << "hours: ";
	cin >> hours;
	cout << "minutes: ";
	cin >> minutes;
	Time now;
	Time due_date = Time(hours, minutes, 0);
	int time_left = due_date.seconds_from(now); // in seconds
	cout << time_left / 60 << " minutes" << endl;
}
void p21()
{
	string f_name, l_name;
	int starting_salary;
	cout << "Enter the first name of the employee: ";
	cin >> f_name;
	cout << "Enter the last name of the employee: ";
	cin >> l_name;
	cout << "Enter a starting salary: ";
	cin >> starting_salary;
	string full_name = f_name + " " + l_name;
	Employee employee(full_name, starting_salary);
	employee.set_salary(starting_salary + 0.05*starting_salary);
	cout << "Name: " << employee.get_name() << endl
		<< "NEW Salary: " << employee.get_salary() << endl;
}

void p29()
{
	cout << "This program is to test how fast you can type \n"
		<< "By typing the following sentence: " << endl
		<< "The quick brown fox jumps over the lazy dog" << endl
		<< "Press Enter if you're ready!" << endl;
	cin.get();
	if (cin.get() == '\n')
	{
	begin:
		Time before_write = Time();
		cout << "The quick brown fox jumps over the lazy dog" << endl;
		string input;
		getline(cin, input);
		if (input != "The quick brown fox jumps over the lazy dog")
		{
			cout << "Try again!, Enter the correct sentence!" << endl << endl;
			goto begin;
		}
		Time after_write = Time();
		cout << "You took: " << after_write.seconds_from(before_write) << " seconds" << endl;
		if (after_write.seconds_from(before_write) > 60)
			cout << "Too slow!" << endl;
		else
			cout << "Great!" << endl;
	}

}
void p30()
{
	Employee boss("Jones, Juliet", 45000.00);
	Employee boss_with_new_name("Arterton, Gemma", 45000.00);
	boss = boss_with_new_name;
	cout << "Name: " << boss.get_name() << "\n";
	cout << "Salary: " << boss.get_salary() << "\n";
}