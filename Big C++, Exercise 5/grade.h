#ifndef GRADE_H
#define GRADE_H

#include <string>

class Grade
{
public:
	Grade();
	Grade(std::string new_grade);
	double convert_grade() const;

private:
	std::string grade_score;
};



#endif