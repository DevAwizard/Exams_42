// Always include Headlines, if you want to compile the program

# include <unistd.h>

/* This program takes an input string and converts all lowercase letters to uppercase and all uppercase letters to lowercase.

Example:
Input: "Hello World!"
Output: "hELLO wORLD!"

Input: "123AbC"
Output: "123aBc" */

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
			string[index] -=32;
		else if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] +=32;
		
		write (1, &string[index], 1);
		index++;

	}
	write (1, "\n", 1);
	return (0);
}