// Always include Headlines, if you want to compile the program
# include <stdio.h>


// Function prototype
char *ft_strdup(char *destination, char *source)
{
	int index;
	
	index = 0;

	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}

	destination[index] = '\0';

	return (destination);
}

// Main program
int main (void)
{
	char s1[10];
	char *s2;

	s2 = "Hello????";
	printf("Copy from source to destination = %s\n", ft_strdup(s1,s2));
	return (0);
}