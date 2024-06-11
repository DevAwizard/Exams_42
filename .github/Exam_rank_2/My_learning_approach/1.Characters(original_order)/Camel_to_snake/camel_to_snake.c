# include <unistd.h>

// The goal of this program is to convert uppercase characters to lowercase and precede them with an '_'
// Example: HOLA -> _h_o_l_a


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

	while (string[index] != '\0')
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
		{
			string[index] += 32;
			write (1, "_", 1);
		}
		write (1, &string[index], 1);
		index++;
	}
	write (1, "\n", 1);
	return (0);
}