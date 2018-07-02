#include "queue.h"

Queue::Queue()
{
}

void Queue::push(const std::string & data)
{
	queue.push_back(data);
}

void Queue::pop()
{
	queue.pop_front();
}

size_t Queue::size() const
{
	return queue.size();
}

bool Queue::empty() const
{
	return queue.empty();
}

std::string Queue::front() const
{
	return queue.front();
}

std::string Queue::back() const
{
	return queue.back();
}

