/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "list.h"
#include "circular_list.h"
#include "polynomial.h"
#include "stack.hpp"
#include "queue.h"
#include "list_sl.h"


/**
	Sets the seed of the random number generator.
*/
void rand_seed();

/**
	Removes every second value from a given linked list.
*/
void downsize(std::list<std::string>& names);

/**
	Gets the position of the largest element in a list range.
	@param a the list
	@param from pointer to beginning of the range
	@param to pointer to the end of the range
	@return a pointer to the largest element in
	the range a[from]...a[to]
*/
std::list<int>::iterator maximum(std::list<int> number_list, std::list<int>::iterator from, std::list<int>::iterator to);

/**
	Gets the position of the smallest element in a list range.
	@param a the list
	@param from pointer to beginning of the range
	@param to pointer to the end of the range
	@return a pointer to the smallest element in
	the range a[from]...a[to]
*/
std::list<int>::iterator min_position(std::list<int> a, std::list<int>::iterator from, std::list<int>::iterator to);

/**
	Sorts a list using the selection sort algorithm
	@param a the list to sort
*/
void sort(std::list<int>& a);

/**
	Merges two lists and reurn the complete list
	@param a the first list with the elements to merge
	@param b the second list with the elements to merge
	@return the merged list
*/
std::list<int> merge(std::list<int> a, std::list<int> b);

/**
	sorts the vector v using merge sort
	@param v vector to be sorted
*/
void merge_sort(std::vector<int>& v);

/**
	Merges two vectors
	@param v1 first vector with the elements to merge
	@param v2 second vector with the elements to merge
   @return the merged vector
*/
std::vector<int> merge_vectors(const std::vector<int>& v1, const std::vector<int>& v2);

/**
	Finds the permutations of a given string
	@param s string to find its permutations
	@return vector of permutations
*/
std::vector<std::string> permutate(const std::string& s);


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
void p14();
void p15();
void p16();
void p17();
void p18();



int main()
{

	std::cout << "Write the letter \"p\" followed by the problem number to show the solution: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;

	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16, p17, p18" << std::endl
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
		else if (problem_name == ("p12"))
			p12();
		else if (problem_name == ("p13"))
			p13();
		else if (problem_name == ("p14"))
			p14();
		else if (problem_name == ("p15"))
			p15();
		else if (problem_name == ("p16"))
			p16();
		else if (problem_name == ("p17"))
			p17();
		else if (problem_name == ("p18"))
			p18();
	

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n";
}

void print_list(std::list<std::string> ls)
{
	std::list<std::string>::iterator pos;
	for (pos = ls.begin(); pos != ls.end(); pos++)
		std::cout << *pos << "   ";
	std::cout << "\n";
}

void print_list(std::list<int> ls)
{
	std::list<int>::iterator pos;
	for (pos = ls.begin(); pos != ls.end(); pos++)
		std::cout << *pos << "   ";
	std::cout << "\n";
}

void print_vector(std::vector<int> v)
{
	std::vector<int>::iterator pos;
	for (pos = v.begin(); pos != v.end(); pos++)
		std::cout << *pos << "   ";
	std::cout << "\n";
}

void print_list(List ls)
{
	Iterator iter;
	for (iter = ls.begin(); !iter.equals(ls.end()); iter.next())
		std::cout << iter.get() << "   ";
	std::cout << "\n";
}

void print_list(List_SL ls)
{
	Iterator_SL iter;
	for (iter = ls.begin(); !iter.equals(ls.end()); iter.next())
		std::cout << iter.get() << "   ";
	std::cout << "\n";
}

void print_list(Circular_List ls)
{
	Circ_Iterator iter = ls.begin();

	do
	{
		if (!ls.empty())
		{
			std::cout << iter.get() << "   ";
			iter.next();
		}
	} while (!iter.equals(ls.begin()));

	std::cout << "\n";
}

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

void p1()
{
	std::list<std::string> names;
	names.push_back("Henry");
	names.push_back("Tom");
	names.push_back("Hima");

	print_list(names);

	downsize(names);
	
	std::cout << "Output: \n";
	print_list(names);
}

void downsize(std::list<std::string>& names)
{
	std::list<std::string>::iterator pos = names.begin();
	pos++; // now it points to the second value
	names.erase(pos);
}

void p2()
{
	std::list<int> numbers;
	
	rand_seed(); int random;
	for (size_t i = 0; i < 15; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		numbers.push_back(random);
	}

	print_list(numbers);
	std::cout << "\n" << *(maximum(numbers, numbers.begin(), numbers.end())) << "\n";
}

std::list<int>::iterator maximum(std::list<int> number_list, std::list<int>::iterator from, std::list<int>::iterator to)
{
	std::list<int>::iterator  max_pos = from;
	std::list<int>::iterator i;
	for (i = from++; i != to; i++)
		if (*i > *max_pos) max_pos = i;
	return max_pos;
}

void p3()
{
	std::list<int> numbers;

	rand_seed(); int random;
	for (size_t i = 0; i < 20; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		numbers.push_back(random);
	}

	print_list(numbers);

	sort(numbers);

	print_list(numbers);
}

std::list<int>::iterator min_position(std::list<int> a, std::list<int>::iterator from, std::list<int>::iterator to)
{
	std::list<int>::iterator  min_pos = from;
	std::list<int>::iterator i = from++;
	for (i; i != to; i++)
		if (*i < *min_pos) min_pos = i;
	return min_pos;
}

void sort(std::list<int>& a)
{
	std::list<int>::iterator next; // The next position to be set to the minimum

	for (next = a.begin(); next != a.end(); next++)
	{
		// Find the position of the minimum
		std::list<int>::iterator min_pos = min_position(a, next, a.end());
		if (min_pos != next)
			std::swap(*min_pos, *next);
	}
}

void p4()
{
	std::list<int> number_list1(3);
	std::list<int> number_list2(5);

	std::list<int>::iterator mid, i, j;
	rand_seed(); int random;
	for (i = number_list1.begin(); i != number_list1.end(); i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		*i = random;
	}
	
	for (j = number_list2.begin(); j != number_list2.end(); j++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		*j = random;
	}

	print_list(number_list1);
	print_list(number_list2);

	std::list<int> result = merge(number_list1, number_list2);

	print_list(result);
}

std::list<int> merge(std::list<int> a, std::list<int> b)
{

	std::list<int>::iterator first_start = a.begin(), second_start = b.begin(),
		first_end = a.end(), second_end = b.end();

	std::list<int> result;

	std::list<int>::iterator i1 = first_start;
	// Next element to consider in the first list 
	std::list<int>::iterator i2 = second_start;
	// Next element to consider in the second list 

	// As long as neither i1 nor i2 is past the end, move the smaller
	// element into b

	while (i1 != first_end && i2 != second_end)
	{
		result.push_back(*i1);
		i1++;

		result.push_back(*i2);
		i2++;
	}

	// Note that only one of the two while loops below is executed

	// Copy any remaining entries of the first list
	while (i1 != first_end)
	{
		result.push_back(*i1);
		i1++;
	}

	// Copy any remaining entries of the second list
	while (i2 != second_end)
	{
		result.push_back(*i2);
		i2++;
	}

	return result;
}

void p5()
{
	List staff;

	staff.push_back(5);
	staff.push_back(4);
	staff.push_back(9);
	staff.push_back(9);

	// Add a value in fourth place

	Iterator pos;
	pos = staff.begin();
	pos.next();
	pos.next();
	pos.next();

	staff.insert(pos, 92);

	// Remove the value in second place

	pos = staff.begin();
	pos.next();

	staff.erase(pos);

	// Print all values
	print_list(staff);
}

void p6()
{
	rand_seed();

	List staff;
	int i, random;
	for (i = 0; i < 10; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		staff.push_back(random);
	}

	print_list(staff);
	staff.reverse();
	print_list(staff);
}

void p7()
{
	List num;
	num.push_front(5); // list conatins 5
	num.push_front(8); // list conatins 8 5
	num.push_front(11); // list conatins 11 8 5
	num.push_back(24); // list conatins 11 8 5 24

	print_list(num);
}

void p8()
{
	List num_list1, num_list2;
	rand_seed();

	int i, random;
	for (i = 0; i < 10; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		num_list1.push_back(random);
		random = 0 + rand() % (1000 - 0 + 1);
		num_list2.push_back(random);
	}

	//print the contents of the two lists
	std::cout << "List 1:	";
	print_list(num_list1);
	std::cout << "List 2:	";
	print_list(num_list2);

	num_list1.swap(num_list2);
	std::cout << "After Swapping\n";
	std::cout << "List 1:	";
	print_list(num_list1);
	std::cout << "List 2:	";
	print_list(num_list2);
}

void p9()
{
	List num_list;
	rand_seed();

	int i, random;
	for (i = 0; i < 10; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		num_list.push_back(random);
	}

	print_list(num_list);

	int list_size = num_list.get_size();
	std::cout << "Size of this list is: " << list_size << "\n";
}

void p10()
{
	List num_list;
	rand_seed();

	int i, random;
	for (i = 0; i < 10; i++)
	{
		random = 0 + rand() % (1000 - 0 + 1);
		num_list.push_back(random);
	}

	int list_size;
	print_list(num_list);
	list_size = num_list.get_size();
	std::cout << "Size of this list is: " << list_size << "\n";

	Iterator iter = num_list.begin();
	print_list(num_list);
	iter = num_list.erase(iter);
	list_size = num_list.get_size();
	std::cout << "Size of this list is: " << list_size << "\n";

	num_list.insert(iter, 0);
	print_list(num_list);
	list_size = num_list.get_size();
	std::cout << "Size of this list is: " << list_size << "\n";
}

void p11()
{
	Circular_List list;
	list.push_back(4);
	print_list(list);
	list.push_back(5);
	print_list(list);

	Circ_Iterator iter = list.begin();
	iter.next(); //insert before the second node
	list.insert(iter, 1);
	print_list(list);

	iter = list.erase(iter);
	print_list(list);

	list.push_front(0);
	print_list(list);
	
	list.push_front(5);
	print_list(list);
	list.push_back(1);
	print_list(list);

	list.reverse();
	print_list(list);
}

void p12()
{
	List_SL list;
	list.push_back(5);
	list.push_back(4);
	list.push_front(0);
	list.insert(list.begin(), 1);
	print_list(list);
	list.erase(list.begin());
	print_list(list);
}

void p13()
{

}

void p14()
{
	Polynomial p(Term(-10, 0));
	p.add(Polynomial(Term(-1, 1)));
	p.add(Polynomial(Term(-5, 1)));
	p.add(Polynomial(Term(9, 7)));
	p.add(Polynomial(Term(5, 10)));
	p.print_polynomial();
	Polynomial result = p.multiply(Polynomial(Term(5, 1)));
	result.print_polynomial();
}

void p15()
{
	Stack s;
	s.push("HI");
	s.push("Hima");
	s.pop();
	std::cout << s.size() << "\n";
}

void p16()
{
	Queue q;
	q.push("Z");
	q.push("Y");
	q.push("A");
	std::cout << "Front: " << q.front() << "\n"
		<< "Back: " << q.back() << "\n";
	q.pop();
	std::cout << "Front: " << q.front() << "\n"
		<< "Back: " << q.back() << "\n";
}

void p17()
{
	rand_seed();

	std::vector<int> to_merge;
	int i, random;
	for (i = 0; i < 16; i++) // size of to_merge must be power of 2
	{
		random = 0 + rand() % (1000 - 0 + 1);
		to_merge.push_back(random);
	}
	
	print_vector(to_merge);
	merge_sort(to_merge);
	print_vector(to_merge);
}

void merge_sort(std::vector<int>& v)
{
	std::queue<std::vector<int>> q;
	q.push(v);

	int n = v.size();
	for (size_t i = 0; i < log2(v.size()); i++)
	{
		n = n / 2;
		for (size_t j = 0, length = static_cast<size_t>(pow(2, i)); j < length; j++)
		{
			std::vector<int> popped = q.front();
			std::vector<int>::iterator beg = popped.begin(), end = popped.end(), mid = popped.begin();
			q.pop();

			std::advance(mid, n);

			std::vector<int> first(beg, mid);
			std::vector<int> last(mid, end);
			
			q.push(first);
			q.push(last);
		}
	}
	//now vector sizes are all 1
	while(q.size() != 1)
	{
		std::vector<int> first = q.front();
		q.pop();
		std::vector<int> second = q.front();
		q.pop();

		std::vector<int> result = merge_vectors(first, second);
		q.push(result);
		//merge the two vectors
	}

	v = q.front();
}

std::vector<int> merge_vectors(const std::vector<int>& v1, const std::vector<int>& v2)
{
	int i1 = 0;
	// Next element to consider in the first vector 
	int i2 = 0;
	// Next element to consider in the second vector 
	int j = 0; // Next open position in b 

	// As long as neither i1 nor i2 is past the end, move the smaller
	// element into b

	int v1_size = v1.size(), v2_size = v2.size();
	std::vector<int> result(v1_size + v2_size);
	while (i1 < v1_size && i2 < v2_size)
	{
		if (v1[i1] < v2[i2])
		{
			result[j] = v1[i1];
			i1++;
		}
		else
		{
			result[j] = v2[i2];
			i2++;
		}
		j++;
	}
	// Copy any remaining entries of the first vector
	while (i1 < v1_size)
	{
		result[j] = v1[i1];
		i1++;
		j++;
	}
	// Copy any remaining entries of the second vector
	while (i2 < v2_size)
	{
		result[j] = v2[i2];
		i2++;
		j++;
	}

	return result;
}

void p18()
{
	std::string str;
	std::cout << "Enter a string to permutate: ";
	std::cin >> str;

	std::vector<std::string> result = permutate(str);
	for (size_t i = 0, n = result.size(); i < n; i++)
		std::cout << result[i] << "\n";
}

std::vector<std::string> permutate(const std::string& s)
{
	std::vector<std::string> result;

	std::stack<std::string> stack;
	stack.push("+" + s);

	std::string popped, to_permutate;
	std::string::iterator iter;

	while (stack.empty() == false)
	{
		popped = stack.top();
		stack.pop();

		int n = popped.length();
		if (popped[n - 1] == '+')//check the last char
			result.push_back(popped.substr(0, n - 1));
		else
		{
			size_t pos = popped.find('+');
			if (pos != -1)
			{
				for (size_t j = pos + 1; j < n; j++)
				{
					to_permutate = popped;

					iter = to_permutate.begin();
					std::advance(iter, pos);
					to_permutate.insert(iter, popped[j]);

					iter = to_permutate.begin();
					std::advance(iter, j + 1); // we add 1 because the insertion that we made
					iter = to_permutate.erase(iter);
					
					stack.push(to_permutate);
				}
			}
		}
	}
	return result;
}