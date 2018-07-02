#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker
{
public:
	/**
		Constructs the Worker object with an empty name and zero salary rate
	*/
	Worker();
	/**
		Constructs the Worker object with a given name and a salary rate
		@param name the worker name
		@param salary the worker salary rate per hour
	*/
	Worker(const std::string& worker_name, double worker_salary_rate);
	/**
		Computes the default pay for a worker i.e. the salaried wage
		@param hours the number of hours the worker did
		@return the wage of this worker
	*/
	virtual double compute_pay(int hours) const;

protected: 
	/**
		Gets the salary_rate of this worker
		@return the salary_rate
	*/
	double get_salary_rate() const;
private:
	std::string name;
	double salary_rate;
};

#endif