# include <stdio.h>

/*
This program takes a string and reverses it. The function ft_strrev is responsible for reversing the string in place, meaning it modifies the original string.

Example:
Input: "hello, world"
Output: "dlrow ,olleh"
*/

char *ft_strrev(char *string)
{
	int start_index;
	int end_index;
	char temporal;
	
	end_index = 0;

	while (string[end_index] != '\0')
		end_index++;
	
	end_index--;

	start_index = 0;
	
	while (end_index > start_index)
	{
		temporal = string[start_index];
		string[start_index] = string[end_index];
		string[end_index] = temporal;

		end_index--;
		start_index++;
	}

	return (string);
}

// Main program
int main (void)
{
	char string[] = "hello, word";

	printf("Original = %s\n", string);
	printf("Reversed = %s\n", ft_strrev(string));
	return (0);
}