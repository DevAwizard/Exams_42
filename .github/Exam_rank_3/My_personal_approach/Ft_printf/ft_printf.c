#include <unistd.h>
#include <stdarg.h>

void put_str(char *string, int *length)
{
	int index;

	index = 0;
	if (!string)
		string = "(null)";
	while (string[index])
		*length += write(1, &string[index++], 1);

}

void put_digit(long long int number, int base, int *len)
{
	char *hexa;
	
	hexa = "0123456789abcdef";
	if (number < 0)
	{
		number *= -1;
		*len += write(1, "-", 1);
	}

	if (number >= base)
	{
		put_digit((number/base), base, len);
	}
	*len += write(1,&hexa[number % base], 1);
}


int	ft_printf(const char *string, ...)
{
	int		length;
	int		index;
	va_list argument;

	length = 0;
	va_start(argument, string);
	index = 0;
	while (string[index])
	{
		if (string[index] == '%' && string[index + 1])
		{
			index++;
			if (string[index] == 's')
				put_str(va_arg(argument, char *), &length);
			else if (string[index] == 'd')
				put_digit((long long int)va_arg(argument, int), 10, &length);
			else if(string[index] == 'x')
				put_digit((long long int)va_arg(argument, unsigned int), 16, &length);
		}
		else
			length += write(1, &string[index], 1);
		index++;
	}
	va_end(argument);
	return (length);
}

int main (void)
{
	// Example with strings
    ft_printf("String: %s\n", "Hello, world!");  // Outputs: String: Hello, world!
    ft_printf("String: %s\n", "42 Network");     // Outputs: String: 42 Network
    ft_printf("Empty string: '%s'\n", "");  // Expected: Empty string: ''
    ft_printf("Spaces: '%s'\n", "   ");     // Expected: Spaces: '   '
	ft_printf("String: %s\n", "");     // Expected nothing
	ft_printf("String: %s\n", NULL);  // Outputs: String: (null) (if the string is NULL)

	// Example using decimal and hexadecimal
    ft_printf("Decimal: %d\n", 255);       // Outputs: Decimal: 255
    ft_printf("Hexadecimal: %x\n", 255);   // Outputs: Hexadecimal: ff
    
    // Another example with a larger number
    ft_printf("Decimal: %d\n", 4096);      // Outputs: Decimal: 4096
    ft_printf("Hexadecimal: %x\n", 4096);  // Outputs: Hexadecimal: 1000
    
    // Example with a small number
    ft_printf("Decimal: %d\n", 16);        // Outputs: Decimal: 16
    ft_printf("Hexadecimal: %x\n", 16);    // Outputs: Hexadecimal: 10

    // Example with zero
    ft_printf("Decimal: %d\n", 0);         // Outputs: Decimal: 0
    ft_printf("Hexadecimal: %x\n", 0);     // Outputs: Hexadecimal: 0

	return (0);
}
---
