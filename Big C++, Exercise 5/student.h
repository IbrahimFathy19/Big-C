#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "grade.h"

class Student
{
public:
	/**
		Constructs the Student object with total_score 0
		the name is automatically constructed by the std::string class.
	*/
	Student();

	/**
		Constructs the student object with a name and new total_score
		@param student_name is the name of the student
		@param student_total_score is his new total score
	*/
	Student(std::string student_name, double student_total_score, Grade student_grade);
	
	/**
		Gets the name of this student
		@return the name of the student
	*/
	std::string get_name() const;

	/**
		Adds new quiz score to the total score of the student
		@param quiz_score is the score to be added to the total_score
	*/
	void add_quiz(double quiz_score);

	/**
		Gets the total score of this student
		@return the total score of 'this' student
	*/
	double get_total_score() const;

	/**
		Gets the average score of this student
		@param number_quizes is the number of quizes that the student took
		@return the average score of 'this' student
	*/
	double get_average_score(int number_quizes) const;

	/**
		Adds new grade as a string such as (A+)
		@param new_grade is the grade of the student
	*/
	void add_grade(Grade new_grade);

	/**
		Gets the current Grade Point Average (GPA)
		@return the value of GPA
	*/
	double get_GPA() const;
private:
	std::string name;
	double total_score;
	Grade grade;
};


#endif