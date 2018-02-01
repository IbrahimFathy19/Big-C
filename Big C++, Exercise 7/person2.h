#pragma once
#ifndef PERSON2_H
#define PERSON2_H

#include <string>

class Person2
{
public: 
	Person2();
	Person2(const std::string& n, int a);
	void update_age(int a);
private:
	std::string name;
	int age;
};



#endif