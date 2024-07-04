# include <unistd.h>


void rstr_capitalizer(char *string)
{
	int index;

	index = 0;

	if (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
        {
            write(1, &string[index], 1);
            index++;
        }	
	
	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] += 32;
		
		if (string[index] >= 'a' && string[index] <= 'z' && (string[index + 1] == ' ' || string[index + 1] == '\0' || string[index + 1] == '\t'))
			string[index] -= 32;
		write (1, &string[index], 1);
		index++;
	}
}

int main (int argc, char **argv)
{
	int index;

	if (argc <= 1)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 1;
	while (index < argc)
	{
		rstr_capitalizer(argv[index]);
		write (1, " ", 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}
