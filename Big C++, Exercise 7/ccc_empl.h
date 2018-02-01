#ifndef CCC_EMPL_H
#define CCC_EMPL_H
#include "BankAccount.h"
#include <string>

using namespace std;

/**
   A basic employee class that is used in many examples
   in the book "Computing Concepts with C++ Essentials"
*/
class Employee
{
public:
   /**
      Constructs an employee with empty name and no salary.
   */
   Employee();
   /**
      Constructs an employee with a given name and salary.
      @param employee_name the employee name
      @param initial_salary the initial salary
   */
   Employee(string employee_name, double initial_salary);
	/**
	Constructs an employee with a given name, salary and bank account.
	@param employee_name the employee name
	@param initial_salary the initial salary
	@param account the Bank Account
	*/
	Employee(string employee_name, double initial_salary, BankAccount* account);
   /**
      Sets the salary of this employee.
      @param new_salary the new salary value
   */
   void set_salary(double new_salary);
   /**
      Gets the salary of this employee.
      @return the current salary
   */
   double get_salary() const;
   /**
      Gets the name of this employee.
      @return the employee name
   */
   string get_name() const;
	/**
		Sets the Bank account for the employee
		@param account the bank account of this empployee
	*/
	void set_account(BankAccount* account);
	/**
		Gets the account balance of this employee.
		@return the account balance pointer
	*/
	BankAccount* get_account() const;
	/**
	
	
	*/
	void format(char buffer[], int buffer_maxlength);
private:
   string name;
   double salary;
	BankAccount* acc;
};

#endif
