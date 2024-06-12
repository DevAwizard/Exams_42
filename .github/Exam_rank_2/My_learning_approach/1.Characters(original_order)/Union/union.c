# include <unistd.h>

/*
This program takes two input strings and writes all unique characters from both strings in the order they appear.
Characters are not repeated and the order of appearance is preserved.

Example:
Input: "./a.out hello world"
Output: "helo wrd"

Input: "./a.out 123 456"
Output: "123456"
*/

int main (int argc, char **argv)
{
	int index_s1;
	int index_s2;

    // Array to track already printed characters
	char seen[256] = {0};

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	index_s1 = 0;
    
	while (argv[1][index_s1] != '\0')
	{
		if (!seen[(unsigned char)argv[1][index_s1]])
		{
			write (1, &argv[1][index_s1], 1);
	
			seen[(unsigned char) argv[1][index_s1]] = 1;
		}
		index_s1++;
	}

	index_s2 = 0;

	while (argv[2][index_s2] != '\0')
	{
		if (!seen[(unsigned char)argv[2][index_s2]])
		{
			write (1, &argv[2][index_s2], 1);

			seen[(unsigned char) argv[2][index_s2]] = 1;
		}
		index_s2++;
	}
	write (1, "\n", 1);
	return (0);
}