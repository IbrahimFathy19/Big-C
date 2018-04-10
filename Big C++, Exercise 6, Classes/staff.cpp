#include "staff.h"

Staff::Staff()
{
}

void Staff::read() 
{
	std::cout << "Enter the number of employees in the staff: ";
	int n;
	std::cin >> n;
	std::string name;
	double salary;
	std::cout << "Enter the following:\n";
	// the members vector is empty and can hold nothing
	for (int i = 0; i < n; i++)
	{
		std::cin.ignore();
		std::cout << i + 1 << ". Name: ";
		getline(std::cin, name);
		std::cout << "Salary: ";
		std::cin >> salary;
		members.push_back(Employee(name, salary));
	}
}



Employee Staff::find(const std::string & name) const
{
	if (members.size() == 0)
		return Employee();
	for (int i = 0, n = members.size(); i < n; i++)
	{
		if (members[i].get_name() == name)
			return members[i];
	}
}

void Staff::raise_salary(const std::string & name, double new_salary)
{
	Employee e = find(name);
	e.set_salary(new_salary);
}


