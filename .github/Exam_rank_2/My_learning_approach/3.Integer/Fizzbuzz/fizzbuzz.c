# include <unistd.h>

void write_number(int number)
{
	char digit;

	if (number >= 10)
		write_number(number / 10);
	
	digit = (number % 10) + '0';
	
	write (1, &digit, 1);
}

int main (void)
{
	int number;

	number = 1;

	while (number <= 100)
	{
		if (number % 3 == 0)
			write(1, "fizz\n", 5);
		else if(number % 5 == 0)
			write (1, "buzz\n", 5);
		else if (number % 15 == 0)
			write (1, "fizzbuzz\n", 9);
		else
		{
			write_number(number);
			write (1, "\n", 1);
		}
		number++;
	}
	write (1, "\n", 1);
	return (0);
}