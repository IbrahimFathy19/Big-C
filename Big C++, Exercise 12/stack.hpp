#pragma once
#ifndef STACK_H
#define STACK_H

#include <list>

class Stack
{
public:
	/**
		Constructs a stack with empty nodes
	*/
	Stack();
	/**
		Pushes a new data into the stack
		@param data new element to be pushed
	*/
	void push(const std::string& data);
	/**
		pop the top element of the stack
	*/
	void pop();
	/**
		Gets the size of the stack
		@return the size
	*/
	size_t size() const;
	/**
		Checks if the stack is empty or not
		@return true if the stack is empty
	*/
	bool empty() const;
	/**
		Gets the top element of the stack
		@return the top
	*/
	std::string top() const;
private:
	std::list<std::string> stack;
};

#endif // !STACK_H
