// Always include Headlines, if you want to compile the program
# include <stdio.h>


/* This program defines a function ft_strdup that duplicates a string (src) by allocating dynamic memory for the new string and copying the content of src to this new memory location.

Example:
Input: source = "Hola mundo"
Output: Duplicated string: "Hola mundo" 
*/

# include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *dst;
	int index;

	index = 0;

	while (src[index] != '\0')
		index++;

	dst = malloc(sizeof(char) * (index + 1));

	if (!dst)
		return (NULL);

	index = 0;

	while (src[index] != '\0')
	{
		dst[index] = src[index];

		index++;
	}

	dst[index] = '\0';

	return (dst);
}
