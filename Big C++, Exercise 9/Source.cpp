#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "ccc_empl.h"
#include <iomanip>
#include <algorithm>







/**
	Prints the proper usage of the function (encrypt or decrypt)
	@param program_name Program Name
*/
void usage(const std::string& programe_name);

/**
	Prints error when facing troubles in opening files and terminate the program
	@param file_name File name that could not be loaded
*/
void open_file_error(const std::string& file_name);

/**
	Developes a 26 letter character forming the key
	which are the letters of the premitive key (after removing duplicated
	letters and then the alphabet is appended in reverse way)
	@param key the very first key that's provided in command arguments
*/
void develop_monoalphabetic_key(std::string & key);

/**
	Encrypts a charcter using a string key
	@param c char to encrypt
	@param key the key of encryption
	@return the encrypted character
*/
char encrypt(char c, const std::string& key);

/**
	Decrypts a char c using the given string key
	@param c letter to be decrypted
	@param key a string used to decrypt the char c
	@return the decrypted character
*/
char decrypt(char c, const std::string& key);

/**
	Remove duplicated chars from a std::string
	@param str the string to remove the duplicated chars from
*/
void rmv_dublicate_chars(std::string& str);

/**
	Encrypts an input stream and put the output in output stream
*/
void encrypt_file_monoalphabetic(std::istream& is, std::ostream& os, std::string& key);

/**
	Decrypts an input stream and put the output in output stream
*/
void decrypt_file_monoalphabetic(std::istream & is, std::ostream & os, std::string & key);

/**
	Converts a string into an integer
	@param x The string that contains the integer as string
	@return the integer value in string x
*/
int string_to_int(const std::string& x);

/**
	Develops alphabet which is just the regular alphabet shifted to start at
	character k
	@param k character of the key used to be the start of the alphabet key
	@return the alphabet key
*/
std::string develop_Vigenere_key(char k);

/**
	Encrypts a file characters according to their position in the file
	follows the method of vigenere cipher
*/
void encrypt_file_Vigenere(std::istream& is, std::ostream& os, std::string& key);

/**
	Decrypts a file characters according to their position in the file
	follows the method of vigenere cipher
*/
void decrypt_file_Vigenere(std::istream& is, std::ostream& os, std::string& key);

/**
	Create keyword for playfair using string "key" and remove duplicate letters from it.
	Then you fill the keyword, and the remaining letters of the alphabet, into a 5 � 5 square.
	(Since there are only 25 squares, I and J are considered the same letter.)
	
	Here is such an arrangement with the keyword PLAYFAIR.
	P L A Y F
	I R B C D
	E G H K M
	N O Q S T
	U V W X Z
	@param key is the initial keyword
*/
void develop_playfair_key(std::string& key);

/**
	Use the keyword produced in the function develop_playfair_key and encrypt according to the playfair
	cipher technique
	To encrypt a letter pair, say AM, look at the rectangle with corners A and M:
	P L A Y F
	I R B C D
	E G H K M
	N O Q S T
	U V W X Z
	The encoding of this pair is formed by looking at the other two corners of the rectangle,
	in this case, FH. If both letters happen to be in the same row or column, such
	as GO, simply swap the two letters.

	@param a Fist char to encrypt
	@param b Second char to encrypt
	@param key the 25 keyword to use in Encryption
*/
void encrypt_playfair(char & a, char & b, std::string key);

/**
	Encrypts a file characters according to their position in the file
	follows the method of playfair cipher
*/
void encrypt_file_playfair(std::istream & is, std::ostream & os, std::string & key);

/**
	Count how many lines in an istream
	@param is Input Stream to count its lines.
	@return Number of lines
*/
int count_lines(std::istream& is);

/**
	Converts a string to a floating-point value, e.g.
	"3.14" -> 3.14.
	@param s a string representing a floating-point value
	@return the equivalent floating-point value
*/
double string_to_double(std::string s);

/**
	Raises an employee salary.
	@param e employee receiving raise
	@param percent the percentage of the raise
*/
void raise_salary(Employee& e, double percent);

/**
	Reads an employee record from a file.
	@param e filled with the employee
	@param in the stream to read from
*/
void read_employee(Employee& e, std::istream& in);

/**
	Writes an employee record to a stream.
	@param e the employee record to write
	@param out the stream to write to
*/
void write_employee(const Employee& e, std::ostream& out);

/**
	Searches input stream and find an employee record with a given name
	Then it prompts the user to choose what happen
	� Change the salary of this record
	� View the next record
	� Find another employee
	� Quit
	@param database Input/Output stream contains reocords of multiple employees
	@param nrecord Number of records in database stream
	@return true if record was found
*/
bool find_employee(std::iostream& database, int nrecord);

/**
	Sorts a stream lines according to "string comparisons"
	@param database Input/Output stream contains reocords of multiple employees
	@param nrecord Number of records in database stream
	@return 0 if sort is successfully completed
*/
int sort_database(std::iostream& database, int nrecord);

int newline_length(std::fstream& fs);
void p1();
void p2(int argc, char* argv[]);
void p3();
void p4(int argc, char* argv[]);
void p5(int argc, char* argv[]);
void p6();
void p7();
void p8();
void p9();
void p10();
void p11();


int main(int argc, char* argv[])
{
	std::cout << "Write the code of the problem to show the solution of it: \n"
		<< "Example: p5" << std::endl
		<< "******" << std::endl;

	std::cout << "Contents: p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11," << std::endl
		<< "p12, p13, p14, p15, p19, p20" << std::endl
		<< "******\n";

	std::string problem_name;
	do
	{
		std::cout << "Enter the problem's code: ";
		std::cin >> problem_name;
		if (problem_name == ("p1"))
			p1();
		else if (problem_name == ("p2"))
			p2(argc, argv);
		else if (problem_name == ("p3"))
			p3();
		else if (problem_name == ("p4"))
			p4(argc, argv);
		else if (problem_name == ("p5"))
			p5(argc, argv);
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
	std::string file_name;
	std::cout << "Enter the file name to read from? ";
	std::cin >> file_name;

	std::ifstream input_fs(file_name.c_str());
	input_fs.seekg(0, std::ios::end);//move get position to the end of the file

	std::streamoff file_length = input_fs.tellg();//number of characters
	//std::streamoff is long long type

	std::cout << "File size: " << file_length << "\n";

	input_fs.seekg(0, std::ios::beg);//move the get position to the start again

	std::string word;
	int word_count = 0;
	while (input_fs >> word)
		word_count++;

	std::cout << "Number of words: " << word_count << "\n";
	input_fs.clear();/*clear the failure status, stream failed because it
	has reached the end of file*/

	input_fs.seekg(0, std::ios::beg);//move the get position to the start
	std::string line;
	int line_count = 0;
	while (getline(input_fs, line))
		line_count++;

	std::cout << "Number of lines: " << line_count << "\n";
	input_fs.close();

	std::string next_file_name;
	std::cout << "Enter the name of the next file? ";
	std::cin >> next_file_name;

	std::ifstream next_fs(next_file_name.c_str());

	if (next_fs.fail())
	{
		std::cout << "Error opening file!\n";
		std::exit(1);
	}
	else
		std::cout << "File was opened successfully\n";
}

void p2(int argc, char* argv[])
{
	int nfile = 0;
	std::ifstream infile;
	std::ofstream outfile;
	bool decrypt = false;
	std::string key;

	//input should be like this: crypt -d -kFEATHER encrypt.txt output.txt
	if (argc > 5 || argc < 4)
		usage(std::string(argv[0]));

	for (int i = 1; i < argc; i++)
	{
		std::string arg = std::string(argv[i]);
		if (arg.length() >= 2 && arg[0] == '-')
			// It is a command line option
		{
			char option = arg[1];
			if (option == 'd')
				decrypt = true;
			else if (option == 'k')
				key = arg.substr(2);
		}
		else
			//file
		{
			nfile++;
			if (nfile == 1)
			{
				infile.open(arg.c_str());
				if (infile.fail())
					open_file_error(arg);
			}
			else if (nfile == 2)
			{
				outfile.open(arg.c_str());
				if (outfile.fail())
					open_file_error(arg);
			}
		}
	}
	if (key.empty() || nfile != 2)
		usage(argv[0]);


	if (decrypt == true)
		decrypt_file_monoalphabetic(infile, outfile, key);
	else
		encrypt_file_monoalphabetic(infile, outfile, key);

	std::cout << "cryption is done! check output file\n";
	infile.close();
	outfile.close();
}

void usage(const std::string& programe_name)
{
	std::cout << "Usage: \n" << programe_name
		<< " [-d] -kFEATHER input.txt output.txt\n\n"
		<< "parentheses[] means optional\n";
	std::exit(1);
}

void open_file_error(const std::string& file_name)
{
	std::cout << "Error opening file " << file_name << "\n";
	std::exit(1);
}

void develop_monoalphabetic_key(std::string & key)
{
	const short NLETTER = 26;
	rmv_dublicate_chars(key);

	//to upper the letters of the key
	for (int i = 0, n = key.size(); i < n; i++)
		key[i] = toupper(key[i]);

	//Append the alphabet chars to the KEY
	for (char ch = 'Z'; ch > 'Z' - NLETTER; ch--)
		key += (ch);

	rmv_dublicate_chars(key);// remove the duplicated characters
}

char encrypt(char c, const std::string& key)
{
	int key_index;

	if (c >= 'A' && c <= 'Z')
	{
		key_index = int(c) - 'A';
		return key[key_index];
	}
	if (c >= 'a' && c <= 'z')
	{
		key_index = int(c) - 'a';
		return tolower(key[key_index]);//note that key contains upper letters only
	}
	//else
	return c;
}

char decrypt(char c, const std::string& key)
{
	const short NLETTER = 26;
	std::string alphabet;

	//generate alphabet letters
	for (char ch = 'A'; ch <= 'Z'; ch++)
		alphabet += ch;

	// now we have two strings each of length 26: key and alphabet
	// We decrypt as follows

	for (std::string::size_type i = 0; i < NLETTER; i++)
	{
		if (toupper(c) == key[i])//note that key contains upper letters only
		{
			if (islower(c))
				return tolower(alphabet[i]);
			else
				return alphabet[i];
		}
	}
	//else
	return c;
}

void rmv_dublicate_chars(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		std::string::size_type j = i + 1;
		while (j < str.size())
		{
			if (str[i] == str[j])
			{
				str.erase(j, 1);
			}
			else
			{
				++j;
			}
		}
	}
}

void encrypt_file_monoalphabetic(std::istream& is, std::ostream& os, std::string& key)
{
	develop_monoalphabetic_key(key);
	char c;
	while (is.get(c))
		os.put(encrypt(c, key));
}

void decrypt_file_monoalphabetic(std::istream& is, std::ostream& os, std::string& key)
{
	develop_monoalphabetic_key(key);
	char c;
	while (is.get(c))
		os.put(decrypt(c, key));
}

int string_to_int(const std::string& x)
{
	int y;
	std::istringstream istr(x);
	istr >> y;
	return y;
}

void p3()
{
	std::ifstream input_file;
	std::cout << "Enter the input file name\\directory: ";
	std::string file_directory;
	std::cin >> file_directory;
	input_file.open(file_directory.c_str());
	if (input_file.fail())
	{
		std::cout << "Error opening file\n";
		return;
	}

	const int NLETTER = 26;
	std::vector<double> letter_frequency(NLETTER, 0); /* each element denotes a
	character's frequnecy, for example letter_frequency[0] denotes
	letter A frequency and so on according to their arrangemnt in alphabet*/

	char ch;
	while (input_file.get(ch))
	{
		if (ch >= 'A' && ch <= 'Z') //uppercase letter
			letter_frequency[ch - 'A'] += 1;/*if (ch == 'A') then the changed element
		in the vector is letter_frequency[0] which is really denotes to
		character's 'A' frequnecy*/
		else if (ch >= 'a' && ch <= 'z')
			letter_frequency[ch - 'a'] += 1;
	}

	//calculate the size of file (number of characters)
	input_file.clear(); /*clear the failure status, stream failed because it
		has reached the end of file*/

	input_file.seekg(0, std::ios::end);//move get position to the end of the file
	std::streamoff file_length = input_file.tellg();//number of characters
	//std::streamoff is long long type

	std::cout << "Letter Frequencies are:\n";
	for (int i = 0; i < NLETTER; i++)
	{
		letter_frequency[i] = letter_frequency[i] / file_length;// calculate frequency
		std::cout << (char)(i + 'A') << ": " << letter_frequency[i] << "\n";
	}
	input_file.close();
}

void p4(int argc, char* argv[])
{
	int nfile = 0;
	std::ifstream infile;
	std::ofstream outfile;
	bool decrypt = false;
	std::string key;

	//input should be like this: crypt -d -kFEATHER encrypt.txt output.txt
	if (argc > 5 || argc < 4)
		usage(std::string(argv[0]));

	for (int i = 1; i < argc; i++)
	{
		std::string arg = std::string(argv[i]);
		if (arg.length() >= 2 && arg[0] == '-')
			// It is a command line option
		{
			char option = arg[1];
			if (option == 'd')
				decrypt = true;
			else if (option == 'k')
				key = arg.substr(2);
		}
		else
			//file
		{
			nfile++;
			if (nfile == 1)
			{
				infile.open(arg.c_str());
				if (infile.fail())
					open_file_error(arg);
			}
			else if (nfile == 2)
			{
				outfile.open(arg.c_str());
				if (outfile.fail())
					open_file_error(arg);
			}
		}
	}
	if (key.empty() || nfile != 2)
		usage(argv[0]);


	if (decrypt == true)
		decrypt_file_Vigenere(infile, outfile, key);
	else
		encrypt_file_Vigenere(infile, outfile, key);

	std::cout << "cryption is done! check output file\n";
	infile.close();
	outfile.close();
}

std::string develop_Vigenere_key(char k)
{
	std::string key;
	const short NLETTER = 26;

	//Append the alphabet chars to char k
	char ch = k;
	for (int i = 0; i < NLETTER; i++)
	{
		key += ch;
		if (ch < 'Z')
			ch++;
		else if (ch >= 'Z')
			ch = 'A';
	}
	return key;
}

void encrypt_file_Vigenere(std::istream& is, std::ostream& os, std::string& key)
{
	rmv_dublicate_chars(key);
	char c;
	std::string key_alphabet;
	while (is.get(c))
	{
		int key_index = is.tellg();
		key_index = (key_index - 1)% key.size();
		char ch = key[key_index];// The char to be the start of the key
		//tellg gives 1 at the start

		key_alphabet = develop_Vigenere_key(toupper(ch));
		os.put(encrypt(c, key_alphabet));
	}
}

void decrypt_file_Vigenere(std::istream& is, std::ostream& os, std::string& key)
{
	rmv_dublicate_chars(key);
	char c;
	std::string key_alphabet;
	while (is.get(c))
	{
		int key_index = is.tellg();
		key_index = (key_index - 1)% key.size();
		char ch = key[key_index];// The char to be the start of the key
		//tellg gives 1 at the start

		key_alphabet = develop_Vigenere_key(toupper(ch));
		os.put(decrypt(c, key_alphabet));
	}
}

void p5(int argc, char* argv[])
{
	int nfile = 0;
	std::ifstream infile;
	std::ofstream outfile;
	bool decrypt = false;
	std::string key;

	//input should be like this: crypt -d -kFEATHER encrypt.txt output.txt
	if (argc > 5 || argc < 4)
		usage(std::string(argv[0]));

	for (int i = 1; i < argc; i++)
	{
		std::string arg = std::string(argv[i]);
		if (arg.length() >= 2 && arg[0] == '-')
			// It is a command line option
		{
			char option = arg[1];
			if (option == 'd')
				decrypt = true;
			else if (option == 'k')
				key = arg.substr(2);
		}
		else
			//file
		{
			nfile++;
			if (nfile == 1)
			{
				infile.open(arg.c_str());
				if (infile.fail())
					open_file_error(arg);
			}
			else if (nfile == 2)
			{
				outfile.open(arg.c_str());
				if (outfile.fail())
					open_file_error(arg);
			}
		}
	}
	if (key.empty() || nfile != 2)
		usage(argv[0]);

	encrypt_file_playfair(infile, outfile, key);

	std::cout << "cryption is done! check output file\n";
	
	infile.close();
	outfile.close();
}

void develop_playfair_key(std::string& key)
{
	//to upper the letters of the key
	for (int i = 0, n = key.size(); i < n; i++)
		key[i] = toupper(key[i]);

	const int NLETTER = 26;
	for (int i = 0; i < NLETTER; i++)
		key += static_cast<char> (i + 'A');

	//remove character j
	int i = 0, n =  key.size();
	while (i < n)
	{
		if (key[i] == 'J')
			key[i] = 'I';//replace letter J with I
		i++;
	}
	rmv_dublicate_chars(key);
}

void encrypt_playfair(char& a, char& b, std::string key)
{
	//if the character is 'J'
	if (a == 'J')
		a = 'I';
	else if (a == 'j')
		a = 'i';

	if (b == 'J')
		b = 'I';
	else if (b == 'j')
		b = 'i';

	develop_playfair_key(key);
	//make a 2D array to contain the key letters (25 letters)
	const int ROW_SIZE = 5, COLUMN_SIZE = 5;
	char key_letters[ROW_SIZE][COLUMN_SIZE];

	//fill in the array
	//and BTW find where the 2 chars are located in the array
	int key_index = 0;
	int a_row_index, a_column_index, b_row_index, b_column_index;
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COLUMN_SIZE; j++)
		{
			key_letters[i][j] = key[key_index];
			key_index++;


			if (toupper(a) == key_letters[i][j])
			{
				a_row_index = i;
				a_column_index = j;
			}
			if (toupper(b) == key_letters[i][j])
			{
				b_row_index = i;
				b_column_index = j;
			}
		}
	}

	if (a_row_index == b_row_index
		|| a_column_index == b_column_index)
		//then they are in the same row or in the same column respectively
		//we need to swap both values
	{
		char temp = a;
		a = b;
		b = temp;
	}

	else
	{
		//handle low case letters
		if (a >= 'a' && a <= 'z')
			a = tolower(key_letters[a_row_index][b_column_index]);
		else
			a = key_letters[a_row_index][b_column_index];

		if (b >= 'a' && b <= 'z')
			b = tolower(key_letters[b_row_index][a_column_index]);
		else
			b = key_letters[b_row_index][a_column_index];
	}
}

void encrypt_file_playfair(std::istream& is, std::ostream& os, std::string& key)
{
	const int N_CHARS = 2;
	char chars_to_encrpyt[N_CHARS];
	char c;
	int i = 0;
	while (is.get(c))
	{
		if (isalpha(c))
		{
			chars_to_encrpyt[i] = c;
			i++;
			if (i == 2)//array is filled
			{
				encrypt_playfair(chars_to_encrpyt[0], chars_to_encrpyt[1], key);
				os.put(chars_to_encrpyt[0]);
				os.put(chars_to_encrpyt[1]);
				i = 0;
			}
		}
		else
			os.put(c);
	}
	if (i == 1)//half of the array is filled because number of characters is odd
		//and the loop failed because eof has been reached
		os.put(chars_to_encrpyt[0]);
}

void decrypt_file_playfair(std::istream& is, std::ostream& os, std::string& key)
{
	develop_monoalphabetic_key(key);

	char c;
	while (is.get(c))
		os.put(decrypt(c, key));
}

void p6()
{
	std::ifstream template_file, database_file;
	std::ofstream junk_mail("p6_junk_mail.txt");

	template_file.open("p6_template.txt");
	database_file.open("p6_database.txt");

	if (template_file.fail())
		open_file_error("p6_template.txt");
	else if (database_file.fail())
		open_file_error("p6_database.txt");
	else if (junk_mail.fail())
		open_file_error("p6_junk_mail.txt");

	int n_lines = count_lines(database_file);

	srand(time(0));
	int line = 1 + rand() % (n_lines - 1 + 1); // generate random number between 1 and 3

	std::string database_line;
	for (int i = 0; i < line; i++)
		getline(database_file, database_line);

	std::vector<std::string> field;
	field.push_back(database_line.substr(0, database_line.find('|', 0 + 1))); // add the first field
	int first = 0, second;
	std::string field_string;
	for (int i = 0, n = database_line.size(); i < n; i++)
	{
		second = database_line.find('|', first + 1);
		if (database_line[i] == '|')
		{
			field_string = database_line.substr(first + 1, second - first - 1);
			field.push_back(field_string);
		}
		first = i + 1;
	}

#if 0
	for (int i = 0; i < field.size(); i++)
		std::cout << field[i] << "\n";
#endif

	char template_char;
	while (template_file.get(template_char))
	{
		std::string num_tag, tag;

		if (template_char == '|')//find tag
		{
			while (template_file.get(template_char) &&
				(template_char >= '0' && template_char <= '9'))
				num_tag += template_char;

			
			if (!num_tag.empty())
				tag = field[string_to_int(num_tag) - 1];

			junk_mail << tag;
		}
		else
			junk_mail << template_char;
	}

	template_file.close();
	database_file.close();
	junk_mail.close();
}

int count_lines(std::istream& is)
{
	is.seekg(0, std::ios::beg);//move the get position to the start
	std::string line;
	int line_count = 0;
	while (getline(is, line))
		line_count++;

	is.clear();/*clear the failure status, stream failed because it
					 has reached the end of file*/
	is.seekg(0, std::ios::beg);//move the get position to the start again
	
	return line_count;
}

const int NEWLINE_LENGTH = 2;
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

void p7()
{
	std::string file_name = "p7_employee_data.txt";
	std::fstream fs;
	fs.open(file_name.c_str());
	if (fs.fail())
		open_file_error(file_name.c_str());

	fs.seekg(0, std::ios::end); // Go to end of file
	int nrecord = fs.tellg() / RECORD_SIZE;

	double salary_change;
	std::cout << "Enter salary change percentage: ";
	std::cin >> salary_change;

	Employee e;
	for (int i = 0; i < nrecord; i++)
	{
		fs.seekg(i * RECORD_SIZE, std::ios::beg);
		read_employee(e, fs);
		raise_salary(e, salary_change);
		std::cout << "New salary: " << e.get_salary() << "\n";
		fs.seekp(i * RECORD_SIZE, std::ios::beg);
		write_employee(e, fs);
	}
	fs.close();
}

double string_to_double(std::string s)
{
	std::istringstream instr(s);
	double x;
	instr >> x;
	return x;
}

void raise_salary(Employee& e, double percent)
{
	double new_salary = e.get_salary() * (1 + percent / 100);
	e.set_salary(new_salary);
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

void write_employee(const Employee& e, std::ostream& out)
{
	out << e.get_name()
		<< std::setw(10 + (30 - e.get_name().length()))
		<< std::fixed << std::setprecision(2)
		<< e.get_salary();
}

void p8()
{
	std::string file_name = "p8_employee_data.txt", employee_name;

	std::fstream database;
	database.open(file_name.c_str());
	if (database.fail())
		open_file_error(file_name);

	database.seekg(0, std::ios::end); // Go to end of file
	int nrecord = database.tellg() / RECORD_SIZE;

	bool found = find_employee(database, nrecord);

	if (!found)
		std::cout << "No such employee exists!\n";
	
	database.close();
}

bool find_employee(std::iostream& database, int nrecord)
{
	std::string employee_name;
	std::cout << "Enter employee's name: ";
	std::cin.ignore();
	getline(std::cin, employee_name);

	employee_name.erase(std::remove_if(employee_name.begin(), employee_name.end(), ::isspace),
		employee_name.end()); // remove spaces from the string to compare correctly


	Employee e;
	std::string database_empl_name;
	for (int i = 0; i < nrecord; i++)
	{
		database.seekg(i * RECORD_SIZE, std::ios::beg);
		read_employee(e, database);
		database_empl_name = e.get_name();

		database_empl_name.erase(std::remove_if(database_empl_name.begin(), database_empl_name.end(),
			::isspace),
			database_empl_name.end()); // remove spaces from the string to compare correctly

		if (database_empl_name == employee_name) // location found
		{
			std::cout << "Employee's info:\n\n"
				<< "Name: " << e.get_name() << "\n"
				<< "Salary: " << e.get_salary() << "\n\n"
				<< "Choose what to do! (1 - 4)\n"
				<< "1. Change the salary of this record\n"
				<< "2. View the next record\n"
				<< "3. Find another employee\n"
				<< "4. Quit\n";
			

			int record_location = i; 

			short choice;
			do
			{
				std::cin >> choice;
				
				switch (choice)
				{
				case 1: // Change the salary of this record
				{
					double salary_change;
					std::cout << "Enter salary change percentage: ";
					std::cin >> salary_change;

					raise_salary(e, salary_change);
					std::cout << "New salary: " << e.get_salary() << "\n";
					database.seekp(record_location * RECORD_SIZE, std::ios::beg);
					write_employee(e, database);
					break;
				}
				case 2: // View the next record
				{
					record_location++;
					database.seekg(record_location * RECORD_SIZE, std::ios::beg);
					read_employee(e, database);

					std::cout << "\nNext Record is:\nName: " << e.get_name() << "\n"
						<< "Salary: " << e.get_salary() << "\n\n";
					break;
				}
				case 3: //Find another employee
				{
					find_employee(database, nrecord);
					break;
				}
				case 4: // Quit
				{
					break;
				}
				default:
					std::cout << "No such choice! Enter a value (1 - 4), Try again: ";
				}
			} while (record_location < nrecord && (choice < 1 && choice > 4));
			return true;
		}
	}
	return false;
}

void p9()
{
	// file code
	std::string file_name = "p9_employee_data.txt", employee_name;
	std::fstream database;
	database.open(file_name.c_str());
	if (database.fail())
		open_file_error(file_name);
	
	// calculate number of records
	database.seekg(0, std::ios::end); // Go to end of file
	int nrecord = database.tellg() / RECORD_SIZE;

	// sort file
	sort_database(database, nrecord);

	// get the name of employee to be viewed
	std::cout << "Enter employee's name: ";
	std::cin.ignore();
	getline(std::cin, employee_name);

	employee_name.erase(std::remove_if(employee_name.begin(), employee_name.end(), ::isspace),
		employee_name.end()); // remove spaces from the string to compare correctly

	// find that employee in the file using binary search
	Employee e;
	int first = 0, last = nrecord, mid;
	std::string database_empl_name;

	do
	{
		mid = (first + last) / 2;
		database.seekg(mid * RECORD_SIZE, std::ios::beg);
		read_employee(e, database);
		database_empl_name = e.get_name();

		database_empl_name.erase(std::remove_if(database_empl_name.begin(), database_empl_name.end(),
			::isspace),
			database_empl_name.end()); // remove spaces from the string to compare correctly

		if (database_empl_name == employee_name) // location identified
		{
			std::cout << "Employee's info:\n\n"
				<< "Name: " << e.get_name() << "\n"
				<< "Salary: " << e.get_salary() << "\n\n";
		}

		else
			first++;

	} while (database_empl_name != employee_name);
	
	database.close();
}

int sort_database(std::iostream& database, int nrecord)
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
	return 0;
}

void p10()
{
	// file code
	std::string file_name = "p10_employee_data.txt", employee_name;
	std::fstream database;
	database.open(file_name.c_str());
	if (database.fail())
		open_file_error(file_name);

	std::cout << "Newline length in p10_employee_data.txt is: " << newline_length(database)
		<< "\n";

	database.close();
}

int newline_length(std::fstream& fs)
{
	std::streampos get_pos = fs.tellg(); // Remember the current get position

	fs.seekg(0, std::ios::beg); //Reset it to the beginning of the file
	std::streampos  get = fs.tellg();
	std::streampos get2 = fs.tellg();

	char ch;
	std::streampos i = 0;
	while (fs.get(ch))
	{
		get = fs.tellg();
		if (ch == '\n')
		{
			fs.seekg(get_pos, std::ios::beg);

			if ((get - i) == 1)
				return 1;

			else if ((get - i) == 2)
				return 2;
		}
		i.operator+=(1);
	}
	fs.seekg(get_pos, std::ios::beg);
	return 0;
}

void p11()
{

}
