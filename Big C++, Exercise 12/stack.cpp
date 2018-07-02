#include "stack.hpp"
Stack::Stack()
{
}

void Stack::push(const std::string & data)
{
	stack.push_back(data);
}

void Stack::pop()
{
	stack.pop_back();
}

size_t Stack::size() const
{
	return stack.size();
}

bool Stack::empty() const
{
	return stack.empty();
}

std::string Stack::top() const
{
	return stack.back();
}

