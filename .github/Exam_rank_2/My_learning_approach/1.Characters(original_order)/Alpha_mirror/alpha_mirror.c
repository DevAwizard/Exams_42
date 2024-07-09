# include <unistd.h>

// The objective is that the first character will become the last character, the second character will become the second to last, and so on.
// Example: abc --> zyx


int main (int argc, char **argv)
{
	char *string;
	int index;

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
			string[index] = ('a' - string[index]) + 'z';
		
		else if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] = ('A' - string[index]) + 'Z';

		write (1, &string[index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}
