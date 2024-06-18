# include <unistd.h>

/*
This program takes an input string and prints it word by word in reverse order.
Words are defined as sequences of characters separated by spaces or tabs.

Example:
Input: "./a.out "Hello World"
Output: "World Hello"

Input: "./a.out "abc def ghi"
Output: "ghi def abc"
*/

int main(int argc, char **argv)
{
    int index;
    char *string;
    int start_word;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    string = argv[1];

    // Find the length of the string
    index = 0;
    while (string[index] != '\0')
        index++;
    
    // Start from the end of the string
    index--;

    while (index >= 0)
    {
        // Find the start of the word
        while (index >= 0 && string[index] != ' ' && string[index] != '\t')
            index--;
        
        start_word = index + 1;

        // Print the word
        while (string[start_word] != '\0' && string[start_word] != ' ' && string[start_word] != '\t')
        {
            write(1, &string[start_word], 1);
            start_word++;
        }

        // Print a space if it's not the last word
        if (index >= 0)
            write(1, " ", 1);

        // Skip spaces or tabs
        while (index >= 0 && (string[index] == ' ' || string[index] == '\t'))
            index--;
    }

    write(1, "\n", 1);
    return (0);
}
