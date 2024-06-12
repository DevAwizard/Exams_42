# include <unistd.h>

/*
This program takes an input string and prints it word by word in reverse order.
Words are defined as sequences of characters separated by spaces or tabs.

Example:
Input: "./a.out "Hello World"
Output: "World Hello"

Input: "./a.out "abc def ghi"
Output: "ghi def abc"
*/


int main (int argc, char **argv)
{
	int word_start; 
	int index;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	index = 0;
	while (argv[1][index] != '\0')
		index++;
	
	index--;
	
	word_start = 0;

	while (index >= 0)
	{
		if (argv[1][index] == ' ' || argv[1][index] == '\t' || index == 0)
		{
			if (index == 0)
				word_start = 0;
			else
				word_start = index + 1;

			while (argv[1][word_start] != '\0' && argv[1][word_start] != ' ' && argv[1][word_start] != '\t')
			{
				write (1, &argv[1][word_start], 1);
				word_start++;
			}
			if (index != 0)
				write (1, " ", 1);
		}
		index--;
	}
	write (1, "\n", 1);
	return (0);
}