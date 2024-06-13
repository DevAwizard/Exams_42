# include <unistd.h>

// Function that prints an integer character by character

void write_number(int number)
{
	char digit;
	if (number >= 10)
	{
		write_number(number / 10);
	}
	digit = (number % 10) + '0';
	write (1, &digit, 1);
}

int main (int argc, char **argv)
{
	(void)argv;

	write_number(argc - 1);

	write (1, "\n", 1);

	return (0);
}
