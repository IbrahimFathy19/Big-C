#pragma once

#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "iterator.h" 

class List
{
public:
	/**
		Constructs an empty list;
	*/
	List();
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
	void insert(Iterator iter, int n);
	/**
		Removes an element from the list.
		@param iter the position to remove
		@return an iterator pointing to the element after the
		erased element
	*/
	Iterator erase(Iterator iter);
	/**
		Gets the beginning position of the list.
		@return an iterator pointing to the beginning of the list
	*/
	Iterator begin();
	/**
		Gets the past-the-end position of the list.
		@return an iterator pointing past the end of the list
	*/
	Iterator end();
	/**
		reverses the nodes in a list.
	*/
	void reverse();
	/**
		Swaps the elements of this list and other
	*/
	void swap(List& other);
	/**
		Gets the size of the list
		@return the size of this list
	*/
	size_t get_size();
private:
	Node * first;
	Node* last;
	size_t size;
	friend class Iterator;
};


#endif // !LIST_H
