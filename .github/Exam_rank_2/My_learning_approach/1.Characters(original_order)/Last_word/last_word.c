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
		write (1, "\n", 1);
		return (0);
	}
	index = 0;
	string = argv[1];

	while (string[index] != '\0')
		index++;
	
	// Start from the last letter and not from the null character
	index--;

	// Skip spaces and tabs until reaching a non-space character
	while (string[index] >= 0 && string[index] <= 32)
		index--;
	
	// Move the index to the first letter of the word (last word)
	while (string[index] >= 0 && string[index] > 32)
		index--;

	// Start from the first character of the last word
	index++;

	while(string[index] != '\0')
	{
		write(1, &string[index], 1);
		index++;
	}

	write (1, "\n", 1);
	return (0);
}



