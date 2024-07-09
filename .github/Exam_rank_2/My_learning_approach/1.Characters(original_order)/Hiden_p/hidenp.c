# include <unistd.h>

/*
The objective of this program is to check if all the characters of one string are contained in another string in the same order.

In other words, it determines if the first string (argv[1]) is a subsequence of the second string (argv[2]).

Example:
"hola" "hawol" -> 0
"hola" "holaaaa" -> 1
*/

// Main program

# include <unistd.h>

int main (int argc, char **argv)
{
	int index_s1;
	int index_s2;

	char *s1;
	char *s2;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	s1 = argv[1];
	s2 = argv[2];

	index_s1 = 0;
	index_s2 = 0;
	
	while (s1[index_s1] != '\0' && s2[index_s2] != '\0')
	{
		if (s1[index_s1] == s2[index_s2])
			index_s1++;
		
		index_s2++;
	}

	if (s1[index_s1] == '\0')
		write (1, "1", 1);
	else
		write (1, "0", 1);
	
	write (1, "\n", 1);
	return (0);
}
















