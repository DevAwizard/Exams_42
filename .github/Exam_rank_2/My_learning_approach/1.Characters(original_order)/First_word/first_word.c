# include <unistd.h>

/* This program takes an input string as an argument and prints the first word of the string, ignoring the initial spaces and tabs.

Example:
Input: " Hello World"
Output: "Hello"

Input: " Hola\t\tMundo "
Output: "Hola"

Input: " \t\t foo bar"
Output: "foo" */

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

	string = argv[1];
	index = 0;

	if (string[index] == 32 || (string[index] >= 9 && string[index] <= 13))
		index++;

	while (string[index] != '\0' && string[index] != ' ' && string[index] != '\t' && string[index] != '\n')
	{
		write (1, &string[index], 1);
		index++;
	}

	write(1, "\n", 1);
	return (0);
}

