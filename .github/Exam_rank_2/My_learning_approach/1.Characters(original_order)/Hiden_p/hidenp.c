# include <unistd.h>

/*
The objective of this program is to check if all the characters of one string are contained in another string in the same order.

In other words, it determines if the first string (argv[1]) is a subsequence of the second string (argv[2]).

Example:
"hola" "hawol" -> 0
"hola" "holaaaa" -> 1
*/

// Main program

int main (int argc, char **argv)
{
	int index_s1;
	int index_s2;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
  
	index_s1 = 0;
	index_s2 = 0;

	while (argv[1][index_s1] != '\0' && argv[2][index_s2] != '\0')
	{
		if (argv[1][index_s1] == argv[2][index_s2])
			index_s1++;

		index_s2++;
	}

  if (argv[1][index_s1] == '\0')
		write (1, "1", 1);

	else
		write (1, "0", 1);
	
	write (1, "\n", 1);
	return (0);
}
















