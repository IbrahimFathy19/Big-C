#include "student.h"


Student::Student()
{
	this->id = -1;
}

Student::Student(double ID)
{
	this->id = ID;
}

void Student::add_class_value(const std::string& class_name, const std::string& value)
{
	this->class_value[class_name] = value;
}

void Student::print_student() const
{
	std::cout << "Student ID " << std::fixed << std::setprecision(0) << this->id << "\n";
	std::map<std::string, std::string>::const_iterator i;

	for (i = this->class_value.begin(); i != this->class_value.end(); i++)
		std::cout << i->first << " " << i->second << "\n";
}