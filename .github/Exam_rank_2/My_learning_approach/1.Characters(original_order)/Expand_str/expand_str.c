# include <unistd.h>

/* 
Program Behavior

1. Skipping Initial Spaces:

- The program skips all spaces and tabs at the beginning of the input string.

2. Processing Words:

- Writes the characters of a word without modification.

- When it encounters a space or tab, it continues moving forward until it finds the next non-space/tab character.

3. Adding Spaces Between Words:

Before writing the next word, the program always adds three spaces, regardless of how many spaces or tabs there were originally.

4. Final Spaces:

Spaces at the end of the string do not cause the writing of three additional spaces because the main loop terminates when the null character ('\0') is reached.

Example:
Input: "Hello    World"
Output: "Hello   World"

Input: "  Hola\t\tMundo  "
Output: "Hola   Mundo"

This program processes an input string, removing extra spaces and tabs and replacing them with exactly three spaces between words.

*/

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

	while (string[index] == 9 || string[index] == 32)
		index++;
	
	while (string[index] != '\0')
	{
		while (string[index] != '\0' && string[index] != ' ')
		{
			write (1, &string[index], 1);
			index++;
		}
		while (string[index] == 9 || string[index] == 32)
			index++;
		
		if (string[index] != '\0')
		{
			write (1, "   ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}