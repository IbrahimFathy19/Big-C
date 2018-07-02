#pragma once
#ifndef CIRCULAR_LIST
#define CIRCULAR_LIST

#include "node.h"
#include "circ_iterator.h" 


class Circular_List
{
public:
	/**
		Constructs an empty list;
	*/
	Circular_List();
	/**
		Appends an element to the back of the list.
		@param data the value to append
	*/
	void push_back(int data);
	/**
		Appends an element to the front of the list.
		@param data the value to append
	*/
	void push_front(int data);
	/**
		Inserts an element into the list.
		@param iter the position before which to insert
		@param n the value to append
	*/
	void insert(Circ_Iterator iter, int n);
	/**
		Removes an element from the list.
		@param iter the position to remove
		@return an iterator pointing to the element after the
		erased element
	*/
	Circ_Iterator erase(Circ_Iterator iter);
	/**
		Gets the beginning position of the list.
		@return an iterator pointing to the beginning of the list
	*/
	Circ_Iterator begin();
	/**
		reverses the nodes in a list.
	*/
	void reverse();
	/**
		Gets the size of the list
		@return the size of this list
	*/
	size_t get_size();
	/**
		Checks whether a list is empty or not
		return true if the list is empty
	*/
	bool empty() const;
private:
	Node * first;
	size_t size;
	friend class Circ_Iterator;
};
#endif // !CIRCULAR_LIST
