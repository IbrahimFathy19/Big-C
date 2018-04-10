#include "hourlyworker.h"

HourlyWorker::HourlyWorker()
{
}

HourlyWorker::HourlyWorker(const std::string & worker_name, double worker_salary_rate)
	:Worker(worker_name, worker_salary_rate)
{
}

double HourlyWorker::compute_pay(int hours) const
{
	const int NORMAL_HOURS = 40;
	double salary_rate = Worker::get_salary_rate();
	
	double wage = salary_rate * hours;
	if (wage > NORMAL_HOURS)
		wage += (hours - NORMAL_HOURS) * 1.5 * salary_rate;
	
	return wage;
}
