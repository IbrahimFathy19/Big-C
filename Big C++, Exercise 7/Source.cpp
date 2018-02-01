#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <string>
#include "ccc_empl.h"
#include "Person.h"
#include "person2.h"
#include "car.h"
#include <algorithm>
#include <iterator>
#include <iomanip>

typedef double(*DoubleFunPointer)(double);
typedef int(*IntFunPointer)(int);

//p stands for problem
void p1();
void p2();
void p3();
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


/**
	Calculate the average of an array double elements
	@param a beginnig element address
	@param a_size size of the array
	@return average of this array
*/
double average(double* a, int a_size);
/**
	Gets the maximum value of an array of double values
	@param a the address of the first element
	@param a_size size of the array
	@return the address of the max value
*/
double * maximum(double a[], int a_size);
/**
	Reverses the values of an array of floating-point data
	@param a the address of the first element
	@param a_size size of the array
*/
void reverse(double a[], int a_size);
/**
	Copies the first num characters of source to destination
	@param cpy_to the distination array to copy to
	@param cpy_from the source array to copy from
	@param num the first characters of source to be copied to destination
*/
void my_strncpy(char* cpy_to, const char* cpy_from, int num);
/**
	Gets the length of the initial portion of s consisting of characters in t 
	(in any order)
	@param s the first array
	@param t the second array
	@return length of the initial portion of s consisting of characters in t
*/
int my_strspn(const char s[], const char t[]);
/**
	Reverses the values of an array of floating-point data
	@param s the address of the first element
*/
void reverse(char s[]);
/**
	Concatenates the strings a and b to the (null-terminated) buffer result
	@param a first string
	@param b second string
	@param result the concatenated string
	@param result_maxlength size of the array result
*/
void concat(const char a[], const char b[], char result[], int result_maxlength);
/**
	Prints a table using the two functions (*f1) & (*f2)
	@param f1 a pointer to a function that consumes and yields a floating-point variable
	@param f2 a pointer to a function that consumes and yields a floating-point variable
*/
void print_table(DoubleFunPointer f1, DoubleFunPointer f2);
/**
	Prints a table using the function (*f)
	@param a array that the function -to which f points- will modify
	@param size array a's size
	@param f1 a pointer to a function that consumes and yields an int
*/
void fill_with_values(int a[], int size, IntFunPointer f);
/**
	Calculates the square of a number
	@param x input to the function to be squared
	@return square(x)
*/
double square(double x);
/**
	Calculates the square of a number
	@param x input to the function to be squared
	@return square(x)
*/
int square(int x);

int main()
{
	std::string problem_name;
	std::cout << "Write the code of the problem to show the solution of it: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl
		<< "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p16, p17" << std::endl
		<< "******\n";

	do {
		std::cout << "Enter the problem's code: ";
		getline(std::cin, problem_name);


		if (problem_name == ("p1"))
			p1();
		else if (problem_name == ("p2"))
			p2();
		else if (problem_name == ("p3"))
			p3();
		else if (problem_name == ("p4"))
			std::cout << "Done in p3!\n";
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


		else
			std::cout << "Error, no such problem was found. Try again!\n";

	} while (problem_name != ("Quit"));
	std::cout << "Thanks\n\a";
	return 0;
	
}

void p1()
{
	std::cout << "How many persons? ";
	int number_names;
	std::cin >> number_names;
	std::vector<Person*> persons(number_names);
	std::cin.ignore();
	int i, n = number_names;
	for (i = 0; i < n; i++)
	{
		std::cout << "The person's name: ";
		std::string name;
		getline(std::cin, name);
		Person* p = new Person(name);
		persons[i] = p;
	}
	// Now you have an array of pointers with each one of them 
	// points to a person object located in the heap
	for (int j = 0; j < n; j++)
	{// For each person, find his best_friend person
		std::cout << persons[j]->get_name() << "'s best friend is: ";
		std::string bf_name;
		getline(std::cin, bf_name);
		for (i = 0; i < n; i++)
		{
			if (bf_name == persons[i]->get_name())
			{
				persons[j]->set_best_friend(persons[i]);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		persons[i]->print_person();
	}
	for (i = 0; i < n; i++)
	{
		delete persons[i];
		persons[i] = NULL;
	}
}

void p2()
{
	std::cout << "How many drivers and owners? ";
	int number_names;
	std::cin >> number_names;
	std::vector<Person2*> people(number_names);
	std::vector<Car*> cars(number_names / 2);
	std::cin.ignore();
	int i, n = number_names, age, nCars = number_names / 2, j = 0, k = 0;
	Person2* driver;
	Person2* owner;

	std::string name, model;
	for (i = 0; i < n; i++, j += 2)
	{
		if (i % n == 0)
		{
			std::cout << "Enter the car's model";
			getline(std::cin, model);
			std::cout << "The owner's info of the car number " << i + 1 << " \n";
		}
		else
			std::cout << "The driver's info of the car number " << i + 1 << " \n";

		std::cout << "The person's name: ";
		getline(std::cin, name);

		std::cout << "The person's age: ";
		std::cin >> age;
		std::cin.ignore();

		Person2* p = new Person2(name, age);
		people[i] = p;

		if (i % n == 0 && i > 1 && j + 1 < n)
		{
			Car* c = new Car(model, people[j], people[j + 1]);
			cars[k] = c;
			k++;
		}
	}

}

void p3() // And p4
{
	int nEmployees;
	std::cout << "How many employees do you have? ";
	std::cin >> nEmployees;
	std::vector<Employee> empl(nEmployees);
	int n = empl.size();
	double salary;
	std::string name;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Employee number: " << i + 1 << ", name: ";
		std::cin >> name;
		std::cout << "Salary? ";
		std::cin >> salary;
		
		BankAccount* b_a = new BankAccount;
		empl[i] = Employee(name, salary, b_a);
		if (i > 0)
			if (empl[i].get_salary() == empl[i - 1].get_salary())
				empl[i - 1].set_account(b_a);
		b_a->add_money((1.0 / 12.0) * salary);
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << "Name: " << empl[i].get_name() << "\n"
			<< "Account balance: " << empl[i].get_account()->get_balance() << "\n";
		if (i > 0)
			if (empl[i].get_salary() == empl[i - 1].get_salary())
				continue;
			else
				delete empl[i].get_account();
	}
	std::cin.ignore();
}

void p5()
{
	std::cout << "Enter the size of the array: ";
	unsigned int capacity;
	std::cin >> capacity;
	double* a = new double[capacity];
	double value;
	for (int i = 0; i < capacity; i++)
	{
		std::cout << "Value number " << i + 1 << " in the array: ";
		std::cin >> value;
		*(a + i) = value;
	}
	std::cout << "Average: " << average(a, capacity) << "\n";
	delete[] a;
	std::cin.ignore();
}

double average(double * a, int a_size)
{
	double sum = 0;
	for (int i = 0; i < a_size; i++)
		sum += *(a + i);
	double avg = sum / a_size;
	return avg;
}

void p6()
{
	std::cout << "Enter the size of the array: ";
	unsigned int capacity;
	std::cin >> capacity;
	double* a = new double[capacity];
	double value;
	for (int i = 0; i < capacity; i++)
	{
		std::cout << "Value number " << i + 1 << " in the array: ";
		std::cin >> value;
		*(a + i) = value;
	}
	std::cout << "Maximum: " << *(maximum(a, capacity)) << "\n";
	delete[] a;
	std::cin.ignore();
}

double* maximum(double a[], int a_size)
{
	if (a_size == 0)
		return nullptr;
	double* max = a;
	for (int i = 1; i < a_size; i++)
		if (*max < a[i])
			*max = a[i];
	return max;
}

void p7()
{
	std::cout << "Enter the size of the array: ";
	unsigned int capacity;
	std::cin >> capacity;
	double* a = new double[capacity];
	double value;
	for (int i = 0; i < capacity; i++)
	{
		std::cout << "Value number " << i + 1 << " in the array: ";
		std::cin >> value;
		*(a + i) = value;
	}
	reverse(a, capacity);
	std::cout << "Reversed array:\n";
	for (int i = 0; i < capacity; i++)
		std::cout << *(a + i) << "\n";

	delete[] a;
	std::cin.ignore();

}

void reverse(double a[], int a_size)
{
	double* b = new double[a_size];
	for (int i = a_size - 1, j = 0; i >= 0, j < a_size; i--, j++)
		*(b + j) = *(a + i);
	for (int i = 0; i < a_size; i++)
		*(a + i) = *(b + i);
	delete[] b;
}

void p8()
{
	char a[] = "Hello";
	char b[5]; /* then should the output be "Hell" only, because the function
				  my_strncpy is null terminated*/
	my_strncpy(b, a, 5);
	for (int i = 0; i < 5; i++)
		std::cout << b[i];
	std::cout << "\n";
}

void my_strncpy(char* cpy_to, const char* cpy_from, int num)
{
	for (int i = 0; i < num; i++)
		cpy_to[i] = cpy_from[i];
	if (cpy_to[num - 1] != '\0')
		cpy_to[num - 1] = '\0';
}

void p9()
{
	int len;
	const char str1[] = "ABCDEFG019874";
	const char str2[] = "ABCD";

	len = my_strspn(str1, str2);

	printf("Length of initial segment matching %d\n", len);
}

int my_strspn(const char s[], const char t[])
{
	int match = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		if (t[i] != '\0')
			if (s[i] == t[i])
				match++;
		i++;
	}
	return match;
}

void p10()
{
	char name[] = "Harry";
	reverse(name);
	int i = 0;
	while (name[i] != '\0')
	{
		std::cout << name[i];
		i++;
	}
	std::cout << "\n";
}

void reverse(char s[])
{
	int capacity = 0, i = 0, j;
	while (s[i] != '\0')
	{
		capacity++;
		i++;
	}
	char* p = new char[capacity];
	for (i = 0, j = capacity - 1; i < capacity, j >= 0; i++, j--)
		p[i] = s[j];
	for (i = 0; i < capacity; i++)
		s[i] = p[i];
	delete[] p;
}

void p11()
{
	char a[] = "Ibrahim ";
	char b[] = "Fathy";
	char result[14];
	concat(a, b, result, 14);
	puts(result); // prints the character array
}

void concat(const char a[], const char b[], char result[],
	int result_maxlength)
{
	/* result_maxlength It can hold result_maxlength characters, not counting the
	'\0' terminator. (That is, the buffer has result_maxlength + 1 bytes available.*/
	strncpy(result, a, result_maxlength);
	int i = 0, cap_b = strlen(b);
	strncat(result, b, cap_b); /* Appends the first cap_b characters of source(b)
				to destination(result) , plus a terminating null-character.*/
	if (result[result_maxlength - 1] != '\0')
		result[result_maxlength - 1] = '\0';

	// another implementation
#if 0 
	int i = 0;
	while (a[i] != '\0' && i < result_maxlength)
	{
		result[i] = a[i];
		i++;
	}
	int j = 0;
	while (b[j] != '\0' && i < result_maxlength)
	{
		result[i] = b[j];
		j++;
		i++;
	}
	result[result_maxlength] = '\0';
#endif
}

void p12()
{
	Employee e("Ibrahim", 5000);
	char x[50];
	e.format(x,50);
	puts(x);
}

void p13()
{
	const int BUFFER_CAPACITY = 1000,
		LINES_CAPACITY = 100;
	char buffer[BUFFER_CAPACITY];
	char* lines[LINES_CAPACITY];
	char c;
	int i = 0, j;

	std::cout << "Enter some lines:\n";
	while (i < BUFFER_CAPACITY)
	{
		scanf("%c", &c);
		if (c == '\n')
			buffer[i] = '\0';
		else
			buffer[i] = c;
		i++;
		std::cout << "i = " << i << "\n";
	}
	// Test
#if 0

	i = 0;
	while (i < BUFFER_CAPACITY)
	{
		std::cout << buffer[i];
		i++;
	}
	std::cout << "s\n";
#endif

	lines[0] = &buffer[0];
	for (i = 1, j = 1; i < BUFFER_CAPACITY && j < LINES_CAPACITY; i++)
		if (buffer[i] == '\0'&& i < BUFFER_CAPACITY - 1)
		{
			lines[j] = &buffer[i + 1];
			j++;
		}
	/* Now every element in lines[] points to the firrst char of
			each line*/
	std::cout << "Output:\n";
	for (j = j - 1; j >=0; j--)//j - 1 indicates the last input line, refer to the previous loop
		puts(lines[j]);
}

void p14()
{
	std::string buffer;
	std::string input;
	int capacity = 0;
	std::cout << "Enter some lines. When your'e finshed, type ""end""\n";
	do
	{
		buffer = buffer + input + '\0';
		getline(std::cin, input);
		capacity++;
	} while (input != ("end"));
	capacity--;//to remove the count for "end"

//	std::cout << "capacity: " << capacity << "\n";
//	std::cout << buffer << "-\n";
	std::vector<char*> lines(capacity);
	std::vector<int> offset(capacity);
	//Calculate the offsets
	const int n = buffer.size();
	int k = 0;
	for (int i = 0; i < n && k < capacity; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (buffer[i] == '\0' && buffer[j] == '\0')
			{
				offset[k] = j - (i + 1);
	//			std::cout << "offset[" << k << "] = " << offset[k] << "\n";
				k++;
				break;
			}
		}
	}
	std::cout << "Output:\n";
	k = 0;
	for (int i = 0; i < n && k < capacity; i++)
	{
		if (buffer[i] == '\0' && i < n - 1)
		{
			std::string line = buffer.substr(i + 1, offset[k] + 1);
			lines[k] = new char[line.length()];
			strcpy(lines[k], line.c_str());
			k++;
		}
	}
	for (k = capacity - 1; k >= 0; k--)
	{
		puts(lines[k]);
		delete[] lines[k];
	}
//	puts(lines[0]);
}

void p15()
{
	int BUFFER_CAPACITY = 1000, LINES_CAPACITY = 0;
	char* buffer = new char[BUFFER_CAPACITY];
	char c;
	int i = 0, j;

	std::cout << "Enter some lines, type '@' to end:\n";
	while (scanf("%c", &c))
	{
		if (i < BUFFER_CAPACITY) {
			if (c == '\n')
			{
				buffer[i] = '\0';
				LINES_CAPACITY++;
			}
			else
				buffer[i] = c;
			i++;
		}
		else
		{
			char *buffer_new = buffer;
			BUFFER_CAPACITY = BUFFER_CAPACITY * 2;
			buffer = new char[BUFFER_CAPACITY];
			for (int i = 0; i < BUFFER_CAPACITY; i++)
				buffer[i] = buffer_new[i];
			delete[] buffer_new;
		}
		std::cout << "i = " << i << "\n";
		if (c == '@')
			break;
	}
	char** lines = new char*[LINES_CAPACITY];

	 lines[0] = &buffer[0];
	for (i = 1, j = 1; i < BUFFER_CAPACITY && j < LINES_CAPACITY; i++)
		if (buffer[i] == '\0'&& i < BUFFER_CAPACITY - 1)
		{
			lines[j] = &buffer[i + 1];
			j++;
		}
	/* Now every element in lines[] points to the firrst char of
	each line*/
	std::cout << "Output:\n";
	for (j = j - 1; j >= 0; j--)//j - 1 indicates the last input line, refer to the previous loop
		puts(lines[j]);

	delete[] lines;
	delete[] buffer;
}

void p16()
{
	print_table(square, sqrt);
}

void print_table(DoubleFunPointer f1, DoubleFunPointer f2)
{
	std::cout << std::setw(10) << "x" << "|" << std::setw(10) << "square(x)"
		<< "|" << std::setw(10) << "sqrt(x)" << std::endl;
	std::cout << std::setprecision(7);
	for (double x = 1; x <= 10; x++)
	{
		double y1 = (*f1)(x);
		double y2 = (*f2)(x);
		
		std::cout << std::setw(10) << x << "|" << std::setw(10) << y1 
			<< "|" << std::setw(10) << y2 << std::endl;
	}
}

double square(double x) 
{
	return x * x;
}

void p17()
{
	int a[10];
	fill_with_values(a, 10, square);
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << ", ";
	std::cout << "\n";
}

void fill_with_values(int a[], int size, IntFunPointer f)
{
	for (int i = 0; i < size; i++)
		a[i] = (*f)(i + 1);
}

int square(int x)
{
	return x * x;
}
