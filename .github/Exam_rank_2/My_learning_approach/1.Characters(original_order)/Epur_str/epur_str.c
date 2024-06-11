# include <unistd.h> 

/* 

The goal of this program is to convert sequences of spaces and tabs in an input string 
into a sequence of three spaces and then print the modified string.


Behavior Details

1. Space Accumulation:

- As the program traverses the string, if it encounters spaces or tabs, it sets check_space to 1.

- No matter how many spaces or tabs there are, as long as it keeps finding spaces/tabs, check_space will remain 1.

2. Upon Finding a Non-space Character:

- When the program encounters a character that is neither a space nor a tab, it checks check_space.
- If check_space is 1, this indicates that there were one or more spaces/tabs before the current character.
- At this point, it writes three spaces to represent the accumulated spaces/tabs.
- Then, it writes the non-space character.
- It resets check_space to 0 to indicate that the spaces/tabs have been handled.

Example:
Input: "Hello World"
Output: "Hello World"

Input: "Hola\t\tMundo"
Output: "Hola Mundo"
*/

int main (int argc, char **argv)
{
	int index;
	int check_space;
	char *string;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	string = argv[1];
	index = 0;
	check_space = 0;

	while (string[index] != 0)
	{
		if (string[index] == ' ' || string[index] == '\t')
		{
			check_space = 1;
		}
		else
		{
			if (check_space)
			{
				write (1, "   ", 3);
				check_space = 0;
			}
			write (1, &string[index], 1);
		}
		index++;
		
	}
	write(1, "\n", 1);
	return (0);
}