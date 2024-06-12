# include <unistd.h>

// The program takes a number as an argument and returns the sum of all prime numbers less than or equal to that number.

/* 
Example input and output:

Input: 10
Output: 17 (2 + 3 + 5 + 7 = 17)

Input: 20
Output: 77 (2 + 3 + 5 + 7 + 11 + 13 + 17 + 19 = 77)
*/

// Convert ASCII digit character to number
int ft_atoi (char *string)
{
	int index;
	int result;
	int sign;

	index = 0;

	while (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
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

// Function to write the number recursively
void write_number(int number)
{
	char digit;

	if (number < 0)
	{
		write (1, "-", 1);
		number = -number;
	}

	if (number >= 10)
		write_number(number / 10);

	digit = (number % 10) + '0';
	write (1, &digit, 1);
}

// Discover which numbers are prime
int is_prime (int number)
{
	int index;

	if (number <= 1)
		return (0);

	if (number == 2)
		return (1);

	if (number % 2 == 0)
		return (0);
	
	index = 3;

	while (index * index <= number)
	{
		if (number % index == 0)
			return (0);
		
		index = index + 2;
	}
	// If it returns 1, it means it is a prime number
	return (1);
}

// Ensures that it is ALWAYS a positive number the digital character I will give you
int is_positive_number(char *string)
{
	int index;

	index = 0;

	if (string[index] == '\0')
		return (0);

	while (string[index] != '\0')
	{
		if (string[index] < '0' || string[index] > '9')
			return (0);

		index++;
	}
	// The characters found are digits
	return (1);
}

// Main program
int main (int argc, char **argv)
{
	int number;
	int sum_of_prime_numbers;

	if (argc != 2 || !is_positive_number(argv[1]))
	{
		write_number(0);
		write (1, "\n", 1);
		return (0);
	}

	number = ft_atoi(argv[1]);

	if (number < 1)
	{
		write_number(0);
		write (1, "\n", 1);
		return (0);
	}

	sum_of_prime_numbers = 0;

	while (number > 0)
	{
		if(is_prime(number))
			sum_of_prime_numbers = sum_of_prime_numbers + number;

		// Decrement the number to check the next number in the next iteration
		number--;
	}

	write_number(sum_of_prime_numbers);
	
	write (1, "\n", 1);
	
	return (0);
}

