/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "ccc_empl.h"
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "ccc_time.h"
#include "appointment.h"
#include "date.h"
#include <sstream>

/**
	Gets the position of the largest element in a vector range.
	@param a the vector
	@param from the beginning of the range
	@param to the end of the range
	@return the position of the largest element in
	the range a[from]...a[to]
*/
int max_position(std::vector<int>& a, int from, int to);

/**
	Sorts a vector using the selection sort algorithm in descending order
	@param a the vector to sort
*/
void selection_sort_max(std::vector<int>& a);

/**
	Swaps two values a and b
	@param a First value to be swapped
	@param b Second value to be swapped
*/
void swap(int & x, int & y);
void swap(Employee& a, Employee& b);

/**
	Sets the seed of the random number generator.
*/
void rand_seed();

/**
	Gets the position of the smallest element in a vector range.
	@param a the vector
	@param from the beginning of the range
	@param to the end of the range
	@return the position of the smallest element in
	the range a[from]...a[to]
*/
int min_position(std::vector<Employee>& a, int from, int to);
int min_position(std::vector<int>& a, int from, int to);

/**
	Sorts a vector using the selection sort algorithm
	@param a the vector to sort
*/
void selection_sort(std::vector<Employee>& a);
void selection_sort(std::vector<int>& a);

/**
	Merges two adjacent ranges in a vector
	@param a the vector with the elements to merge
	@param from the start of the first range
	@param mid the end of the first range
	@param to the end of the second range
*/
void merge(std::vector<int>& a, int from, int mid, int to);
void merge(std::vector<Employee>& a, int from, int mid, int to);

/**
	Sorts the elements in a range of a vector.
	@param a the vector with the elements to sort
	@param from start of the range to sort
	@param to end of the range to sort
*/
void merge_sort_empl(std::vector<Employee>& a, int from, int to);
void merge_sort_nonRecursive_power2only(std::vector<int>& a, int from, int to);
void merge_sort_nonRecursive(std::vector<int>& a, int from, int to);

/**
	Finds an element in a sorted vector.
	@param v the sorted vector with the elements to search
	@param from the start of the range to search
	@param to the end of the range to search
	@param value the value to search for
	@param index is the first match. Or, if not found, the next larger value instead, 
	or to a.size() if a is larger than all the elements of the vector
	@return true if value was found
*/
bool binary_search(std::vector<int> v, int from, int to, int value, int& index);
bool binary_search(std::vector<Appointment> v, int from, int to, const Appointment & value, int & index);
/**
	@param is input stream to search in it
*/
bool binary_search(std::istream & is, int from, int to, Employee& value);

/**
	Sort Array using binary_search algorithm
	@param v vector to be sorted
*/
void sort_with_binary_search(std::vector<int>& v);

/**
	Compares two appointment times (date, starting time and ending time)
	@param a first Appointment to compare
	@param b second Appointment to compare
	@return true if a happens before b
*/
bool appointment_date_cmp(const Appointment & a, const Appointment & b);

/**
	Prints all appointments of a vector
*/
void print_all_appointment(std::vector<Appointment> appointment_list);

/**
	Prints all appointments in a given day
	@param appointment_list vector of appointments
	@param d date to list appointments in it
*/
void print_appointment_same_day(std::vector<Appointment> appointment_list, const Date & d);

/**
	Test whose salary is larger of the two given emplyees
	@return true if empl1's salary is larger than empl2's salary
*/
bool empl_salary_larger_than(const Employee & empl1, const Employee & empl2);

/**
	Sorts a stream according to "string comparisons"
	@param database Input/Output stream contains reocords of multiple employees
	@param nrecord Number of records in database stream
*/
void sort_database(std::iostream& database, int nrecord);

/**
	Converts a string to a floating-point value, e.g.
	"3.14" -> 3.14.
	@param s a string representing a floating-point value
	@return the equivalent floating-point value
*/
double string_to_double(std::string s);

/**
	Reads an employee record from a file.
	@param e filled with the employee
	@param in the stream to read from
*/
void read_employee(Employee& e, std::istream& in);

void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();
void p8();
void p9();
void p10();
void p11();
void p12();
void p13();



int main()
{
	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;

	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16" << std::endl
		<< "******\n";

	std::string problem_name;
	do
	{
		std::cout << "Enter the problem's code: ";
		std::cin >> problem_name;
		if (problem_name == ("p1"))
			p1();
		else if (problem_name == ("p2"))
			p2();
		else if (problem_name == ("p3"))
			p3();
		else if (problem_name == ("p4"))
			p4();
		else if (problem_name == ("p5"))
			p5();
		else if (problem_name == ("p6"))
			p6();
		else if (problem_name == ("p7"))
			p7();
		else if (problem_name == ("p8"))
			p8();
		else if (problem_name == ("p9"))
			p9();
		else if (problem_name == ("p10"))
			p10();
		else if (problem_name == ("p11"))
			p11();

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n";
}

void p1()
{
	std::vector<int> unsorted_vector(20);
	rand_seed();
	int random;

	std::cout << "Unsorted Vector: \n";
	for (size_t i = 0, n = unsorted_vector.size(); i < n; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		unsorted_vector[i] = random;
		std::cout << unsorted_vector[i] << " ";
	}
	std::cout << "\n**********\nSorted Vector: \n";
	selection_sort_max(unsorted_vector);
	for (size_t i = 0, n = unsorted_vector.size(); i < n; i++)
		std::cout << unsorted_vector[i] << " ";
	std::cout << "\n";
}

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

int max_position(std::vector<int>& a, int from, int to)
{
	int max_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
		if (a[i] > a[max_pos]) 
			max_pos = i;
	return max_pos;
}

void selection_sort_max(std::vector<int>& a)
{
	int next, n; // The next position to be set to the maximum

	for (next = 0, n = a.size(); next < n - 1; next++)
	{
		// Find the position of the maximum
		int max_pos = max_position(a, next, a.size() - 1);
		if (max_pos != next)
			swap(a[max_pos], a[next]);
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void p2()
{
	std::vector<Employee> empl(10);
	rand_seed();
	int random;
	std::cout << "Unsorted:\n";
	for (int i = 0, n = empl.size(); i < n; i++)
	{
		empl[i] = Employee("", random = 0 + rand() % (1000 - 0 + 1));
		std::cout << "Employee " << i << "'s Salary: " << empl[i].get_salary() << "\n";
	}
	selection_sort(empl);
	std::cout << "Sorted:\n";
	for (int i = 0, n = empl.size(); i < n; i++)
		std::cout << "Employee " << i << "'s Salary: " << empl[i].get_salary() << "\n";
}

int min_position(std::vector<Employee>& a, int from, int to)
{
	int min_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
		if (a[i] < a[min_pos]) min_pos = i;
	return min_pos;
}

void selection_sort(std::vector<Employee>& a)
{
	int next, n; // The next position to be set to the minimum

	for (next = 0, n = a.size(); next < n - 1; next++)
	{
		// Find the position of the minimum
		int min_pos = min_position(a, next, a.size() - 1);
		if (min_pos != next)
			swap(a[min_pos], a[next]);
	}
}

void swap(Employee& a, Employee& b)
{
	Employee temp = Employee(a);
	a = b;
	b = Employee(temp);
}

void p3()
{
	rand_seed();

	size_t min_n, max_n, n, measurements;
	std::cout << "Minimum size of array: ";
	std::cin >> min_n;
	std::cout << "Maximum size of array: ";
	std::cin >> max_n;
	std::cout << "Number of measurements: ";
	std::cin >> measurements;

	for (size_t i = 0; i < measurements; i++)
	{
		n = min_n + rand() % (max_n - min_n + 1);
		std::vector<int> unsorted_vector(n);
		int random;

		std::cout << "Unsorted Vector: \n";
		for (size_t j = 0, n = unsorted_vector.size(); j < n; j++)
		{
			random = 0 + rand() % (1000 - 0 + 1);
			unsorted_vector[j] = random;
			std::cout << unsorted_vector[j] << " ";
		}

		std::cout << "\nSorted Vector: \n";
		selection_sort_max(unsorted_vector);
		for (size_t j = 0, n = unsorted_vector.size(); j < n; j++)
			std::cout << unsorted_vector[j] << " ";
		std::cout << "\n\n";
	}
}

void p4()
{
	std::vector<Employee> empl(10);
	rand_seed();
	int random;
	std::cout << "Unsorted:\n";
	for (int i = 0, n = empl.size(); i < n; i++)
	{
		empl[i] = Employee("", random = 0 + rand() % (1000 - 0 + 1));
		std::cout << "Employee " << i << "'s Salary: " << empl[i].get_salary() << "\n";
	}
	merge_sort_empl(empl,0, empl.size() - 1);
	std::cout << "Sorted:\n";
	for (int i = 0, n = empl.size(); i < n; i++)
		std::cout << "Employee " << i << "'s Salary: " << empl[i].get_salary() << "\n";
}

void merge(std::vector<Employee>& a, int from, int mid, int to)
{
	int n = to - from + 1; // Size of the range to be merged 
								  // Merge both halves into a temporary vector b 
	std::vector<Employee> b(n);

	int i1 = from;
	// Next element to consider in the first half 
	int i2 = mid + 1;
	// Next element to consider in the second half 
	int j = 0; // Next open position in b 

				  // As long as neither i1 nor i2 is past the end, move the smaller
				  // element into b

	while (i1 <= mid && i2 <= to)
	{
		if (a[i1] < a[i2])
		{
			b[j] = a[i1];
			i1++;
		}
		else
		{
			b[j] = a[i2];
			i2++;
		}
		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first half
	while (i1 <= mid)
	{
		b[j] = a[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second half
	while (i2 <= to)
	{
		b[j] = a[i2];
		i2++;
		j++;
	}

	// Copy back from the temporary vector
	for (j = 0; j < n; j++)
		a[from + j] = b[j];
}

void merge_sort_empl(std::vector<Employee>& a, int from, int to)
{
	if (from == to) return;
	int mid = (from + to) / 2;
	// Sort the first and the second half
	merge_sort_empl(a, from, mid);
	merge_sort_empl(a, mid + 1, to);
	merge(a, from, mid, to);
}

void p5()
{
	
}

void p6()
{
	//test new binary_search
	std::vector<int> v(100);
	for (size_t i = 0, n = v.size(); i < n; i++)
	{
		v[i] = i;

	}
	int m;
	if (binary_search(v, 0, v.size() - 1, 100, m))
		std::cout << "Found at: " << m << "\n";
	else
		std::cout << "Doesn't exist, m = " << m << "\n";

}

bool binary_search(std::vector<int> v, int from, int to, int value, int& index)
{
	if (from > to)
	{
		index = from;
		return false;
	}
	int mid = (from + to) / 2;
	if (v[mid] == value)
	{
		index = mid;
		return true;
	}
	else if (v[mid] < value)
		return binary_search(v, mid + 1, to, value, index);
	else
		return binary_search(v, from, mid - 1, value, index);
}

void p7()
{
	//Stress Test
	rand_seed();
	while (true)
	{
		int n = rand() % 1000 + 2;
		std::cout << n << "\n";
		std::vector<int> a;
		for (int i = 0; i < n; ++i)
			a.push_back(rand() % 10000000);

		std::vector<int> b(n);
		for (int i = 0; i < n; ++i)
		{
			std::cout << a[i] << ' ';
			b[i] = a[i];
		}

		std::cout << "\n";

		std::cout << "Sorting ... Selection Sort\n";
		selection_sort(a);
		std::cout << "Done Sorting\n\nSorting ... Binary Search Sort\n";
		sort_with_binary_search(b);
		std::cout << "Done Sorting\n\n\n";

		for (int i = 0, n = a.size(); i < n; i++)
		{
			std::cout << a[i] << std::setw(10) << b[i] << std::setw(30);
			if (a[i] != b[i])
			{
				std::cout << "Wrong answer\n";
				return;
			}
			else
				std::cout << "OK\n";
		}
	}
}

/*This algorithm is of O(n log(n) + n (n + (n - 1) + (n - 2) + ... + 1 + 0) = O(n^2)*/
void sort_with_binary_search(std::vector<int>& v)
{
	int n = v.size();
	std::vector<int> to_sort(n);
	int index;
	for (int i = 0; i < n; i++)
	{
		bool result = binary_search(to_sort, 0, n - 1, v[i], index);
		if (result == false)
			index--;

		// move elements above the insertion point up.
		for (int j = 0; j < index; j++)
			to_sort[j] = to_sort[j + 1];
	
		to_sort[index] = v[i];
	}

	for (int i = 0; i < n; i++)
		v[i] = to_sort[i];
}

int min_position(std::vector<int>& a, int from, int to)
{
	int min_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
		if (a[i] < a[min_pos]) min_pos = i;
	return min_pos;
}

void selection_sort(std::vector<int>& a)
{
	int next, n; // The next position to be set to the minimum

	for (next = 0, n = a.size(); next < n - 1; next++)
	{
		// Find the position of the minimum
		int min_pos = min_position(a, next, a.size() - 1);
		if (min_pos != next)
			swap(a[min_pos], a[next]);
	}
}

void p8()	
{
	//Stress Test
	rand_seed();
	while (true)
	{
		int n = rand() % (1000 + 1) ;
		
		while (log2(n) != floor(log2(n)))
			n = rand() % 10000 + 1; // get n of power 2

		std::cout << n << "\n";
		std::vector<int> a;
		for (int i = 0; i < n; ++i)
			a.push_back(rand() % 10000000);

		std::vector<int> b(n);
		for (int i = 0; i < n; ++i)
		{
			std::cout << a[i] << ' ';
			b[i] = a[i];
		}

		std::cout << "\n";

		std::cout << "Sorting ... Selection Sort\n";
		selection_sort(a);
		std::cout << "Done Sorting\n\nSorting ... Merge Sorting\n";
		merge_sort_nonRecursive_power2only(b, 0, n - 1);
		std::cout << "Done Sorting\n\n\n";

		for (int i = 0, n = a.size(); i < n; i++)
		{
			std::cout << a[i] << std::setw(10) << b[i] << std::setw(30);
			if (a[i] != b[i])
			{
				std::cout  << "Wrong answer\n";
				return;
			}
			else
				std::cout << "OK\n";
		}
	}
}

void merge(std::vector<int>& a, int from, int mid, int to)
{
	int n = to - from + 1; // Size of the range to be merged 
								  // Merge both halves into a temporary vector b 
	std::vector<int> b(n);

	int i1 = from; // Next element to consider in the first half 
	int i2 = mid + 1; // Next element to consider in the second half 
	
	int j = 0; // Next open position in b 

				  // As long as neither i1 nor i2 is past the end, move the smaller
				  // element into b

	while (i1 <= mid && i2 <= to)
	{
		if (a[i1] < a[i2])
		{
			b[j] = a[i1];
			i1++;
		}
		else
		{
			b[j] = a[i2];
			i2++;
		}
		j++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first half
	while (i1 <= mid)
	{
		b[j] = a[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second half
	while (i2 <= to)
	{
		b[j] = a[i2];
		i2++;
		j++;
	}

	// Copy back from the temporary vector
	for (j = 0; j < n; j++)
		a[from + j] = b[j];
}

void merge_sort_nonRecursive_power2only(std::vector<int>& a, int from, int to)
{
	int mid;
	int n = to - from + 1;

	// log2() to get how many iterations needed, if n = 4, then we need to merge adjacent regions of size 1, then adjacent
	// regions of size 2, which means two sizes
	for (int i = 1; i <= log2(n); i++)
	{
		int start = from;
		while (start < to)
		{
			int next = start;
			next += static_cast<int>(pow(2, i));
			mid = (next + start) / 2 - 1;
			merge(a, start, mid, next - 1);
			start = next;		
		}
	}
}

void p9()
{
	std::vector<int> a(6);
	for (int i = 0, n = a.size(); i < n; i++)
	{
		a[i] = n - i - 1;
		std::cout << a[i] << " ";
	}
	std::cout << "\n";

	merge_sort_nonRecursive(a, 0, 5);
	for (int i = 0, n = a.size(); i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	/**	//Stress Test
	rand_seed();
	while (true)
	{
		rand_seed();
		int n = rand() % 10000 + 1;

		std::cout << n << "\n";
		std::vector<int> a;
		for (int i = 0; i < n; ++i)
			a.push_back(rand() % 10000000);

		std::vector<int> b = a;
		for (int i = 0; i < n; ++i)
		{
			std::cout << a[i] << ' ';
			b[i] = a[i];

		}

		std::cout << "\n";

		std::cout << "Sorting ... Selection Sort\n";
		selection_sort(a);
		std::cout << "Done Sorting\n\nSorting ... Merge Sorting\n";
		merge_sort_nonRecursive(b, 0, n - 1);
		std::cout << "Done Sorting\n\n\n";

		for (int i = 0, n = a.size(); i < n; i++)
		{
			std::cout << a[i] << std::setw(10) << b[i] << std::setw(30);
			if (a[i] != b[i])
			{
				std::cout  << "Wrong answer\n";
				return;
			}
			else
				std::cout << "OK\n";
		}
	}*/
}

void merge_sort_nonRecursive(std::vector<int>& a, int from, int to)
{/*
	int mid;
	int n = to - from + 1; 
	int curr_size;
	int left_start;

	// log2() to get how many iterations needed, if n = 4, then we need to merge adjacent regions of size 1, then adjacent
	// regions of size 2, which means two sizes
	for (curr_size = 1; curr_size <= n-1; curr_size =2* curr_size)
	{
		for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
		{
			mid = left_start + curr_size - 1;
			int right_end = min(left_start + 2 * curr_size - 1, n - 1);
			merge(a, start, mid, next );

		}
		int start = from;
		while (start < to)
		{
			int next = start;
			next += pow(2, i);
			if (next <= n) {
				mid = (next + start) / 2 - 1;
				merge(a, start, mid, next - 1);
			}
			start = next;
		}
	}
	*/
}

void p10()
{
	rand_seed();
	std::vector<Employee> v(15);
	for (size_t i = 0, n = v.size(); i < n; i++)
	{
		v[i] = Employee("", rand() % 15000);
		std::cout << v[i].get_salary() << "\n";
	}
	std::sort(v.begin(), v.end(), empl_salary_larger_than);
	std::cout << "Sorted Employees:\n";
	for (size_t i = 0, n = v.size(); i < n; i++)
		std::cout << v[i].get_salary() << "\n";
}

bool empl_salary_larger_than(const Employee& empl1, const Employee& empl2)
{
	if (empl1.get_salary() > empl2.get_salary())
		return true;
	else
		return false;
}

void p11()
{
	rand_seed();
	std::vector<Time> v(1000);
	for (size_t i = 0, n = v.size(); i < n; i++)
	{
		v[i] = Time(1 + rand() % (23), rand() % (60), rand() % (60));
		std::cout << v[i].get_hours() << ":" << v[i].get_minutes() << ":" << v[i].get_seconds() << "\n";
	}
	std::sort(v.begin(), v.end());
	std::cout << "Sorted Times:\n";
	for (size_t i = 0, n = v.size(); i < n; i++)
		std::cout << v[i].get_hours() << ":" << v[i].get_minutes() << ":" << v[i].get_seconds() << "\n";
}

void p12()
{
	int choice;
	std::vector<Appointment> app_book;
	std::cout << "This is an Appointment Organizing program\n";
		

	while (true)
	{
		std::cout << "\n********\nPlease choose what you want to do:\n"
			<< "1. List all appointments.\n"
			<< "2. List appointment of the same day.\n"
			<< "3. Add appointment.\n"
			<< "4. Remove appointment.\n********\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			print_all_appointment(app_book);
			break;
		}
		case 2:
		{
			Date d;
			d.read_date();
			print_appointment_same_day(app_book, d);
			break;
		}
		case 3:
		{
			Appointment a;
			a.read_appointment();
			int index;
			if (binary_search(app_book, 0, app_book.size() - 1, a, index) == true)
				std::cout << "This appointment can't be added, it conflicts with another appointment\n";

			else
			{	
				app_book.push_back(a);
				std::sort(app_book.begin(), app_book.end(), appointment_date_cmp);
				/*
				//keep the book sorted
				index--;
				if (index >= app_book.size())
					app_book.resize(index + 1);
				// move elements above the insertion point up.
				for (int i = 0; i < index; i++)
					app_book[i] = app_book[i + 1];

				//app_book[index] = a;

				std::vector<Appointment>::iterator it = app_book.begin();
				std::advance(it, index);
				app_book.insert(it, a);
				*/
			}
			break;
		}
		case 4:
		{
			Appointment a;
			a.read_appointment();
			int index;
			std::vector<Appointment>::iterator it = app_book.begin();
			if (binary_search(app_book, 0, app_book.size() - 1, a, index) == true)
			{
				std::advance(it, index);
				app_book.erase(it);
			}
			else
				std::cout << "No such Appointment exists\n";
			break;
		}
		default:
		{
			std::cin.ignore();
			std::cout << "Please choose 1...4\n";
			break;
		}
		}
	}
}

bool binary_search(std::vector<Appointment> v, int from, int to, const Appointment& value, int& index)
{
	if (from > to)
	{
		index = from;
		return false;
	}
	int mid = (from + to) / 2;
	if (v[mid] == value)
	{
		index = mid;
		return true;
	}
	else if (v[mid] < value)
		return binary_search(v, mid + 1, to, value, index);
	else
		return binary_search(v, from, mid - 1, value, index);
}

bool appointment_date_cmp(const Appointment& a, const Appointment& b)
{
	if (a.happens_before(b))
		return true;
	return false;
}

void print_all_appointment(std::vector<Appointment> appointment_list)
{
	for (std::vector<Appointment>::iterator i = appointment_list.begin(); i != appointment_list.end(); i++)
	{
		if (!(*i).empty())
		{
			std::cout << "******\n";
			(*i).print_appointment();
			std::cout << "******\n";
		}
	}

}

void print_appointment_same_day(std::vector<Appointment> appointment_list, const Date& d)
{
	for (std::vector<Appointment>::iterator i = appointment_list.begin(); i != appointment_list.end(); i++)
	{
		if (((*i).get_day()).is_same_date(d))
		{
			if (!(*i).empty())
			{
				std::cout << "******\n";
				(*i).print_appointment();
				std::cout << "******\n";
			}
		}
	}
}

const int NEWLINE_LENGTH = 2;
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;
void p13()
{
	std::fstream in_data("employee.dat");
	if (in_data.fail())
	{
		std::cout << "Failed to open file employee.dat\n";
		exit(0);
	}
	in_data.seekg(0, std::ios::end); // Go to end of file
	int nrecord = in_data.tellg() / RECORD_SIZE;

	sort_database(in_data, nrecord);

	std::string name;
	std::cout << "Employee's name: ";
	std::cin.ignore();
	getline (std::cin, name);
	Employee e = Employee(name, 0);

	bool found = binary_search(in_data, 0, nrecord -1, e);
	if (found == true)
	{
		std::cout << "Found\n";
		std::cout << "Employee's name: " << e.get_name() << "\nEmployee's salary: " << e.get_salary() << "\n";
	}
	else
		std::cout << "Not found\n";
}

bool binary_search(std::istream& is, int from, int to, Employee& value)
{
	if (from > to)
	{
		return false;
	}
	int mid = (from + to) / 2;

	is.seekg(mid * RECORD_SIZE, std::ios::beg);
	Employee e;
	read_employee(e, is);

	std::string employee_name = e.get_name();
	employee_name.erase(std::remove_if(employee_name.begin(), employee_name.end(), ::isspace),
		employee_name.end()); // remove spaces from the string to compare correctly

	std::string value_empl_name = value.get_name();
	value_empl_name.erase(std::remove_if(value_empl_name.begin(), value_empl_name.end(), ::isspace),
		value_empl_name.end()); // remove spaces from the string to compare correctly

	value = Employee(value.get_name(), e.get_salary());//set the salary

	if (employee_name == value_empl_name)
	{
		return true;
	}
	else if (e.get_name() < value.get_name())
		return binary_search(is, mid + 1, to, value);
	else
		return binary_search(is, from, mid - 1, value);
}

void sort_database(std::iostream& database, int nrecord)
{
	Employee e;
	std::vector<std::string> database_empl(nrecord);


	for (int i = 0; i < nrecord; i++)
	{
		database.seekg(i * RECORD_SIZE, std::ios::beg);
		getline(database, database_empl[i]);
	}

	std::sort(database_empl.begin(), database_empl.end());

	for (int i = 0; i < nrecord; i++)
	{
		database.seekp(i * RECORD_SIZE, std::ios::beg);
		database << database_empl[i];
	}
}

double string_to_double(std::string s)
{
	std::istringstream instr(s);
	double x;
	instr >> x;
	return x;
}

void read_employee(Employee& e, std::istream& in)
{
	std::string line;
	getline(in, line);
	if (in.fail()) return;
	std::string name = line.substr(0, 30);
	double salary = string_to_double(line.substr(30, 10));
	e = Employee(name, salary);
}