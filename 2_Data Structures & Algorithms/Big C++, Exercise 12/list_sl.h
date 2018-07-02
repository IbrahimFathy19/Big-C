#pragma once

#ifndef LIST_SL_H
#define LIST_SL

#include "node_sl.h"
#include "iterator_sl.h" 

class List_SL
{
public:
	/**
	Constructs an empty list;
	*/
	List_SL();
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
	void insert(Iterator_SL iter, int n);
	/**
	Removes an element from the list.
	@param iter the position to remove
	@return an iterator pointing to the element after the
	erased element
	*/
	Iterator_SL erase(Iterator_SL iter);
	/**
	Gets the beginning position of the list.
	@return an iterator pointing to the beginning of the list
	*/
	Iterator_SL begin();
	/**
	Gets the past-the-end position of the list.
	@return an iterator pointing past the end of the list
	*/
	Iterator_SL end();
	/**
	Gets the size of the list
	@return the size of this list
	*/
	size_t get_size();
private:
	Node_SL * first;
	Node_SL* last;
	size_t size;
	friend class Iterator_SL;
};


#endif // !LIST_SL