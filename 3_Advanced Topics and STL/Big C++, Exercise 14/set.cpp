#include "set.h"
#include <algorithm>

Set::Set()
{
}

void Set::add(int x)
{
	if (count(x) > 0) // it exists, do nothing
		;
	else
		elements.push_back(x);
}

void Set::remove(int x)
{
	size_t i;
	if (count(x, i) > 0) // it exists, remove it
	{
		std::vector<int>::iterator iter = elements.begin();
		std::advance(iter, i);
		elements.erase(iter);
	}
	else
		; // it doesn't exist, do nothing 
}

int Set::count(int x) const
{
	int c = 0;
	for (size_t i = 0, n = elements.size(); i < n; i++)
		if (elements[i] == x)
			c++;
	
	return c;
}

int Set::count(int x, size_t & index) const
{
	int c = 0;
	size_t n = elements.size(), i;
	for (i = 0; i < n; i++)
	{
		if (elements[i] == x)
		{
			c++;
			index = i;
		}
	}
	return c;
}

std::vector<int> Set::get_elements() const
{
	return elements;
}

Set operator&(const Set& s, const Set& s2)
{
	Set result;
	std::vector<int> elements_s = s.get_elements(),
		elements_s2 = s2.get_elements();
	for (size_t i = 0, n = elements_s.size(); i < n; i++)
	{
		if (s2.count(elements_s[i]) > 0) // if the element of the 1st set exists in the second set
		{
			//they do intersect
			result.add(elements_s[i]);
		}
	}
	return result;
}

Set operator|(const Set& s, const Set& s2)
{
	Set result;
	std::vector<int> elements_s = s.get_elements(),
		elements_s2 = s2.get_elements();
	
	for (size_t i = 0, n = elements_s.size(); i < n; i++)
		result.add(elements_s[i]);

	for (size_t i = 0, n = elements_s2.size(); i < n; i++)
		result.add(elements_s2[i]);

	return result;
}

Set operator~(const Set & s)
{
	Set result;
	std::vector<int> elements = s.get_elements();
	std::vector<int>::iterator min_iter = std::min(elements.begin(), elements.end());
	int min = *min_iter;
	
	std::vector<int>::iterator max_iter = std::max_element(elements.begin(), elements.end());
	int max = *max_iter;
	for (int i = min; i < max; i++)
		if (s.count(i) == 0)
			result.add(i);

	return result;
}

std::ostream & operator<<(std::ostream & out, const Set & s)
{
	std::vector<int> elements = s.get_elements();
	out << "{ ";
	for (size_t i = 0, n = elements.size(); i < n; i++)
	{
		out << elements[i];
		
		if (i == n - 1) // last iteration
			out << " }";
		else
			out << ", ";
	}

	return out;
}
