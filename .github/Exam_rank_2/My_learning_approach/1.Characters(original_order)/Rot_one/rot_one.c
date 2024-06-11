# include <unistd.h>

/*

This program applies a character transformation to the input string provided as an argument.
Each letter is replaced by the next letter in the alphabet.
If the letter is 'z' or 'Z', it is replaced by 'a' or 'A' respectively.

Example:
Input: "Hello World!"
Output: "Ifmmp Xpsme!"

Input: "zZ"
Output: "aA"
*/


int main (int argc, char **argv)
{
	int index;

	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 0;

	while (argv[1][index] != '\0')
	{
    
		if ((argv[1][index] >= 'a' && argv[1][index] <= 'z') || (argv[1][index] >= 'A' && argv[1][index] <= 'Z'))
		{

			if (argv[1][index] == 'z')
				argv[1][index] = 'a';
            
			else if (argv[1][index] == 'Z')
				argv[1][index] = 'A';

			else 
				argv[1][index] += 1;

			write (1, &argv[1][index], 1);
			index++;
		}
	}
	write (1, "\n", 1);
	return (0);
}