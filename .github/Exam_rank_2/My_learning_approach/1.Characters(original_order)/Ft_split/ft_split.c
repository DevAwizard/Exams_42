#include <stdlib.h>
#include <stdio.h>

Example input and output:

Input: "Hello world this is a test"
Output: ["Hello", "world", "this", "is", "a", "test", NULL]

Program/function description:
- The function `count_words` counts the number of words in a given string. It considers a word as a sequence of non-separator characters (neither space, tab, nor newline) delimited by separators or the end of the string.

- The function `split_words` divides the input string into words, using the `count_words` function to determine the number of words. Then, it traverses the string, skipping the separators and copying each word into a new array of strings.

- Each word is stored in a new memory location, and the resulting array of pointers to words is terminated with a null pointer.

- If any memory allocation fails, the function returns NULL.
*/

# include <stdlib.h>
# include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int length)
{
	int index;

	index = 0;

	while (index < length && s2[index] != '\0')
	{
		s1[index] = s2[index];

		index++;
	}

	s1[index] = '\0';

	return (s1);
}

int count_words(char *string)
{
	int index;
	int count_words;

	index = 0;
	count_words = 0;

	if (!string)
		return (0);

	while (string[index] != '\0')
	{
		if (string[index] != '\0' && string[index] != '\t' && string[index] != ' ' 
		&& string[index] != '\n' && (string[index + 1] == ' ' || string[index + 1] == '\t' || string[index + 1] == '\n' || string[index + 1] == '\0'))
			count_words++;
		index++;
	}
	return (count_words);
}

char **ft_split (char *string)
{
	char **split_words;
	int length;
	int index;
	int start_index_position;
	int index_char;

	index = 0;

	if (string == NULL || string[index] == '\0')
    {
        split_words = (char **)malloc(sizeof(char *));
        split_words[0] = NULL;
        return split_words;
    }

	length = count_words(string);

	split_words = (char **)malloc(sizeof(char *) * (length + 1));

	index_char = 0;
	while (string[index])
	{
		while (string[index] && (string[index] == ' ' || string[index] == '\t' || string[index] == '\n'))
			index++;
		
		start_index_position = index;

		while (string[index] && (string[index] != ' ' && string[index] != '\t' && string[index] != '\n'))
			index++;

		if (index > start_index_position)
		{
			split_words[index_char] = (char *)malloc(sizeof(char) * ((index - start_index_position) + 1));
	
			ft_strncpy(split_words[index_char], &string[start_index_position], index - start_index_position);
			index_char++;
		}
	}
	split_words[index_char] = NULL;
	return (split_words);
}

int main(void)
{
    char **split;
    split = ft_split("");
    printf("Cada    --> %s\n", split[0]);
    printf("palabra --> %s\n", split[0]);
    printf("una     --> %s\n", split[0]);
	printf("linea   --> %s\n", split[0]);
	return (0);
}
