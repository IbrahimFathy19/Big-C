#include "circ_iterator.h"

Circ_Iterator::Circ_Iterator()
{
	position = NULL;
	container = NULL;
}

int Circ_Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Circ_Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Circ_Iterator::previous()
{
	assert(position != NULL);

	Node* last = container->first->previous;
	position = position->previous;
}

bool Circ_Iterator::equals(Circ_Iterator b) const
{
	return position == b.position;
}


