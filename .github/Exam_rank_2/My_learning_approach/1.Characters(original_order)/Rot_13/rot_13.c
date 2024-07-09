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

# include <unistd.h>

int main (int argc, char **argv)
{
	int index;
	char *string;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 0;
	string = argv[1];

	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] = ((string[index] - 'A' + 13) % 26 + 'A');
		else if (string[index] >= 'a' && string[index] <= 'z')
			string[index] = ((string[index] - 'a' + 13) % 26 + 'a');
		
		write (1, &string[index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}
