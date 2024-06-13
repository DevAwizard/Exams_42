# include <stdio.h> // printf
# include <stdlib.h> // atoi

// Main program

int main (int argc, char **argv)
{
	int number_1;
	int number_2;

	if (argc != 4)
	{
		printf("\n");
		return (0);
	}

	number_1 = atoi(argv[1]);
	number_2 = atoi(argv[3]);
	
	if (argv[2][0] == '+')
		printf("%d\n", number_1 + number_2);
	
	else if(argv[2][0] == '-')
		printf("%d\n", number_1 + number_2);
	
	else if (argv[2][0] == '*')
		printf("%d\n", number_1 + number_2);
	else if (argv[2][0] == '/')
	{
		if (number_2 == 0)
			printf("Error: Divisible by zero");
		else
			printf("%d\n", number_1 / number_2);
	}
	else if (argv[2][0] == '%')
	{
		if(number_2 == 0)
			printf("Error: Modulus by zero");
		else 
			printf("%d\n", number_1 % number_2);
	}
	printf("\n");
	return (0);
}