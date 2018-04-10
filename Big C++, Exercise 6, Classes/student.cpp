#include "student.h"

Student::Student()
{
		birthDay_day = 0;
		birthDay_month = 0;
		birthDay_year = 0;
}

void Student::read_student()
{
	std::cout << "Enter the student's name: ";
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << "Enter the birthday date:\n";
	std::cout << "day: ";
	std::cin >> birthDay_day;
	std::cout << "month: ";
	std::cin >> birthDay_month;
	std::cout << "year: ";
	std::cin >> birthDay_year;
}

int Student::get_month() const
{
	return birthDay_month;
}

void Student::print_student() const
{
	std::cout << "Student's name: " << this->name << "\n"
		<< "Birthday: " << birthDay_day << "/" << birthDay_month << "/"
		<< birthDay_year << "\n";
}
std::vector<Student> find_friends(const std::vector<Student>& friends)
{
	std::vector<Student> mutual_birthdays;
	for (int i = 0, n = friends.size(); i < n - 1; i++)
	{//change this condition to test whether the student's month equals to the current
		//month or not! 
		if (friends[i].get_month() == friends[i + 1].get_month())
		{
			mutual_birthdays.push_back(friends[i]);
			mutual_birthdays.push_back(friends[i + 1]);
		}
	}
	return mutual_birthdays;
}
