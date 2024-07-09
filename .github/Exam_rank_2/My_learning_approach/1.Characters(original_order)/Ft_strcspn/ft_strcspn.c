# include <stdio.h>
#include <stddef.h>

/*
This program defines a function `ft_strcspn` that searches a string (`s1`) for the first occurrence of any character present in another string (`reject`), and returns the position of that character.

Example:
Input: s1 = "hola mundo", reject = "aeiou"
Output: First occurrence of a rejected character in 'hola mundo': 1

Input: s1 = "programación", reject = "aeiou"
Output: First occurrence of a rejected character in 'programación': 2

Input: s1 = "lenguaje", reject = "xyz"
Output: First occurrence of a rejected character in 'lenguaje': none

*/

// Function that checks the two strings and finds the position where a rejected character first appears


size_t ft_strcspn(const char *s1, const char *reject)
{
	size_t index_s1;
	size_t index_reject;

	index_s1 = 0;

	while (s1[index_s1] != '\0')
	{
		index_reject = 0;
		
		while (reject[index_reject] != '\0')
		{
			if (s1[index_s1] == reject[index_reject])
				return (index_s1);
			
			index_reject++;
		}
		index_s1++;
	}
	return (index_s1);
}


// Main program

int main (void)
{
	char *s1;
	char *reject;

	s1 = "lenguaje";
	reject = "xyz";

	printf("%zu\n", ft_strcspn(s1, reject));
	return (0);
}







