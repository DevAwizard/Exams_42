# include <stdio.h>

/*
This program defines a function `ft_strspn` that calculates the initial segment of a string (`string`) that consists only of characters from another string (`accept`). It returns the length of this initial segment.

Example:
Input: String = "holfdaaaaads", Accept = "holaaaa"
Output: Length of the initial segment in 'holfdaaaaads' that consists only of characters from 'holaaaa': 3 The first 3 letters are accepted, so it will return 3.

Input: String = "abc123", Accept = "abc"
Output: Length of the initial segment in 'abc123' that consists only of characters from 'abc': 3 The first 3 letters are accepted, so it will return 3.

Input: String = "123abc", Accept = "123"
Output: Length of the initial segment in '123abc' that consists only of characters from '123': 3 The first 3 letters are accepted, so it will return 3.
*/

// Function that calculates the initial segment of 'string' that consists only of characters from 'accept'

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t index_s;

	size_t index_accept;

	size_t check_match;

	index_s = 0;

	while (s[index_s] != '\0')
	{
		index_accept = 0;
		check_match = 0;
		
		while (accept[index_accept] != '\0')
		{
			if (s[index_s] == accept[index_accept])
			{
				check_match = 1;

				break;
			}
			index_accept++;
		}
		
		if (check_match == 0)
		{
			return (index_s);
		}
		index_s++;
	}
	return (index_s);
}


// Main program

int main(void)
{
    const char *string = "holaaaa";
    const char *accept = "holaaaa";
    printf("Length of initial segment accepted: %zu\n", ft_strspn(string, accept));

    return 0;
}
