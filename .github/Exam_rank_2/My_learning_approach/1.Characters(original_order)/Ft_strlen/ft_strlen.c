// Always include Headlines, if you want to compile the program

# include <stdio.h> // printf

int ft_strlen(char *string)
{
	int index;
	
	index = 0;

	while (string[index] != '\0')
		index++;
	return (index);
}

// main program

int main (void)
{
	char *string;

	string = "Hello world";

	printf ("Length of the string is = %d\n", ft_strlen(string));

	return (0);
}