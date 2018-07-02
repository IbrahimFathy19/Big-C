/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>


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
int min_position(std::vector<int>& a, int from, int to);
/**
	Sorts a vector using the selection sort algorithm
	@param a the vector to sort
*/
void selection_sort(std::vector<int>& a);
/**
	Merges two adjacent ranges in a vector
	@param a the vector with the elements to merge
	@param from the start of the first range
	@param mid the end of the first range
	@param to the end of the second range
*/
void merge(vector<int>& a, int from, int mid, int to);
/**
	Sorts the elements in a range of a vector.
	@param a the vector with the elements to sort
	@param from start of the range to sort
	@param to end of the range to sort
*/
void merge_sort(vector<int>& a, int from, int to);
/**
	Finds an element in a sorted vector.
	@param v the sorted vector with the elements to search
	@param from the start of the range to search
	@param to the end of the range to search
	@param value the value to search for
	@return the index of the first match, or -1 if not found
*/
int binary_search(vector<int> v, int from, int to, int value);
/**
	Draws the vector elements as lines with values as height and index as their x. 
	i.e. (x, y) = (i, v[i])
	@param v Vector to draw
*/
void draw_vector(const std::vector<int>& v);

void p14();
void p15();
void p16();

int ccc_win_main()
{
	std::string problem_name;
	do {

		problem_name = cwin.get_string("Enter the problem's code: ");
		if (problem_name == ("p14"))
			p14();
		else if (problem_name == ("p15"))
			p15();
		else if (problem_name == ("p16"))
			p16();

		std::string clear;
		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();


	} while (problem_name != ("Quit"));

	return 0;
}

void p14()
{
	int size = cwin.get_int("Enter the size of the vector to be sorted using \"Selection Sort\":");

	std::vector<int> v(size);

	rand_seed();
	int random;

	// fill the vector with random numbers
	for (size_t i = 0; i < size; i++)
	{
		random = 1 + rand() % 100;
		v[i] = random;
	}
	draw_vector(v);
	selection_sort(v);
}

void draw_vector(const std::vector<int>& v)
{
	const int _y = -7;
	int size = v.size(),
		half_size = size / 2;
	Point x_axis; // the point on x axis
	Point at_end; // the point at end of the line that represents the value of the element of the vector
	Line element_value;
	for (int i = -half_size, j = 0; j < size; i++, j++)
	{
		x_axis = Point(i * 0.2, _y); //the start point lies on the x-axis
		at_end = Point(i * 0.2, v[j] * 0.1 + _y);
		element_value = Line(x_axis, at_end);
		cwin << element_value;
	}
}

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
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
		{
			std::swap(a[min_pos], a[next]);
			draw_vector(a);
			Sleep(60);
			cwin.clear();
		}
	}
}

void p15()
{
	int size = cwin.get_int("Enter the size of the vector to be sorted using \"Merge Sort\":");
	std::vector<int> v(size);

	rand_seed();
	int random;

	// fill the vector with random numbers
	for (size_t i = 0; i < size; i++)
	{
		random = 1 + rand() % 100;
		v[i] = random;
	}
	draw_vector(v);
	merge_sort(v, 0, size - 1);
}

void merge(vector<int>& a, int from, int mid, int to)
{
	int n = to - from + 1; // Size of the range to be merged 
								  // Merge both halves into a temporary vector b 
	vector<int> b(n);

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
	{
		a[from + j] = b[j];
	}
}

void merge_sort(vector<int>& a, int from, int to)
{
	if (from == to) return;
	int mid = (from + to) / 2;
	// Sort the first and the second half
	merge_sort(a, from, mid);
	merge_sort(a, mid + 1, to);
	merge(a, from, mid, to);
	draw_vector(a);
	Sleep(60);
	cwin.clear();
}

void p16()
{
	int size = cwin.get_int("Enter the size of the vector to use \"Binary Search\":");
	std::vector<int> v(size);

	rand_seed();
	int random;

	// fill the vector with random numbers
	for (size_t i = 0; i < size; i++)
	{
		random = 1 + rand() % 100;
		v[i] = random;
	}
	std::sort(v.begin(), v.end());
	const int value_to_find = 10;
	binary_search(v, 0, size - 1, value_to_find);
}

int binary_search(vector<int> v, int from, int to, int value)
{
	if (from > to)
		return -1;
	int mid = (from + to) / 2;

	draw_vector(v);
	const int _y = -7;
	int half_size = v.size() / 2;
	Point x_axis; // the point on x axis
	Point at_end; 
	Line element_value;
	x_axis = Point((mid - half_size) * 0.3, _y - 0.5); 
	at_end = Point((mid - half_size) * 0.3, _y - 2);
	element_value = Line(x_axis, at_end);
	cwin << element_value;
	Sleep(2000);
	cwin.clear();

	if (v[mid] == value)
		return mid;
	else if (v[mid] < value)
		return binary_search(v, mid + 1, to, value);
	else
		return binary_search(v, from, mid - 1, value);
}