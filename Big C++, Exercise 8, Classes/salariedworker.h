#pragma once
#ifndef SALARIEDWORKER_H
#define SALARIEDWORKER_H

#include "worker.h"

class SalariedWorker : public Worker
{
public:
	/**
		Constructs the Worker object with an empty name and zero salary rate
	*/
	SalariedWorker();
	/**
		Constructs the Worker object with a given name and a salary rate
		@param name the worker name
		@param salary the worker salary rate per hour
	*/
	SalariedWorker(const std::string& worker_name, double worker_salary_rate);

private:

};
#endif