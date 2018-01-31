#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void p1();
void p2(int argc, char* argv[]);

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

/**
	Remove duplicated chars from a std::string
	@param str the string to remove the duplicated chars from
	@return a string free of duplicated characters
*/
std::string rmv_duplicate_string(std::string str);
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
		exit(1);
	}
	else
		std::cout << "File was opened successfully\n";
}

void p2(int argc, char* argv[])
{
	std::cout << argc << "\n" << rmv_duplicate_string(argv[1]);
	
	//input should be like this: crypt -d -kFEATHER encrypt.txt output.txt
	if (argc > 5 || argc < 4)
		usage(std::string(argv[0]));
		
	
	for (int i = 0; i < argc; i++)
	{
		std::string arg = std::string(argv[i]);
		std::cout << arg << "\n";
	}
}

void usage(std::string programe_name)
{
	std::cout << "Usage: \n" << programe_name
		<< " [-d] -kFEATHER encrypt.txt output.txt\n\n"
		<< "parentheses[] means optional\n";
	exit(1);
}

void open_file_error(std::string file_name)
{
	std::cout << "Error opening file " << file_name << "\n";
	exit(1);
}

char encryt(char c, std::string key)
{
	return '0';

}

std::string rmv_duplicate_string(std::string str)
{
	for (std::string::size_type i = 0, str_size = str.size(); i < str_size; i++)
	{
		std::string::size_type j = i + 1;
		while (j < str_size)
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
	return str;
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