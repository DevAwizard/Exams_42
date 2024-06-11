# include <unistd.h>

/*
This program applies the ROT13 cipher to the input string provided as an argument.
Each letter is replaced by the letter that is 13 positions later in the alphabet.
ROT13 is a simple letter substitution cipher where each letter is replaced by the letter that is 13 positions later in the alphabet.

Example:
Input: "Hello World!"
Output: "Uryyb Jbeyq!"

Input: "Abc XYZ"
Output: "Nop KLM"
*/

int main (int argc, char **argv)
{
	int index;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 0;

	while (argv[1][index] != '\0')
	{
		if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
		{
			argv[1][index] = (argv[1][index] - 'a'  + 13) % 26 + 'a';
		}
		else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
		{
			argv[1][index] = (argv[1][index] - 'A'  + 13) % 26 + 'A';
		}
		write (1, &argv[1][index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}