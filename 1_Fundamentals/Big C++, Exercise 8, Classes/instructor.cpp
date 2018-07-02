#include "instructor.h"


Instructor::Instructor()
	:Person(std::string(), 0, 0, 0)
{
	salary = 0;
}

Instructor::Instructor(const std::string & instructor_name, int month, int day,
	int year, double instructor_salary)
	:Person(instructor_name, month, day, year)
{
	salary = instructor_salary;
}

void Instructor::print() const
{
	Person::print();
	std::cout << "Salary: " << salary << "$\n";
}
