#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>

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
void p17();






/**
	Computes the scalar product of two vectors. The scalar product is
	a0 . b0 + a1 . b1 + ... + an−1 . bn−1
	@param a the first vector
	@param b the second vector
	@return the scalar product of the two vectors
*/
double scalar_product(const std::vector<double>& a,
	const std::vector<double>& b);
/**
	computes the alternating sum of all elements in a vector.
	For example, if alternating_sum is called with a vector containing
	1 4 9 16 9 7 4 9 11
	then it computes:
	1 − 4 + 9 − 16 + 9 − 7 + 4 − 9 + 11 = −2
	@param a the vector to be calculated its alternating sum
	@return the alternating sum
*/
double alternating_sum(const std::vector<double> a);
/**
	Reverses the sequence of elements in a vector. (e.g. if reverse is called 
	with a vector containing 
	1 4 9 16 9 7 4 9 11
	then the vector is changed to
	11 9 4 7 9 16 9 4 1
	@param a the vector whose elements will be reversed
*/
void reverse(std::vector<double>& a);
/**
	Appends one vector after another
	@param a is the vector to which the vector b is appended
	@param b is the vector appended to vector a
	@return the two vectors appended to each other
*/
std::vector<int> append(const std::vector<int>& a, const std::vector<int>& b);
/**
	merges two arrays, alternating elements from both arrays. If one array is
	shorter than the other, then alternate as long as you can and then append the
	remaining elements from the longer array. For example, if a is
										1 4 9 16
	And b is:
									  9 7 4 9 11	
	then merge returns the array
								1 9 4 7 9 4 16 9 11
	@param a vector contains the first set of numbers
	@param b vector conatins the second set of numbers
	@return vector contains the first vector merged with the second vector
*/
std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b);
/**
	Reads in a vector element of integers
	@param a vector to be read from the console
*/
void read_int_vector(std::vector<int>& a);
/**
	Prints a vector of integers
*/
void print_int_vector(const std::vector<int>& a);
/**
	merges two sorted vectors, producing a new sorted vector
	@return the sorted vector
*/
std::vector<int> merge_sorted(const std::vector<int>& a,const std::vector<int>& b);
/**
	Checks whether two vectors have the same elements in the same order.
	@return true if the two vectors have the same elements in the same order
*/
bool equals(const std::vector<int>& a, const std::vector<int>& b);
/**
	checks whether two vectors have the same elements in some order, ignoring
	multiplicities. For example, the two vectors 
												1 4 9 16
	and
											  9 7 4 9 11
	would be
										 1 9 4 7 9 4 16 9 11
	would be considered identical.
	@param a first vector 
	@param b second vector
	@return true if they are the same set
*/
bool same_set(const std::vector<int>& a, const std::vector<int>& b);
/**
	Removes duplicates from a vector
	@parma a the vector from which the duolicates will be removed
*/
void remove_duplicates(std::vector<int>& a);
/**
	checks whether two vectors have the same elements in some order, with the
	same multiplicities. For example,
										1 4 9 16 9 7 4 9 11
	and
										11 1 4 9 16 9 7 4 9
	would be considered identical, but
										1 4 9 16 9 7 4 9 11
	and
										 11 11 7 9 16 4 1
	would not.
	@param a the first vector
	@param b the second vector
	@return true if they are the same
*/
bool same_elements(const std::vector<int>& a, const std::vector<int>& b);

void permutation_helper(const std::vector<int>& prefix,
	const std::vector<int>& to_permute);
void remove_element_vector(int pos, std::vector<int>& values);
void calculate_permutation(int n);
/**
	Check whether a given number is a perfect square or not
	@param n Number to be checked
	@return true if it's perfect square
*/
bool is_perfect_square(int n);
/**
	Gets the total sum of a vector of type int
	@param vec the vector to add up its elemnts
	@return the sum of the elements of the vector
*/
int sum_vector_int(const std::vector<int> & vec);
int main()
{
	std::string problem_name = "Hello";
	std::cout << "Write the code of the problem to show the solution of it: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl
		<< "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23" << std::endl
		<< "p24, p25, p26, p27, p28, p29, p30" << std::endl
		<< "******\n";
	

	do {
		std::cout << "Enter the problem's code: ";
		std::cin >> problem_name;
		std::cin.ignore();//ignore any \n coming from the problems functions
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
		else if (problem_name == ("p17"))
			p17();


		else if (problem_name == ("p13"))
			p13();
	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n\a";
	return 0;
	
}


void p1()
{
	std::vector<double> first(2);
	std::vector<double> second(2);
	std::cout << "Fill the first vector!\n";
	for (int i = 0; i < first.size(); i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> first[i];
	}
	std::cout << "Fill the second vector!\n";
	for (int i = 0; i < second.size(); i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> second[i];
	}
	std::cout << "Scalar product of the two vectors is: " <<
		scalar_product(first, second) << "\n";
}
void p2()
{
	std::vector<double> numbers(8);
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> numbers[i];
	}
	double s = alternating_sum(numbers);
	std::cout << "The alternating sum is: " << s << "\n";
}
void p3()
{
	std::vector<double> numbers(4);
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << "Enter a number: ";
		std::cin >> numbers[i];
	}
	reverse(numbers);
	for (int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << "\n";
}
void p4()
{
	std::vector<int> A(5), B(3);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(A);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(B);
	std::cout << "The two sets appended to each other is:\n";
	std::vector<int> all = append(A, B);
	print_int_vector(all);
}
void p5()
{
	std::vector<int> A(4), B(5);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(A);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(B);
	std::cout << "The merged set:\n";
	std::vector<int> m = merge(A, B);
	print_int_vector(m);
}
void p6()
{
	std::vector<int> A(4), B(5);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(A);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(B);
	std::cout << "The sorted merge set:\n";
	std::vector<int> m = merge_sorted(A, B);
	print_int_vector(m);
}
void p7()
{
	std::vector<int> A(3), B(2);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(A);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(B);
	bool test = equals(A, B);
	if (test == true)
		std::cout << "The two vectors are the same and in the same order!\n";
	else
		std::cout << "The two vectors are not the same or in different order!\n";
}
void p8()
{
	std::vector<int> a(9), b(7);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(a);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(b);
	bool test = same_set(a, b);
	if (test == true)
		std::cout << "The two vectors are the same!\n";
	else
		std::cout << "The two vectors are not the same!\n";
}
void p9()
{
	std::vector<int> a(9), b(9);
	std::cout << "Enter the first set of integers:\n";
	read_int_vector(a);
	std::cout << "Enter the second set of integers:\n";
	read_int_vector(b);
	bool test = same_elements(a, b);
	if (test == true)
		std::cout << "The two vectors are the same!\n";
	else
		std::cout << "The two vectors are not the same!\n";
}
void p10()
{
	std::vector<int> x(9);
	std::cout << "Enter a set of numbers with duplicates: \n";
	read_int_vector(x);
	remove_duplicates(x);
	std::cout << "The set of numbers without duplicates: \n";
	print_int_vector(x);
}
void p11()
{
	unsigned int n;
	std::cout << "Enter a number: ";
	std::cin >> n;
	calculate_permutation(n);
}

void p12()
{
	std::vector<int> permutation(10);
	
	for (int i = 0, n = permutation.size(); i < n; i++)
	{
		calculate_permutation(i+1);
		//std::cout << i + 1;
		//calculate_permutation(i + 1);
		std::cout << "****************\n****************\n";
	}
}

void p13()
{

}
void p17()
{
	int n;
	std::vector<int> numbers;

	std::cout << "Enter numbers to check whether they form a magic"
		<< " square or not, type \"q\" to end\n";
	
	int index = 0;
	while(std::cin >> n)//First read the numbers into a vector.
	{
		numbers.push_back(n);
		index++;
	}
	std::cin.clear();
	std::cin.ignore();

	if (!is_perfect_square(numbers.size())) //If the size of that vector is a square
	{
		std::cout << "Can't be magic square!, n must be square value\n";
		return;
	}

	//test whether all numbers between 1 and n are present

	for (int i = 0, numbers_size = numbers.size();
		i < numbers_size; i++)
	{
		bool exist = false, occur_once =false;
		for (int j = 0; j < numbers_size; j++)
		{
			if (numbers[i] == j + 1)
			{
				exist = true;
				break;
			}
		}
		if (!exist)
		{
			std::cout << "Missing number, Can't be magic square!\n";
			return;
		}
	}

	int numbers_size = numbers.size();
	//If every number occur exactly once
	for (int i = 0; i < numbers_size; i++)
	{
		int occur_once = 0;
		for (int j = 0; j < numbers_size; j++)
		{
			if (numbers[i] == numbers[j])
				occur_once++;
		}
		if (occur_once > 1)
		{
			std::cout << "duplicated number, Can't be magic square!\n";
			return;
		}
	}

	int row_size = sqrt(numbers_size), column_size = row_size;

	std::vector<int> row(row_size);//row 
	std::vector<int> column(column_size);//column
	
	std::vector<int> sum_rows(row_size, 0);
	std::vector<int> sum_columns(row_size, 0);

	for (int i = 0; i < row_size; i++)
	{
		//fill the rows
		for (int j = i * row_size, k = 0;
			j < numbers_size, k < row_size; j++, k++)
		{
			row[k] = numbers[j];
			sum_rows[i] += numbers[j];
		}
		//fill the columns
		for (int j = i, k = 0;
			j < numbers_size, k < column_size; j += column_size, k++)
		{
			column[k] = numbers[j];
			sum_columns[i] += numbers[j];
		}
	}

	int sum_first_diagonal = 0, sum_second_diagonal = 0;
	//fill the first diagonal the diagonal
	for (int j = 0, k = 0;
		j < numbers_size, k < column_size; j += column_size + 1, k++)
		sum_first_diagonal += numbers[j];

	//fill the second diagonal the diagonal
	for (int j = row_size - 1, k = 0;
		j < numbers_size, k < column_size; j += column_size - 1, k++)
		sum_second_diagonal += numbers[j];

	//check if the sum of the elements in each row, in each column are the same
	for (int i = 0, sum_size = sum_rows.size(); i < sum_size - 1; i++)
		if (sum_rows[i] != sum_rows[i + 1]
			|| sum_columns[i] != sum_columns[i + 1])
		{
			std::cout << "error 1, Can't be magic square!\n";
			return;
		}
	//then we need to check if the two sum vectors are the same
	for (int i = 0, sum_size = sum_rows.size(); i < sum_size; i++)
		for(int j = 0; j < sum_size; j++)
			if(sum_rows[i] != sum_columns[j])
			{
				std::cout << "error 2, Can't be magic square!\n";
				return;
			}

	//then check the two diagonals
	if (sum_first_diagonal == sum_second_diagonal)
	{
		if (sum_first_diagonal == sum_rows[0])
			std::cout << "It's a fucking magic square!\n";
	}
	else
		std::cout << "error 3, Can't be magic square!\n";
}

bool is_perfect_square(int n) {
	if (n < 0)
		return false;
	int root(round(sqrt(n)));
	return n == root * root;
}
double scalar_product(const std::vector<double>& a, 
	const std::vector<double>& b)
{
	if (a.size() == 0 || b.size() == 0)
		return 0;
	double product = 0;
	for (int i = 0; i < a.size(); i++)
		product = product + a[i] * b[i];
	return product;
}
double alternating_sum(const std::vector<double> a)
{
	double a_sum = 0;//a stands for alternating
	for (int i = 0; i < a.size() - 1; i += 2)
	{
		a_sum = a_sum + a[i] - a[i + 1];
	}
	if (a.size() % 2 != 0)
		a_sum = a_sum + a[a.size() - 1];
	return a_sum;
}
void reverse(std::vector<double>& a)
{
	double temp;
	for (int i = 0, n = a.size(); i < (int)(n / 2); i++)
	{
		temp = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = temp;
	}
}
std::vector<int> append(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int> all(a.size() + b.size());
	int i, n;
	for (i = 0, n = a.size(); i < n; i++)
	{
		all[i] = a[i];
	}
	for (int j = 0, n = b.size(); j < n; j++, i++)
		all[i] = b[j];
	return all;
}
std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b)
{
	const int a_size = a.size(), b_size = b.size();
	std::vector<int> merged(a_size + b_size);
	const int n = merged.size();
	merged = append(a, b);
	for (int i = 1, j = 0, x = 1; i < a_size; 
		i++, j++, x += 2)
	{
		int pos = a_size + j;//pos of the first number of b in the merged vector
		int value = merged[pos];
		for (int k = pos; k > i + j; k--) //shift a part of the merged vector 
			merged[k] = merged[k - 1];

		merged[x] = value;
	}
	return merged;
}
void read_int_vector(std::vector<int>& a)
{
	for (int i = 0, n = a.size(); i < n; i++)
		std::cin >> a[i];
}
void print_int_vector(const std::vector<int>& a)
{
	for (int i = 0, n = a.size(); i < n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
}
std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int> sorted = merge(a, b);
	std::sort(sorted.begin(), sorted.end());	
	return sorted;
}
bool equals(const std::vector<int>& a, const std::vector<int>& b)
{
	int a_size = a.size(), b_size = b.size();
	if (a_size != b_size)
		return false;
	int n = a_size;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
bool same_set(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int> a_cp = a, b_cp = b;
	remove_duplicates(a_cp);
	remove_duplicates(b_cp);
	std::sort(a_cp.begin(), a_cp.end());
	std::sort(b_cp.begin(), b_cp.end());
	return equals(a_cp,b_cp);
}
void remove_duplicates(std::vector<int>& a)
{
	int a_size = a.size();
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i] == a[j])
			{
				for (int k = j; k < a.size() - 1; k++)
					a[k] = a[k + 1];
				a.pop_back();
				j--;
			}
		}
	}
}
bool same_elements(const std::vector<int>& a, const std::vector<int>& b)
{
	int a_size = a.size(), b_size = b.size();
	if (a_size != b_size)
		return false;
	int n = a_size;
	std::vector<int> a_cp = a, b_cp = b;
	std::sort(a_cp.begin(), a_cp.end());
	std::sort(b_cp.begin(), b_cp.end());
	for (int i = 0; i < n; i++)
	{
		if(a_cp[i] != b_cp[i])
			return false;
	}
	return true;
}
void permutation_helper(const std::vector<int>& prefix,
	const std::vector<int>& to_permute)
{
	std::vector<int> to_permute2 = to_permute;
	std::vector<int> prefix2 = prefix;

	int e, j;

	if (to_permute.empty())
	{
		print_int_vector(prefix2);
		return;
	}
	else
	{
		e = to_permute[0], j = 0; //look in the problem to see why (e)
		   // Note: Both {to_permute and to_permute2 have the same size}
		for (int i = 0, n = to_permute.size(); i < n; i++)
		{
			if (to_permute[i] != e)
			{
				to_permute2[j] = to_permute[i];
				j++;
			}
			else
				remove_element_vector(i, to_permute2);
		}
	}
	prefix2.push_back(e);
	to_permute2.resize(to_permute2.size());
	permutation_helper(prefix2, to_permute2);
}

void remove_element_vector(int pos, std::vector<int>& values)
{
	for (int i = pos; i < values.size() - 1; i++)
		values[i] = values[i + 1];
	values.pop_back();
}

void calculate_permutation(int n)
{
	std::vector<int> prefix(1), all_numbers(n);
	std::vector<int> to_permute(n - 1);

	for (int i = 0; i < n; i++)
		all_numbers[i] = i + 1;

	for (int prefix_index = 0; prefix_index < n; prefix_index++)
	{
		prefix[0] = all_numbers[prefix_index];
		for (int i = 0, to_permute_index = 0; i < n,
			to_permute_index < n - 1; i++)
		{
			if (all_numbers[i] != prefix[0])
			{
				to_permute[to_permute_index] = all_numbers[i];
				to_permute_index++;
			}
		}
		permutation_helper(prefix, to_permute);
		if (n - 1 >= 2)
		{
			iter_swap(to_permute.begin() + 0, to_permute.end() - 1);//swap the vector
			permutation_helper(prefix, to_permute);
		}
	}
}
int sum_vector_int(const std::vector<int> & vec)
{
	int sum = 0;
	for (int i = 0, n = vec.size(); i < n; i++)
	{
		sum += vec[i];
	}
	return sum;
}
