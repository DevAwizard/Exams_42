// Always include Headlines, if you want to compile the program

# include <unistd.h>

/* This program takes an input string and capitalizes each word in the string. The first letter of each word is converted to uppercase, and all other letters are converted to lowercase.

Example:
Input: "hello world! 42FOOBAR"
Output: "Hello World! 42foobar"

Input: "a SIMPLE test"
Output: "A Simple Test" */

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

	while (string[index] && (string[index] >= 'a' && string[index] <= 'z'))
		string[index] -=32;
	
	write (1, &string[index], 1);
	
	index++;

	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] += 32;
		
		if (string[index] >= 'a' && string[index] <= 'z')
			{
				if (string[index - 1] == ' ' || string[index - 1] == '\t' || string[index - 1] == 32)
					string[index] -=32;
			}
		write (1, &string[index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}