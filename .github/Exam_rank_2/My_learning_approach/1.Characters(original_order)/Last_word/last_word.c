# include <unistd.h>

/* 
The goal of this program is to find and print the last word of a string (argv[1]). A word is considered to be delimited by spaces, tabs, or other whitespace characters.

Example:
Input: "hello world"
Output: "world"

Input: " this is a test "
Output: "test" 
*/

// Main program

int main (int argc, char **argv)
{
	int index;
	char *string;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	index = 0;
	string = argv[1];


	while (string[index] != '\0')
		index++;

	index--;

	while (index >= 0 && (string[index] == ' ' || string[index] == '\t'))
		index--;

	while (index >= 0 && string[index] != ' ' && string[index] != '\t')
		index--;
	
	index++;

	while (string[index] != '\0' && string[index] != ' ' && string[index] != '\t')
	{
		write (1, &string[index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}


