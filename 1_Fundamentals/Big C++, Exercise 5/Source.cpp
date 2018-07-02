/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include <string>
#include <stdio.h>
#include "message.h"
#include "mailbox.h"



int main()
{
	Message m("Ibrahim", "Abdo");
	m.append("Hello bro!");
;

	Mailbox b;
	b.add_message(m);
	Message s = b.get_message(1);
	s.print_message();
	return 0;
}




#if 0
int main()
{
	

#if 0 //test the probelm p11
	Country largest, most_populous;
	bool more = true;
	std::string test;
	std::string name;
	long population;
	double area;

	while (more == true)
	{
		Country next;
		next.read_country();
		if (next.is_larger_than(largest))
			largest = next;
		if (next.more_population_than(most_populous))
			most_populous = next;

		std::cout << "More data? (y/n)";
		std::cin >> test;
		if (test != "y")
			more = false;
	}
	std::cout << "The country with the largest area is: \n";
	largest.print_country();
	std::cout << "The most populous country is: \n";
	most_populous.print_country();
#endif
}
#endif