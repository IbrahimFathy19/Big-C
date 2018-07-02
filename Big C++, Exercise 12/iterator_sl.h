#pragma once
#ifndef ITERATOR_SL_H
#define ITERATOR_SL_H

#include "list_sl.h"

class Iterator_SL
{
public:
	/**
		Constructs an iterator that does not point into any list.
	*/
	Iterator_SL();
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
		Compares two iterators
		@param b the iterator to compare with this iterator
		@return true if this iterator and b are equal
	*/
	bool equals(Iterator_SL b) const;
private:
	Node_SL * position;
	List_SL* container;
	Node_SL* predecessor;
	friend class List_SL;
};

#endif // !ITERATOR_SL_H