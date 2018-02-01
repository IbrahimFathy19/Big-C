#include "worker.h"

Worker::Worker()
{
	salary_rate = 0;
}

Worker::Worker(const std::string & worker_name, double worker_salary_rate)
	:name(worker_name)
{
	salary_rate = worker_salary_rate;
}

double Worker::compute_pay(int hours) const
{
	double wage = salary_rate * hours;// default wage _SALARIED_WAGE
	return wage;
}


double Worker::get_salary_rate() const
{
	return salary_rate;
}
