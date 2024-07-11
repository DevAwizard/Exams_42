// Always include Headlines, if you want to compile the program

# include <unistd.h>

/* This program takes an input string and capitalizes each word in the string. The first letter of each word is converted to uppercase, and all other letters are converted to lowercase.

Example:
Input: "hello world! 42FOOBAR"
Output: "Hello World! 42foobar"

Input: "a SIMPLE test"
Output: "A Simple Test" 

Input: "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" 

Output:
Second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$

*/

# include <unistd.h>

int ft_strlen (char *string)
{
	int index;

	index = 0;

	while (string[index] != '\0')
		index++;
	return (index);
}

void str_capitalizer (char *string)
{
	int index;

	index = 0;

	while (string[index] <= 32 && string[index] != '\0')
		index++;

	while (string[index] != '\0')
	{
		if ((index == 0 || string[index - 1] ==  '\t' || string[index - 1] == ' ') && (string[index] >= 'a' && string[index] <= 'z'))
		{
			string[index] -= 32;
		}

		else if (!(index == 0 || string[index - 1] == '\t' || string[index - 1] == ' ') && (string[index] >= 'A' && string[index] <= 'Z'))
			string[index] += 32;

		index++;
	}
}



int main (int argc, char **argv)
{
	int index;

	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	index = 1;

	while (index < argc)
	{
		str_capitalizer(argv[index]);
		write (1, argv[index], ft_strlen(argv[index]));
		write (1, "\n", 1);
		index++;
	}
	return (0);
}
