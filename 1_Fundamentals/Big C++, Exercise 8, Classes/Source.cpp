/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include "ccc_empl.h"
#include "programmer.h"
#include "student.h"
#include "person.h"
#include "instructor.h"
#include "manager.h"
#include "executive.h"
#include "savings.h"
#include "checkings.h"
#include <iomanip>
#include <time.h>
#include "hourlyworker.h"
#include "salariedworker.h"
#include "appointment.h"


void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();

int main()
{
	std::string problem_name;
	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl
		<< "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14" << std::endl
		<< "******\n";

	do {
		std::cout << "Enter the problem's code: ";
		getline(std::cin, problem_name);

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

		else
			std::cout << "Error, no such problem was found. Try again!\n";

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n\a";
	
	return 0;
}

void p1()
{
	Programmer p("Hacker, Harry", 5000);
	std::cout << p.get_name() << "\n";
}

void p2()
{
	std::vector<Person*> all(3, NULL);
	all[0] = new Person("Ibrahim, Fathy", 11, 7, 1955);
	all[1] = new Student("Ibrahim, Fathy", 11, 7, 1955, "Computer Engineering");
	all[2] = new Instructor("Ibrahim, Fathy", 11, 7, 1955, 5000);
	
	for (int i = 0, n = all.size(); i < n; i++)
	{
		all[i]->print();
		std::cout << "****\n";
		delete all[i];
	}
	all.clear();
	// No virtual function version
#if 0 
	Person p("Ibrahim, Fathy", 11, 7, 1955);
	p.print();

	std::cout << "****\n";

	Student s("Ibrahim, Fathy", 11, 7, 1955, "Computer Engineering");
	s.print();

	std::cout << "****\n";

	Instructor i("Ibrahim, Fathy", 11, 7, 1955, 5000);
	i.print();
#endif
}

void p3()
{
	Manager m("Ibrahim, Fathy", 5000, "Computer Engineering");
	m.print();
	
	std::cout << "****\n";

	Executive e("Ibrahim, Fathy", 5000, "Computer Engineering", "CO");
	e.print();
}

void p4()
{
	Savings s(5000, 140318);
	for (int i = 1; i <= 30; i++) // 30 stands for month
	{
		std::cout << "Day " << std::setw(2) << i << " interst:  " <<
			s.daily_interst() << "\n";
	}
	std::cout << "****\nFinally Account data is:\n";
	s.print();
	std::cout << "****\n";
	Checkings c(5000, 140317);
	for (int i = 1; i <= 30; i++) 
	{
		std::cout << "Day " << std::setw(2) << i << " interst:  " <<
			c.daily_interst() << "\n";
	}
	std::cout << "****\nFinally Account data is:\n";
	c.print();
}

void p5()
{
	clock_t time = clock();
	
	Person* p= new Student("Ibrahim, Fathy", 11, 7, 1955, "Computer Engineering");
	p->print();

	std::cout << "Statically bound call time: " << (clock() - time) << " clock ticks\n";
	///////
	time = clock();

	Student s("Ibrahim, Fathy", 11, 7, 1955, "Computer Engineering");
	s.print();
	
	std::cout << "Dynamically bound call time: " << (clock() - time) << " clock ticks\n";
}

void p6()
{
	HourlyWorker hw("Abod, Fathy", 60);
	SalariedWorker sw("Ibrahim, Fathy", 60);

	std::cout << "Abdo has made " << hw.compute_pay(100)/*100 hours*/ <<
		" in 100 hours\n";
	std::cout << "Ibrahim has made " << sw.compute_pay(100)/*100 hours*/ <<
		" in 100 hours\n";
}

void p7()
{
	Date today(12, 2, 2017);
	Time t;
	Appointment a("Ibrahim, Fathy first date :D", today, t);

}