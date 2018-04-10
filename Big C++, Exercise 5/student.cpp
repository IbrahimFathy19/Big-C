#include "student.h"

Student::Student()
{
	total_score = 0;
}
Student::Student(std::string student_name, double student_total_score,
	Grade student_grade)
	:grade (student_grade), name(student_name)
{
	total_score = student_total_score;
}
std::string Student::get_name() const
{
	return name;
}
void Student::add_quiz(double quiz_score)
{
	total_score = total_score + quiz_score;
}
double Student::get_total_score() const
{
	return total_score;
}
double Student::get_average_score(int number_quizes) const
{
	double average = (total_score * 1.0) / number_quizes;
	return average;
}

void Student::add_grade(Grade new_grade)
{
	grade = new_grade;
}

double Student::get_GPA() const
{
	return grade.convert_grade();
}
