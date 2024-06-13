# include <unistd.h>

/* 
Example

./print_hex "10"      # Expected output: a
./print_hex "255"     # Expected output: ff
./print_hex "5156454" # Expected output: 4eae66
./print_hex           # Expected output: (just a newline)
./print_hex "-10"     # Expected output: (just a newline)
*/

// Function that converts a string to an integer (similar to atoi)
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
	return (result * sign);
}

// Function to print an integer as a hexadecimal string

void print_hex(int number)
{
	char hex_digit[] = "0123456789abcdef";
	
	char digit;

	if (number >= 16)
		print_hex(number / 16);
	digit = hex_digit[number % 16];
	write(1, &digit, 1);
}

// Main program
int main (int argc, char **argv)
{
	unsigned int number;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	if (argv[1][0] == '-')
	{
		write (1, "\n", 1);
		return (0);
	}

	number = ft_atoi(argv[1]);

	print_hex(number);

	write (1, "\n", 1);

	return (0);

}