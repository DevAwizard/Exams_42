# include <unistd.h>

// Function that prints a character 'index' times
void print_character(char character, int index)
{
	// Same as index > 0
	while (index--)
	{
		write (1, &character, 1);
	}
}

/*
The objective of this program is to print each letter of the input string as many times as its position in the alphabet.
Uppercase and lowercase letters are treated separately, and any other character is printed as is.

Example:
Input: "abc"
Output: "abbccc"

Input: "A Bc"
Output: "A BBccc"
*/

// Main program

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
		if (string[index] >= 'a' && string[index] <= 'z')
			print_character(string[index], (string[index] - 'a') + 1);
		
		else if (string[index] >= 'A' && string[index] <= 'Z')
			print_character(string[index], (string[index] - 'A') + 1);
		else
			write (1, &string[index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
