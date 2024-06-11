# include <unistd.h>

/* 

This program takes an input string formatted in snake_case and converts it to camelCase. Each underscore ('_') followed by a lowercase letter is replaced by the corresponding uppercase letter. All other characters remain unchanged.

Example:
Input: "hello_world"
Output: "helloWorld"

Input: "snake_case_to_camel_case"
Output: "snakeCaseToCamelCase" 
*/

// Main program
int main (int argc, char **argv)
{
	int index;
	char *string;
	char character;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 0;
	string = argv[1];

	while (string[index] != '\0')
	{
		if (string[index] == '_')
		{
			index++;
			if (string[index] >= 'a' && string[index] <= 'z')
			{
				character = string[index] - 32;
				write (1, &character, 1);
			}
			else if (string[index] >= 'A' && string[index] <= 'Z')
				write (1, &string[index], 1);
		}
		else 
			write (1, &string[index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}