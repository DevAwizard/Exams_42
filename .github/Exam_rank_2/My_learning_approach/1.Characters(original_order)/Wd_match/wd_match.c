# include <unistd.h>

/*
This program checks if all characters of the first string (string_s1) appear in the second string (string_s2) in the same order.
If so, it prints the first string. Otherwise, it prints nothing.

Example:
Input: "./a.out abc abdc"
Output: "abc"

Input: "./a.out abc acb"
Output: ""

Input: "./a.out test this is a test"
Output: "test"
*/

// Function that checks if all characters of string_s1 are in string_s2 in the same order

char *wd_match(char *string_s1, char *string_s2)
{
	int index_s1;
	int index_s2;

	index_s1 = 0;

	while (string_s1[index_s1] != '\0')
	{
		index_s2 = 0;
		
		while (string_s2[index_s2] != '\0')
		{
			if (string_s1[index_s1] == string_s2[index_s2])
			{
				index_s1++;
				break;
			}
			index_s2++;
		}

		if (string_s1[index_s1] == '\0')
			break ;
	}

	if (string_s1[index_s1] == '\0')
		return (string_s1);
	
	return(NULL);
}

int main (int argc, char **argv)
{
	int index_s1;
	char *temporal;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	index_s1 = 0;
	temporal = wd_match(argv[1], argv[2]);

	if (temporal != NULL)
	{
		while (argv[1][index_s1] != '\0')
		{
			write(1, &argv[1][index_s1], 1);
			index_s1++;
		}
	}
	write (1, "\n", 1);
	return (0);
}