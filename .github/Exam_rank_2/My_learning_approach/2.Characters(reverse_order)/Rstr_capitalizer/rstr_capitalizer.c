# include <unistd.h>

void rstr_capitalizer(char *string)
{
	int index;

	index = 0;

	
	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] += 32;
		
		if ((string[index] >= 'a' && string[index] <= 'z') && (string[index + 1] == ' ' || string[index + 1] == '\t' || string[index + 1] == '\n' || string[index + 1] == '\0'))
			string[index] -= 32;

		write(1, &string[index], 1);
		index++;
	}
}

int main (int argc, char **argv)
{
	int index;

	index = 1;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (index < argc)
	{
		rstr_capitalizer(argv[index]);
		if (index < argc - 1)
			write (1, "\n", 1);
		index++;
	}

	write (1, "\n", 1);
	return (0);
}
