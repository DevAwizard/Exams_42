# include <stdlib.h>
# include <stdio.h>

/*
This program defines a function `ft_strpbrk` that searches a string (`s1`) for the first occurrence of any character present in another string (`s2`), and returns a pointer to that character in `s1`.
As soon as it finds the first occurrence, it copies the rest of the characters.

Example:
Input: s1 = "Hola mundo", s2 = "aeiou"
Output: First occurrence of a character from 'aeiou' in 'Hola mundo': 'o' -> ola mundo

Input: s1 = "programación", s2 = "xyz"
Output: No characters from 'xyz' found in 'programación' -> Null

Input: s1 = "OpenAI", s2 = "e"
Output: First occurrence of a character from 'e' in 'OpenAI': 'e' -> enAI
*/

// Function that searches for the first occurrence in string s1 of any character that is in string s2
char *ft_strpbrk(const char *s1, const char *s2)
{
	int index_s1;
	int index_s2;

	index_s1 = 0;

	while (s1[index_s1] != '\0')
	{
		index_s2 = 0;

		while (s2[index_s2] != '\0')
		{
			if (s1[index_s1] == s2[index_s2])
				return ((char *) &s1[index_s1]);
			
			index_s2++;
		}
		index_s1++;
	}

	return (NULL);
}



// Main program

int main (void)
{
	printf("%s\n", ft_strpbrk("Hola Mundo", "aeiou"));

	return (0);
}


