#include <stdlib.h> // Malloc & NULL
#include <stdio.h> // Printf
#include <math.h> // abs

/*
Example:
Input: start = 1, end = 3
Output: [3, 2, 1]

Input: start = -1, end = 2
Output: [2, 1, 0, -1]

Input: start = 0, end = 0
Output: [0]

Input: start = 3, end = -3
Output: [-3, -2, -1, 0, 1, 2, 3]
*/

// Function that creates an array of integers from 'end' to 'start', including both
int *ft_rrange(int start, int end)
{
	int index;
	int size;
	int *array_integer;
	
	index = 0;

	// Calculate the size of the array based on the difference between start and end, plus 1
	size = abs(start - end) + 1;

	array_integer = malloc(sizeof(int) * size);
	
	if (!array_integer)
		return (NULL);
	
	if (end > start)
	{
		while (index < size)
		{
			array_integer[index] = end;
			
			index++;
			
			end--;
		}
	}
	else if (end < start)
	{
		while (index < size)
		{
			array_integer[index] = end;
			
			index++;
			
			end++;
		}
	}
	else
		array_integer[index] = end;

	return (array_integer);
}


// Function to print the array for testing
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main program

int main(void)
{
	int i;
	int *prt;

	// Example 1
	i = 0;
	prt = ft_rrange(1, 3);
	while(i <= 2)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");
	free(prt);

	// Example 2
	i = 0;
	prt = ft_rrange(-1, 2);
	while(i <= 3)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");
	free(prt);

	// Example 3
	i = 0;
	prt = ft_rrange(0, 0);
	while(i <= 0)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");
	free(prt);

	// Example 4
	i = 0;
	prt = ft_rrange(3, -3);
	while(i <= 6)
	{
		printf("%d ", prt[i]);
		i++;
	}
	printf("\n");
	free(prt);

	return (0);
}
