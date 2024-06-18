# include <unistd.h>

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

	while (index > 0)
	{
		index--;
		write (1, &string[index], 1);

	}
	write (1, "\n", 1);
	return (0);
}
