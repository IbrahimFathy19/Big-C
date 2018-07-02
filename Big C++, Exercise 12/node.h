#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>

class List;
class Iterator;

class Node
{
public:
	/**
	Constructs a node with a given data value.
	@param n the data to store in this node
	*/
	Node(int n);
private:
	int data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Circular_List;
	friend class Iterator;
	friend class Circ_Iterator;
};


#endif // !NODE_H