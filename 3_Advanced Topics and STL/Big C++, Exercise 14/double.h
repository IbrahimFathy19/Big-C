#pragma once
#ifndef DOUBLE_H
#define DOUBLE_H

#include <string>

class Double
{
public:
	Double();
	Double(double v, const std::string& k);
private:
	double value;
	std::string key;
	friend class AssociativeArray;
};

#endif // !DOUBLE_H
