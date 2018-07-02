#pragma once
#ifndef NOD_SL_H
#define NOD_SL_H

#include <iostream>
#include <cassert>

class List_SL;
class Iterator_SL;

class Node_SL
{
public:
	/**
		Constructs a node with a given data value.
		@param n the data to store in this node
	*/
	Node_SL(int n);
private:
	int data;
	Node_SL* next;
	friend class List_SL;
	friend class Iterator_SL;
};


#endif // !NOD_SL_H#pragma once
