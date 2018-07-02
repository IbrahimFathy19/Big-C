#include <iostream>
#include <string>

int main()
{
	std::string word;
	int sum_words = 0;
	int word_length;
	int syllables = 0;
	bool syllables_changed = false;
	int sentences = 0;
	double index;
	while (std::cin >> word)
	{
		sum_words++;
		word_length = word.length();
		if (word[word_length - 1] == 'e')
			word[word_length - 1] = ' ';
		for (int i = 0; i < word_length; i++)
		{
			if (word[i] == ',' || word[i] == ';' || word[i] == '?' || word[i] == '!'
				|| word[i] == '.')
				sentences++;

			if (word[i] == 'a' || (word[i] == 'e') ||word[i] == 'i' ||
				word[i] == 'o' || word[i] == 'u' || word[i] == 'y')
			{
				if (word[i + 1] == 'a' || word[i + 1] == 'e' || word[i + 1] == 'i' ||
					word[i + 1] == 'o' || word[i + 1] == 'u' || word[i + 1] == 'y')
				{
					syllables++;
					i = i + 1;
				}
				else
					syllables++;

				syllables_changed = true;
			}
			if (syllables_changed == false)
				syllables++;
		}
		
	}
	index = 206.835 - 84.6 * (syllables / (sum_words * 1.0)) - 
		1.015 * (sum_words / (sentences * 1.0));
	std::cout << "1. Number of words is: " << sum_words << '\n';
	std::cout << "2. Number of syllables is: " << syllables << '\n';
	std::cout << "3. Number of sentences is: " << sentences << '\n';
	std::cout << "4. The index is: " << index << '\n';
}