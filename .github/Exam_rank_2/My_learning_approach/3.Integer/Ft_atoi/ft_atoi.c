# include <stdio.h>

// Function that converts a string of characters into an integer (similar to the standard atoi function)
int ft_atoi (char *string)
{
	int index;
	int result;
	int sign;

	index = 0;
	while (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
		index++;
	
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

	while (string[index] >= '0' && string[index] <= '9')
	{
		result = (result * 10) + (string[index] - '0');
		index++;
	}

	return (result * sign);
}

int main (void)
{
	printf("Atoi = %d\n", ft_atoi("-1203"));
	printf("Atoi = %d\n", ft_atoi("1203"));
	printf("Atoi = %d\n", ft_atoi("+-1203"));

	return (0);
}