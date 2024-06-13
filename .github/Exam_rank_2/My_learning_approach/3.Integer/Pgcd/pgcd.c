#include <stdio.h>
#include <stdlib.h> // Atoi

/*
Explanation of GCD:
The greatest common divisor (GCD) of two positive integers is the largest positive integer that divides both numbers without leaving a remainder. 
The Euclidean algorithm is an efficient method for computing the GCD, which works by repeatedly subtracting the smaller number from the larger number until the two numbers become equal. The value of the equal numbers is the GCD.

Examples:
1. Input: argv = ["program_name", "48", "18"]
   Output: 6
   Explanation: The GCD of 48 and 18 is 6.

2. Input: argv = ["program_name", "56", "98"]
   Output: 14
   Explanation: The GCD of 56 and 98 is 14.

3. Input: argv = ["program_name", "101", "103"]
   Output: 1
   Explanation: The GCD of 101 and 103 is 1 (they are coprime).
*/

// Main function that calculates the greatest common divisor (GCD) of two positive numbers
int main(int argc, char **argv)
{
	int number_1;
	int number_2;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}

	number_1 = atoi(argv[1]);
	number_2 = atoi(argv[2]);

	if (number_1 > 0 && number_2 > 0)
	{
		
		while (number_1 != number_2)
		{
			if (number_1 > number_2)
				number_1 = number_1 - number_2;
			
			else
				number_2 = number_2 - number_1;
		}

		printf("%d", number_1);
	}

	printf("\n");

	return (0);
}