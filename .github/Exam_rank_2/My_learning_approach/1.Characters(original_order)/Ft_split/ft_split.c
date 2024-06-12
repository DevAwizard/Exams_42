#include <stdlib.h>
#include <stdio.h>

/* Simplified Variable Explanation

Function count_words:

- str: the input string.
- i: index to traverse the string.
- word_count: counter for words found.

Function split_words (formerly ft_split):

- str: the input string.
- word_index: index for words in the array.
- char_index: index for characters within a word.
- start: start index of a word.
- i: index to traverse the string.
- words: array of pointers to words. */

/*
Example input and output:

Input: "Hello world this is a test"
Output: ["Hello", "world", "this", "is", "a", "test", NULL]

Program/function description:
- The function `count_words` counts the number of words in a given string. It considers a word as a sequence of non-separator characters (neither space, tab, nor newline) delimited by separators or the end of the string.

- The function `split_words` divides the input string into words, using the `count_words` function to determine the number of words. Then, it traverses the string, skipping the separators and copying each word into a new array of strings.

- Each word is stored in a new memory location, and the resulting array of pointers to words is terminated with a null pointer.

- If any memory allocation fails, the function returns NULL.
*/

// Function to count the number of words in a string
int count_words(char *str)
{
    // Declaration of variables for the index and word count
    int index;
    int word_count;

    // Initialize variables
    index = 0;
    word_count = 0;
    
    // Traverse the string
    while (str[index] != '\0')
    {
        // Count a word when a non-separator character is followed by a separator or the end of the string
        if (str[index] != ' ' && str[index] != '\t' && str[index] != '\n' &&
            (str[index + 1] == '\0' || str[index + 1] == ' ' || str[index + 1] == '\t' || str[index + 1] == '\n'))
        {
            // Increment word_count
            word_count++;
        }
        // Increment index
        index++;
    }
    // Return the total number of words found
    return (word_count);
}

// Function to split a string into words
char **ft_split(char *str)
{
    // Declaration of variables for the word index, character index, word start, string index, and the array of words
    int     word_index;
    int     char_index;
    int     start;
    int     index;
    char    **words;

    // Initialize variables
    word_index = 0;
    index = 0;

    // Allocate memory for the array of word pointers, including space for the NULL pointer at the end
    words = (char **)malloc(sizeof(char *) * (count_words(str) + 1));

    // If words is NULL, return NULL
    if (words == 0)
        return (0);

    // Traverse the input string to split it into words
    while (str[index] != '\0')
    {
        // Initialize char_index to 0
        char_index = 0;
        
        // Skip the separators (spaces, tabs, newlines)
        while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
            index++;
        
        // Mark the start of a word
        start = index;
        
        // Find the end of the word
        while (str[index] != '\0' && str[index] != ' ' && str[index] != '\t' && str[index] != '\n')
            index++;

        // Allocate memory for the current word, including space for the null character
        words[word_index] = (char *)malloc(sizeof(char) * (index - start + 1));

        if (words[word_index] == 0)
            return (0);
        
        // Copy the word to the array
        while (start < index)
        {
            // Copy the word from str to the words array
            words[word_index][char_index] = str[start];
            
            // Increment the start index to move to the next character in str
            start++;
            
            // Increment the char_index to move to the next character in the current word in words
            char_index++;
        }

        // Add the null character at the end of the word
        words[word_index][char_index] = '\0';
        
        // Increment the word index
        word_index++;
    }
    // Add a null pointer at the end of the array
    words[word_index] = 0;
    // Return the array of words
    return (words);
}


int main(void)
{
    char *input = "   Hello   world \t this is \n a test  ";
    char **words;
    int index;

    // Call the split_words function
    words = ft_split(input);

    // Print the resulting words
    index = 0;
    while (words[index] != NULL)
    {
        printf("Word %d: %s\n", index, words[index]);
        index++;
    }

    // Free the memory allocated for each word and for the array of pointers
    index = 0;
    while (words[index] != NULL)
    {
        free(words[index]);
        index++;
    }
    free(words);

    return 0;
}
