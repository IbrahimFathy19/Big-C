#include "salariedworker.h"

SalariedWorker::SalariedWorker()
{
}

SalariedWorker::SalariedWorker(const std::string & worker_name, double worker_salary_rate)
	:Worker(worker_name, worker_salary_rate)
{
}
