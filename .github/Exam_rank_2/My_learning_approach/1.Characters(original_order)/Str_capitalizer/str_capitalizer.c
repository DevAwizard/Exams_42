// Always include Headlines, if you want to compile the program

# include <unistd.h>

/* This program takes an input string and capitalizes each word in the string. The first letter of each word is converted to uppercase, and all other letters are converted to lowercase.

Example:
Input: "hello world! 42FOOBAR"
Output: "Hello World! 42foobar"

Input: "a SIMPLE test"
Output: "A Simple Test" */

void str_capitalizer(char *str)
{
    int index;
	
	index = 0;

    while (str[index] != '\0')
    {
        if ((index == 0 || str[index - 1] == ' ' || str[index - 1] == '\t') && (str[index] >= 'a' && str[index] <= 'z'))
            str[index] -= 32;
        else if (!(index == 0 || str[index - 1] == ' ' || str[index - 1] == '\t') && (str[index] >= 'A' && str[index] <= 'Z'))
            str[index] += 32;
        write(1, &str[index], 1);
        index++;
    }
}

// Main program

int main(int argc, char **argv)
{
    int index;
	
	index = 1;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    while (index < argc)
    {
        str_capitalizer(argv[index]);
        write(1, "\n", 1);
        index++;
    }
    return (0);
}
