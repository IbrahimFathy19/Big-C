#pragma once
#ifndef CAR_H
#define CAR_H

#include "person2.h"
class Car
{
public:
	Car();
	Car(const std::string& m, Person2* o, Person2* d);



private:
	std::string model;
	Person2* owner;
	Person2* driver;
};





#endif