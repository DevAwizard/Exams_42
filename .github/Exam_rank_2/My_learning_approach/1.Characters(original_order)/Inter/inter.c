# include <unistd.h>
# include <stdbool.h>

/*
The objective of this program is to find and print the common characters between two strings (argv[1] and argv[2]).
Each common character is printed only once in the order it appears in argv[1].

Example:
Input: "abcdef" "bdfg"
Output: "bdf"

Input: "hello" "world"
Output: "lo"
*/

int main (int argc, char **argv)
{
	int index_s1;
	int index_s2;

    // Array to track already printed characters
	bool printed[256] = {0};

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	index_s1 = 0;

	while (argv[1][index_s1] != '\0')
	{
		index_s2 = 0;
		
		while (argv[2][index_s2] != '\0')
		{
			if ((argv[1][index_s1] == argv[2][index_s2]) && !printed[(unsigned char) argv[1][index_s1]])
			{
				write (1, &argv[1][index_s1], 1);
				
				printed[(unsigned char) argv[1][index_s1]] = 1;

				break;
			}
			index_s2++;
		}
		index_s1++;
	}
	write (1, "\n", 1);
	return (0);
}
