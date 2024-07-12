# include <unistd.h>

/*
This program checks if all characters of the first string (string_s1) appear in the second string (string_s2) in the same order.
If so, it prints the first string. Otherwise, it prints nothing.

Example:
Input: "./a.out "abc" "abdc" | cat -e
Output: abc$

Input: "./a.out "abc" "acb" | cat -e
Output: $

Input: "./a.out "test" "this is a test" | cat -e
Output: test$
*/


# include <unistd.h>

void	ft_putstr(char const *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index++;
	}
}

int main (int argc, char **argv)
{
	int index_s1;
	int index_s2;

	char *s1;
	char *s2;

	if(argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}


	s1 = argv[1];
	s2 = argv[2];
	index_s1 = 0;
	index_s2 = 0;

	while (s2[index_s2] != '\0')
	{
		if (s2[index_s2] == s1[index_s1])
			index_s1++;
		index_s2++;
	}

	if (!s1[index_s1])
		ft_putstr(s1);

	write (1, "\n", 1);
	return (0);
}
