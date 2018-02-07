#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>




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

void p1();
void p2(int argc, char* argv[]);
void p3();
void p4(int argc, char* argv[]);
void p5(int argc, char* argv[]);
void develop_playfair_key(std::string& key);
void encrypt_playfair(char & a, char & b, std::string key);
void encrypt_file_playfair(std::istream & is, std::ostream & os, std::string & key);
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

	input_fs.seekg(0, std::ios::beg);//move the get position to the start over
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
	int i = 0;
	while (i < key.size())
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


}

void p7()
{


}

void p8()
{

}

void p9()
{

}

void p10()
{

}

void p11()
{

}
