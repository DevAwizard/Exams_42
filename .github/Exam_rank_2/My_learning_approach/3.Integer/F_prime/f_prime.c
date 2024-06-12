# include <stdio.h>
# include <stdlib.h> // Atoi


// Function that decomposes a number into its prime factors and prints them in multiplicative format.
// Example: If the input is 18, the output will be "2*3*3".

int main (int argc, char **argv)
{
	int index;
	int number;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}

	number = atoi(argv[1]);

	if (number == 1)
	{
		printf("\n");
		return (0);
	}

	index = 2;

	while (number >= index)
	{
		if (number % index == 0)
		{
			printf("%d", index);

			number = number / index;

			if (number > 1)
				printf("*");
		}
		else
			index++;
	}
	printf("\n");
	return (0);
}