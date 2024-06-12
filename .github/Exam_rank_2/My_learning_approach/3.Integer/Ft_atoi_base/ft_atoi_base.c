# include <stdio.h>

// Convert the character to its corresponding number depending on the base
int char_to_hex_value(char character)
{
	if (character >= '0' && character <= '9')
		return (character - '0');
	
	else if (character >= 'a' && character <= 'f')
		return (character - 'a' + 10);
	
	else if (character >= 'A' && character <= 'F')
		return (character - 'A' + 10);
	
	return (-1);
}

// Function that converts a string of characters into an integer, interpreting the string according to the specified base
int ft_atoi_base (const char *string, int str_base)
{
	int sign;
	int store_new_value;
	int index;
	int result;

	index = 0;
	while (string[index] == 32 || (string[index] >= 9 && string[index] <= 13))
		index++;

	if (str_base < 2 || str_base > 16)
		return (0);
	
	sign = 1;

	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
		{
			sign = -1;
			index++;
		}
	}

	result = 0;
	store_new_value = 0;

	while (string[index] != '\0')
	{
		store_new_value = char_to_hex_value(string[index]);

		// If the converted value is invalid or greater than the base, exit the loop
		if (store_new_value == -1 || store_new_value >= str_base)
			break;
		
		result = result * str_base + store_new_value;
		index++;
	}

	return (result * sign);
}

// Main program 

int main(void) 
{
    printf("Result of ft_atoi_base(\"1aF\", 16): %d\n", ft_atoi_base("  1aF", 16)); // Should print 431
    printf("Result of ft_atoi_base(\"1a\", 10): %d\n", ft_atoi_base("1a", 10));   // Should print 1
    printf("Result of ft_atoi_base(\"123\", 2): %d\n", ft_atoi_base("123", 2));   // Should print 1 (stops at '2')
    printf("Result of ft_atoi_base(\"-1A\", 16): %d\n", ft_atoi_base("-1A", 16)); // Should print -26

    return 0;
}
