#include <iostream>
#include <string>

int main()
{
	double input;
	double sum = 0, sum_squared = 0;
	int n = 0;
	while (std::cin >> input)
	{
		std::cout << input << " __ ";
		n++;
		sum = sum + input;
		sum_squared = sum_squared + input * input;
	}
	std::cout << "\n";
	std::cout << "sum : " << sum << std::endl;
	double average = sum / n;
	double s_deviation = sqrt((sum_squared - (1.0 / n) * sum * sum) / (n - 1));
	std::cout << "Number of elements: " << n << '\n'
		<< "Average: " << average << '\n'
		<< "Standard deviation: " << s_deviation << '\n';
	return 0;
}