// Always include Headlines, if you want to compile the program

# include <stdio.h>

// Function prototype

int ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;

	while (s1[index] != '\0' && s2[index] != '\0' && s1[index] == s2[index])
		index++;
	
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

// MAIN PROGRAM

int main (void)
{
	char s1[] = "Hello";
	char s2[] = "Hello0";
	char s3[] = "42 uptoo";
	char s4[] = "42 uptoo";
	char s5[] = "Hello friend, good luck 111";
	char s6[] = "Bye, seeya";

	printf("Compare s1 and s2 = %d\n", ft_strcmp(s1,s2));
	printf("\n");

	printf("Compare s3 and s4 = %d\n", ft_strcmp(s3,s4));
	printf("\n");

	printf("Compare s5 and s6 = %d\n", ft_strcmp(s5,s6));
	printf("\n");

	return (0);
	
}