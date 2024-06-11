# include <unistd.h>

/*
This program takes three input arguments: a string and two characters.
It replaces all occurrences of the second character in the string with the third character.
If the number of arguments is incorrect, or if the replacement characters are not valid (more than one character), it prints a new line and terminates.

Example:
Input: "hello world" "l" "x"
Output: "hexxo worxd"

Input: "123123" "2" "9"
Output: "193193"
*/


int main (int argc, char **argv)
{
	int index;
	char *string;

	if (argc != 4)
	{
		write (1, "\n", 1);
		return (0);
	}


	if (argv[2][1] != '\0' && argv[3][1] != '\0')
	{
		write (1, "\n", 1);
		return (0);
	}

	string = argv[1];
	index = 0;

	while (string[index] != '\0')
	{
		if (string[index] == argv[2][0])
			string[index] = argv[3][0];
		index++;
	}

	index = 0;

	while (string[index] != '\0')
	{
		write (1, &string[index], 1);
		index++;
	}

	write (1, "\n", 1);
	return (0);
}
