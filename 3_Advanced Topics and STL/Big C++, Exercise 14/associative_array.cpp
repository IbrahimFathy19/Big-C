#include "associative_array.h"

AssociativeArray::AssociativeArray()
{
}

AssociativeArray::AssociativeArray(const std::vector<Double>& v)
{
	values = std::vector<Double>(v);
}

int AssociativeArray::find(const std::string & k) const
{
	for (int i = 0, size = values.size(); i < size; i++)
		if (values[i].key == k)
			return i;

	return -1;
}

double & AssociativeArray::operator[](const std::string & k)
{
	int i = find(k);
	if (i == -1) // not found, add it
	{
		values.push_back((Double(0, k))); // save the key
		int size = values.size();
		return values[size - 1].value; // return reference to add value to its double part
	}
	return values[i].value;
}

double AssociativeArray::operator[](const std::string & k) const
{
	//here we are allowed to just access the existed values
	int i = find(k);
	assert(i >= 0); //find function will always return i < size if this element exists
	return values[i].value;
}

double & AssociativeArray::operator[](int i)
{
	size_t size = values.size();
	assert((i >= 0) && (i < size));
	return values[i].value;
}

double AssociativeArray::operator[](int i) const
{
	size_t size = values.size();
	assert((i >= 0) && (i < size));
	return values[i].value;
}
