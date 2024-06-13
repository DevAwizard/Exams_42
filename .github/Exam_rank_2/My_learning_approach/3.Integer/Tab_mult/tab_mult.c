# include <unistd.h>

// Convert a string representation of an integer to an integer value

int ft_atoi(char *string)
{
	int sign;
	int result;
	int index;

	index = 0;
	while (string[index] == 32 || (string[index] >= 9 && string[index] <= 13))
		index++;
	
	sign = 1;

	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
		{
			sign = -1;
			index++;
		}
	}

	result = 0;

	while (string[index] >= '0' && string[index] <= '9')
	{
		result = (result * 10) + (string[index] - '0');
		index++;
	}
	return (sign * result);
}


// Print an integer to the standard output

void write_number (int number)
{
	char digit;

	if (number == -2147483648)
	{
		write (1, "-2", 2);
		number = 147483648;
	}

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}

	if (number >= 10)
		write_number(number / 10);
	
	digit = (number % 10) + '0';
	
	write (1, &digit, 1);
}

// Print the multiplication table of a given number from 1 to 9

void print_multiplication_table (int number)
{
	int index;

	index = 1;

	while (index <= 9)
	{
		write_number(number);
		write (1, "*", 1);
		write_number(index);
		write (1, "=", 1);
		write_number(index * number);
		write (1,"\n", 1);
		
		index++;
	}
}

// Main program

int main (int argc, char **argv)
{
	int number;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	number = ft_atoi(argv[1]);

	print_multiplication_table(number);

	write (1,"\n", 1);
	
	return (0);

}
