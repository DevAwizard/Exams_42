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

int ft_strlen (char *string)
{
	int index;

	index = 0;

	while (string[index] != '\0')
		index++;

	return (index);
}

int main (int argc, char **argv)
{
	int index_total_string;
	int index_start;
	int new_index;

	char *string;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	string = argv[1];
	index_total_string = ft_strlen(string) - 1;

	while (index_total_string >= 0)
	{
		while (index_total_string >= 0 && (string[index_total_string] == ' ' || string[index_total_string] == '\t'))
			index_total_string--;

		index_start = index_total_string;
		
		while (index_total_string >= 0 && string[index_total_string] != ' ' && string[index_total_string] != '\t')
			index_total_string--;
		
		new_index = index_total_string + 1;

		while (new_index <= index_start)
		{
			write (1, &string[new_index], 1);
			new_index++;
		}

		if (new_index != -1)
			write (1, " ", 1);

	}
	
	write (1, "\n", 1);
	return (0);
}
