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
	{
		if (string[index] >= 'a' && string[index] <= 'z')
			string[index] -=32;
		else if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] +=32;
		
		write (1, &string[index], 1);
		index++;

	}
	write (1, "\n", 1);
	return (0);
}