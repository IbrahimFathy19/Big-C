#include "iterator.h"


Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

int Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}

Iterator& Iterator::operator++()
{
	this->next();
	return *this;
}

Iterator Iterator::operator++(int unused)
{
	Iterator i = *this;
	this->next();
	return i;
}


