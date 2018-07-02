#pragma once
#ifndef CIRC_ITERATOR_H
#define CIRC_ITERATOR_H

#include "circular_list.h"
class Circular_List;
class Circ_Iterator
{
public:
	/**
	Constructs an iterator that does not point into any list.
	*/
	Circ_Iterator();
	/**
	Looks up the value at a position.
	@return the value of the node to which the iterator points
	*/
	int get() const;
	/**
	Advances the iterator to the next node.
	*/
	void next();
	/**
	Moves the iterator to the previous node.
	*/
	void previous();
	/**
	Compares two iterators
	@param b the iterator to compare with this iterator
	@return true if this iterator and b are equal
	*/
	bool equals(Circ_Iterator b) const;
private:
	Node * position;
	Circular_List* container;
	friend class Circular_List;
};
#endif // !CIRC_ITERATOR_H
