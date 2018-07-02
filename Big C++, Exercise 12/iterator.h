#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

class Iterator
{
public:
	/**
	Constructs an iterator that does not point into any list.
	*/
	Iterator();
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
	bool equals(Iterator b) const;
private:
	Node * position;
	List* container;
	friend class List;
};

#endif // !ITERATOR_H
