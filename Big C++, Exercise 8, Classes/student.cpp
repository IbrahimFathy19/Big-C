#include "student.h"

Student::Student()
	:Person(std::string(), 0, 0, 0)
{
}
Student::Student(const std::string& student_name, int month, int day,
	int year, const std::string& student_major)
	:Person(student_name, month, day, year), 
	major(student_major)
{
}
void Student::print() const
{
	Person::print();
	std::cout <<"Major: " << major << "\n";
}