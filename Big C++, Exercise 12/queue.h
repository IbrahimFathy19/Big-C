#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <list>

class Queue
{
public:
	/**
		Constructs a queue with empty nodes
	*/
	Queue();
	/**
		Pushes a new data into the queue
		@param data new element to be pushed
	*/
	void push(const std::string& data);
	/**
		pop the top element of the queue
	*/
	void pop();
	/**
		Gets the size of the queue
		@return the size
	*/
	size_t size() const;
	/**
		Checks if the queue is empty or not
		@return true if the queue is empty
	*/
	bool empty() const;
	/**
		Gets the front element of the queue
		@return the front
	*/
	std::string front() const;
	/**
		Gets the back element of the queue
		@return the back
	*/
	std::string back() const;
private:
	std::list<std::string> queue;
};

#endif // !QUEUE_H
