#pragma once
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "worker.h"

class HourlyWorker : public Worker 
{
public:
	/**
		Constructs the Worker object with an empty name and zero salary rate
	*/
	HourlyWorker();
	/**
		Constructs the Worker object with a given name and a salary rate
		@param name the worker name
		@param salary the worker salary rate per hour
	*/
	HourlyWorker(const std::string& worker_name, double worker_salary_rate);
	/**
		Computes the wage for Hourly worker
		@param hours the number of hours the worker did
		@return the wage of this worker
	*/
	virtual double compute_pay(int hours) const;
private:

};
#endif