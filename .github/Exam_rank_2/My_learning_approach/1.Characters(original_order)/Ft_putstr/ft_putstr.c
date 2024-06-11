// Always include Headlines, if you want to compile the program

# include <unistd.h> // write 
# include <stdio.h> // printf


// Function prototype
void ft_putstr(char *string)
{
	int index;

	index = 0;

	while (string[index] != '\0')
	{
		write (1, &string[index], 1);
		index++;
	}
}


// main program
int main(void)
{
    char *test_string;

	test_string = "Good Job pal";

    ft_putstr(test_string);
    return 0;
}
