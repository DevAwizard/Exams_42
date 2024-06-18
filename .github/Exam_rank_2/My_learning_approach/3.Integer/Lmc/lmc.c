# include <stdio.h>

// Function that calculates the least common multiple (LCM) of two positive integers

// Example lmc of 14, 20 is 140

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int number;

	if (a == 0 || b == 0)
		return (0);

	if (a > b)
		number = a;
	else 
		number = b;

	while (1)
	{
		if ((number % a) == 0 && (number % b) == 0)
		{
			return (number);
		}
		number++;
	}
	return (number);
}

// Main program
int main(void)
{

	int number;
	
	number = lcm(14, 20);
    printf("%u\n", number);
	
    return 0; 
}
