#include "iterator_sl.h"


Iterator_SL::Iterator_SL()
{
	position = NULL;
	container = NULL;
	predecessor = NULL;
}

int Iterator_SL::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator_SL::next()
{
	assert(position != NULL);
	predecessor = position;
	position = position->next;
}

bool Iterator_SL::equals(Iterator_SL b) const
{
	return position == b.position;
}


