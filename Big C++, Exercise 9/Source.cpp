#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

/**
	Prints the proper usage of the function (encrypt or decrypt)
	@param program_name Program Name
*/
void usage(std::string program__name);

/**
	Prints error when facing troubles in opening files and terminate the program
	@param file_name File name that could not be loaded
*/
void open_file_error(std::string file_name);
void develop_key_26_chars(std::string & key);


char decrypt(char c, std::string key);

/**
	Remove duplicated chars from a std::string
	@param str the string to remove the duplicated chars from
*/
void rmv_duplicate_string(std::string& str);

/**
	Encrypts a charcter using a string key
	@param c char to encrypt
	@param key the key of encryption
	@return the encrypted character
*/
char encrypt(char c, std::string key);

/**
	Encrypts an input stream and put the output in output stream
*/
void encrypt_file(std::istream& is, std::ostream& os, const std::string& key);

void decrypt_file(std::istream & is, std::ostream & os, const std::string & key);

/**
	Converts a string into an integer
	@param x The string that contains the integer as string
	@return the integer value in string x
*/
int string_to_int(const std::string& x);

void p1();
void p2(int argc, char* argv[]);
void p3();
void p4();
void p5();
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
			p4();
		else if (problem_name == ("p5"))
			p5();
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
	input_fs.clear();

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
		decrypt_file(infile, outfile, key);
	else
		encrypt_file(infile, outfile, key);

	std::cout << "cryption is done! check output file\n";
	infile.close();
	outfile.close();
}

void usage(std::string programe_name)
{
	std::cout << "Usage: \n" << programe_name
		<< " [-d] -kFEATHER encrypt.txt output.txt\n\n"
		<< "parentheses[] means optional\n";
	std::exit(1);
}

void open_file_error(std::string file_name)
{
	std::cout << "Error opening file " << file_name << "\n";
	std::exit(1);
}

void develop_key_26_chars(std::string & key)
{
	const short NLETTER = 26;
	rmv_duplicate_string(key);

	//Append the alphabet chars to the KEY
	for (int ch = 'Z'; ch > 'Z' - NLETTER; ch--)
		key += static_cast<char> (ch);

	rmv_duplicate_string(key);// remove the duplicated characters
}

char encrypt(char c, std::string key)
{
	rmv_duplicate_string(key);
	int initial_key_size = key.size();

	develop_key_26_chars(key);
	std::string key_lower = key; // lower appended chars

	//lower down the appended charcters
	for (int i = initial_key_size, n = key.size(); i < n; i++)
		key_lower[i] = tolower(key_lower[i]);

	// Now we encrypt
	int key_index;

	if (c >= 'A' && c <= 'Z')
	{
		key_index = int(c) - 'A';
		return key[key_index];
	}
	if (c >= 'a' && c <= 'z')
	{
		key_index = int(c) - 'a';
		return key_lower[key_index];
	}
	//else
	return c;
}

char decrypt(char c, std::string key)
{
	const short NLETTER = 26;
	develop_key_26_chars(key);
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
	return c;
}
void rmv_duplicate_string(std::string& str)
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
void encrypt_file(std::istream& is, std::ostream& os, const std::string& key)
{
	char c;
	while (is.get(c))
		os.put(encrypt(c, key));
}

void decrypt_file(std::istream& is, std::ostream& os, const std::string& key)
{
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

}

void p4()
{

}

void p5()
{

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
